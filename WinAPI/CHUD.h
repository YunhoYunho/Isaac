#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;

class CHUD : public CGameObject
{
public:
	CHUD();
	virtual ~CHUD();

private:
	CAnimator* m_pAnimator;
	CImage* m_pHUDImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

