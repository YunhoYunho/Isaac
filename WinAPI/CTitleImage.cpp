#include "framework.h"
#include "CTitleImage.h"

CTitleImage::CTitleImage()
{
	m_layer = Layer::Title;
	m_pTitleImage = nullptr;
}

CTitleImage::~CTitleImage()
{
}

void CTitleImage::Init()
{
	m_pTitleImage = RESOURCE->LoadImg(L"TitleImage", L"Image\\SCENE\\Scene_Title.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"TitleImage", m_pTitleImage, Vector(0.f, 0.f), Vector(1280.f, 720.f), Vector(1280.f, 0.f), 0.2f, 2);
	m_pAnimator->Play(L"TitleImage");
	AddComponent(m_pAnimator);
}

void CTitleImage::Update()
{
}

void CTitleImage::Render()
{
}

void CTitleImage::Release()
{
}
