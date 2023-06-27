#include "framework.h"
#include "CBaby.h"

CBaby::CBaby()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"Monster";

	m_pBabyImage = nullptr;
	m_pBabyDeadImage = nullptr;

	m_fRange = 300.0f;
	m_fSpeed = 70.0f;
	m_HP = 10;
	m_fTimer = 0;
}

CBaby::~CBaby()
{
}

void CBaby::Init()
{
	DustEffect();

	m_pBabyImage = RESOURCE->LoadImg(L"Baby", L"Image\\Unit\\Mon_baby.png");
	m_pBabyDeadImage = RESOURCE->LoadImg(L"BabyDead", L"Image\\Effect\\Effect_DEAD.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"Move", m_pBabyImage, Vector(0.f, 0.f), Vector(120.f, 60.f), Vector(120.f, 0.f), 0, 1);

	m_pAnimator->CreateAnimation(L"Shot", m_pBabyImage, Vector(0.f, 60.f), Vector(120.f, 60.f), Vector(120.f, 0.f), 0, 1, false);

	m_pAnimator->CreateAnimation(L"Dead", m_pBabyDeadImage, Vector(0.f, 0.f), Vector(75.f, 75.f), Vector(75.f, 0.f), 0.1f, 10, false);

	m_pAnimator->Play(L"Move");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CBaby::Update()
{
	if (m_HP <= 0)
	{
		stateBaby = L"Dead";
		Dead();
	}
	else
	{
		TargetDist();

		if (targetDist <= m_fRange * m_fRange)
		{
			stateBaby = L"Shot";
			CreateMissile();
		}

		else
		{
			stateBaby = L"Move";
			Trace();
		}
	}
	AnimatorUpdate();
}

void CBaby::Render()
{
}

void CBaby::Release()
{
}

void CBaby::AnimatorUpdate()
{
	m_pAnimator->Play(stateBaby, false);
}

void CBaby::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CBaby::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CBaby::OnCollisionExit(CCollider* pOtherCollider)
{
}
