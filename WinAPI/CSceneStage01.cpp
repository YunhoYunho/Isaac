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
#include "CFly.h"

#include "CCameraController.h"
#include "CButton.h"
#include "CPanel.h"

#include "CImageObject.h"
#include "CPlayerHP.h"
#include "CItemRock.h"

#include "CTripleShot.h"

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

	CGish* pGish = new CGish();
	pGish->SetPos(500, WINSIZEY * 0.5f);
	AddGameObject(pGish);

	/*CBaby* pBaby = new CBaby();
	pBaby->SetPos(300, WINSIZEY * 0.5f);
	AddGameObject(pBaby);

	CBoomfly* pBoomfly = new CBoomfly();
	pBoomfly->SetPos(700, WINSIZEY * 0.5f);
	AddGameObject(pBoomfly);

	CFly* pFly1 = new CFly();
	pFly1->SetPos(800, WINSIZEY * 0.5f);
	AddGameObject(pFly1);

	CFly* pFly2 = new CFly();
	pFly2->SetPos(800, WINSIZEY * 0.3f);
	AddGameObject(pFly2);*/

	CCameraController* pCamController = new CCameraController;
	AddGameObject(pCamController);

	CImageObject* pBackGround = new CImageObject;
	pBackGround->SetImage(RESOURCE->LoadImg(L"Map", L"Image\\Map\\Isaac_StageMap.png"));
	AddGameObject(pBackGround);

	CPlayerHP* pPlayerHPImage = new CPlayerHP;
	pPlayerHPImage->SetPos(70, 50);
	AddGameObject(pPlayerHPImage);

	CTripleShot* pTripleShot = new CTripleShot;
	pTripleShot->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.5f);
	AddGameObject(pTripleShot);

	CItemRock* pItemRock = new CItemRock;
	pItemRock->SetPos(WINSIZEX * 0.5f + 2, WINSIZEY * 0.5f + 15);
	AddGameObject(pItemRock);
}

void CSceneStage01::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\Isaac_StageMap_tile");

	SOUND->Play(pSound, 0.6f, false);
}

void CSceneStage01::Update()
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

void CSceneStage01::Render()
{
}

void CSceneStage01::Exit()
{
	// 게임오브젝트 삭제
	for (int layer = 0; layer < (int)Layer::Size; layer++)
	{
		for (CGameObject* pGameObject : m_listObj[layer])
		{
			pGameObject->GetReserveDelete();
			delete pGameObject;
			SOUND->Pause(pSound);
		}
		m_listObj[layer].clear();
	}
	// 초기화 후 다시 시작
	Init();
}

void CSceneStage01::Release()
{
}