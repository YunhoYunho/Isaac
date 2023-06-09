#include "framework.h"
#include "CDoorBossTeleport.h"

CDoorBossTeleport::CDoorBossTeleport()
{
	m_layer = Layer::Teleport;
	m_strName = L"Teleport";
}

CDoorBossTeleport::~CDoorBossTeleport()
{
}

void CDoorBossTeleport::CheckTouch()
{
	TOUCHTELEPORT = m_bIsTouch;
}

void CDoorBossTeleport::Init()
{
	AddColl();
}

void CDoorBossTeleport::Update()
{
	CheckTouch();
}

void CDoorBossTeleport::Render()
{
}

void CDoorBossTeleport::Release()
{
}

void CDoorBossTeleport::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Player")
	{
		m_bIsTouch = true;
	}
}

void CDoorBossTeleport::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CDoorBossTeleport::OnCollisionExit(CCollider* pOtherCollider)
{
}
