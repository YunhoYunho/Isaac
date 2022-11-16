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
	Vector PlayerPos;
};

#define GAME	CGameManager::GetInstance()
#define PLAYERPOS	CGameManager::GetInstance()->PlayerPos