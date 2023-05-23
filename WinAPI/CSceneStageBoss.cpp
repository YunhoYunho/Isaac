#include "framework.h"
#include "CSceneStageBoss.h"

#include "CCameraController.h"
#include "CImageObject.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "CGish.h"

CSceneStageBoss::CSceneStageBoss()
{
	pPlayer = nullptr;
}

CSceneStageBoss::~CSceneStageBoss()
{
}

void CSceneStageBoss::Init()
{
	pPlayer = new CPlayer();
	pPlayer->SetPos(200, WINSIZEY * 0.5f);
	AddGameObject(pPlayer);

	CGish* pGish = new CGish();
	pGish->SetPos(500, WINSIZEY * 0.5f);
	AddGameObject(pGish);
	  
	CCameraController* pCamController = new CCameraController;
	AddGameObject(pCamController);

	CImageObject* pBackGround = new CImageObject;
	pBackGround->SetImage(RESOURCE->LoadImg(L"Map", L"Image\\Map\\Isaac_BossMap.png"));
	AddGameObject(pBackGround);
}

void CSceneStageBoss::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\Isaac_Map_tile");

	//SOUND->Play(pSound, 0.6f, false);
}

void CSceneStageBoss::Update()
{
	if (BUTTONDOWN(VK_ESCAPE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}

	if (BUTTONSTAY('R'))
	{
		CAMERA->FadeOut(0.1f);
		DELAYCHANGESCENE(GroupScene::Stage01, 0.15f);
	}

	if (PLAYERHP == 0)
	{
		CSound* pDeadSound = RESOURCE->LoadSound(L"Died", L"Sound\\Scene\\Died.wav");
		//SOUND->Play(pDeadSound);
	}
}

void CSceneStageBoss::Render()
{
}

void CSceneStageBoss::Exit()
{
	// 게임오브젝트 삭제
	for (int layer = 0; layer < (int)Layer::Size; layer++)
	{
		for (CGameObject* pGameObject : m_listObj[layer])
		{
			pGameObject->GetReserveDelete();
			delete pGameObject;
			//SOUND->Pause(pSound);
		}
		m_listObj[layer].clear();
	}
	// 초기화 후 다시 시작
	Init();
}

void CSceneStageBoss::Release()
{
}
