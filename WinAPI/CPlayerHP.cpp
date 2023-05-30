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
	RENDER->Image(m_pPlayerHPFrame, 0, 0, 300, 50);

	float hpWidth = 300 * PLAYERHP / PLAYERMAXHP;

	if (m_playerHP >= 0)
	{
		RENDER->FrameImage(m_pPlayerHPGauge, 0, 0, hpWidth, 50, 0, 0, hpWidth, 50);
	}
}

void CPlayerHP::Release()
{
}
