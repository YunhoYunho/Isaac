#include "framework.h"
#include "CGameManager.h"
#include "CCollider.h"

CGameManager::CGameManager()
{
	m_bIsDebugMode = false;
	m_bIsRoom1Clear = false;
	m_bIsRoom2Clear = false;
	m_bIsRoom3Clear = false;
	m_bIsTouchTeleport = false;
	m_bIsResetKillCount = false;
	m_iMonsterKillCount = 0;
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

	CheckKillCount();
}

void CGameManager::Release()
{
}

bool CGameManager::GetIsDebugMode()
{
	return m_bIsDebugMode;
}

void CGameManager::CheckKillCount()
{
	if ((INROOM1 && ROOM1CLEAR) || ((INROOM2 && ROOM2CLEAR)))
	{
		m_bIsResetKillCount = true;

		ResetKillCount();
	}
}

void CGameManager::ResetKillCount()
{
	if (MONSTERKILLCOUNT != 0)
	{
		if (true == m_bIsResetKillCount)
		{
			MONSTERKILLCOUNT = 0;
			Logger::Debug(L"몬스터 킬카운트 초기화");
			m_bIsResetKillCount = false;
		}
	}
}
