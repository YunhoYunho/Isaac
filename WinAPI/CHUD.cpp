#include "framework.h"
#include "CHUD.h"

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
	
	wstring curBomb;
	curBomb = Util::WStringFormat(L"%02d", PLAYERBOMB);	

	wstring curKey;
	curKey = Util::WStringFormat(L"%02d", PLAYERKEY);

	RENDER->Text(curBomb, 230, 160, 50, 50, Color(255, 255, 255, 1), 30.0f);
	RENDER->Text(curKey, 230, 260, 50, 50, Color(255, 255, 255, 1), 30.0f);

	Logger::Debug(curBomb);
}

void CHUD::Release()
{
}
