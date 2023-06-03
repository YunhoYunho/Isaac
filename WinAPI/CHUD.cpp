#include "framework.h"
#include "CHUD.h"

#pragma region HUD
#define ROOM1B	240, 160, 50, 50, Color(255, 255, 255, 1), 30.0f
#define ROOM1K	240, 250, 50, 50, Color(255, 255, 255, 1), 30.0f
#define ROOM2B	2800, 160, 50, 50, Color(255, 255, 255, 1), 30.0f
#define ROOM2K	2800, 250, 50, 50, Color(255, 255, 255, 1), 30.0f
#define ROOM3B	5360, 160, 50, 50, Color(255, 255, 255, 1), 30.0f
#define ROOM3K	5360, 250, 50, 50, Color(255, 255, 255, 1), 30.0f
#pragma endregion

CHUD::CHUD()
{
	m_layer = Layer::HUD;
	m_pHUDImage = nullptr;
}

CHUD::~CHUD()
{
}

void CHUD::Init()
{
	m_pHUDImage = RESOURCE->LoadImg(L"HUD", L"Image\\Map\\Icon.png");
}

void CHUD::Update()
{
}

void CHUD::Render()
{
	RENDER->Image(m_pHUDImage, 80, 80, 130, 180);
	RENDER->Image(m_pHUDImage, 1360, 80, 1410, 180);
	RENDER->Image(m_pHUDImage, 2640, 80, 2690, 180);
	
	wstring curBomb;
	curBomb = Util::WStringFormat(L"%02d", PLAYERBOMB);	

	wstring curKey;
	curKey = Util::WStringFormat(L"%02d", PLAYERKEY);

	if (INROOM1)
	{
		RENDER->Text(curBomb, ROOM1B);
		RENDER->Text(curKey, ROOM1K);
	}

	if (INROOM2)
	{
		RENDER->Text(curBomb, ROOM2B);
		RENDER->Text(curKey, ROOM2K);
	}

	if (INROOM3)
	{
		RENDER->Text(curBomb, ROOM3B);
		RENDER->Text(curKey, ROOM3K);
	}
}

void CHUD::Release()
{
}
