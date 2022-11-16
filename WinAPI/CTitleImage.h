#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;

class CTitleImage : public CGameObject
{
public:
	CTitleImage();
	virtual ~CTitleImage();

private:
	CAnimator* m_pAnimator;
	CImage* m_pTitleImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

