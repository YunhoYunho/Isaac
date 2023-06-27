#include "framework.h"
#include "CGish.h"
#include "CMonsterMissile.h"

 CGish::CGish()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"Gish";
	m_gishState = MonsterState::Ready;

	m_pGishLeftImage = nullptr;
	m_pGishRightImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);

	m_fRange = 300.0f;
	m_fSpeed = 100.0f;
	m_HP = 40;
	m_MaxHP = m_HP;

	m_fTimer = 0;
	m_fSaveTimer = 0;
	m_fJumpTimer = 0;

	savePlayerPosX = 0;
	savePlayerPosY = 0;
	saveCount = 0;

	m_bIsShot = false;
	m_bIsTouchDown = false;
	m_bIsBoss = true;
}

CGish::~CGish()
{
}

void CGish::ChangeState(MonsterState state)
{
	m_gishState = state;
	m_fTimer = 0;
}

void CGish::ActionUpdate()
{
	if (m_HP <= 0)
	{
		m_gishState = MonsterState::Dead;
	}
	else
	{
		TargetDist();
		TargetPos();

		m_fTimer += DT;

		switch (m_gishState)
		{
		case MonsterState::Ready:
			if (m_fTimer >= 0.5f)
			{
				ChangeState(MonsterState::Move);
			}
			break;
		case MonsterState::Move:
			if (m_fTimer >= 3.0f)
			{
				(targetDist <= (m_fRange * m_fRange)) ?
					ChangeState(MonsterState::Shot) : ChangeState(MonsterState::Jump);
			}
			break;
		case MonsterState::Shot:
			if (true == m_bIsShot)
			{
				ChangeState(MonsterState::Ready);
			}
			break;
		case MonsterState::Jump:
			if (true == m_bIsTouchDown)
			{
				ChangeState(MonsterState::Shot);
			}
			break;
		}
	}
}

void CGish::ChangeUpdate()
{
	switch (m_gishState)
	{
	case MonsterState::Ready:
		ReadyUpdate();
		break;
	case MonsterState::Move:
		MoveUpdate();
		break;
	case MonsterState::Shot:
		ShotUpdate();
		break;
	case MonsterState::Jump:
		JumpUpdate();
		break;
	case MonsterState::Dead:
		DeadUpdate();
		break;
	}
}

void CGish::ReadyUpdate()
{
	m_bIsShot = false;
	m_bIsTouchDown = false;

	if (GetLookDir().x == -1)
	{
		state = L"IdleLeft";
	}
	else if (GetLookDir().x == +1)
	{
		state = L"IdleRight";
	}
}

void CGish::MoveUpdate()
{
	Trace();
	MoveState();
}

void CGish::ShotUpdate()
{
	CreateMissile();
	ShotState();
}

void CGish::JumpUpdate()
{
	Jumping();
}

void CGish::DeadUpdate()
{
	BossDead();
	DeadState();
}

void CGish::MoveState()
{
	state = targetDir ? L"MoveRight" : L"MoveLeft";
}

void CGish::ShotState()
{
	state = targetDir ? L"ShotRight" : L"ShotLeft";
}

void CGish::DeadState()
{
	state = L"Dead";
}

void CGish::Jumping()
{	
	m_fSaveTimer += DT;

	if (m_fSaveTimer >= 1.5f)
	{
		Up(false);
	}

	else
	{
		RemoveCollider();
		Up(true);
	}

	m_fJumpTimer += DT;

	if (m_fJumpTimer >= 1.5f && m_fJumpTimer < 1.7f)
	{
		SavePos();
	}

	if (m_fJumpTimer >= 1.7f && m_fJumpTimer < 2.0f)
	{
		m_vecPos.x = savePlayerPosX;
	}

	if (m_fJumpTimer >= 2.0f)
	{
		if (m_vecPos.y >= savePlayerPosY)
		{
			Down(false);
			state = L"JumpCrash";
			AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 40));

			m_bIsTouchDown = true;
			saveCount = 0;
			m_fJumpTimer = 0;
			m_fSaveTimer = 0;
		}

		else
		{
			Down(true);
		}
	}
}

void CGish::Up(bool up)
{
	if (true == up)
	m_vecPos.y -= 1000 * DT;
}

void CGish::Down(bool down)
{
	if (true == down)
	m_vecPos.y += 1000 * DT;
}

void CGish::CheckDir()
{
	targetDir = PLAYERPOS.x - m_vecPos.x > 0 ? true : false;
}

void CGish::SavePos()
{
	if (saveCount == 0)
	{
		savePlayerPosX = PLAYERPOS.x;
		savePlayerPosY = PLAYERPOS.y;
		saveCount++;
	}
}

float CGish::GetHP()
{
	return m_HP;
}

float CGish::GetMaxHP()
{
	return m_MaxHP;
}

void CGish::Init()
{
	DustEffect();

	m_pGishLeftImage = RESOURCE->LoadImg(L"GishLeft", L"Image\\Unit\\Gish_Left.png");
	m_pGishRightImage = RESOURCE->LoadImg(L"GishRight", L"Image\\Unit\\Gish_Right.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"IdleLeft",		 m_pGishLeftImage,	Vector(    0.f,   0.f), Vector(140.f, 196.f), Vector( 140.f, 0.f), 0.2f, 1);
	m_pAnimator->CreateAnimation(L"IdleRight",		 m_pGishRightImage, Vector(    0.f,   0.f), Vector(140.f, 196.f), Vector( 140.f, 0.f), 0.2f, 1);
	m_pAnimator->CreateAnimation(L"MoveLeft",		 m_pGishLeftImage,	Vector(    0.f, 196.f), Vector(140.f, 196.f), Vector( 140.f, 0.f), 0.2f, 5);
	m_pAnimator->CreateAnimation(L"MoveRight",		 m_pGishRightImage, Vector(  560.f, 196.f), Vector(140.f, 196.f), Vector(-140.f, 0.f), 0.2f, 5);
	m_pAnimator->CreateAnimation(L"ShotLeft",		 m_pGishLeftImage,  Vector(    0.f,   0.f), Vector(140.f, 196.f), Vector( 140.f, 0.f), 0.2f, 5, true);
	m_pAnimator->CreateAnimation(L"ShotRight",		 m_pGishRightImage, Vector(  560.f,   0.f), Vector(140.f, 196.f), Vector(-140.f, 0.f), 0.2f, 5, true);
	m_pAnimator->CreateAnimation(L"JumpUp",			 m_pGishLeftImage,	Vector(	   0.f, 196.f), Vector(140.f, 196.f), Vector( 140.f, 0.f), 0.2f, 2, false);
	m_pAnimator->CreateAnimation(L"JumpDown",		 m_pGishLeftImage,	Vector(	 140.f, 196.f), Vector(140.f, 196.f), Vector( 140.f, 0.f), 0   , 1, false);
	m_pAnimator->CreateAnimation(L"JumpCrash",		 m_pGishLeftImage,	Vector(	   0.f, 196.f), Vector(140.f, 196.f), Vector( 140.f, 0.f), 0   , 1, false);
	m_pAnimator->CreateAnimation(L"Dead",			 m_pGishLeftImage,	Vector(  560.f, 196.f), Vector(140.f, 196.f), Vector( 140.f, 0.f), 0,	 1, false);

	m_pAnimator->Play(L"MoveLeft");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 40));
}

void CGish::Update()
{
	DeadCount();
	CheckDir();
	ActionUpdate();
	ChangeUpdate();

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
	m_pAnimator->Play(state, false);
}

void CGish::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CGish::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CGish::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Player")
	{
		Logger::Debug(L"몬스터가 Player와 충돌해제");
	}
	else if (pOtherCollider->GetObjName() == L"미사일")
	{
		Logger::Debug(L"몬스터가 미사일과 충돌해제");
	}
}
