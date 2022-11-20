#include "framework.h"
#include "CMonsterMissile.h"

CMonsterMissile::CMonsterMissile()
{
	m_vecScale = Vector(10, 10);
	m_vecDir = Vector(0, 0);
	m_fVelocity = 300;
	m_layer = Layer::MonsterMissile;
	m_strName = L"MonsterMissile";

	m_pTearsImage = nullptr;
	m_bIsHit = false;
}

CMonsterMissile::~CMonsterMissile()
{
}

void CMonsterMissile::Init()
{
	m_pTearsImage = RESOURCE->LoadImg(L"MonsterTears", L"Image\\Effect\\Monster_Tears.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"None", m_pTearsImage, Vector(0.f, 0.f), Vector(64.f, 64.f), Vector(64.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"Hit", m_pTearsImage, Vector(0.f, 0.f), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1f, 14, false);
	m_pAnimator->Play(L"None");

	AddComponent(m_pAnimator);

	m_tearsState = TearsState::None;

	AddCollider(ColliderType::Circle, Vector(8, 8), Vector(0, 0));
}

void CMonsterMissile::Update()
{
	m_vecPos += m_vecDir * m_fVelocity * DT;

	// 화면밖으로 나갈경우 삭제
	if (m_vecPos.x < 0 ||
		m_vecPos.x > WINSIZEX ||
		m_vecPos.y < 0 ||
		m_vecPos.y > WINSIZEY)
		DELETEOBJECT(this);

	switch (m_tearsState)
	{
	case TearsState::None:
		stateTears = L"None";

		if (true == m_bIsHit)
		{
			m_tearsState = TearsState::Hit;
		}
	case TearsState::Hit:
		stateTears = L"Hit";

		if (false == m_bIsHit)
		{
			m_tearsState = TearsState::None;
		}
	}
}

void CMonsterMissile::Render()
{
	RENDER->FrameCircle(
		m_vecPos.x,
		m_vecPos.y,
		m_vecScale.x);
}

void CMonsterMissile::Release()
{
}

void CMonsterMissile::OnCollisionEnter(CCollider* pOtherCollider)
{
	Logger::Debug(L"미사일이 충돌체와 부딪혀 사라집니다.");
	DELETEOBJECT(this);
}

void CMonsterMissile::SetDir(Vector dir)
{
	m_vecDir = dir.Normalized();
}

void CMonsterMissile::SetVelocity(float velocity)
{
	m_fVelocity = velocity;
}