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
	m_pBoomflyDeadImage = nullptr;

	m_fSpeed = 100.0f;
	m_HP = 7;
	
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
	m_pBoomflyImage = RESOURCE->LoadImg(L"Boomfly", L"Image\\Unit\\Mon_Boomfly.png");
	m_pBoomflyDeadImage = RESOURCE->LoadImg(L"BoomflyDead", L"Image\\Effect\\Effect_BOOM.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"Move", m_pBoomflyImage, Vector(0.f, 0.f), Vector(75.f, 75.f), Vector(75.f, 0.f), 0.1f, 2);

	m_pAnimator->CreateAnimation(L"Dead", m_pBoomflyDeadImage, Vector(0.f, 0.f), Vector(100.f, 100.f), Vector(100.f, 0.f), 0.1f, 12, false);

	m_pAnimator->Play(L"Move");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(60, 60), Vector(0, 0));
}

void CBoomfly::Update()
{
	if (m_HP <= 0)
	{
		stateBoomfly = L"Dead";
		Dead();
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

void CBoomfly::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (m_HP <= 0)
	{
		SOUND->Play(pExplosion, 0.8f, false);
	}
}

void CBoomfly::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CBoomfly::OnCollisionExit(CCollider* pOtherCollider)
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
