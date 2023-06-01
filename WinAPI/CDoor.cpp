#include "framework.h"
#include "CDoor.h"

CDoor::CDoor()
{
	m_layer = Layer::DoorFrame;
	m_strName = L"Door";
	m_bIsTouch = false;
}

CDoor::~CDoor()
{
}

void CDoor::Open()
{
	if (true == m_bIsTouch)
	{
		RemoveCollider();
	}
}

void CDoor::Init()
{
}

void CDoor::Update()
{
}

void CDoor::Render()
{
}

void CDoor::Release()
{
}

void CDoor::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CDoor::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CDoor::OnCollisionExit(CCollider* pOtherCollider)
{
}
