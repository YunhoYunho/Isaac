#include "framework.h"
#include "CRock.h"
#include "CPickupHeart.h"
#include "CPickupBomb.h"
#include "CPickupKey.h"
#include "CGroundTile.h"

CRock::CRock()
{
	m_layer = Layer::Rock;
	m_strName = L"Rock";
	m_pRockImage = nullptr;
	m_pFragmentsImage = nullptr;
	m_bIsBroken = false;
	m_bIsSpecial = false;
	m_fTimer = 0;
	dir = CollisionDir::None;
	offset = 0.25f;
}

CRock::~CRock()
{
}

void CRock::Broken()
{
	if (true == m_bIsBroken)
	{
		m_pAnimator->Play(L"Broken");

		BrokenSound();
		RemoveCollider();
		
		if (true == m_bIsSpecial)
		{
			AppearItem();
		}

		m_bIsBroken = false;
	}
}

void CRock::BrokenSound()
{
	SOUND->Play(pBrokenSound, 1);

	m_fTimer += DT;

	if (m_fTimer > 1.0f)
	{
		SOUND->Pause(pBrokenSound);
		m_fTimer = 0;
	}
}

void CRock::AppearItem()
{
	int num = rand() % 3;
	
	SelectItem(num);
}

void CRock::SelectItem(int num)
{
	CPickupHeart* pPickupHeart = new CPickupHeart();
	CPickupBomb* pPickupBomb = new CPickupBomb();
	CPickupKey* pPickupKey = new CPickupKey();

	switch (num)
	{
	case 0:
		pItem = pPickupHeart;
		break;

	case 1:
		pItem = pPickupBomb;
		break;

	case 2:
		pItem = pPickupKey;
		break;
	}

	pItem->SetPos(m_vecPos);
	ADDOBJECT(pItem);
	int count = 0;
	count++;
	m_bIsSpecial = false;
}

void CRock::Init()
{
	m_pRockImage = RESOURCE->LoadImg(L"RockImage", L"Image\\Item\\Rock.png");
	m_pFragmentsImage = RESOURCE->LoadImg(L"Fragments", L"Image\\Item\\Fragments.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"NotBroken", m_pRockImage, Vector(0.0f, 0.0f), Vector(57.0f, 61.0f), Vector(57.0f, 0.0f), 0, 1, false);
	m_pAnimator->CreateAnimation(L"Broken", m_pFragmentsImage, Vector(0.0f, 0.0f), Vector(64.0f, 64.0f), Vector(64.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"NotBroken");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(57, 61), Vector(0, 0));
}

void CRock::Update()
{
	Broken();
}

void CRock::Render()
{
}

void CRock::Release()
{
}

void CRock::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Explosion")
	{
		m_bIsBroken = true;
	}
}

void CRock::OnCollisionStay(CCollider* pOtherCollider)
{

	if (pOtherCollider->GetObjName() == L"Player")
	{
		PushObject(pOtherCollider);
	}
}

void CRock::OnCollisionExit(CCollider* pOtherCollider)
{
}
