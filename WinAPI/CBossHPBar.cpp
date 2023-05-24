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

void CBossHPBar::CalculateHpPercent()
{
	HP = 402 - pGish->GetHP();
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
	RENDER->FrameImage(m_pHPBarGauge, 439, 634, 841 - (402 - pGish->GetHP()), 720, 0, 0, 402, 86);
}

void CBossHPBar::Release()
{
}
