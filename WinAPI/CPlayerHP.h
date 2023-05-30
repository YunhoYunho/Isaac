#pragma once
#include "CPlayer.h"

class CImage;

class CPlayerHP : public CGameObject
{
public:
	CPlayerHP();
	virtual ~CPlayerHP();

private:
	CImage* m_pPlayerHPFrame;
	CImage* m_pPlayerHPGauge;
	CPlayer* pPlayer;

private:
	int m_playerHP;

public:
	void GetHP(CPlayer* value);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

