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
