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
	CImage* m_pEnding1Image;
	CImage* m_pEnding2Image;

	float fCooltime;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};