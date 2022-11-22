#include "framework.h"
#include "CGish.h"

 CGish::CGish()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"Gish";

	m_pGishLeftImage = nullptr;
	m_pGishRightImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, 0);

	m_bIsMove = false;
	m_bIsJump = false;
	m_bIsShot = false;
	m_bIsDead = false;

	up = false;
	down = false;
	left = false;
	right = false;

	m_fSpeed = 50.0f;
	m_iHP = 30;
}

CGish::~CGish()
{
}

void CGish::Init()
{
	m_pGishLeftImage = RESOURCE->LoadImg(L"GishLeft", L"Image\\Unit\\Gish_Left.png");
	m_pGishRightImage = RESOURCE->LoadImg(L"GishRight", L"Image\\Unit\\Gish_Right.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"MoveLeft",		 m_pGishLeftImage,	Vector(  0.f, 196.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0.2f, 5);
																																		  
	m_pAnimator->CreateAnimation(L"MoveRight",		 m_pGishRightImage, Vector(  0.f, 196.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0.2f, 5);
																																		  
	m_pAnimator->CreateAnimation(L"ShotLeft",		 m_pGishLeftImage,  Vector(  0.f,   0.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0.2f, 5, true);
	m_pAnimator->CreateAnimation(L"ShotRight",		 m_pGishRightImage, Vector(  0.f,   0.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0.2f, 5, true);

	m_pAnimator->CreateAnimation(L"Dead",			 m_pGishLeftImage,	Vector(560.f, 196.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0, 1, false);

	m_pAnimator->Play(L"MoveLeft");

	AddComponent(m_pAnimator);

	m_GishState = GishState::Move;

	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 40));
}

void CGish::Update()
{
	if (m_iHP < 1)
	{
		stateGish = L"Dead";
		RemoveCollider();
	}
	else
	{
		switch (m_GishState)
		{
			m_vecPlayerPosition = PLAYERPOS;

		case GishState::Move:
			if (PLAYERPOS.x < m_vecPos.x)
			{
				stateGish = L"MoveLeft";
				left = true;
				right = false;
			}
			if (PLAYERPOS.x > m_vecPos.x)
			{
				stateGish = L"MoveRight";
				left = false;
				right = true;
			}

			if (PLAYERPOS.y < m_vecPos.y)
			{
				stateGish = L"MoveRight";
				up = true;
				down = false;
			}
			if (PLAYERPOS.y > m_vecPos.y)
			{
				stateGish = L"MoveLeft";
				up = false;
				down = true;
			}

			if (up) m_vecPos.y -= m_fSpeed * DT;
			if (down) m_vecPos.y += m_fSpeed * DT;
			if (left) m_vecPos.x -= m_fSpeed * DT;
			if (right) m_vecPos.x += m_fSpeed * DT;

		case GishState::Jump:
			// TODO: 플레이어 위치로 순간이동 구현

		case GishState::Shot:
			if (PLAYERPOS.x < m_vecPos.x)
			{
				stateGish = L"ShotLeft";
			}
			if (PLAYERPOS.x > m_vecPos.x)
			{
				stateGish = L"ShotRight";
			}

			CreateMissile();

		case GishState::Dead:
			if (m_iHP < 1)
			{
				stateGish = L"Dead";

				m_fTimer = 3.0f;
				m_fTimer += DT;

				if (m_fTimer = 0)
				{
					m_fTimer = 0;
					break;
				}
			}
			else
			{
				m_stateGish = GishState::Move;
			}
			break;
		}
	}
	AnimatorUpdate();
}

void CGish::Render()
{
}

void CGish::Release()
{
}

void CGish::AnimatorUpdate()
{
	m_pAnimator->Play(stateGish, false);
}

void CGish::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"PlayerMissile")
	{
		m_iHP--;
	}

	if (m_iHP < 1)
	{
		m_GishState = GishState::Dead;
	}
}

void CGish::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CGish::OnCollisionExit(CCollider* pOtherCollider)
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
