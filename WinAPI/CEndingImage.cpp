#include "framework.h"
#include "CEndingImage.h"

CEndingImage::CEndingImage()
{
	m_layer = Layer::Title;
	m_pEndingImage = nullptr;
}

CEndingImage::~CEndingImage()
{
}

void CEndingImage::Init()
{
	m_pEndingImage = RESOURCE->LoadImg(L"EndingImage", L"Image\\Scene_Ending.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"TitleImage", m_pEndingImage, Vector(0.f, 0.f), Vector(1280.f, 720.f), Vector(1280.f, 0.f), 0.2f, 2);
	m_pAnimator->Play(L"TitleImage");
	AddComponent(m_pAnimator);
}

void CEndingImage::Update()
{
}

void CEndingImage::Render()
{
}

void CEndingImage::Release()
{
}
