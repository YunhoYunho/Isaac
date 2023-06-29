#include "framework.h"
#include "CTenBombs.h"

#include "CPlayer.h"

CTenBombs::CTenBombs()
{
	m_layer = Layer::PassiveItem;
	m_strName = L"TenBombs";

	m_pTenBombsImage = nullptr;

	m_fTimer = 0;
	m_bIsGetItem = false;
}

CTenBombs::~CTenBombs()
{
}

void CTenBombs::Activate(CPlayer* pPlayer)
{
	pPlayer->SetBomb(10);
}

void CTenBombs::Init()
{
	m_pTenBombsImage = RESOURCE->LoadImg(L"TenBombs,", L"Image\\Item\\TenBombs.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"TenBombs", m_pTenBombsImage, Vector(0.0f, 0.0f), Vector(80.0f, 80.0f), Vector(80.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"TenBombs");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CTenBombs::Update()
{
	GetItem();
}

void CTenBombs::Render()
{
}

void CTenBombs::Release()
{
}

void CTenBombs::OnCollisionEnter(CCollider* pOtherCollider)
{
	CheckColl(pOtherCollider);
}

void CTenBombs::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CTenBombs::OnCollisionExit(CCollider* pOtherCollider)
{
}
