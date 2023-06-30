#include "framework.h"
#include "CLoadingImage.h"

CLoadingImage::CLoadingImage()
{
	m_layer = Layer::Loading;
	m_pLoadingImage = nullptr;
	pBossLoadingSound = nullptr;
}

CLoadingImage::~CLoadingImage()
{
}

void CLoadingImage::Init()
{
	m_pLoadingImage = RESOURCE->LoadImg(L"Loading", L"Image\\Scene\\Scene_Boss.png");
	pBossLoadingSound = RESOURCE->LoadSound(L"BossLoading", L"Sound\\Scene\\Loading.wav");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"LoadingImage", m_pLoadingImage, Vector(0.f, 0.f), Vector(1280.f, 720.f), Vector(1280.f, 0.f), 0, 1);
	m_pAnimator->Play(L"LoadingImage");
	AddComponent(m_pAnimator);
	SOUND->Play(pBossLoadingSound, 0.7f, false);
}

void CLoadingImage::Update()
{
	m_fTimer += DT;

	if (m_fTimer > 2.0f)
	{
		DELETEOBJECT(this);
		m_fTimer = 0;
	}
}

void CLoadingImage::Render()
{
}

void CLoadingImage::Release()
{
}
