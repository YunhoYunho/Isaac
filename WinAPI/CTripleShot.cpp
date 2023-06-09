#include "framework.h"
#include "CTripleShot.h"

#include "CPlayer.h"

CTripleShot::CTripleShot()
{
	m_layer = Layer::PassiveItem;
	m_strName = L"TripleShot";

	m_pTripleShotImage = nullptr;

	m_fTimer = 0;
	m_iCount = 0;
	m_bIsGetItem = false;
}

CTripleShot::~CTripleShot()
{
}

void CTripleShot::Activate(CPlayer* pPlayer)
{
	pPlayer->SetTripleShot(true);
}

void CTripleShot::Init()
{
	m_pTripleShotImage = RESOURCE->LoadImg(L"TripleShot,", L"Image\\Item\\TripleShot.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"TripleShot", m_pTripleShotImage, Vector(0.0f, 0.0f), Vector(80.0f, 80.0f), Vector(80.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"TripleShot");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CTripleShot::Update()
{
	GetItem();
}

void CTripleShot::Render()
{
}

void CTripleShot::Release()
{
}

void CTripleShot::OnCollisionEnter(CCollider* pOtherCollider)
{
	CheckColl(pOtherCollider);
}

void CTripleShot::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CTripleShot::OnCollisionExit(CCollider* pOtherCollider)
{
}
