#include "framework.h"
#include "CEndingImage.h"

CEndingImage::CEndingImage()
{
	m_layer = Layer::Ending;
	m_pEnding1Image = nullptr;
	m_pEnding2Image = nullptr;
	fCooltime = 0;
}

CEndingImage::~CEndingImage()
{
}

void CEndingImage::Init()
{
	m_pEnding1Image = RESOURCE->LoadImg(L"Endings1", L"Image\\SCENE\\End1.png");
	m_pEnding2Image = RESOURCE->LoadImg(L"Endings2", L"Image\\SCENE\\End2.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Ending1Image", m_pEnding1Image, Vector(0.f, 0.f), Vector(1280.f, 720.f), Vector(1280.f, 0.f), 0.2f, 2, true);
	m_pAnimator->CreateAnimation(L"Ending2Image", m_pEnding2Image, Vector(0.f, 0.f), Vector(1280.f, 720.f), Vector(1280.f, 0.f), 1.0f, 2, false);

	m_pAnimator->Play(L"Ending1Image");
	AddComponent(m_pAnimator);
}

void CEndingImage::Update()
{
	fCooltime += DT;

	if (fCooltime > 3.0f)
	{
		m_pAnimator->Stop();
		m_pAnimator->Play(L"Ending2Image");
		fCooltime = 0;
	}
}

void CEndingImage::Render()
{
}

void CEndingImage::Release()
{
}
