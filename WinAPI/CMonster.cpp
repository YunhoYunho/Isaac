#include "framework.h"
#include "CMonster.h"

#include "CRenderManager.h"
#include "CCollider.h"

#include "CMissile.h"

CMonster::CMonster()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;


	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);

	m_bIsMove = false;
	m_bIsShot = false;
	m_bIsDead = false;
}

CMonster::~CMonster()
{
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

void CMonster::CreateMissile()
{
	Logger::Debug(L"적 미사일 생성");

	if (m_bIsShot)
	{
		CMissile* pMissile = new CMissile();
		pMissile->SetPos(m_vecPos);
		pMissile->SetDir(m_vecTargetDir);
		ADDOBJECT(pMissile);
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

Vector CMonster::GetMonLookAt()
{
	return m_vecMonLookAt;
}

Vector CMonster::GetPlayerPos()
{
	return m_vecPlayerPos;
}

CGameObject* CMonster::GetPlayerObj()
{
	return m_pPlayerObj;
}

void CMonster::SetPlayerPos(Vector playerPos, float timeToPlayer)
{
	m_vecPlayerPos = playerPos;
	m_fTimeToPlayer = timeToPlayer;
}

void CMonster::SetPlayerObj(CGameObject* pPlayerObj)
{
	m_pPlayerObj = pPlayerObj;
}

void CMonster::Trace(Vector dir, float velocity)
{
	if (dir.Magnitude() == 0)
		return;

	m_vecPlayerPos = m_vecMonLookAt;
	m_vecPlayerPos += dir.Normalized() * velocity * DT;
	m_fTimeToPlayer = 0;
}