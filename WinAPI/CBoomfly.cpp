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

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);

	m_bIsMove = false;
	m_bIsShot = false;
	m_bIsDead = false;

	m_fSpeed = 100.0f;
	m_iHP = 7;
	
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

	m_BoomflyState = BoomflyState::Move;

	AddCollider(ColliderType::Rect, Vector(60, 60), Vector(0, 0));
}

void CBoomfly::Update()
{
	if (m_iHP < 1)
	{
		stateBoomfly = L"Dead";
		RemoveCollider();
	}

	else
	{
		switch (m_BoomflyState)
		{
		case BoomflyState::Move:
			stateBoomfly = L"Move";

			if (m_vecPos.x >= WINSIZEX)
			{
				left = true;
				right = false;
			}

			if (m_vecPos.x <= 0)
			{
				left = false;
				right = true;
			}

			if (m_vecPos.y >= WINSIZEY - 100)
			{
				up = true;
				down = false;
			}

			if (m_vecPos.y <= 0)
			{
				up = false;
				down = true;
			}

			if (up) m_vecPos.y -= m_fSpeed * DT;
			if (down) m_vecPos.y += m_fSpeed * DT;
			if (left) m_vecPos.x -= m_fSpeed * DT;
			if (right) m_vecPos.x += m_fSpeed * DT;

		case BoomflyState::Dead:
			if (m_iHP < 1)
			{
				stateBoomfly = L"Dead";

				if (m_fTimer = 0)
				{
					DELETEOBJECT(this);
				}

				m_fTimer += DT;

				if (m_fTimer > 1.0f)
				{
					m_fTimer = 0;
				}
			}
			else
			{
				m_BoomflyState = BoomflyState::Move;
			}
			break;
		}
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
	if (pOtherCollider->GetObjName() == L"PlayerMissile")
	{
		m_iHP--;
	}

	if (m_iHP < 1)
	{
		m_BoomflyState = BoomflyState::Dead;
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
