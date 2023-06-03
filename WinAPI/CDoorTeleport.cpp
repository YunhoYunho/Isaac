#include "framework.h"
#include "CDoorTeleport.h"

CDoorTeleport::CDoorTeleport()
{
	m_layer = Layer::Teleport;
	m_strName = L"Teleport";
}

CDoorTeleport::~CDoorTeleport()
{
}

void CDoorTeleport::Init()
{
	AddCollider(ColliderType::Rect, Vector(240, 100), Vector(0, 0));
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
