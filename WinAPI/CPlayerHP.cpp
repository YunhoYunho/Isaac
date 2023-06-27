#include "framework.h"
#include "CPlayerHP.h"

#include "CPlayer.h"

CPlayerHP::CPlayerHP()
{
	m_layer = Layer::PlayerHP;
	m_strName = L"PlayerHP";

	pPlayer = nullptr;
	m_pPlayerHPFrame = nullptr;
	m_pPlayerHPGauge = nullptr;
}

CPlayerHP::~CPlayerHP()
{
}

void CPlayerHP::GetHP(CPlayer* value)
{
	pPlayer = value;
}

void CPlayerHP::Init()
{
	m_pPlayerHPFrame = RESOURCE->LoadImg(L"Empty_Heart", L"Image\\Map\\Empty_Heart.png");
	m_pPlayerHPGauge = RESOURCE->LoadImg(L"Full_Heart", L"Image\\Map\\Full_Heart.png");
}

void CPlayerHP::Update()
{
}

void CPlayerHP::Render()
{
	RENDER->Image(m_pPlayerHPFrame, 130, 780, 310, 810);
	RENDER->Image(m_pPlayerHPFrame, 130, 60, 310, 90);
	RENDER->Image(m_pPlayerHPFrame, 1410, 60, 1590, 90);
	RENDER->Image(m_pPlayerHPFrame, 2690, 60, 2870, 90);
	RENDER->Image(m_pPlayerHPFrame, 1410, 780, 1590, 810);

	float hpWidth = (310 - 130) * PLAYERHP / PLAYERMAXHP;

	if (m_playerHP >= 0)
	{
		if (INROOM0)
		{
			RENDER->FrameImage(m_pPlayerHPGauge, 130, 780, 130 + hpWidth, 810, 0, 0, hpWidth, 30);
		}

		if (INROOM1)
		{
			RENDER->FrameImage(m_pPlayerHPGauge, 130, 60, 130 + hpWidth, 90, 0, 0, hpWidth, 30);
		}

		if (INROOM2)
		{
			RENDER->FrameImage(m_pPlayerHPGauge, 1410, 60, 1410 + hpWidth, 90, 0, 0, hpWidth, 30);
		}

		if (INROOM3)
		{
			RENDER->FrameImage(m_pPlayerHPGauge, 2690, 60, 2690 + hpWidth, 90, 0, 0, hpWidth, 30);
		}

		if (INROOM4)
		{
			RENDER->FrameImage(m_pPlayerHPGauge, 1410, 780, 1410 + hpWidth, 810, 0, 0, hpWidth, 30);
		}
	}
}

void CPlayerHP::Release()
{
}
