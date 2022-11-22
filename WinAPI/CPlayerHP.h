#pragma once
#include "CPlayer.h"

class CAnimator;
class CImage;

class CPlayerHP : public CGameObject
{
public:
	CPlayerHP();
	virtual ~CPlayerHP();

private:
	CAnimator* m_pAnimator;
	CImage* m_pPlayerHPImage;

private:
	int m_playerHP;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

