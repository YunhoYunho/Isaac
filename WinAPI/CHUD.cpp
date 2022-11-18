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
	m_pHUDImage = RESOURCE->LoadImg(L"HUD", L"Image\\Map\\HUD.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"HUD", m_pHUDImage, Vector(0.f, 0.f), Vector(1280.f, 720.f), Vector(1280.f, 0.f), 0, 1);
	m_pAnimator->Play(L"HUD");
	AddComponent(m_pAnimator);
}

void CHUD::Update()
{
}

void CHUD::Render()
{
}

void CHUD::Release()
{
}
