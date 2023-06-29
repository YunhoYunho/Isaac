#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;

class CLoadingImage : public CGameObject
{
public:
	CLoadingImage();
	virtual ~CLoadingImage();

private:
	CAnimator* m_pAnimator;
	CImage* m_pLoadingImage;
	CSound* pBossLoadingSound;

	float m_fTimer = 0;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};