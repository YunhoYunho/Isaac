#pragma once
#include "CPlayer.h"

class CAnimator;
class CImage;

class CPlayerHP : public CPlayer
{
public:
	CPlayerHP();
	virtual ~CPlayerHP();

private:
	CAnimator* m_pAnimator;
	CImage* m_pPlayerHP1Image;
	CImage* m_pPlayerHP2Image;
	CImage* m_pPlayerHP3Image;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

