#include "framework.h"
#include "CDoorTeleport.h"

CDoorTeleport::CDoorTeleport()
{
	m_layer = Layer::Teleport;
	m_strName = L"";
}

CDoorTeleport::~CDoorTeleport()
{
}

void CDoorTeleport::AddColl()
{
	AddCollider(ColliderType::Rect, Vector(240, 220), Vector(-10, -10));
}

void CDoorTeleport::Init()
{
	AddColl();
	GetName();
}

void CDoorTeleport::Update()
{
}

void CDoorTeleport::Render()
{
}

void CDoorTeleport::Release()
{
}

void CDoorTeleport::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CDoorTeleport::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CDoorTeleport::OnCollisionExit(CCollider* pOtherCollider)
{
}
