#include "framework.h"
#include "CSceneStage01.h"

#include "WinAPI.h"
#include "CInputManager.h"
#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CEventManager.h"
#include "CCameraManager.h"
#include "CPathManager.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "CGish.h"
#include "CBaby.h"
#include "CBoomfly.h"

#include "CCameraController.h"
#include "CButton.h"
#include "CPanel.h"

#include "CImageObject.h"
#include "CGameUI.h"


CSceneStage01::CSceneStage01()
{
	pPlayer = nullptr;
}

CSceneStage01::~CSceneStage01()
{
}

void CSceneStage01::Init()
{
	pPlayer = new CPlayer();
	pPlayer->SetPos(200, WINSIZEY * 0.5f);
	AddGameObject(pPlayer);

	CMonster* pMonster = new CMonster();
	pMonster->SetPos(1000, WINSIZEY * 0.5f);
	AddGameObject(pMonster);

	CGish* pGish = new CGish();
	pGish->SetPos(500, WINSIZEY * 0.5f);
	AddGameObject(pGish);

	CBaby* pBaby = new CBaby();
	pBaby->SetPos(300, WINSIZEY * 0.5f);
	AddGameObject(pBaby);

	CBoomfly* pBoomfly = new CBoomfly();
	pBoomfly->SetPos(700, WINSIZEY * 0.5f);
	AddGameObject(pBoomfly);

	CCameraController* pCamController = new CCameraController;
	AddGameObject(pCamController);

	CImageObject* pBackGround = new CImageObject;
	pBackGround->SetImage(RESOURCE->LoadImg(L"HUD", L"Image\\Map\\Isaac_Map.png"));
	AddGameObject(pBackGround);

	/*CImage* pHUD = new CImage;
	pHUD->Load(SetImage(RESOURCE->LoadImg(L"HUD", L"Image\\Map\\HUD.png"));*/
}

void CSceneStage01::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\Isaac_Map_tile");
}

void CSceneStage01::Update()
{
	if (BUTTONDOWN(VK_ESCAPE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}
}

void CSceneStage01::Render()
{
}

void CSceneStage01::Exit()
{
}

void CSceneStage01::Release()
{
}
