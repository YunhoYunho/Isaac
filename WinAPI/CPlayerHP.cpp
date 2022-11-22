#include "framework.h"
#include "CPlayerHP.h"

#include "CPlayer.h"

CPlayerHP::CPlayerHP()
{
	m_layer = Layer::HUD;
	m_strName = L"HUD";

	m_pPlayerHPImage = nullptr;
}

CPlayerHP::~CPlayerHP()
{
}

void CPlayerHP::Init()
{
	m_pPlayerHPImage = RESOURCE->LoadImg(L"PlayerHP,", L"Image\\Map\\3Heart.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"PlayerHP0", m_pPlayerHPImage, Vector(0.f, 0.f), Vector(  1.f,  1.f), Vector(  1.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"PlayerHP1", m_pPlayerHPImage, Vector(0.f, 0.f), Vector( 45.f, 45.f), Vector( 45.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"PlayerHP2", m_pPlayerHPImage, Vector(0.f, 0.f), Vector( 90.f, 45.f), Vector( 90.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"PlayerHP3", m_pPlayerHPImage, Vector(0.f, 0.f), Vector(135.f, 45.f), Vector(135.f, 0.f), 0, 1);

	AddComponent(m_pAnimator);
}

void CPlayerHP::Update()
{
	m_playerHP = PLAYERHP;

	switch (m_playerHP)
	{
	case 3:
		m_pAnimator->Play(L"PlayerHP3");
		break;
	case 2:
		m_pAnimator->Play(L"PlayerHP2");
		break;
	case 1:
		m_pAnimator->Play(L"PlayerHP1");
		break;
	case 0:
		m_pAnimator->Play(L"PlayerHP0");
	}
}

void CPlayerHP::Render()
{
}

void CPlayerHP::Release()
{
}
