#include "framework.h"
#include "CBaby.h"

CBaby::CBaby()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"Baby";

	m_pBabyImage = nullptr;
	m_pBabyDeadImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);

	m_bIsMove = false;
	m_bIsShot = false;
	m_bIsDead = false;

	m_fSpeed = 100.0f;
	m_HP = 10;

	up = true;
	down = false;
	left = false;
	right = true;
}

CBaby::~CBaby()
{
}

void CBaby::Init()
{
	m_pBabyImage = RESOURCE->LoadImg(L"Baby", L"Image\\Unit\\Mon_baby.png");
	m_pBabyDeadImage = RESOURCE->LoadImg(L"BabyDead", L"Image\\Effect\\Effect_DEAD.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"Move", m_pBabyImage, Vector(0.f, 0.f), Vector(120.f, 60.f), Vector(120.f, 0.f), 0, 1);

	m_pAnimator->CreateAnimation(L"Shot", m_pBabyImage, Vector(0.f, 60.f), Vector(120.f, 60.f), Vector(120.f, 0.f), 0, 1, false);

	m_pAnimator->CreateAnimation(L"Dead", m_pBabyDeadImage, Vector(0.f, 0.f), Vector(75.f, 75.f), Vector(75.f, 0.f), 0.1f, 10, false);

	m_pAnimator->Play(L"Move");

	AddComponent(m_pAnimator);

	m_BabyState = BabyState::Move;

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CBaby::Update()
{
	switch (m_BabyState)
	{
	case BabyState::Move:
	{
		m_bIsMove = true;
		stateBaby = L"Move";
		
		m_vecPlayerPosition = PLAYERPOS;

		if (PLAYERPOS.x < m_vecPos.x)
		{
			m_vecLookDir.x = -1;
			m_vecPos.x -= m_fSpeed * DT;
		}
		else if (PLAYERPOS.x > m_vecPos.x)
		{
			m_vecLookDir.x = +1;
			m_vecPos.x += m_fSpeed * DT;
		}
		else
		{
			m_vecPos.x = 0;
		}

		if (PLAYERPOS.y < m_vecPos.y)
		{
			m_vecLookDir.y = -1;
			m_vecPos.y -= m_fSpeed * DT;
		}
		else if (PLAYERPOS.y > m_vecPos.y)
		{
			m_vecLookDir.y = +1;
			m_vecPos.y += m_fSpeed * DT;
		}
		else
		{
			m_vecPos.y = 0;
		}

		if (true == m_bIsShot)
		{
			m_stateBaby = BabyState::Shot;
		}

		if (true == m_bIsDead || BUTTONDOWN('P'))
		{
			m_stateBaby = BabyState::Dead;
		}
	}
	case BabyState::Shot:
	{
		stateBaby = L"Shot";
		/*CreateMissile();*/

		if (false == m_bIsShot)
		{
			m_stateBaby = BabyState::Move;
		}

		if (true == m_bIsDead || BUTTONDOWN('P'))
		{
			m_stateBaby = BabyState::Dead;
		}
	}
	case BabyState::Dead:
	{
		if (true == m_bIsDead || BUTTONDOWN('P'))
		{
			stateBaby = L"Dead";
			break;
		}

		else if (false == m_bIsDead)
		{
			m_stateBaby = BabyState::Move;
		}

		if (true == m_bIsShot)
		{
			m_stateBaby = BabyState::Shot;
		}
	}
		AnimatorUpdate();
	}
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
	if (pOtherCollider->GetObjName() == L"�÷��̾�")
	{
		Logger::Debug(L"���Ͱ� �÷��̾�� �浹����");
	}
	else if (pOtherCollider->GetObjName() == L"�̻���")
	{
		Logger::Debug(L"���Ͱ� �̻��ϰ� �浹����");
	}
}

void CBaby::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CBaby::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"�÷��̾�")
	{
		Logger::Debug(L"���Ͱ� �÷��̾�� �浹����");
	}
	else if (pOtherCollider->GetObjName() == L"�̻���")
	{
		Logger::Debug(L"���Ͱ� �̻��ϰ� �浹����");
	}
}
