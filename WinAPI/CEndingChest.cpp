#include "framework.h"
#include "CEndingChest.h"

CEndingChest::CEndingChest()
{
	m_layer = Layer::EndingChest;
	m_strName = L"EndingChest";
	m_pEndingChestImage = nullptr;
	m_bIsTouch = false;
}

CEndingChest::~CEndingChest()
{
}

void CEndingChest::Init()
{
	m_pEndingChestImage = RESOURCE->LoadImg(L"EndingChest", L"Image\\Item\\EndingChest.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"EChest", m_pEndingChestImage, Vector(0.0f, 0.0f), Vector(192.0f, 154.0f), Vector(192.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"EChest");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CEndingChest::Update()
{
}

void CEndingChest::Render()
{
}

void CEndingChest::Release()
{
}

void CEndingChest::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Player")
	{
		SetTouch(true);
	}
}

void CEndingChest::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CEndingChest::OnCollisionExit(CCollider* pOtherCollider)
{
}
