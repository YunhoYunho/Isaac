#include "framework.h"
#include "CDoorCollider.h"

CDoorCollider::CDoorCollider()
{
	m_strName = L"DoorCollider";
}

CDoorCollider::~CDoorCollider()
{
}

void CDoorCollider::Remove()
{
	if (ROOM1CLEAR || ROOM2CLEAR || ROOM3CLEAR)
	{
		RemoveCollider();
	}
}

void CDoorCollider::Init()
{
	AddCollider(ColliderType::Rect, Vector(70, 70), Vector(0, 0));
}

void CDoorCollider::Update()
{
	Remove();
}

void CDoorCollider::Render()
{
}

void CDoorCollider::Release()
{
}

void CDoorCollider::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CDoorCollider::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CDoorCollider::OnCollisionExit(CCollider* pOtherCollider)
{
}
