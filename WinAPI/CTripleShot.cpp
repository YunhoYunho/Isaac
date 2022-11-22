#include "framework.h"
#include "CTripleShot.h"

CTripleShot::CTripleShot()
{
	m_layer = Layer::Item;
	m_strName = L"TripleShot";

	m_pTripleShotImage = nullptr;
}

CTripleShot::~CTripleShot()
{
}

void CTripleShot::Init()
{
	m_pTripleShotImage = RESOURCE->LoadImg(L"TripleShot,", L"Image\\Item\\TripleShot.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"TripleShot", m_pTripleShotImage, Vector(0.f, 0.f), Vector(80.f, 90.f), Vector(80.f, 0.f), 0.5f, 2);

	m_pAnimator->Play(L"TripleShot");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CTripleShot::Update()
{
}

void CTripleShot::Render()
{
}

void CTripleShot::Release()
{
}

void CTripleShot::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"플레이어")
	{

	}
}

void CTripleShot::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CTripleShot::OnCollisionExit(CCollider* pOtherCollider)
{
}
