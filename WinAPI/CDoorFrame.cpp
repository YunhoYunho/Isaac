#include "framework.h"
#include "CDoorFrame.h"

CDoorFrame::CDoorFrame()
{
	m_layer = Layer::DoorFrame;
	m_pNLFrameImage = nullptr;
	m_pNRFrameImage = nullptr;
	m_pBLFrameImage = nullptr;
	m_pBRFrameImage = nullptr;
	m_pDFrameImage = nullptr;
	m_pUFrameImage = nullptr;
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

	m_pDFrameImage = RESOURCE->LoadImg(L"DownFrame", L"Image\\Map\\RV_Door_Frame.png");
	m_pUFrameImage = RESOURCE->LoadImg(L"UpFrame", L"Image\\Map\\Door_Frame.png");
}

void CDoorFrame::Update()
{
}

void CDoorFrame::Render()
{
	RENDER->Image(m_pNRFrameImage, 1125, 308, 1195, 412);
	RENDER->Image(m_pNLFrameImage, 1390, 308, 1460, 412);

	RENDER->Image(m_pNRFrameImage, 1125, 1028, 1195, 1132);
	RENDER->Image(m_pNLFrameImage, 1390, 1028, 1460, 1132);

	RENDER->Image(m_pBRFrameImage, 2330, 286, 2483, 434);
	RENDER->Image(m_pBLFrameImage, 2655, 286, 2808, 434);

	RENDER->Image(m_pDFrameImage, 588, 565, 692, 635);
	RENDER->Image(m_pUFrameImage, 588, 802, 692, 872);
	
	RENDER->Image(m_pDFrameImage, 1866, 565, 1970, 635);
	RENDER->Image(m_pUFrameImage, 1866, 802, 1970, 872);
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
