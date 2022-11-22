#include "framework.h"
#include "CFly.h"

CFly::CFly()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"Fly";

	m_pFlyImage = nullptr;

	m_bIsMove = false;
	m_bIsShot = false;
	m_bIsDead = false;

	m_fSpeed = 30.0f;
	m_iHP = 10;
}

CFly::~CFly()
{
}

void CFly::Init()
{
	m_pFlyImage = RESOURCE->LoadImg(L"Fly", L"Image\\Unit\\Mon_Fly.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"Move", m_pFlyImage, Vector(0.f, 100.f), Vector(80.f, 80.f), Vector(80.f, 0.f), 0.1f, 2);

	m_pAnimator->CreateAnimation(L"Dead", m_pFlyImage, Vector(0.f, 0.f), Vector(110.f, 100.f), Vector(100.f, 0.f), 0.1f, 12, false);

	m_pAnimator->Play(L"Move");

	AddComponent(m_pAnimator);

	m_FlyState = FlyState::Move;

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CFly::Update()
{
	if (m_iHP < 1)
	{
		stateFly = L"Dead";
		RemoveCollider();
	}
	else
	{
		switch (m_FlyState)
		{
			m_vecPlayerPosition = PLAYERPOS;

		case FlyState::Move:
			stateFly = L"Move";

			if (PLAYERPOS.x < m_vecPos.x)
			{
				left = true;
				right = false;
			}

			if (PLAYERPOS.x > m_vecPos.x)
			{
				left = false;
				right = true;
			}

			if (PLAYERPOS.y < m_vecPos.y)
			{
				up = true;
				down = false;
			}
			if (PLAYERPOS.y > m_vecPos.y)
			{
				up = false;
				down = true;
			}

			if (up) m_vecPos.y -= m_fSpeed * DT;
			if (down) m_vecPos.y += m_fSpeed * DT;
			if (left) m_vecPos.x -= m_fSpeed * DT;
			if (right) m_vecPos.x += m_fSpeed * DT;

		case FlyState::Dead:

			if (m_iHP < 1)
			{
				stateFly = L"Dead";
			}
			else
			{
				m_FlyState = FlyState::Move;
			}
			break;
		}
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
	if (pOtherCollider->GetObjName() == L"PlayerMissile")
	{
		m_iHP--;
	}

	if (m_iHP < 1)
	{
		m_FlyState = FlyState::Dead;
	}
}

void CFly::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CFly::OnCollisionExit(CCollider* pOtherCollider)
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
