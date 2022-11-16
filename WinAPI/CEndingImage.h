#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;

class CEndingImage : public CGameObject
{
public:
	CEndingImage();
	virtual ~CEndingImage();

private:
	CAnimator* m_pAnimator;
	CImage* m_pEndingImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

