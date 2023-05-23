#include "framework.h"
#include "CGameManager.h"
#include "CCollider.h"

CGameManager::CGameManager()
{
	m_bIsDebugMode = false;
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
}

void CGameManager::Release()
{
}

bool CGameManager::GetIsDebugMode()
{
	return m_bIsDebugMode;
}
