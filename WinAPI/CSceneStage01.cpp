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
#include "CDoorTeleport.h"
#include "CDoorBossTeleport.h"

#include "CLoadingImage.h"
#include "CRock.h"
#include "CBlackRock.h"

#pragma region MonsterSpawnPosition
#define ROOM1P1		Vector(800, 200)
#define ROOM1P2		Vector(800, 300)
#define ROOM1P3		Vector(800, 400)
#define ROOM1P4		Vector(800, 500)

#define ROOM2P1		Vector(1510, 200)
#define ROOM2P2		Vector(1510, 500)
#define ROOM2P3		Vector(2330, 200)
#define ROOM2P4		Vector(2330, 500)

#define ROOM3P1		Vector(3500, 360)
#pragma endregion
#pragma region GridPosition
#define ROCK1		Vector(1600, 250)
#define ROCK2		Vector(1600, 500)
#define ROCK3		Vector(2200, 250)
#define ROCK4		Vector(2200, 500)
#pragma endregion

CSceneStage01::CSceneStage01()
{
	pPlayer = nullptr;
	pMonster = nullptr;
	m_fTimer = 0;
	m_fSpawnTimer = 0;
	m_fLoadTimer = 0;
	m_fSoundTimer = 0;
	randomNumber = 0;
	killCount = 0;
	enterCount = 0;
	soundCount = 0;
	m_bIsSpawnComplete = false;
	m_bIsRoom0Open = false;
	m_bIsRoom1Clear = false;
	m_bIsRoom2Clear = false;
	m_bIsRoom3Clear = false;
	m_bIsEnterBossRoom = false;
}

CSceneStage01::~CSceneStage01()
{
}

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

void CSceneStage01::CreateBoss()
{
	if (true != m_bIsSpawnComplete)
	{
		CGish* pGish = new CGish();
		pMonster = pGish;
		pMonster->SetPos(ROOM3P1);
		m_vecSpawnMonsters.emplace_back(pGish);
		AddGameObject(pGish);

		CBossHPBar* pBossHPBar = new CBossHPBar();
		AddGameObject(pBossHPBar);
		pBossHPBar->GetBossHP(pGish);

		SOUND->Play(pBossRoomSound, 0.7f, true);

		m_bIsSpawnComplete = m_vecSpawnMonsters.size() == 1 ? true : false;
	}
}

void CSceneStage01::CreateRock()
{
	for (int i = 0; i < 3; i++)
	{
		CRock* pRock = new CRock();
		pRock->SetPos(m_vecRockPositions[i]);
		AddGameObject(pRock);
	}

	CBlackRock* pBlackRock = new CBlackRock();
	pBlackRock->SetPos(m_vecRockPositions[3]);
	AddGameObject(pBlackRock);
}

void CSceneStage01::CreateDoorTeleport()
{
	CDoorTeleport* pDoorTeleport = new CDoorTeleport();
	pDoorTeleport->SetPos(Vector(1280, 360));
	pDoorTeleport->SetName(L"LRTeleport");
	AddGameObject(pDoorTeleport);

	CDoorTeleport* pDoorTeleport2 = new CDoorTeleport();
	pDoorTeleport2->SetPos(Vector(640, 720));
	pDoorTeleport2->SetName(L"UDTeleport");
	AddGameObject(pDoorTeleport2);
}

void CSceneStage01::CreateDoorBossTeleport()
{
	CDoorBossTeleport* pDoorBossTeleport = new CDoorBossTeleport();
	pDoorBossTeleport->SetPos(Vector(2560, 360));
	AddGameObject(pDoorBossTeleport);
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

void CSceneStage01::SpawnRoom3()
{
	if (INROOM3 && (false == m_bIsRoom3Clear))
	{
		m_fSpawnTimer += DT;

		if (m_fSpawnTimer > 2.0f)
		{
			CreateBoss();
			m_fSpawnTimer = 0;
		}
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
				m_bIsRoom0Open = true;
				m_bIsRoom1Clear = true;
				m_bIsSpawnComplete = false;
				Logger::Debug(L"방1 클리어? : " + to_wstring(m_bIsRoom1Clear));
			}

			if (INROOM2 && (true != m_bIsRoom2Clear))
			{
				m_bIsRoom2Clear = true;
				m_bIsSpawnComplete = false;
				Logger::Debug(L"방2 클리어? : " + to_wstring(m_bIsRoom2Clear));
			}

			if (INROOM3 && (true != m_bIsRoom3Clear))
			{
				m_bIsRoom3Clear = true;
				m_bIsSpawnComplete = false;
				Logger::Debug(L"방3 클리어? : " + to_wstring(m_bIsRoom3Clear));
			}

			m_vecSpawnMonsters.clear();
		}
	}
}

void CSceneStage01::WhatRoomClear()
{
	ROOM0OPEN = m_bIsRoom0Open;
	ROOM1CLEAR = m_bIsRoom1Clear;
	ROOM2CLEAR = m_bIsRoom2Clear;
	ROOM3CLEAR = m_bIsRoom3Clear;
}

void CSceneStage01::StartBossLoading()
{
	if (INROOM3 && (false == m_bIsRoom3Clear))
	{
		if (enterCount == 0)
		{
			CLoadingImage* pLoading = new CLoadingImage();
			pLoading->SetPos(WINSIZEX * 2.5, WINSIZEY / 2);
			ADDOBJECT(pLoading);

			SOUND->Stop(pBGMSound);

			enterCount++;
		}
	}
}

void CSceneStage01::StartBossSound()
{
	if (true == m_bIsRoom3Clear)
	{
		if (soundCount == 0)
		{
			SOUND->Stop(pBossRoomSound);
			SOUND->Play(pBossClearSound, 0.7f, false);
			soundCount++;
		}
	}
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

	m_vecRockPositions.emplace_back(ROCK1);
	m_vecRockPositions.emplace_back(ROCK2);
	m_vecRockPositions.emplace_back(ROCK3);
	m_vecRockPositions.emplace_back(ROCK4);
}

void CSceneStage01::Init()
{
	pPlayer = new CPlayer();
	pPlayer->SetPos(200, WINSIZEY * 0.5f);
	AddGameObject(pPlayer);
	
#pragma region 디버깅용

	/*CGish* pGish = new CGish();
	pGish->SetPos(300, WINSIZEY * 0.5f);
	AddGameObject(pGish);*/

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
	pBackGround->SetImage(RESOURCE->LoadImg(L"Map", L"Image\\Map\\Stage_Map.png"));
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

	CHUD* pHUD = new CHUD();
	AddGameObject(pHUD);

	CDoorControl* pDoorControl = new CDoorControl();
	AddGameObject(pDoorControl);

	CDoorFrame* pDoorFrame = new CDoorFrame();
	AddGameObject(pDoorFrame);

	CreateDoorTeleport();
	CreateDoorBossTeleport();
	MonsterPool();
	PositionPool();
	CreateRock();
}

void CSceneStage01::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\Isaac_Stage_tile");

	SOUND->Play(pBGMSound, 0.6f, false);
	SOUND->Pause(pBossRoomSound);
	SOUND->Pause(pBossClearSound);
}

void CSceneStage01::Update()
{
	WhatRoomClear();
	SpawnRoom1();
	SpawnRoom2();
	SpawnRoom3();
	CheckRoomClear();
	StartBossLoading();
	StartBossSound();

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
	/*Vector killCount = CAMERA->ScreenToWorldPoint(Vector(50, 50));
	wstring count = L"킬 카운트 : " + to_wstring(MONSTERKILLCOUNT) + L"\n생성된 적 : " + to_wstring(m_vecSpawnMonsters.size());
	RENDER->Text(count, killCount.x - 50, killCount.y - 10, killCount.x + 50, killCount.y + 10, Color(255, 255, 255, 1.f), 15);*/
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
			SOUND->Pause(pBGMSound);
			SOUND->Pause(pBossRoomSound);
			SOUND->Pause(pBossClearSound);
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

