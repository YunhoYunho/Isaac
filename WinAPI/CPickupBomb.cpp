#include "framework.h"
#include "CPickupBomb.h"

#include "CPlayer.h"

CPickupBomb::CPickupBomb()
{
	m_layer = Layer::PickupItem;
	m_strName = L"PickupBomb";
	m_pPickBombImage = nullptr;

	m_fTimer = 0;
	m_bIsContact = false;
}

CPickupBomb::~CPickupBomb()
{
}

void CPickupBomb::Activate(CPlayer* pPlayer)
{
	pPlayer->SetBomb(1);
}

void CPickupBomb::Init()
{
	m_pPickBombImage = RESOURCE->LoadImg(L"PickBomb", L"Image\\Item\\Item_Bomb.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"PBomb", m_pPickBombImage, Vector(0.0f, 0.0f), Vector(50.0f, 50.0f), Vector(50.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"PBomb");

	AddComponent(m_pAnimator);
	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CPickupBomb::Update()
{
	Contact();
}

void CPickupBomb::Render()
{
} 

void CPickupBomb::Release()
{
}

void CPickupBomb::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Player")
	{
		m_bIsContact = true;
	}
}

void CPickupBomb::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CPickupBomb::OnCollisionExit(CCollider* pOtherCollider)
{
}
