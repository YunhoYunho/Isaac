#include "framework.h"
#include "CSkeletonKey.h"

#include "CPlayer.h"

CSkeletonKey::CSkeletonKey()
{
	m_layer = Layer::PassiveItem;
	m_strName = L"SkeletonKey";

	m_pSkeletonKeyImage = nullptr;

	m_fTimer = 0;
	m_bIsGetItem = false;
}

CSkeletonKey::~CSkeletonKey()
{
}

void CSkeletonKey::Activate(CPlayer* pPlayer)
{
	pPlayer->SetKey(10);
}

void CSkeletonKey::Init()
{
	m_pSkeletonKeyImage = RESOURCE->LoadImg(L"SkeletonKey,", L"Image\\Item\\SkeletonKey.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"SkeletonKey", m_pSkeletonKeyImage, Vector(0.0f, 0.0f), Vector(80.0f, 80.0f), Vector(80.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"SkeletonKey");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CSkeletonKey::Update()
{
	GetItem();
}

void CSkeletonKey::Render()
{
}

void CSkeletonKey::Release()
{
}

void CSkeletonKey::OnCollisionEnter(CCollider* pOtherCollider)
{
	CheckColl(pOtherCollider);
}

void CSkeletonKey::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CSkeletonKey::OnCollisionExit(CCollider* pOtherCollider)
{
}
