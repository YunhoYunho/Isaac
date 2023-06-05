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
	void ResetKillCount();
	
public:
	Vector PlayerPos;
	bool m_bIsDebugMode;
	bool m_bIsRoom1Clear;
	bool m_bIsRoom2Clear;
	bool m_bIsRoom3Clear;

	int monsterKillCount;

public:
	int PlayerHP;
	int PlayerMaxHP;
	int PlayerBomb;
	int PlayerKey;
};

#define GAME		CGameManager::GetInstance()
#define PLAYERPOS	CGameManager::GetInstance()->PlayerPos
#define PLAYERHP	CGameManager::GetInstance()->PlayerHP
#define PLAYERMAXHP	CGameManager::GetInstance()->PlayerMaxHP
#define PLAYERBOMB	CGameManager::GetInstance()->PlayerBomb
#define PLAYERKEY	CGameManager::GetInstance()->PlayerKey
#define MONSTERKILLCOUNT	CGameManager::GetInstance()->monsterKillCount

#pragma region IsRoomClear
#define ROOM1CLEAR	CGameManager::GetInstance()->m_bIsRoom1Clear
#define ROOM2CLEAR	CGameManager::GetInstance()->m_bIsRoom2Clear
#define ROOM3CLEAR	CGameManager::GetInstance()->m_bIsRoom3Clear
#pragma endregion

#pragma region WhatRoomIsIt
#define INROOM1		(PLAYERPOS.x < 1200)
#define INROOM2		(PLAYERPOS.x > 1400 && PLAYERPOS.x < 2500)
#define INROOM3		(PLAYERPOS.x > 2600)
#pragma endregion

#pragma region MonsterSpawnPosition
#define ROOM1P1		Vector(800, 200)
#define ROOM1P2		Vector(800, 300)
#define ROOM1P3		Vector(800, 400)
#define ROOM1P4		Vector(800, 500)

#define ROOM2P1		Vector(1510, 200)
#define ROOM2P2		Vector(1510, 500)
#define ROOM2P3		Vector(2330, 200)
#define ROOM2P4		Vector(2330, 500)

#define ROOM3P1		Vector(3500, 360)
#pragma endregion

#pragma region DoorCollider
#define ROOM1COLLR	Vector(1125, 308)
#define ROOM2COLLL	Vector(1390, 308)
#define ROOM2COLLR	Vector(2330, 286)
#define ROOM3COLLL	Vector(2655, 302)
#pragma endregion