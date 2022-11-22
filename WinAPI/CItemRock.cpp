#include "framework.h"
#include "CItemRock.h"

CItemRock::CItemRock()
{
	m_layer = Layer::ItemRock;
	m_strName = L"ItemRock";

	m_pItemRockImage = nullptr;
}

CItemRock::~CItemRock()
{
}

void CItemRock::Init()
{
	m_pItemRockImage = RESOURCE->LoadImg(L"ItemRock,", L"Image\\Item\\ItemRock.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"ItemRock", m_pItemRockImage, Vector(0.f, 0.f), Vector(85.f, 85.f), Vector(85.f, 0.f), 0, 1);

	m_pAnimator->Play(L"ItemRock");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CItemRock::Update()
{
}

void CItemRock::Render()
{
}

void CItemRock::Release()
{
}
