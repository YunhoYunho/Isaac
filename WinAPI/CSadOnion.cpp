#include "framework.h"
#include "CSadOnion.h"

#include "CPlayer.h"

CSadOnion::CSadOnion()
{
	m_layer = Layer::PassiveItem;
	m_strName = L"SadOnion";

	m_pSadOnionImage = nullptr;

	m_fTimer = 0;
	m_bIsGetItem = false;
}

CSadOnion::~CSadOnion()
{
}

void CSadOnion::Activate(CPlayer* pPlayer)
{
	float shotSpeed = pPlayer->GetShotSpeed();

	if (shotSpeed > 0.1f)
	{
		pPlayer->SetShotSpeed(shotSpeed - 0.3f);
	}
}

void CSadOnion::Init()
{
	m_pSadOnionImage = RESOURCE->LoadImg(L"SadOnion,", L"Image\\Item\\SadOnion.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"SadOnion", m_pSadOnionImage, Vector(0.0f, 0.0f), Vector(80.0f, 80.0f), Vector(80.0f, 0.0f), 0, 1, false);

	m_pAnimator->Play(L"SadOnion");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
}

void CSadOnion::Update()
{
	GetItem();
}

void CSadOnion::Render()
{
}

void CSadOnion::Release()
{
}

void CSadOnion::OnCollisionEnter(CCollider* pOtherCollider)
{
	CheckColl(pOtherCollider);
}

void CSadOnion::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CSadOnion::OnCollisionExit(CCollider* pOtherCollider)
{
}
