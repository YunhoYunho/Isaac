#include "framework.h"
#include "CMonster.h"

#include "CRenderManager.h"
#include "CCollider.h"

#include "CMonsterMissile.h"
#include "CPlayerMissile.h"

CMonster::CMonster()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, 0);

	left = false;
	right = false;
	up = false;
	down = false;

	fCooltime = 0;
	m_fRange = 10.0f;
}

CMonster::~CMonster()
{
}

Vector CMonster::GetLookDir()
{
	return m_vecLookDir;
}

void CMonster::SetLookDir(Vector vecLookDir)
{
	m_vecLookDir = vecLookDir;
}

void CMonster::SetMoveDir(Vector vecMoveDir)
{
	m_vecMoveDir = vecMoveDir;
}

void CMonster::Init()
{
	AddCollider(ColliderType::Rect, Vector(90, 90), Vector(0, 0));
}

void CMonster::Update()
{
}

void CMonster::Render()
{
	RENDER->FrameRect(
		m_vecPos.x - m_vecScale.x * 0.5f,
		m_vecPos.y - m_vecScale.y * 0.5f,
		m_vecPos.x + m_vecScale.x * 0.5f,
		m_vecPos.y + m_vecScale.y * 0.5f);
}

void CMonster::Release()
{
}

void CMonster::GetDamaged(int value)
{
	m_HP -= value;

	if (m_HP < 0) 
		m_HP = 0;
}

void CMonster::BossDead()
{
	if (m_HP <= 0)
	{
		fCooltime += DT;

		if (fCooltime > 0.1f)
		{
			RemoveCollider();
			m_fSpeed = 0;
			fCooltime = 0;
		}
	}
}

void CMonster::Dead()
{
	if (m_HP <= 0)
	{
		fCooltime += DT;

		if (fCooltime > 1.0f)
		{
			DELETEOBJECT(this);
		}

		if (fCooltime > 0.3f)
		{
			RemoveCollider();
		}
	}
}

void CMonster::Trace()
{
	m_vecMoveDir = m_vecPlayerPos.Normalized();
	m_vecPos += m_vecMoveDir * m_fSpeed * DT;
}

void CMonster::PingPong()
{
	if (m_vecPos.x >= WINSIZEX - 100)
	{
		left = true;
		right = false;
	}

	if (m_vecPos.x <= 100)
	{
		left = false;
		right = true;
	}

	if (m_vecPos.y >= WINSIZEY - 100)
	{
		up = true;
		down = false;
	}

	if (m_vecPos.y <= 100)
	{
		up = false;
		down = true;
	}

	if (up) m_vecPos.y -= m_fSpeed * DT;
	if (down) m_vecPos.y += m_fSpeed * DT;
	if (left) m_vecPos.x -= m_fSpeed * DT;
	if (right) m_vecPos.x += m_fSpeed * DT;
}

void CMonster::TargetDist()
{
	targetDist = (m_vecPos - PLAYERPOS).SqrMagnitude();
}

void CMonster::TargetPos()
{
	m_vecPlayerPos = PLAYERPOS - m_vecPos;
}

void CMonster::CreateMissile()
{
	TargetPos();

	if (m_fShotTimer == 0)
	{
		Logger::Debug(L"적 미사일 생성");

		CMonsterMissile* pMissile = new CMonsterMissile();
		pMissile->SetPos(m_vecPos);
		pMissile->SetDir(m_vecPlayerPos);
		ADDOBJECT(pMissile);
	}

	m_fShotTimer += DT;

	if (m_fShotTimer > 1.0f)
	{
		m_fShotTimer = 0;
	}
}

void CMonster::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		Logger::Debug(L"몬스터가 플레이어와 충돌진입");
	}
	else if (pOtherCollider->GetObjName() == L"미사일")
	{
		Logger::Debug(L"몬스터가 미사일과 충돌진입");
	}
}

void CMonster::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CMonster::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		Logger::Debug(L"몬스터가 플레이어와 충돌해제");
	}
	else if (pOtherCollider->GetObjName() == L"미사일")
	{
		Logger::Debug(L"몬스터가 미사일과 충돌해제");
	}
}
