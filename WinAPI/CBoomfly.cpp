#include "framework.h"
#include "CBoomfly.h"

CBoomfly::CBoomfly()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"Boomfly";

	m_pBoomflyImage = nullptr;
	m_pBoomflyDeadImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);

	m_bIsMove = false;
	m_bIsShot = false;
	m_bIsDead = false;
	m_bIsExplode = false;

	m_fSpeed = 10.0f;
	m_HP = 3;
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

	m_pAnimator->CreateAnimation(L"Dead", m_pBoomflyDeadImage, Vector(0.f, 0.f), Vector(100.f, 100.f), Vector(100.f, 0.f), 0.1f, 12);

	m_pAnimator->Play(L"Move");

	AddComponent(m_pAnimator);

	m_BoomflyState = BoomflyState::Move;

	AddCollider(ColliderType::Rect, Vector(60, 60), Vector(0, 0));
}

void CBoomfly::Update()
{
	switch (m_BoomflyState)
	{
	case BoomflyState::Move:
	{
		stateBoomfly = L"Move";
	}

	if (true == m_bIsDead || BUTTONDOWN('P'))
	{
		m_stateBoomfly = BoomflyState::Dead;
	}

	case BoomflyState::Dead:
	{
		if (true == m_bIsDead || BUTTONDOWN('P'))
		{
			stateBoomfly = L"Dead";
			break;
		}

		else if (false == m_bIsDead)
		{
			m_stateBoomfly = BoomflyState::Move;
		}
	}
	AnimatorUpdate();
	}
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
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		Logger::Debug(L"몬스터가 플레이어와 충돌진입");
	}
	else if (pOtherCollider->GetObjName() == L"미사일")
	{
		Logger::Debug(L"몬스터가 미사일과 충돌진입");
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
