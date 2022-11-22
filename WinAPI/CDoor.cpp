#include "framework.h"
#include "CDoor.h"

CDoor::CDoor()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Door;
	m_strName = L"Door";

	m_pBrownDoorImage = nullptr;
	m_pBossDoorImage = nullptr;

	m_bIsClose = true;
	m_bIsOpen = false;
}

CDoor::~CDoor()
{
}

void CDoor::Init()
{
	m_pBrownDoorImage = RESOURCE->LoadImg(L"BrownDoor", L"Image\\BrownDoor.png");
	m_pBossDoorImage = RESOURCE->LoadImg(L"BossDoor", L"Image\\BossDoor.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"BrownDoorCloseUp",	 m_pBrownDoorImage, Vector(  0.f,   0.f), Vector(140.f, 100.f), Vector(140.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"BrownDoorCloseDown",  m_pBrownDoorImage, Vector(  0.f, 140.f), Vector(140.f, 100.f), Vector(140.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"BrownDoorCloseLeft",  m_pBrownDoorImage, Vector(  0.f, 200.f), Vector(100.f, 140.f), Vector(100.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"BrownDoorCloseRight", m_pBrownDoorImage, Vector(100.f, 200.f), Vector(100.f, 140.f), Vector(100.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"BrownDoorOpenUp",	 m_pBrownDoorImage, Vector(140.f,   0.f), Vector(140.f, 100.f), Vector(140.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"BrownDoorOpenDown",   m_pBrownDoorImage, Vector(140.f, 100.f), Vector(140.f, 100.f), Vector(140.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"BrownDoorOpenLeft",	 m_pBrownDoorImage, Vector(  0.f, 340.f), Vector(100.f, 140.f), Vector(100.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"BrownDoorOpenRight",  m_pBrownDoorImage, Vector(100.f, 340.f), Vector(100.f, 140.f), Vector(100.f, 0.f), 0, 1);

	m_pAnimator->CreateAnimation(L"BossDoorCloseLeft",   m_pBossDoorImage, Vector(0.f, 200.f), Vector(210.f, 140.f), Vector(210.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"BossDoorCloseRight",  m_pBossDoorImage, Vector(0.f, 140.f), Vector(140.f, 140.f), Vector(140.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"BossDoorOpenLeft",    m_pBossDoorImage, Vector(0.f, 340.f), Vector(210.f, 140.f), Vector(210.f, 0.f), 0, 1);

	AddComponent(m_pAnimator);

	m_doorState = DoorState::Open;

	AddCollider(ColliderType::Rect, Vector(57, 66), Vector(0, 8));
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

void CDoor::AnimatorUpdate()
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
