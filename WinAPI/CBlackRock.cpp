#include "framework.h"
#include "CBlackRock.h"

CBlackRock::CBlackRock()
{
	m_layer = Layer::Rock;
	m_strName = L"BlackRock";
	m_pBlackRockImage = nullptr;
	m_pBlackFragmentsImage = nullptr;
	m_bIsBroken = false;
	m_bIsSpecial = false;
	m_fTimer = 0;
}

CBlackRock::~CBlackRock()
{
}

void CBlackRock::Init()
{
	m_pBlackRockImage = RESOURCE->LoadImg(L"BlackRockImage", L"Image\\Item\\Black_Rock.png");
	m_pBlackFragmentsImage = RESOURCE->LoadImg(L"BlackFragments", L"Image\\Item\\Black_Fragments.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"NotBlackBroken", m_pBlackRockImage, Vector(0.0f, 0.0f), Vector(57.0f, 60.0f), Vector(57.0f, 0.0f), 0, 1, false);
	m_pAnimator->CreateAnimation(L"BlackBroken", m_pBlackFragmentsImage, Vector(0.0f, 0.0f), Vector(64.0f, 64.0f), Vector(64.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"NotBroken");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(57, 61), Vector(0, 0));
}

void CBlackRock::Update()
{
	Broken();
}

void CBlackRock::Render()
{
}

void CBlackRock::Release()
{
}

void CBlackRock::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Explosion")
	{
		m_bIsBroken = true;
		m_bIsSpecial = true;
	}
}

void CBlackRock::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CBlackRock::OnCollisionExit(CCollider* pOtherCollider)
{
}
