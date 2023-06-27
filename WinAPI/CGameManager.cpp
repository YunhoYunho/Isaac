#include "framework.h"
#include "CGameManager.h"
#include "CCollider.h"

CGameManager::CGameManager()
{
	debugMode = false;
	room0Open = false;
	room1Clear = false;
	room2Clear = false;
	room3Clear = false;
	room4Clear = false;
	touchTeleport = false;
	resetKillCount = false;
	monsterKillCount = 0;
}

CGameManager::~CGameManager()
{
}

void CGameManager::Init()
{
}

void CGameManager::Update()
{
	if (BUTTONDOWN('B'))
	{
		debugMode = !debugMode;
	}

	CheckKillCount();
}

void CGameManager::Release()
{
}

bool CGameManager::GetIsDebugMode()
{
	return debugMode;
}

void CGameManager::CheckKillCount()
{
	if ((INROOM1 && ROOM1CLEAR) || (INROOM2 && ROOM2CLEAR) || (INROOM4 || ROOM4CLEAR))
	{
		resetKillCount = true;
		ResetKillCount();
	}
}

void CGameManager::ResetKillCount()
{
	if (MONSTERKILLCOUNT != 0)
	{
		if (true == resetKillCount)
		{
			MONSTERKILLCOUNT = 0;
			Logger::Debug(L"몬스터 킬카운트 초기화");
			resetKillCount = false;
		}
	}
}
