#include "framework.h"
#include "CSLoadingImage.h"

CSLoadingImage::CSLoadingImage()
{
	m_layer = Layer::Loading;
	m_pLoadingImage = nullptr;
}

CSLoadingImage::~CSLoadingImage()
{
}

void CSLoadingImage::Init()
{
	m_pLoadingImage = RESOURCE->LoadImg(L"Loading", L"Image\\SCENE\\Scene_Stage.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"LoadingImage", m_pLoadingImage, Vector(0.f, 0.f), Vector(1280.f, 720.f), Vector(1280.f, 0.f), 0.2f, 2);
	m_pAnimator->Play(L"LoadingImage");
	AddComponent(m_pAnimator);
}

void CSLoadingImage::Update()
{
}

void CSLoadingImage::Render()
{
}

void CSLoadingImage::Release()
{
}
