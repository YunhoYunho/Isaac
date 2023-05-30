#include "framework.h"
#include "CNormalChest.h"

CNormalChest::CNormalChest()
{
	m_layer = Layer::Chest;
	m_strName = L"NormalChest";
	m_pNormalChestImage = nullptr;
	m_bIsOpen = false;
	m_fTimer = 0;
}

CNormalChest::~CNormalChest()
{
}

void CNormalChest::Open()
{
	if (true == m_bIsOpen)
	{
		m_pAnimator->Play(L"Open");

		OpenSound();

		m_bIsOpen = false;
	}
}

void CNormalChest::OpenSound()
{
	SOUND->Play(pOpenSound, 1);

	m_fTimer += DT;

	if (m_fTimer > 1.0f)
	{
		SOUND->Pause(pOpenSound);
		m_fTimer = 0;
	}
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
