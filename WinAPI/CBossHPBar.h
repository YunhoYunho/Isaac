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
	void GetBossHP(CGish* value);

	void RenderImage();

private:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

