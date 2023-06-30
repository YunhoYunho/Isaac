#include "framework.h"
#include "CMeat.h"

#include "CPlayer.h"

CMeat::CMeat()
{
	m_layer = Layer::PassiveItem;
	m_strName = L"Meat";

	m_pMeatImage = nullptr;

	m_fTimer = 0;
	m_bIsGetItem = false;
}

CMeat::~CMeat()
{
}

void CMeat::Activate(CPlayer* pPlayer)
{
	pPlayer->SetDamage(2);
}

void CMeat::Init()
{
	m_pMeatImage = RESOURCE->LoadImg(L"Meat,", L"Image\\Item\\Meat.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Meat", m_pMeatImage, Vector(0.0f, 0.0f), Vector(80.0f, 80.0f), Vector(80.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"Meat");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CMeat::Update()
{
	GetItem();
}

void CMeat::Render()
{
}

void CMeat::Release()
{
}

void CMeat::OnCollisionEnter(CCollider* pOtherCollider)
{
	CheckColl(pOtherCollider);
}

void CMeat::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CMeat::OnCollisionExit(CCollider* pOtherCollider)
{
}
