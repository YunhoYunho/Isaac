#include "framework.h"
#include "CFly.h"

CFly::CFly()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"Monster";
	
	m_pFlyImage = nullptr;

	m_fSpeed = 100.0f;
	m_HP = 10;
}

CFly::~CFly()
{
}

void CFly::Init()
{
	DustEffect();

	m_pFlyImage = RESOURCE->LoadImg(L"Fly", L"Image\\Unit\\Mon_Fly.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"Move", m_pFlyImage, Vector(0.f, 100.f), Vector(80.f, 80.f), Vector(80.f, 0.f), 0.1f, 2);

	m_pAnimator->CreateAnimation(L"Dead", m_pFlyImage, Vector(0.f, 0.f), Vector(110.f, 100.f), Vector(100.f, 0.f), 0.1f, 12, false);

	m_pAnimator->Play(L"Move");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CFly::Update()
{
	TargetPos();

	if (m_HP <= 0)
	{
		stateFly = L"Dead";
		Dead();
	}
	else
	{
		stateFly = L"Move";
		Trace();
	}

	AnimatorUpdate();
}

void CFly::Render()
{
}

void CFly::Release()
{
}

void CFly::AnimatorUpdate()
{
	m_pAnimator->Play(stateFly, false);
}

void CFly::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CFly::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CFly::OnCollisionExit(CCollider* pOtherCollider)
{
}
