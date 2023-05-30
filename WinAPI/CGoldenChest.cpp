#include "framework.h"
#include "CGoldenChest.h"

CGoldenChest::CGoldenChest()
{
	m_layer = Layer::Chest;
	m_strName = L"GoldenChest";
	m_bIsOpen = false;
}

CGoldenChest::~CGoldenChest()
{
}

void CGoldenChest::Init()
{
	m_pGoldenChestImage = RESOURCE->LoadImg(L"NormalChest", L"Image\\Item\\Golden_Box.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"Close", m_pGoldenChestImage, Vector(0.0f, 0.0f), Vector(62.0f, 56.0f), Vector(62.0f, 0.0f), 0, 1, false);

	m_pAnimator->CreateAnimation(L"Open", m_pGoldenChestImage, Vector(62.0f, 0.0f), Vector(62.0f, 56.0f), Vector(62.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"Close");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CGoldenChest::Update()
{
	Open();
}

void CGoldenChest::Render()
{
}

void CGoldenChest::Release()
{
}

void CGoldenChest::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Player")
	{

	}
}

void CGoldenChest::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CGoldenChest::OnCollisionExit(CCollider* pOtherCollider)
{
}
