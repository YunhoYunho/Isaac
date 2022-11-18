#include "framework.h"
#include "CExplosion.h"

CExplosion::CExplosion()
{
	m_pExplosionImage = nullptr;
	
	m_bIsExplosion = false;
	m_fDamage = 2.0f;
}

CExplosion::~CExplosion()
{
}

bool CExplosion::Boom()
{
	return false;
}

void CExplosion::Init()
{
	m_pExplosionImage = RESOURCE->LoadImg(L"Explosion", L"Image\\Effect\\Effect_BOOM.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Explosion", m_pExplosionImage, Vector(0.f, 0.f), Vector(100.f, 100.f), Vector(100.f, 0.f), 0.1f, 12, false);

	m_pAnimator->Play(L"Explosion");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(60, 60), Vector(0, 0));
}

void CExplosion::Update()
{
	switch (m_explosionState)
	{
	case ExplosionState::None:
		if (true == m_bIsExplosion)
		{
			m_stateEXplosion = ExplosionState::Explosion;
		}
	case ExplosionState::Explosion:
		m_bIsExplosion = true;
		stateExplosion = L"Explosion";

		AnimatorUpdate();
	}
}

void CExplosion::Render()
{
}

void CExplosion::Release()
{
}

void CExplosion::AnimatorUpdate()
{
	m_pAnimator->Play(stateExplosion, false);
}

void CExplosion::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CExplosion::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CExplosion::OnCollisionExit(CCollider* pOtherCollider)
{
}
