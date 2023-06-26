#include "framework.h"
#include "CBoomfly.h"

#include "CExplosion.h"

CBoomfly::CBoomfly()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"Boomfly";

	m_pBoomflyImage = nullptr;

	m_fSpeed = 100.0f;
	m_HP = 7;
	m_fTimer = 0;
	m_bIsExplosion = false;
	m_bIsDead = false;
	
	up = true;
	down = false;
	left = false;
	right = true;
}

CBoomfly::~CBoomfly()
{
}

void CBoomfly::Init()
{
	DustEffect();

	m_pBoomflyImage = RESOURCE->LoadImg(L"Boomfly", L"Image\\Unit\\Mon_Boomfly.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"Move", m_pBoomflyImage, Vector(0.f, 0.f), Vector(75.f, 75.f), Vector(75.f, 0.f), 0.1f, 2);

	m_pAnimator->Play(L"Move");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(60, 60), Vector(0, 0));
}

void CBoomfly::Update()
{
	BoomTrigger();
	DeadCount();

	if (m_HP <= 0)
	{
		m_bIsExplosion = true;
		m_bIsDead = true;
	}

	else
	{
		stateBoomfly = L"Move";
		PingPong();
	}

	AnimatorUpdate();
}

void CBoomfly::Render()
{
}

void CBoomfly::Release()
{
}

void CBoomfly::AnimatorUpdate()
{
	m_pAnimator->Play(stateBoomfly, false);
}

void CBoomfly::BoomTrigger()
{
	if (true == m_bIsExplosion)
	{
		DELETEOBJECT(this);

		Boom();
	}
}

void CBoomfly::Boom()
{
	CExplosion* pExplosion = new CExplosion();
	pExplosion->SetPos(m_vecPos);
	ADDOBJECT(pExplosion);
}

void CBoomfly::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (m_HP <= 0)
	{
		m_bIsExplosion = true;
	}
}

void CBoomfly::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CBoomfly::OnCollisionExit(CCollider* pOtherCollider)
{
}
