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
#include "CBossHPBar.h"
#include "CHUD.h"

#include "CDoorControl.h"
#include "CDoorFrame.h"
#include "CDoorCollider.h"
#include "CDoorTeleport.h"

CSceneStage01::CSceneStage01()
{
	pPlayer = nullptr;
	pMonster = nullptr;
	m_fTimer = 0;
	randomNumber = 0;
	killCount = 0;
	m_bIsSpawnComplete = false;
	m_bIsRoom1Clear = false;
	m_bIsRoom2Clear = false;
}

CSceneStage01::~CSceneStage01()
{
}

//void CSceneStage01::CreateMonsters(int num)
//{
//	if (true != m_bIsSpawnComplete)
//	{
//		srand((unsigned int)time(NULL));
//		randomNumber = rand() % (m_vecMonsters.size() - 1) + 1;
//		int random = 0;
//
//		vector<int> result = Util::NonDuplicatedRandom(0, 100, 5);
//
//		random = (num == 1) ? rand() % 4 : rand() % 4 + 4;
//
//		Logger::Debug(to_wstring(random));
//
//		for (int i = 0; i < randomNumber; i++)
//		{
//			Vector pos = m_vecMonsterPositions[random];
//			pMonster = m_vecMonsters[i]->Clone();
//			pMonster->SetPos(pos);
//			m_vecSpawnMonsters.emplace_back(pMonster);
//			ADDOBJECT(pMonster);
//		}
//
//		m_bIsSpawnComplete = (randomNumber == m_vecSpawnMonsters.size()) ? true : false;
//	}
//}

void CSceneStage01::CreateMonsters(int num)
{
	if (true != m_bIsSpawnComplete)
	{
		srand((unsigned int)time(NULL));
		randomNumber = (rand() % m_vecMonsters.size()) + 1;

		vector<int> result1 = Util::NonDuplicatedRandom(0, 3, 4);
		vector<int> result2 = Util::NonDuplicatedRandom(4, 7, 4);
		vector<int> random = (num == 1) ? result1 : result2;

		for (int i = 0; i < randomNumber; i++)
		{
			Vector pos = m_vecMonsterPositions[random[i]];
			pMonster = m_vecMonsters[i]->Clone();
			pMonster->SetPos(pos);
			m_vecSpawnMonsters.emplace_back(pMonster);
			ADDOBJECT(pMonster);
		}

		m_bIsSpawnComplete = (randomNumber == m_vecSpawnMonsters.size()) ? true : false;
	}
}

void CSceneStage01::CreateDoorCollider()
{
	m_vecDoorControlPositions.emplace_back(ROOM1COLLR);
	m_vecDoorControlPositions.emplace_back(ROOM2COLLL);
	m_vecDoorControlPositions.emplace_back(ROOM2COLLR);
	m_vecDoorControlPositions.emplace_back(ROOM3COLLL);
	m_vecDoorControlPositions.emplace_back(Vector(1280, 360));
	m_vecDoorControlPositions.emplace_back(Vector(2560, 360));

	for (int i = 0; i < 4; i++)
	{
		CDoorCollider* pDoorCollider = new CDoorCollider();
		Vector pos = m_vecDoorControlPositions[i];
		pDoorCollider->SetPos(pos);
		AddGameObject(pDoorCollider);
	}

	for (int i = 4; i < 5; i++)
	{
		CDoorTeleport* pDoorTeleport = new CDoorTeleport();
		Vector pos = m_vecDoorControlPositions[i];
		pDoorTeleport->SetPos(pos);
		AddGameObject(pDoorTeleport);
	}
}

void CSceneStage01::SpawnRoom1()
{
	if (INROOM1 && (m_bIsRoom1Clear == false))
	{
		CreateMonsters(1);
	}
}

void CSceneStage01::SpawnRoom2()
{
	if (INROOM2 && (m_bIsRoom2Clear == false))
	{
		CreateMonsters(2);
	}
}

void CSceneStage01::CheckRoomClear()
{
	if (true != m_vecSpawnMonsters.empty())
	{
		if (m_vecSpawnMonsters.size() == MONSTERKILLCOUNT)
		{
			if (INROOM1 && (true != m_bIsRoom1Clear))
			{
				m_bIsRoom1Clear = true;
				m_bIsSpawnComplete = false;
				Logger::Debug(L"방1 클리어? : " + to_wstring(m_bIsRoom1Clear));
			}

			if (INROOM2 && (true != m_bIsRoom2Clear))
			{
				m_bIsRoom2Clear = true;
				Logger::Debug(L"방2 클리어? : " + to_wstring(m_bIsRoom2Clear));
			}

			ResetVector();
		}
	}
}

void CSceneStage01::WhatRoomClear()
{
	ROOM1CLEAR = m_bIsRoom1Clear;
	ROOM2CLEAR = m_bIsRoom2Clear;
}

void CSceneStage01::ResetVector()
{
	m_vecSpawnMonsters.clear();
	//m_vecMonsterPositions.clear();
}

void CSceneStage01::MonsterPool()
{
	m_vecMonsters.clear();

	m_vecMonsters.emplace_back(new CBaby());
	m_vecMonsters.emplace_back(new CBoomfly());
	m_vecMonsters.emplace_back(new CFly());
}

void CSceneStage01::PositionPool()
{
	m_vecMonsterPositions.emplace_back(ROOM1P1);
	m_vecMonsterPositions.emplace_back(ROOM1P2);
	m_vecMonsterPositions.emplace_back(ROOM1P3);
	m_vecMonsterPositions.emplace_back(ROOM1P4);
						  
	m_vecMonsterPositions.emplace_back(ROOM2P1);
	m_vecMonsterPositions.emplace_back(ROOM2P2);
	m_vecMonsterPositions.emplace_back(ROOM2P3);
	m_vecMonsterPositions.emplace_back(ROOM2P4);
}

void CSceneStage01::Init()
{
	pPlayer = new CPlayer();
	pPlayer->SetPos(200, WINSIZEY * 0.5f);
	AddGameObject(pPlayer);

	CGish* pGish = new CGish();
	pGish->SetPos(ROOM3P1);
	AddGameObject(pGish);

#pragma region 디버깅용
	/*CBaby* pBaby = new CBaby();
	pBaby->SetPos(300, WINSIZEY * 0.5f);
	AddGameObject(pBaby);*/

	/*CBoomfly* pBoomfly = new CBoomfly();
	pBoomfly->SetPos(700, WINSIZEY * 0.5f);
	AddGameObject(pBoomfly);*/

	/*CFly* pFly1 = new CFly();
	pFly1->SetPos(800, WINSIZEY * 0.5f);
	AddGameObject(pFly1);*/

	/*CFly* pFly2 = new CFly();
	pFly2->SetPos(800, WINSIZEY * 0.3f);
	AddGameObject(pFly2);*/
#pragma endregion

	CCameraController* pCamController = new CCameraController;
	AddGameObject(pCamController);

	CImageObject* pBackGround = new CImageObject;
	pBackGround->SetImage(RESOURCE->LoadImg(L"Map", L"Image\\Map\\Stage01_Map.png"));
	AddGameObject(pBackGround);

	CPlayerHP* pPlayerHPImage = new CPlayerHP;
	AddGameObject(pPlayerHPImage);
	pPlayerHPImage->GetHP(pPlayer);

	CTripleShot* pTripleShot = new CTripleShot;
	pTripleShot->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.5f);
	AddGameObject(pTripleShot);

	CItemRock* pItemRock = new CItemRock;
	pItemRock->SetPos(WINSIZEX * 0.5f + 2, WINSIZEY * 0.5f + 15);
	AddGameObject(pItemRock);

	/*CBossHPBar* pBossHPBar = new CBossHPBar();
	AddGameObject(pBossHPBar);
	pBossHPBar->GetBossHP(pGish);*/

	CHUD* pHUD = new CHUD();
	AddGameObject(pHUD);

	CDoorControl* pDoorControl = new CDoorControl();
	AddGameObject(pDoorControl);

	CDoorFrame* pDoorFrame = new CDoorFrame();
	AddGameObject(pDoorFrame);

	CreateDoorCollider();
	MonsterPool();
	PositionPool();
}

void CSceneStage01::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\Isaac_Stage01_tile");

	SOUND->Play(pSound, 0.6f, false);
}

void CSceneStage01::Update()
{
	WhatRoomClear();
	SpawnRoom1();
	SpawnRoom2();
	CheckRoomClear();

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

	/*if ()
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Loading, 0.25f);
	}*/
}

void CSceneStage01::Render()
{
	Vector killCount = CAMERA->ScreenToWorldPoint(Vector(50, 20));
	wstring frame = to_wstring(MONSTERKILLCOUNT);
	RENDER->Text(frame, killCount.x - 50, killCount.y - 10, killCount.x + 50, killCount.y + 10, Color(255, 255, 255, 1.f), 15);
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

	/*DeleteAll();
	Init();*/
}

void CSceneStage01::Release()
{
}

