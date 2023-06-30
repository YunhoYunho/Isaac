#include "framework.h"
#include "CChest.h"
#include "CBomb.h"
#include "CPickupHeart.h"
#include "CPickupBomb.h"
#include "CPickupKey.h"

CChest::CChest()
{
	m_layer = Layer::Chest;
	m_strName = L"Chest";
	m_fTimer = 0;
	m_bIsOpen = false;
	m_bIsGolden = false;
}

CChest::~CChest()
{
}

void CChest::Open()
{
	if (true == m_bIsOpen)
	{
		m_pAnimator->Play(L"Open");

		OpenSound();
		RandomItem();
		RemoveCollider();

		m_bIsOpen = false;
	}
}

void CChest::OpenSound()
{
	SOUND->Play(pOpenSound, 1);

	m_fTimer += DT;

	if (m_fTimer > 1.0f)
	{
		SOUND->Pause(pOpenSound);
		m_fTimer = 0;
	}
}

void CChest::RandomItem()
{
	srand((unsigned int)time(NULL));
	int num;

	for (int i = 0; i < 3; i++)
	{
		num = rand() % 3;
	}

	ChoiceItem(num);
}

void CChest::ChoiceItem(int num)
{
	CPickupHeart* pPickupHeart = new CPickupHeart();
	CPickupBomb* pPickupBomb = new CPickupBomb();
	CPickupKey* pPickupKey = new CPickupKey();
	CBomb* pBomb = new CBomb();

	if (true == m_bIsGolden)
	{
		switch (num)
		{
		case 0:
			pPickupHeart->SetPos(m_vecPos);
			ADDOBJECT(pPickupHeart);
			break;

		case 1:
			pPickupBomb->SetPos(m_vecPos);
			ADDOBJECT(pPickupBomb);
			break;

		case 2:
			pPickupKey->SetPos(m_vecPos);
			ADDOBJECT(pPickupKey);
			break;
		}
	}

	else
	{
		switch (num)
		{
		case 0:
			pPickupHeart->SetPos(m_vecPos);
			ADDOBJECT(pPickupHeart);
			break;

		case 1:
			pPickupBomb->SetPos(m_vecPos);
			ADDOBJECT(pPickupBomb);
			break;

		case 2:
			pBomb->SetPos(m_vecPos);
			pBomb->m_bIsPressE = true;
			ADDOBJECT(pBomb);
			break;
		}
	}
}

void CChest::Init()
{
}

void CChest::Update()
{
}

void CChest::Render()
{
}

void CChest::Release()
{
}

void CChest::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CChest::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CChest::OnCollisionExit(CCollider* pOtherCollider)
{
}
