#include "framework.h"
#include "CPlayerHP.h"

CPlayerHP::CPlayerHP()
{
	m_layer = Layer::Player;
	m_pPlayerHP1Image = nullptr;
	m_pPlayerHP2Image = nullptr;
	m_pPlayerHP3Image = nullptr;
}

CPlayerHP::~CPlayerHP()
{
}

void CPlayerHP::Init()
{
	m_pPlayerHP1Image = RESOURCE->LoadImg(L"PlayerHP1,", L"Image\\Map\\1Heart.png");
	m_pPlayerHP2Image = RESOURCE->LoadImg(L"PlayerHP2,", L"Image\\Map\\2Heart.png");
	m_pPlayerHP3Image = RESOURCE->LoadImg(L"PlayerHP3,", L"Image\\Map\\3Heart.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"PlayerHP1", m_pPlayerHP1Image, Vector(0, 0), Vector(45, 45), Vector(45, 0), 0, 1);
	m_pAnimator->CreateAnimation(L"PlayerHP2", m_pPlayerHP2Image, Vector(0, 0), Vector(90, 45), Vector(90, 0), 0, 1);
	m_pAnimator->CreateAnimation(L"PlayerHP3", m_pPlayerHP3Image, Vector(0, 0), Vector(135, 45), Vector(135, 0), 0, 1);
	
	m_pAnimator->Play(L"PlayerHP3");
	AddComponent(m_pAnimator);
}

void CPlayerHP::Update()
{
}

void CPlayerHP::Render()
{
}

void CPlayerHP::Release()
{
}
