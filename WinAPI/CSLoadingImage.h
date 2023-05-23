#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;

class CSLoadingImage : public CGameObject
{
public:
	CSLoadingImage();
	virtual ~CSLoadingImage();

private:
	CAnimator* m_pAnimator;
	CImage* m_pLoadingImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};