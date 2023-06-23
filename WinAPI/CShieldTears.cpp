#include "framework.h"
#include "CShieldTears.h"

#include "CPlayer.h"

CShieldTears::CShieldTears()
{
	m_layer = Layer::PassiveItem;
	m_strName = L"ShieldTears";

	m_pShieldTearsImage = nullptr;

	m_fTimer = 0;
	m_bIsGetItem = false;
}

CShieldTears::~CShieldTears()
{
}

void CShieldTears::Activate(CPlayer* pPlayer)
{
	pPlayer->SetShieldTears(true);
	pPlayer->m_vecTripleMissiles.clear();
}

void CShieldTears::Init()
{
	m_pShieldTearsImage = RESOURCE->LoadImg(L"ShieldTears,", L"Image\\Item\\ShieldTears.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"ShieldTears", m_pShieldTearsImage, Vector(0.0f, 0.0f), Vector(80.0f, 80.0f), Vector(80.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"ShieldTears");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CShieldTears::Update()
{
	GetItem();
}

void CShieldTears::Render()
{
}

void CShieldTears::Release()
{
}

void CShieldTears::OnCollisionEnter(CCollider* pOtherCollider)
{
	CheckColl(pOtherCollider);
}

void CShieldTears::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CShieldTears::OnCollisionExit(CCollider* pOtherCollider)
{
}
