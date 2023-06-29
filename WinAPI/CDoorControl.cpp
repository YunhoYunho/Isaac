#include "framework.h"
#include "CDoorControl.h"

CDoorControl::CDoorControl()
{
	m_layer = Layer::DoorControl;
	m_strName = L"DoorControl";
	m_pNLCloseImage = nullptr;
	m_pNLOpenImage  = nullptr;
	m_pNRCloseImage = nullptr;
	m_pNROpenImage  = nullptr;
	m_pBLCloseImage = nullptr;
	m_pBLOpenImage  = nullptr;
	m_pBRCloseImage = nullptr;
	m_pBROpenImage  = nullptr;
	m_pDCloseImage = nullptr;
	m_pDOpenImage = nullptr;
	m_pUCloseImage = nullptr;
	m_pUOpenImage = nullptr;
}

CDoorControl::~CDoorControl()
{
}

void CDoorControl::RenderController()
{
#pragma region Room0
	if (true != ROOM0OPEN)
	{
		RENDER->Image(m_pDCloseImage, 588, 565, 692, 635);
		RENDER->Image(m_pUCloseImage, 588, 802, 692, 872);
		RENDER->Image(m_pNRCloseImage, 1125, 1028, 1195, 1132);
	}

	else
	{
		RENDER->Image(m_pDOpenImage, 588, 565, 692, 635);
		RENDER->Image(m_pUOpenImage, 588, 802, 692, 872);
		RENDER->Image(m_pNROpenImage, 1125, 1028, 1195, 1132);
	}
#pragma region Room1
	if (true != ROOM1CLEAR)
	{
		RENDER->Image(m_pNRCloseImage, 1125, 308, 1195, 412);
	}

	else
	{
		RENDER->Image(m_pNROpenImage, 1125, 308, 1195, 412);
	}
#pragma endregion
#pragma region Room2

	if (true != ROOM2CLEAR)
	{
		RENDER->Image(m_pNLCloseImage, 1390, 308, 1460, 412);
		RENDER->Image(m_pBRCloseImage, 2330, 286, 2483, 434);
		RENDER->Image(m_pDCloseImage, 1866, 565, 1970, 635);
	}

	else
	{
		RENDER->Image(m_pNLOpenImage, 1390, 308, 1460, 412);
		RENDER->Image(m_pBROpenImage, 2330, 286, 2483, 434);
		RENDER->Image(m_pDOpenImage, 1866, 565, 1970, 635);
	}
#pragma endregion
#pragma region BossRoom
	if (true != ROOM3CLEAR)
	{
		RENDER->Image(m_pBLCloseImage, 2655, 286, 2808, 434);
	}

	else
	{
		RENDER->Image(m_pBLOpenImage, 2655, 286, 2808, 434);
	}
#pragma endregion
#pragma region Room4
	if (true != ROOM4CLEAR)
	{
		RENDER->Image(m_pUCloseImage, 1866, 802, 1970, 872);
		RENDER->Image(m_pNLCloseImage, 1390, 1028, 1460, 1132);
	}

	else
	{
		RENDER->Image(m_pUOpenImage, 1866, 802, 1970, 872);
		RENDER->Image(m_pNLOpenImage, 1390, 1028, 1460, 1132);
	}
#pragma endregion
}

void CDoorControl::Init()
{
	m_pNLCloseImage = RESOURCE->LoadImg(L"LDoorClose", L"Image\\Map\\L_Door_Close.png");
	m_pNLOpenImage = RESOURCE->LoadImg(L"LDoorOpen", L"Image\\Map\\L_Door_Open.png");
	m_pNRCloseImage = RESOURCE->LoadImg(L"RDoorClose", L"Image\\Map\\R_Door_Close.png");
	m_pNROpenImage = RESOURCE->LoadImg(L"RDoorOpen", L"Image\\Map\\R_Door_Open.png");

	m_pBLCloseImage = RESOURCE->LoadImg(L"LBossClose", L"Image\\Map\\L_Boss_Close.png");
	m_pBLOpenImage = RESOURCE->LoadImg(L"LBossOpen", L"Image\\Map\\L_Boss_Open.png");
	m_pBRCloseImage = RESOURCE->LoadImg(L"RBossClose", L"Image\\Map\\R_Boss_Close.png");
	m_pBROpenImage = RESOURCE->LoadImg(L"RBossOpen", L"Image\\Map\\R_Boss_Open.png");

	m_pDCloseImage = RESOURCE->LoadImg(L"DownClose", L"Image\\Map\\RV_Door_Close.png");
	m_pDOpenImage = RESOURCE->LoadImg(L"DownOpen", L"Image\\Map\\RV_Door_Open.png");
	m_pUCloseImage = RESOURCE->LoadImg(L"UpClose", L"Image\\Map\\Door_Close.png");
	m_pUOpenImage = RESOURCE->LoadImg(L"UpOpen", L"Image\\Map\\Door_Open.png");
}

void CDoorControl::Update()
{
}

void CDoorControl::Render()
{
	RenderController();
}

void CDoorControl::Release()
{
}

void CDoorControl::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CDoorControl::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CDoorControl::OnCollisionExit(CCollider* pOtherCollider)
{
}
