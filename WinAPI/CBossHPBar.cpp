#include "framework.h"
#include "CBossHPBar.h"

#include "CGish.h"

CBossHPBar::CBossHPBar()
{
	pGish = nullptr;
	m_pHPBarFrame = nullptr;
	m_pHPBarGauge = nullptr;
	m_fTimer = 0;
}

CBossHPBar::~CBossHPBar()
{
}

void CBossHPBar::GetBossHP(CGish* value)
{
	pGish = value;
}

void CBossHPBar::Init()
{
	m_pHPBarFrame = RESOURCE->LoadImg(L"BarFrame", L"Image\\Map\\Frame.png");
	m_pHPBarGauge = RESOURCE->LoadImg(L"BarGauge", L"Image\\Map\\Gauge.png");
}

void CBossHPBar::Update()
{
}

void CBossHPBar::Render()
{
	RENDER->Image(m_pHPBarFrame, 439, 634, 841, 720);

	float hpWidth = (841 - 439 - 52 - 52) * pGish->GetHP() / pGish->GetMaxHP();

	if (pGish->GetHP() >= 0)
	{
		RENDER->FrameImage(m_pHPBarGauge, 439, 634, 439 + hpWidth + 52, 720, 0, 0, hpWidth + 52, 86);
	}
}

void CBossHPBar::Release()
{
}
