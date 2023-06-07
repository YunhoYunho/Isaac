#include "framework.h"
#include "CGish.h"
#include "CMonsterMissile.h"

 CGish::CGish()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"Gish";

	m_gishState = MonsterState::Move;

	m_pGishLeftImage = nullptr;
	m_pGishRightImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);

	m_fRange = 200.0f;
	m_fSpeed = 50.0f;
	m_HP = 40;
	m_MaxHP = m_HP;
	m_fTimer = 0;
}

CGish::~CGish()
{
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

		if (targetDist > m_fRange * m_fRange)
		{
			m_gishState = MonsterState::Move;
		}

		else
		{
			m_gishState = MonsterState::Shot;
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
	case MonsterState::Dead:
		DeadUpdate();
		break;
	}
}

void CGish::ReadyUpdate()
{
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
	//Logger::Debug(L"Gish 추격중!");
	Trace();
	MoveState();
}

void CGish::ShotUpdate()
{
	//Logger::Debug(L"Gish 공격중!");
	CreateMissile();
	ShotState();
}

void CGish::JumpUpdate()
{
	//Logger::Debug(L"Gish 점프중!");

}

void CGish::DeadUpdate()
{
	BossDead();
	DeadState();
}

void CGish::MoveState()
{
	//Logger::Debug(to_wstring(GetLookDir().x));

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

void CGish::CheckDir()
{
	targetDir = PLAYERPOS.x - m_vecPos.x > 0 ? true : false;
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

	m_pAnimator->CreateAnimation(L"IdleLeft",		 m_pGishLeftImage,	Vector(  0.f,   0.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0.2f, 1);
	m_pAnimator->CreateAnimation(L"IdleRight",		 m_pGishRightImage, Vector(  0.f,   0.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0.2f, 1);
	m_pAnimator->CreateAnimation(L"MoveLeft",		 m_pGishLeftImage,	Vector(  0.f, 196.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0.2f, 5);
	m_pAnimator->CreateAnimation(L"MoveRight",		 m_pGishRightImage, Vector(  0.f, 196.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0.2f, 5);
	m_pAnimator->CreateAnimation(L"ShotLeft",		 m_pGishLeftImage,  Vector(  0.f,   0.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0.2f, 5, true);
	m_pAnimator->CreateAnimation(L"ShotRight",		 m_pGishRightImage, Vector(  0.f,   0.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0.2f, 5, true);
	m_pAnimator->CreateAnimation(L"Dead",			 m_pGishLeftImage,	Vector(560.f, 196.f), Vector(140.f, 196.f), Vector(140.f, 0.f), 0, 1, false);

	m_pAnimator->Play(L"MoveLeft");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 40));
}

void CGish::Update()
{
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
