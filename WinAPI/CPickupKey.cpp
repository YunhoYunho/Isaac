#include "framework.h"
#include "CPickupKey.h"

#include "CPlayer.h"

CPickupKey::CPickupKey()
{
	m_layer = Layer::PickupItem;
	m_strName = L"Key";

	m_pKeyImage = nullptr;

	m_fTimer = 0;
	m_bIsContact = false;
}

CPickupKey::~CPickupKey()
{
}

void CPickupKey::Activate(CPlayer* pPlayer)
{
	pPlayer->SetKey(1);
}

void CPickupKey::Init()
{
	m_pKeyImage = RESOURCE->LoadImg(L"PickupKey", L"Image\\Item\\Item_Key.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"PKey", m_pKeyImage, Vector(0.0f, 0.0f), Vector(50.0f, 50.0f), Vector(50.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"PKey");

	AddComponent(m_pAnimator);
	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CPickupKey::Update()
{
	Contact();
}

void CPickupKey::Render()
{
}

void CPickupKey::Release()
{
}

void CPickupKey::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Player")
	{
		m_bIsContact = true;
	}
}

void CPickupKey::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CPickupKey::OnCollisionExit(CCollider* pOtherCollider)
{
}
