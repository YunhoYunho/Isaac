#include "framework.h"
#include "CPickupItem.h"

#include "CPlayer.h"

CPickupItem::CPickupItem()
{
	m_layer = Layer::PickupItem;
}

CPickupItem::~CPickupItem()
{
}

void CPickupItem::Contact()
{
	DELETEOBJECT(this);
}

void CPickupItem::Init()
{
}

void CPickupItem::Update()
{
}

void CPickupItem::Render()
{
}

void CPickupItem::Release()
{
}

void CPickupItem::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CPickupItem::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CPickupItem::OnCollisionExit(CCollider* pOtherCollider)
{
}
