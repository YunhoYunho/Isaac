#include "framework.h"
#include "CDoorFrame.h"

CDoorFrame::CDoorFrame()
{
	m_layer = Layer::DoorFrame;
	m_pNLFrameImage = nullptr;
	m_pNRFrameImage = nullptr;
	m_pBLFrameImage = nullptr;
	m_pBRFrameImage = nullptr;
}

CDoorFrame::~CDoorFrame()
{
}

void CDoorFrame::Init()
{
	m_pNLFrameImage = RESOURCE->LoadImg(L"LDoorFrame", L"Image\\Map\\L_Door_Frame.png");
	m_pNRFrameImage = RESOURCE->LoadImg(L"RDoorFrame", L"Image\\Map\\R_Door_Frame.png");

	m_pBLFrameImage = RESOURCE->LoadImg(L"LBossFrame", L"Image\\Map\\L_Boss_Frame.png");
	m_pBRFrameImage = RESOURCE->LoadImg(L"RBossFrame", L"Image\\Map\\R_Boss_Frame.png");
}

void CDoorFrame::Update()
{
}

void CDoorFrame::Render()
{
	RENDER->Image(m_pNRFrameImage, 1125, 308, 1195, 412);
	RENDER->Image(m_pNLFrameImage, 1390, 308, 1460, 412);

	RENDER->Image(m_pBRFrameImage, 2330, 286, 2483, 434);
	RENDER->Image(m_pBLFrameImage, 2655, 286, 2808, 434);
}

void CDoorFrame::Release()
{
}

void CDoorFrame::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CDoorFrame::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CDoorFrame::OnCollisionExit(CCollider* pOtherCollider)
{
}
