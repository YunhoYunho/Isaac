#include "framework.h"
#include "CPassiveItem.h"

#include "CPlayer.h"

CPassiveItem::CPassiveItem()
{
	m_layer = Layer::PassiveItem;
}

CPassiveItem::~CPassiveItem()
{
}

void CPassiveItem::GetItem()
{
	if (true == m_bIsGetItem)
	{
		m_vecPos = Vector(PLAYERPOS.x, PLAYERPOS.y - 30);

		m_fTimer += DT;

		if (m_fTimer > 0.7f)
		{
			DELETEOBJECT(this);
		}
	}
}

void CPassiveItem::CheckColl(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Player")
	{
		m_bIsGetItem = true;
	}
}

void CPassiveItem::Init()
{
}

void CPassiveItem::Update()
{
}

void CPassiveItem::Render()
{
}

void CPassiveItem::Release()
{
}

void CPassiveItem::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CPassiveItem::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CPassiveItem::OnCollisionExit(CCollider* pOtherCollider)
{
}
