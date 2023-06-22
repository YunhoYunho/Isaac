#pragma once
#include "WinAPI.h"

class CGameManager : public SingleTon<CGameManager>
{
	friend SingleTon<CGameManager>;
	friend CCore;
private:
	CGameManager();
	virtual ~CGameManager();

	void Init();
	void Update();
	void Release();

public:
	bool GetIsDebugMode();
	void CheckKillCount();
	void ResetKillCount();
	
public:
	Vector PlayerPos;
	bool debugMode;
	bool room0Open;
	bool room1Clear;
	bool room2Clear;
	bool room3Clear;
	bool touchTeleport;
	bool resetKillCount;
	bool pause;

public:
	int PlayerHP;
	int PlayerMaxHP;
	int PlayerBomb;
	int PlayerKey;
	int monsterKillCount;
	float PlayerDamage;
	float PlayerShotSpeed;
};

#define GAME				CGameManager::GetInstance()
#define PLAYERPOS			CGameManager::GetInstance()->PlayerPos
#define PLAYERHP			CGameManager::GetInstance()->PlayerHP
#define PLAYERMAXHP			CGameManager::GetInstance()->PlayerMaxHP
#define PLAYERDAMAGE		CGameManager::GetInstance()->PlayerDamage
#define PLAYERSHOTSPEED		CGameManager::GetInstance()->PlayerShotSpeed
#define PLAYERBOMB			CGameManager::GetInstance()->PlayerBomb
#define PLAYERKEY			CGameManager::GetInstance()->PlayerKey
#define MONSTERKILLCOUNT	CGameManager::GetInstance()->monsterKillCount
#define TOUCHTELEPORT		CGameManager::GetInstance()->touchTeleport

#pragma region IsRoomClear
#define ROOM0OPEN			CGameManager::GetInstance()->room0Open
#define ROOM1CLEAR			CGameManager::GetInstance()->room1Clear
#define ROOM2CLEAR			CGameManager::GetInstance()->room2Clear
#define ROOM3CLEAR			CGameManager::GetInstance()->room3Clear
#pragma endregion

#pragma region WhatRoomIsIt
#define INROOM0				(PLAYERPOS.x < 1200) && (PLAYERPOS.y > 720)
#define INROOM1				(PLAYERPOS.x < 1200) && (PLAYERPOS.y < 720)
#define INROOM2				(PLAYERPOS.x > 1400 && PLAYERPOS.x < 2500)
#define INROOM3				(PLAYERPOS.x > 2600)
#pragma endregion
