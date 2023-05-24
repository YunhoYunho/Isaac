#pragma once
#include "CGameObject.h"

class CImage;
class CGish;

class CBossHPBar : public CGameObject
{
public:
	CBossHPBar();
	virtual ~CBossHPBar();

public:
	CGish* pGish;
	CImage* m_pHPBarFrame;
	CImage* m_pHPBarGauge;

	float m_fTimer;
	float HP = 0;

	void GetBossHP(CGish* value);
	void CalculateHpPercent();

private:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

