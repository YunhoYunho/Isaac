#include "framework.h"
#include "CPickupKey.h"

CPickupKey::CPickupKey()
{
	m_layer = Layer::Item;
	m_strName = L"Key";

	m_pKeyImage = nullptr;

	m_fTimer = 0;
	m_bIsContact = false;
}

CPickupKey::~CPickupKey()
{
}

void CPickupKey::Init()
{
	m_pKeyImage = RESOURCE->LoadImg(L"Key", L"Image\\Item\\Item_Key.png");
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
