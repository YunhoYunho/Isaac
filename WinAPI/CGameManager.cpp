#include "framework.h"
#include "CGameManager.h"
#include "CCollider.h"

CGameManager::CGameManager()
{
	m_bIsDebugMode = false;
	m_bIsRoom1Clear = false;
	m_bIsRoom2Clear = false;
	m_bIsRoom3Clear = false;
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
		m_bIsDebugMode = !m_bIsDebugMode;
	}

	ResetKillCount();
}

void CGameManager::Release()
{
}

bool CGameManager::GetIsDebugMode()
{
	return m_bIsDebugMode;
}

void CGameManager::ResetKillCount()
{
	if (ROOM1CLEAR || ROOM2CLEAR)
		MONSTERKILLCOUNT = 0;
}
