#include "framework.h"
#include "CPickupHeart.h"

#include "CPlayer.h"

CPickupHeart::CPickupHeart()
{
	m_layer = Layer::PickupItem;
	m_strName = L"Heart";
	m_pHeartImage = nullptr;
	m_bIsContact = false;
	m_fTimer = 0;
}

CPickupHeart::~CPickupHeart()
{
}

void CPickupHeart::Activate(CPlayer* pPlayer)
{
	if (PLAYERHP >= PLAYERMAXHP)
	{
		return;
	}

	else
	{
		pPlayer->SetHP(1);
	}
}

void CPickupHeart::Init()
{
	m_pHeartImage = RESOURCE->LoadImg(L"PickupHeart", L"Image\\Item\\Item_Heart.png");
	
	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"PHeart", m_pHeartImage, Vector(0.0f, 0.0f), Vector(50.0f, 50.0f), Vector(50.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"PHeart");

	AddComponent(m_pAnimator);
	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CPickupHeart::Update()
{
	Contact();
}

void CPickupHeart::Render()
{
}

void CPickupHeart::Release()
{
}

void CPickupHeart::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Player")
	{
		if (PLAYERHP >= PLAYERMAXHP)
		{
			return;
		}

		else
		{
			m_bIsContact = true;
		}
	}
}

void CPickupHeart::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CPickupHeart::OnCollisionExit(CCollider* pOtherCollider)
{
}
