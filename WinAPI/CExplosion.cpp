#include "framework.h"
#include "CExplosion.h"
#include "CMonster.h"
#include "CPlayer.h"

CExplosion::CExplosion()
{
	m_layer = Layer::Explosion;
	m_strName = L"Explosion";

	m_pExplosionImage = nullptr;
	m_fCooltime = 0;
	m_fDamage = 10;
}

CExplosion::~CExplosion()
{
}

void CExplosion::Boom()
{
	m_fCooltime += DT;

	if (m_fCooltime > 0.7f)
	{
		m_pAnimator->Stop();
		m_fCooltime = 0;

		DELETEOBJECT(this);
	}
}

void CExplosion::BoomSound()
{
	m_fCooltime += DT;

	Logger::Debug(L"Æø¹ß»ç¿îµå!");
	SOUND->Play(m_pExplosion, 0.5f, false);

	if (m_fCooltime > 1.0f)
	{
		SOUND->Pause(m_pExplosion);
	}
}

void CExplosion::Init()
{
	m_pExplosionImage = RESOURCE->LoadImg(L"Bomb_Explosion", L"Image\\Effect\\Effect_BOOM.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Explosion", m_pExplosionImage, Vector(0.f, 0.f), Vector(100.f, 100.f), Vector(100.f, 0.f), 0.1f, 12, false);

	m_pAnimator->Play(L"Explosion");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(90, 90), Vector(0, 0));

	BoomSound();
}

void CExplosion::Update()
{
	Boom();
}

void CExplosion::Render()
{
}

void CExplosion::Release()
{
}

void CExplosion::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetOwner()->GetLayer() == Layer::Monster)
	{
		CMonster* pMonster = (CMonster*)(pOtherCollider->GetOwner());
		pMonster->GetDamaged(m_fDamage);
	}

	if (pOtherCollider->GetOwner()->GetLayer() == Layer::Player)
	{
		CPlayer* pPlayer = (CPlayer*)(pOtherCollider->GetOwner());
		pPlayer->HurtState();
	}
}		
