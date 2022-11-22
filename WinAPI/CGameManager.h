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
	Vector NowPlayerPos;
	Vector PrevPlayerPos;

public:
	int PlayerHP;
};

#define GAME		CGameManager::GetInstance()
#define PLAYERPOS	CGameManager::GetInstance()->NowPlayerPos
#define PLAYERHP	CGameManager::GetInstance()->PlayerHP