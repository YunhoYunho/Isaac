#include "framework.h"
#include "CChest.h"
#include "CPickupHeart.h"
#include "CBomb.h"

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
	CBomb* pBomb = new CBomb();

	if (true == m_bIsGolden)
	{
		switch (num)
		{
		case 0:
			Logger::Debug(L"榜电窍飘 积己");
			pPickupHeart->SetPos(m_vecPos);
			ADDOBJECT(pPickupHeart);
			break;

		case 1:
			Logger::Debug(L"榜电1锅气藕 积己");
			pBomb->SetPos(m_vecPos);
			pBomb->m_bIsPressE = true;
			ADDOBJECT(pBomb);
			break;

		case 2:
			Logger::Debug(L"榜电2锅气藕 积己");
			pBomb->SetPos(m_vecPos);
			pBomb->m_bIsPressE = true;
			ADDOBJECT(pBomb);
			break;
		}
	}

	else
	{
		switch (num)
		{
		case 0:
			Logger::Debug(L"窍飘 积己");
			pPickupHeart->SetPos(m_vecPos);
			ADDOBJECT(pPickupHeart);
			break;

		case 1:
			Logger::Debug(L"1锅气藕 积己");
			pBomb->SetPos(m_vecPos);
			pBomb->m_bIsPressE = true;
			ADDOBJECT(pBomb);
			break;

		case 2:
			Logger::Debug(L"2锅气藕 积己");
			pBomb->SetPos(m_vecPos);
			pBomb->m_bIsPressE = true;
			ADDOBJECT(pBomb);
			break;
		}
	}

	Logger::Debug(to_wstring(num));
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
