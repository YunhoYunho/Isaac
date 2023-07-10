#include "framework.h"
#include "CSceneStage01.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "CGish.h"
#include "CBaby.h"
#include "CBoomfly.h"
#include "CFly.h"

#include "CPlayerHP.h"
#include "CBossHPBar.h"
#include "CHUD.h"
#include "CCameraController.h"
#include "CImageObject.h"
#include "CLoadingImage.h"
#include "CEndingChest.h"

#include "CItemRock.h"
#include "CMeat.h"
#include "CSadOnion.h"
#include "CSkeletonKey.h"
#include "CTenBombs.h"
#include "CShieldTears.h"
#include "CTripleShot.h"
#include "CRock.h"
#include "CBlackRock.h"
#include "CPickupHeart.h"
#include "CPickupBomb.h"
#include "CPickupKey.h"
#include "CNormalChest.h"
#include "CGoldenChest.h"

#include "CDoorControl.h"
#include "CDoorFrame.h"
#include "CDoorTeleport.h"
#include "CDoorBossTeleport.h"

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
#define ROOM4P1		Vector(1510, 1000)
#define ROOM4P2		Vector(1510, 1200)
#define ROOM4P3		Vector(2330, 1000)
#define ROOM4P4		Vector(2330, 1200)
#pragma endregion
#pragma region RockPosition
#define ROCK1		Vector(1600, 250)
#define ROCK2		Vector(1600, 500)
#define ROCK3		Vector(2200, 250)
#define ROCK4		Vector(2200, 500)
#define ROCKA		Vector(1910, 1030)
#define ROCKB		Vector(1910, 1080)
#define ROCKC		Vector(1960, 1030)
#define ROCKD		Vector(1960, 1080)
#pragma endregion
#pragma region TeleportPosition
#define TELE1		Vector(1280,  360)
#define TELE2		Vector(1280, 1080)
#define TELE3		Vector( 640,  720)
#define TELE4		Vector(1920,  720)
#define TELEB		Vector(2560,  360)
#pragma endregion
#pragma region
#define ITEM1		Vector(250, 900)
#define ITEM2		Vector(250, 1200)
#define ITEM3		Vector(1000, 900)
#define ITEM4		Vector(1000, 1200)
#define ITEM5		Vector(590, 1050)
#define ITEM6		Vector(680, 1050)
#pragma endregion

CSceneStage01::CSceneStage01()
{
	pPlayer = nullptr;
	pMonster = nullptr;
	pBGMSound = nullptr;
	pBossRoomSound = nullptr;
	pBossClearSound = nullptr;
	pCurSound = nullptr;
	pPassiveItem = nullptr;
	pEndingChest = nullptr;
	pCreateItem = nullptr;
	m_fSpawnTimer = 0;
	randomNumber = 0;
	killCount = 0;
	enterCount = 0;
	soundCount = 0;
	chestCount = 0;
	m_bIsSpawnComplete = false;
	m_bIsRoom0Open = false;
	m_bIsRoom1Clear = false;
	m_bIsRoom2Clear = false;
	m_bIsRoom3Clear = false;
	m_bIsRoom4Clear = false;
}

CSceneStage01::~CSceneStage01()
{
}

void CSceneStage01::PlayBGM(CSound* sound, float volume, bool loop)
{
	if (pCurSound != nullptr)
		SOUND->Stop(pCurSound);

	SOUND->Play(sound, volume, loop);
	pCurSound = sound;
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
	m_vecMonsterPositions.clear();

	m_vecMonsterPositions.emplace_back(ROOM1P1);
	m_vecMonsterPositions.emplace_back(ROOM1P2);
	m_vecMonsterPositions.emplace_back(ROOM1P3);
	m_vecMonsterPositions.emplace_back(ROOM1P4);
	m_vecMonsterPositions.emplace_back(ROOM2P1);
	m_vecMonsterPositions.emplace_back(ROOM2P2);
	m_vecMonsterPositions.emplace_back(ROOM2P3);
	m_vecMonsterPositions.emplace_back(ROOM2P4);
	m_vecMonsterPositions.emplace_back(ROOM4P1);
	m_vecMonsterPositions.emplace_back(ROOM4P2);
	m_vecMonsterPositions.emplace_back(ROOM4P3);
	m_vecMonsterPositions.emplace_back(ROOM4P4);

	m_vecRockPositions.emplace_back(ROCK1);
	m_vecRockPositions.emplace_back(ROCK2);
	m_vecRockPositions.emplace_back(ROCK3);
	m_vecRockPositions.emplace_back(ROCK4);
	m_vecRockPositions.emplace_back(ROCKA);
	m_vecRockPositions.emplace_back(ROCKB);
	m_vecRockPositions.emplace_back(ROCKC);
	m_vecRockPositions.emplace_back(ROCKD);

	m_vecTeleportPositions.emplace_back(TELE1);
	m_vecTeleportPositions.emplace_back(TELE2);
	m_vecTeleportPositions.emplace_back(TELE3);
	m_vecTeleportPositions.emplace_back(TELE4);

	m_vecItemPositions.emplace_back(ITEM1);
	m_vecItemPositions.emplace_back(ITEM2);
	m_vecItemPositions.emplace_back(ITEM3);
	m_vecItemPositions.emplace_back(ITEM4);
	m_vecItemPositions.emplace_back(ITEM5);
	m_vecItemPositions.emplace_back(ITEM6);
}

void CSceneStage01::ItemPool()
{
	m_vecItems.clear();
	m_vecCreateItems.clear();

	m_vecItems.emplace_back(new CMeat());
	m_vecItems.emplace_back(new CSadOnion());
	m_vecItems.emplace_back(new CSkeletonKey());
	m_vecItems.emplace_back(new CTenBombs());
	m_vecItems.emplace_back(new CShieldTears());
	m_vecItems.emplace_back(new CTripleShot());

	m_vecCreateItems.emplace_back(new CPickupHeart());
	m_vecCreateItems.emplace_back(new CPickupBomb());
	m_vecCreateItems.emplace_back(new CPickupKey());
	m_vecCreateItems.emplace_back(new CNormalChest());
	m_vecCreateItems.emplace_back(new CGoldenChest());
}

void CSceneStage01::CreateDoorTeleport()
{
	for (int i = 0; i < 2; i++)
	{
		CDoorTeleport* pDoorTeleport = new CDoorTeleport();
		pDoorTeleport->SetPos(m_vecTeleportPositions[i]);
		pDoorTeleport->SetName(L"LRTeleport");
		AddGameObject(pDoorTeleport);
	}

	for (int i = 2; i < 4; i++)
	{
		CDoorTeleport* pDoorTeleport2 = new CDoorTeleport();
		pDoorTeleport2->SetPos(m_vecTeleportPositions[i]);
		pDoorTeleport2->SetName(L"UDTeleport");
		AddGameObject(pDoorTeleport2);
	}
}

void CSceneStage01::CreateDoorBossTeleport()
{
	CDoorBossTeleport* pDoorBossTeleport = new CDoorBossTeleport();
	pDoorBossTeleport->SetPos(TELEB);
	AddGameObject(pDoorBossTeleport);
}

void CSceneStage01::CreateRock()
{
	for (int i = 0; i < 8; i++)
	{
		CRock* pRock = new CRock();
		pRock->SetPos(m_vecRockPositions[i]);
		AddGameObject(pRock);
	}

	CBlackRock* pBlackRock = new CBlackRock();
	pBlackRock->SetPos(m_vecRockPositions[3]);
	AddGameObject(pBlackRock);
}

void CSceneStage01::CreateItem()
{
	for (int i = 0; i < 6; i++)
	{
		CItemRock* pItemRock = new CItemRock();
		Vector pos = m_vecItemPositions[i];
		pPassiveItem = m_vecItems[i];
		pPassiveItem->SetPos(pos);
		pItemRock->SetPos(pos.x, pos.y + 15.0f);
		AddGameObject(pPassiveItem);
		AddGameObject(pItemRock);
	}
}

void CSceneStage01::CreateMonsters(int num)
{
	if (true != m_bIsSpawnComplete)
	{
		srand((unsigned int)time(NULL));
		randomNumber = (rand() % m_vecMonsters.size()) + 1;

		vector<int> result1 = Util::NonDuplicatedRandom(0, 3, 4);
		vector<int> result2 = Util::NonDuplicatedRandom(4, 7, 4);
		vector<int> result3 = Util::NonDuplicatedRandom(8, 11, 4);
		vector<int> random = (num == 1) ? result1 : result2;
		if (num == 3) random = result3;

		for (int i = 0; i < randomNumber; i++)
		{
			Vector pos = m_vecMonsterPositions[random[i]];
			pMonster = m_vecMonsters[i]->Clone();
			pMonster->SetPos(pos);
			m_vecSpawnMonsters.emplace_back(pMonster);
			AddGameObject(pMonster);
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

		PlayBGM(pBossRoomSound, 0.3f, true);
		m_bIsSpawnComplete = m_vecSpawnMonsters.size() == 1 ? true : false;
	}
}

void CSceneStage01::CreateEndingChest()
{
	if (true == m_bIsRoom3Clear)
	{
		if (chestCount == 0)
		{
			CEndingChest* pEChest = new CEndingChest();
			pEndingChest = pEChest;
			pEndingChest->SetPos(3200, 200);
			AddGameObject(pEndingChest);
			chestCount++;
		}
	}
}

void CSceneStage01::SpawnRoom()
{
	if (INROOM1 && (false == m_bIsRoom1Clear))
	{
		CreateMonsters(1);
	}

	if (INROOM2 && (false == m_bIsRoom2Clear))
	{
		CreateMonsters(2);
	}

	if (INROOM3 && (false == m_bIsRoom3Clear))
	{
		m_fSpawnTimer += DT;

		if (m_fSpawnTimer > 2.0f)
		{
			CreateBoss();
			m_fSpawnTimer = 0;
		}
	}

	if (INROOM4 && (false == m_bIsRoom4Clear))
	{
		CreateMonsters(3);
	}
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
			PlayBGM(pBossClearSound, 0.3f, false);
			soundCount++;
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
				Logger::Debug(L"规1 努府绢? : " + to_wstring(m_bIsRoom1Clear));
			}

			if (INROOM2 && (true != m_bIsRoom2Clear))
			{
				m_bIsRoom2Clear = true;
				m_bIsSpawnComplete = false;
				Logger::Debug(L"规2 努府绢? : " + to_wstring(m_bIsRoom2Clear));
			}

			if (INROOM3 && (true != m_bIsRoom3Clear))
			{
				m_bIsRoom3Clear = true;
				m_bIsSpawnComplete = false;
				Logger::Debug(L"规3 努府绢? : " + to_wstring(m_bIsRoom3Clear));
			}

			if (INROOM4 && (true != m_bIsRoom4Clear))
			{
				m_bIsRoom4Clear = true;
				m_bIsSpawnComplete = false;
				Logger::Debug(L"规4 努府绢? : " + to_wstring(m_bIsRoom2Clear));
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
	ROOM4CLEAR = m_bIsRoom4Clear;
}

void CSceneStage01::CreateItems()
{
	if ((BUTTONDOWN(VK_F6)) || (BUTTONDOWN(VK_F7)) || (BUTTONDOWN(VK_F8)) ||
		(BUTTONDOWN(VK_F9)) || (BUTTONDOWN(VK_F10)))
	{
		float num = 0;

		if (BUTTONDOWN(VK_F6))
		{
			pCreateItem = m_vecCreateItems[0];
			num = 300;
		}

		if (BUTTONDOWN(VK_F7))
		{
			pCreateItem = m_vecCreateItems[1];
			num = 400;
		}

		if (BUTTONDOWN(VK_F8))
		{
			pCreateItem = m_vecCreateItems[2];
			num = 500;
		}

		if (BUTTONDOWN(VK_F9))
		{
			pCreateItem = m_vecCreateItems[3];
			num = 600;
		}

		if (BUTTONDOWN(VK_F10))
		{
			pCreateItem = m_vecCreateItems[4];
			num = 700;
		}

		Vector pos = Vector(num, WINSIZEY * 0.3f);
		pCreateItem->SetPos(pos);
		ADDOBJECT(pCreateItem);
	}
}

void CSceneStage01::Init()
{
	pBGMSound = RESOURCE->LoadSound(L"Basement", L"Sound\\Scene\\basementLoop.wav");
	pBossRoomSound = RESOURCE->LoadSound(L"BossRoom", L"Sound\\Scene\\BossRoom.ogg");
	pBossClearSound = RESOURCE->LoadSound(L"BossClear", L"Sound\\Scene\\BossRoomOutro.ogg");

	pPlayer = new CPlayer();
	pPlayer->SetPos(200, WINSIZEY * 0.5f);
	AddGameObject(pPlayer);

	CCameraController* pCamController = new CCameraController;
	AddGameObject(pCamController);

	CImageObject* pBackGround = new CImageObject;
	pBackGround->SetImage(RESOURCE->LoadImg(L"Map", L"Image\\Map\\Stage_Map.png"));
	AddGameObject(pBackGround);

	CImageObject* pBGShader = new CImageObject;
	pBGShader->SetImage(RESOURCE->LoadImg(L"Shader", L"Image\\Map\\Shader_Map.png"));
	AddGameObject(pBGShader);

	CPlayerHP* pPlayerHPImage = new CPlayerHP;
	AddGameObject(pPlayerHPImage);
	pPlayerHPImage->GetHP(pPlayer);

	CHUD* pHUD = new CHUD();
	AddGameObject(pHUD);

	CDoorControl* pDoorControl = new CDoorControl();
	AddGameObject(pDoorControl);

	CDoorFrame* pDoorFrame = new CDoorFrame();
	AddGameObject(pDoorFrame);

	MonsterPool();
	PositionPool();
	ItemPool();
	CreateDoorTeleport();
	CreateDoorBossTeleport();
	CreateRock();
	CreateItem();
}

void CSceneStage01::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\Isaac_Stage_tile");

	SOUND->Play(pBGMSound, 0.3f, false);
	SOUND->Pause(pBossRoomSound);
	SOUND->Pause(pBossClearSound);
}

void CSceneStage01::Update()
{
	WhatRoomClear();
	SpawnRoom();
	CheckRoomClear();
	StartBossLoading();
	StartBossSound();
	CreateEndingChest();
	CreateItems();

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

	if (pEndingChest != nullptr)
	{
		if (true == pEndingChest->GetTouch())
		{
			CHANGESCENE(GroupScene::Ending);
		}
	}
}

void CSceneStage01::Render()
{
}

void CSceneStage01::Exit()
{
	for (int layer = 0; layer < (int)Layer::Size; layer++)
	{
		for (CGameObject* pGameObject : m_listObj[layer])
		{
			pGameObject->GetReserveDelete();
			delete pGameObject;
			SOUND->Pause(pCurSound);
		}
		m_listObj[layer].clear();
	}
	Init();
}

void CSceneStage01::Release()
{
}

