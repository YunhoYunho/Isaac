#include "framework.h"
#include "CPlayerMissile.h"

CPlayerMissile::CPlayerMissile()
{
	m_vecScale = Vector(10, 10);
	m_vecDir = Vector(0, 0);
	m_fVelocity = 300;
	m_layer = Layer::Missile;
	m_strName = L"PlayerMissile";

	m_pTearsImage = nullptr;
	m_bIsHit = false;
}

CPlayerMissile::~CPlayerMissile()
{
}

void CPlayerMissile::Init()
{
	m_pTearsImage = RESOURCE->LoadImg(L"IsaacTears", L"Image\\Effect\\Isaac_Tears.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"None", m_pTearsImage, Vector(0.f, 0.f), Vector(64.f, 64.f), Vector(64.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"Hit",  m_pTearsImage, Vector(0.f, 0.f), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1f, 14, false);
	m_pAnimator->Play(L"None");

	AddComponent(m_pAnimator);

	m_tearsState = TearsState::None;

	AddCollider(ColliderType::Circle, Vector(8, 8), Vector(0, 0));
}

void CPlayerMissile::Update()
{
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

	m_vecPos += m_vecDir * m_fVelocity * DT;

	// 화면밖으로 나갈경우 삭제
	if (m_vecPos.x < 0 ||
		m_vecPos.x > WINSIZEX ||
		m_vecPos.y < 0 ||
		m_vecPos.y > WINSIZEY)
		DELETEOBJECT(this);
}

void CPlayerMissile::Render()
{
	RENDER->FrameCircle(
		m_vecPos.x,
		m_vecPos.y,
		m_vecScale.x);
}

void CPlayerMissile::Release()
{
}

void CPlayerMissile::OnCollisionEnter(CCollider* pOtherCollider)
{
	Logger::Debug(L"미사일이 충돌체와 부딪혀 사라집니다.");
	DELETEOBJECT(this);
}

void CPlayerMissile::SetDir(Vector dir)
{
	m_vecDir = dir.Normalized();
}

void CPlayerMissile::SetVelocity(float velocity)
{
	m_fVelocity = velocity;
}
