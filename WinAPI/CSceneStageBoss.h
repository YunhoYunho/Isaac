#pragma once
#include "CScene.h"
#include "CGameUI.h"

class CPlayer;
class CPlayerHP;
class CGish;

class CSceneStageBoss : public CScene
{
public:
	CSceneStageBoss();
	virtual ~CSceneStageBoss();

private:
	CPlayer* pPlayer;
	CGish* pGish;

	//CSound* pSound = RESOURCE->LoadSound(L"Basement", L"Sound\\Scene\\basementLoop.wav");

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

