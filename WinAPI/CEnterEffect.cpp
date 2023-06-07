#include "framework.h"
#include "CEnterEffect.h"

CEnterEffect::CEnterEffect()
{
	m_layer = Layer::EnterEffect;
	m_strName = L"EnterEffect";

	m_pEnterEffectImage = nullptr;
	m_fCooltime = 0;
}

CEnterEffect::~CEnterEffect()
{
}

void CEnterEffect::Init()
{
	m_pEnterEffectImage = RESOURCE->LoadImg(L"EnterEffect", L"Image\\Effect\\Effect_Enter.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Enter", m_pEnterEffectImage, Vector(0.0f, 0.0f), Vector(100.0f, 100.0f), Vector(100.0f, 0.0f), 0.03f, 16, false);

	m_pAnimator->Play(L"Enter");

	AddComponent(m_pAnimator);
}

void CEnterEffect::Update()
{
	m_fCooltime += DT;

	if (m_fCooltime > 1.0f)
	{
		m_pAnimator->Stop();
		m_fCooltime = 0;

		DELETEOBJECT(this);
	}
}

void CEnterEffect::Render()
{
}

void CEnterEffect::Release()
{
}

void CEnterEffect::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CEnterEffect::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CEnterEffect::OnCollisionExit(CCollider* pOtherCollider)
{
}
