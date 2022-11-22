#include "framework.h"
#include "CLoadingImage.h"

CLoadingImage::CLoadingImage()
{
	m_layer = Layer::Loading;
	m_pLoadingImage = nullptr;
}

CLoadingImage::~CLoadingImage()
{
}

void CLoadingImage::Init()
{
	m_pLoadingImage = RESOURCE->LoadImg(L"Loading", L"Image\\SCENE\\Scene_Boss.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"LoadingImage", m_pLoadingImage, Vector(0.f, 0.f), Vector(1280.f, 720.f), Vector(1280.f, 0.f), 0, 1);
	m_pAnimator->Play(L"LoadingImage");
	AddComponent(m_pAnimator);
}

void CLoadingImage::Update()
{
}

void CLoadingImage::Render()
{
}

void CLoadingImage::Release()
{
}
