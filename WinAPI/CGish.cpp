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
	m_vecLookDir = Vector(0, -1);

	m_bIsMove = false;
	m_bIsJump = false;
	m_bIsShot = false;
	m_bIsDead = false;

	m_fSpeed = 100.0f;
	m_HP = 3;
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
																																		  
	m_pAnimator->CreateAnimation(L"ShotLeft",		 m_pGishLeftImage,  Vector(  0.f,   0.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0.2f, 5, false);
	m_pAnimator->CreateAnimation(L"ShotRight",		 m_pGishRightImage, Vector(  0.f,   0.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0.2f, 5, false);

	m_pAnimator->CreateAnimation(L"Dead",			 m_pGishLeftImage,	Vector(560.f, 196.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0, 1, false);

	m_pAnimator->Play(L"MoveLeft");

	AddComponent(m_pAnimator);

	m_GishState = GishState::Move;

	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 40));
}

void CGish::Update()
{
	switch (m_GishState)
	{
		m_vecPlayerPosition = PLAYERPOS;
	case GishState::Move:
	{
		m_bIsMove = false;

		if (PLAYERPOS.x < m_vecPos.x)
		{
			stateGish = L"MoveLeft";
			m_vecLookDir.x = -1;
			m_vecPos.x -= m_fSpeed * DT;
		}
		else if (PLAYERPOS.x > m_vecPos.x)
		{
			stateGish = L"MoveRight";
			m_vecLookDir.x = +1;
			m_vecPos.x += m_fSpeed * DT;
		}
		else
		{
			m_vecPos.x = 0;
		}

		if (PLAYERPOS.y < m_vecPos.y)
		{
			stateGish = L"MoveRight";
			m_vecLookDir.y = -1;
			m_vecPos.y -= m_fSpeed * DT;
		}
		else if (PLAYERPOS.y > m_vecPos.y)
		{
			stateGish = L"MoveLeft";
			m_vecLookDir.y = +1;
			m_vecPos.y += m_fSpeed * DT;
		}
		else
		{
			m_vecPos.y = 0;
		}
	}
		break;

	case GishState::Jump:
	{
		// TODO: 플레이어 위치로 순간이동 구현
	}
	case GishState::Shot:
	{
		m_bIsShot = false;

		m_fShotTimer += DT;

		if (m_fShotTimer >= m_fShotSpeed - 0.5f)
		{
			m_bIsShot = true;
			if (PLAYERPOS.x < m_vecPos.x)
			{
				stateGish = L"ShotLeft";
			}
			else
			{
				stateGish = L"ShotRight";
			}
		}

		if (m_fShotTimer >= m_fShotSpeed)
		{
			m_fShotTimer = 0.0f;
			CreateMissile();

			if (false == m_bIsShot)
			{
				if (stateGish == L"ShotLeft")
				{
					m_stateGish = GishState::Move;
				}
				else
				{
					m_stateGish = GishState::Move;
				}
			}
		}
		break;

	case GishState::Dead:
	{
		if (true == m_bIsDead || BUTTONDOWN('P'))
		{
			stateGish = L"Dead";
		}
	}
	}
	AnimatorUpdate();
	}
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
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		Logger::Debug(L"몬스터가 플레이어와 충돌진입");
	}
	else if (pOtherCollider->GetObjName() == L"미사일")
	{
		Logger::Debug(L"몬스터가 미사일과 충돌진입");
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
