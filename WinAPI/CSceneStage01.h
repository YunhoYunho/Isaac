#pragma once
#include "CScene.h"
#include "CGameUI.h"

class CPlayer;
class CMonster;
class CDoorTeleport;

class CSceneStage01 : public CScene
{
public:
	CSceneStage01();
	virtual ~CSceneStage01();

private:
	CPlayer* pPlayer;
	CMonster* pMonster;
	CSound* pBGMSound = RESOURCE->LoadSound(L"Basement", L"Sound\\Scene\\basementLoop.wav");
	CSound* pBossRoomSound = RESOURCE->LoadSound(L"BossRoom", L"Sound\\Scene\\BossRoom.ogg");
	CSound* pBossClearSound = RESOURCE->LoadSound(L"BossClear", L"Sound\\Scene\\BossRoomOutro.ogg");

	float m_fTimer;
	float m_fSpawnTimer;
	float m_fLoadTimer;
	float m_fSoundTimer;

	void MonsterPool();
	void PositionPool();

	void CreateDoorTeleport();
	void CreateDoorBossTeleport();

	void CreateMonsters(int num);
	void CreateBoss();

	void SpawnRoom1();
	void SpawnRoom2();
	void SpawnRoom3();

	void CheckRoomClear();
	void WhatRoomClear();

	void StartBossLoading();
	void StartBossSound();

	vector<CMonster*> m_vecMonsters;
	vector<CMonster*> m_vecSpawnMonsters;
	vector<Vector> m_vecMonsterPositions;

	int randomNumber;
	int killCount;
	int enterCount;
	int soundCount;

	bool m_bIsSpawnComplete;
	bool m_bIsRoom1Clear;
	bool m_bIsRoom2Clear;
	bool m_bIsRoom3Clear;
	bool m_bIsEnterBossRoom;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};
