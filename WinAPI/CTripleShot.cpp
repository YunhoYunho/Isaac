#include "framework.h"
#include "CTripleShot.h"

#include "CPlayer.h"

CTripleShot::CTripleShot()
{
	m_layer = Layer::Item;
	m_strName = L"TripleShot";

	m_pTripleShotImage = nullptr;

	m_fTimer = 0;
	m_bIsGetItem = false;
}

CTripleShot::~CTripleShot()
{
}

void CTripleShot::Init()
{
	m_pTripleShotImage = RESOURCE->LoadImg(L"TripleShot,", L"Image\\Item\\TripleShot.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"TripleShot", m_pTripleShotImage, Vector(0.0f, 0.0f), Vector(80.0f, 90.0f), Vector(80.0f, 0.0f), 0.3f, 2);
	m_pAnimator->CreateAnimation(L"GetItem",	m_pTripleShotImage, Vector(0.0f, 0.0f), Vector(80.0f, 90.0f), Vector(80.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"TripleShot");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CTripleShot::Update()
{
	if (true == m_bIsGetItem)
	{
		m_pAnimator->Play(L"GetItem");
		
		m_vecPos = Vector(PLAYERPOS.x, PLAYERPOS.y - 30);

		m_fTimer += DT;

		if (m_fTimer > 0.7f)
		{
			DELETEOBJECT(this);
		}
	}
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
		m_bIsGetItem = true;
	}
}

void CTripleShot::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CTripleShot::OnCollisionExit(CCollider* pOtherCollider)
{
}
