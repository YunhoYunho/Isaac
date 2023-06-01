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
	m_pGLCloseImage = nullptr;
	m_pGLOpenImage  = nullptr;
	m_pGRCloseImage = nullptr;
	m_pGROpenImage  = nullptr;
}

CDoorControl::~CDoorControl()
{
}

void CDoorControl::Init()
{
	m_pNLCloseImage = RESOURCE->LoadImg(L"LDoorClose", L"Image\\Map\\L_Door_Close.png");
	m_pNLOpenImage = RESOURCE->LoadImg(L"LDoorOpen", L"Image\\Map\\L_Door_Open.png");
	m_pNRCloseImage = RESOURCE->LoadImg(L"RDoorClose", L"Image\\Map\\R_Door_Close.png");
	m_pNROpenImage = RESOURCE->LoadImg(L"RDoorOpen", L"Image\\Map\\R_Door_Open.png");

	m_pGLCloseImage = RESOURCE->LoadImg(L"LBossClose", L"Image\\Map\\L_Boss_Close.png");
	m_pGLOpenImage = RESOURCE->LoadImg(L"LBossOpen", L"Image\\Map\\L_Boss_Open.png");
	m_pGRCloseImage = RESOURCE->LoadImg(L"RBossClose", L"Image\\Map\\R_Boss_Close.png");
	m_pGROpenImage = RESOURCE->LoadImg(L"RBossOpen", L"Image\\Map\\R_Boss_Open.png");
}

void CDoorControl::Update()
{
}

void CDoorControl::Render()
{
#pragma region Stage01
	RENDER->Image(m_pNRCloseImage, 1125, 308, 1195, 412);
	RENDER->Image(m_pNROpenImage, 1125, 308, 1195, 412);
	RENDER->Image(m_pNLCloseImage, 1390, 308, 1460, 412);
	RENDER->Image(m_pNLOpenImage, 1390, 308, 1195, 412);

	RENDER->Image(m_pGRCloseImage, 2330, 286, 2483, 434);
	RENDER->Image(m_pGROpenImage, 2330, 286, 2483, 434);
	RENDER->Image(m_pGLCloseImage, 2655, 302, 2808, 450);
	RENDER->Image(m_pGLOpenImage, 2655, 302, 2808, 450);
#pragma endregion
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
