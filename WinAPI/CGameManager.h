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

public:
	Vector PlayerPos;
	bool m_bIsDebugMode;

public:
	int PlayerHP;
	int PlayerMaxHP;
};

#define GAME		CGameManager::GetInstance()
#define PLAYERPOS	CGameManager::GetInstance()->PlayerPos
#define PLAYERHP	CGameManager::GetInstance()->PlayerHP
#define PLAYERMAXHP	CGameManager::GetInstance()->PlayerMaxHP