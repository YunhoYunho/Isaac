#include "framework.h"
#include "CGish.h"

 CGish::CGish()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"Gish";

	m_curState = MonsterState::Idle;
	fStateTimer = 0;

	m_pGishLeftImage = nullptr;
	m_pGishRightImage = nullptr;

	m_fSpeed = 50.0f;
	m_HP = 30;
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

	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 40));
}

void CGish::Update()
{
	TargetDist();

	switch (m_curState)
	{
	case MonsterState::Idle:
			
	case MonsterState::Move:

	case MonsterState::Jump:

	case MonsterState::Shot:
			
	case MonsterState::Dead:
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
		m_HP--;
	}

	if (m_HP < 1)
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
