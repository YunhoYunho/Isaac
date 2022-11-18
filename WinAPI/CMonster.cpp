#include "framework.h"
#include "CMonster.h"

#include "CRenderManager.h"
#include "CCollider.h"

#include "CMonsterMissile.h"

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

	m_vecLookAt = Vector(0, 0);
	m_vecTargetPos = Vector(0, 0);
	m_pTargetObj = nullptr;
	m_fTimeToTarget = 0;
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
	// 추적할 게임오브젝트가 있을 경우
	if (nullptr != m_pTargetObj)
	{
		if (m_pTargetObj->GetReserveDelete())
		{
			// 추적할 게임오브젝트가 삭제예정인 경우 추적 해제
			m_pTargetObj = nullptr;
		}
		else
		{
			// 추적할 게임오브젝트가 있을 경우 게임오브젝트의 위치를 목표위치로 지정
			SetTargetPos(m_pTargetObj->GetPos());
		}
	}

	// 목표 위치로 이동
	MoveToTarget();
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
		CMonsterMissile* pMissile = new CMonsterMissile();
		pMissile->SetPos(m_vecPos);
		pMissile->SetDir(m_vecTargetPos);
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

Vector CMonster::GetLookAt()
{
	return m_vecLookAt;
}

Vector CMonster::GetTargetPos()
{
	return m_vecTargetPos;
}

CGameObject* CMonster::GetTargetObj()
{
	return m_pTargetObj;
}

void CMonster::SetTargetPos(Vector targetPos, float timeToTarget)
{
	m_vecTargetPos = targetPos;
	m_fTimeToTarget = timeToTarget;
}

void CMonster::SetTargetObj(CGameObject* pTargetObj)
{
	m_pTargetObj = pTargetObj;
}

void CMonster::Scroll(Vector dir, float velocity)
{
	// 스크롤의 방향 크기가 없는 경우 진행하지 않음
	if (dir.Magnitude() == 0)
		return;

	// 스크롤의 목표 위치는 현재위치에서 스크롤 방향으로 떨어진 위치
	m_vecTargetPos = m_vecLookAt;
	m_vecTargetPos += dir.Normalized() * velocity * DT;
	m_fTimeToTarget = 0;	// 스크롤은 시간차를 두지 않은 즉각 이동
}

void CMonster::MoveToTarget()
{
	m_fTimeToTarget -= DT;

	if (m_fTimeToTarget <= 0)
	{
		// 목표위치까지 남은 시간이 없을 경우 목적지로 현재위치 고정
		m_vecLookAt = m_vecTargetPos;
	}
	else
	{
		// 목표위치까지 남은 시간이 있을 경우
		// 목적지까지 남은시간만큼의 속도로 이동
		// 이동거리 = 속력 * 시간
		// 속력 = (도착지 - 출발지) / 소요시간
		// 시간 = 프레임단위시간
		m_vecLookAt += (m_vecTargetPos - m_vecLookAt) / m_fTimeToTarget * DT;
	}
}
