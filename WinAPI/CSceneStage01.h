#pragma once
#include "CScene.h"
#include "CGameUI.h"

class CPlayer;
class CMonster;

class CSceneStage01 : public CScene
{
public:
	CSceneStage01();
	virtual ~CSceneStage01();

private:
	CPlayer* pPlayer;
	CSound* pSound = RESOURCE->LoadSound(L"Basement", L"Sound\\Scene\\basementLoop.wav");

	float m_fTimer;

	void MonsterPool();
	void PositionPool();

	void CreateMonsters(int num);
	void CreateDoorCollider();

	void SpawnRoom1();
	void SpawnRoom2();

	void CheckRoomClear();
	void WhatRoomClear();
	void ResetVector();

	vector<Vector> m_vecDoorControlPositions;
	vector<CMonster*> m_vecMonsters;
	vector<CMonster*> m_vecSpawnMonsters;
	vector<Vector> m_vecMonsterPositions;

	CMonster* pMonster;

	int randomNumber;
	int killCount;

	bool m_bIsSpawnComplete;
	bool m_bIsRoom1Clear;
	bool m_bIsRoom2Clear;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};
