#include "framework.h"
#include "CNormalChest.h"

CNormalChest::CNormalChest()
{
	m_layer = Layer::Chest;
	m_strName = L"NormalChest";
	m_pNormalChestImage = nullptr;
	m_bIsOpen = false;
}

CNormalChest::~CNormalChest()
{
}

void CNormalChest::Init()
{
	m_pNormalChestImage = RESOURCE->LoadImg(L"NormalChest", L"Image\\Item\\Normal_Box.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"Close", m_pNormalChestImage, Vector(0.0f, 0.0f), Vector(62.0f, 56.0f), Vector(62.0f, 0.0f), 0, 1, false);

	m_pAnimator->CreateAnimation(L"Open", m_pNormalChestImage, Vector(62.0f, 0.0f), Vector(62.0f, 56.0f), Vector(62.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"Close");

	AddComponent(m_pAnimator);
	
	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CNormalChest::Update()
{
	Open();
}

void CNormalChest::Render()
{
}

void CNormalChest::Release()
{
}


void CNormalChest::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Player")
	{
		m_bIsOpen = true;
	}
}

void CNormalChest::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CNormalChest::OnCollisionExit(CCollider* pOtherCollider)
{
}
