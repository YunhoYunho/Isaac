#include "framework.h"
#include "CDoorFrame.h"

CDoorFrame::CDoorFrame()
{
	m_layer = Layer::DoorFrame;
	m_pNLFrameImage = nullptr;
	m_pNRFrameImage = nullptr;
	m_pGLFrameImage = nullptr;
	m_pGRFrameImage = nullptr;
}

CDoorFrame::~CDoorFrame()
{
}

void CDoorFrame::Init()
{
	m_pNLFrameImage = RESOURCE->LoadImg(L"LDoorFrame", L"Image\\Map\\L_Door_Frame.png");
	m_pNRFrameImage = RESOURCE->LoadImg(L"RDoorFrame", L"Image\\Map\\R_Door_Frame.png");

	m_pGLFrameImage = RESOURCE->LoadImg(L"LBossFrame", L"Image\\Map\\L_Boss_Frame.png");
	m_pGRFrameImage = RESOURCE->LoadImg(L"RBossFrame", L"Image\\Map\\R_Boss_Frame.png");
}

void CDoorFrame::Update()
{
}

void CDoorFrame::Render()
{
	RENDER->Image(m_pNRFrameImage, 1125, 308, 1195, 412);
	RENDER->Image(m_pNLFrameImage, 1390, 308, 1460, 412);

	RENDER->Image(m_pGRFrameImage, 2330, 286, 2483, 434);
	RENDER->Image(m_pGLFrameImage, 2655, 302, 2808, 450);
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
