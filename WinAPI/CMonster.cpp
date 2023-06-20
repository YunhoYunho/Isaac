#include "framework.h"
#include "CMonster.h"

#include "CRenderManager.h"
#include "CCollider.h"

#include "CMonsterMissile.h"
#include "CPlayerMissile.h"
#include "CEnterEffect.h"

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

	m_bIsDead = false;
	m_bIsShot = false;
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
	DustEffect();
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

void CMonster::DustEffect()
{
	CEnterEffect* pEnterEffect = new CEnterEffect();
	pEnterEffect->SetPos(m_vecPos);
	ADDOBJECT(pEnterEffect);
}

void CMonster::GetDamaged(float value)
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
			m_bIsDead = true;
		}
	}
}

void CMonster::Dead()
{
	fCooltime += DT;

	if (fCooltime > 0.3f)
	{
		RemoveCollider();
	}

	if (fCooltime > 1.0f)
	{
		m_bIsDead = true;
		DeadCount();
		DELETEOBJECT(this);
		fCooltime = 0;
	}
}

void CMonster::DeadCount()
{
	if (true == m_bIsDead)
	{
		MONSTERKILLCOUNT++;
		m_bIsDead = false;
	}
}

void CMonster::Trace()
{
	m_vecMoveDir = m_vecPlayerPos.Normalized();
	m_vecPos += m_vecMoveDir * m_fSpeed * DT;
}

void CMonster::PingPong()
{
	int max = 0;
	int min = 0;

	max = INROOM1 ? WINSIZEX : WINSIZEX * 2;
	min = INROOM1 ? 0 : WINSIZEX;

	if (m_vecPos.x >= max - 100)
	{
		left = true;
		right = false;
	}

	if (m_vecPos.x <= min + 100)
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
		//Logger::Debug(L"적 미사일 생성");

		if (true != m_bIsBoss)
		{
			CMonsterMissile* pMissile = new CMonsterMissile();
			pMissile->SetPos(m_vecPos);
			pMissile->SetDir(m_vecPlayerPos);
			ADDOBJECT(pMissile);
		}

		else
		{
			RangeMissile();
		}

		m_bIsShot = true;
	}

	m_fShotTimer += DT;

	if (m_fShotTimer > 1.0f)
	{
		m_fShotTimer = 0;
	}
}

void CMonster::RangeMissile()
{
	float angleToTarget = Vector::DirToAngle(PLAYERPOS - m_vecPos);

	for (int i = 0; i < 10; i++)
	{
		CMonsterMissile* pMissile = new CMonsterMissile();

		pMissile->SetPos(m_vecPos);
		float missileAngle = angleToTarget + rand() % 60 - 30;
		Vector angleToDir = Vector::AngleToDir(missileAngle);
		pMissile->SetDir(angleToDir);
		ADDOBJECT(pMissile);
	}
}

void CMonster::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Player")
	{
		Logger::Debug(L"몬스터가 Player와 충돌진입");
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
	if (pOtherCollider->GetObjName() == L"Player")
	{
		Logger::Debug(L"몬스터가 Player와 충돌해제");
	}
	else if (pOtherCollider->GetObjName() == L"미사일")
	{
		Logger::Debug(L"몬스터가 미사일과 충돌해제");
	}
}
