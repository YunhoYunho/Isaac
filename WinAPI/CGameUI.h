#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;

class CGameUI : public CGameObject
{
public:
	CGameUI();
	virtual ~CGameUI();

private:
	CAnimator* m_pAnimator;
	CImage* m_pHUDImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

