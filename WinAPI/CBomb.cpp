#include "framework.h"
#include "CBomb.h"
#include "CExplosion.h"

CBomb::CBomb()
{
	m_vecScale = Vector(10, 10);
	m_layer = Layer::Bomb;
	m_strName = L"Bomb";
	
	m_pBombImage = nullptr;
	m_pSparkImage = nullptr;

	m_fSpeed = 500.0f;
	m_fCooltime = 0;
	m_fTimer = 0;
	m_bIsTimesUP = false;
	m_bIsPressE = false;
	m_bIsLeft = false;
	m_bIsRight = false;
	m_bIsUp = false;
	m_bIsDown = false;

}

CBomb::~CBomb()
{
}

void CBomb::BombTimer()
{
	if (true == m_bIsPressE)
	{
		m_fCooltime += DT;

		if (m_fCooltime > 3.0f)
		{
			m_pBombAnimator->Stop();
			m_pSparkAnimator->Stop();

			DELETEOBJECT(this);
			m_fCooltime = 0;
			m_bIsPressE = false;

			Boom();
		}
	}
}

void CBomb::Boom()
{
	CExplosion* pExplosion = new CExplosion();
	pExplosion->SetPos(m_vecPos);
	ADDOBJECT(pExplosion);
}

void CBomb::Init()
{
	m_pBombImage = RESOURCE->LoadImg(L"Bomb", L"Image\\Item\\Bomb.png");
	m_pSparkImage = RESOURCE->LoadImg(L"Bomb_Spark", L"Image\\Item\\Spark.png");

	m_pBombAnimator = new CAnimator;
	m_pSparkAnimator = new CAnimator;
	
	m_pBombAnimator->CreateAnimation(L"Boom", m_pBombImage, Vector(0.0f, 0.0f), Vector(46.0f, 45.0f), Vector(46.0f, 0.0f), 0.3f, 2, true);
	m_pSparkAnimator->CreateAnimation(L"Spark", m_pSparkImage, Vector(0.0f, 0.0f), Vector(47.0f, 45.0f), Vector(45.0f, 0.0f), 0.4f, 8, true);

	m_pBombAnimator->Play(L"Boom");
	m_pSparkAnimator->Play(L"Spark");

	AddComponent(m_pBombAnimator);
	AddComponent(m_pSparkAnimator);

	AddCollider(ColliderType::Circle, Vector(10, 10), Vector(0, 0));
}

void CBomb::Update()
{
	BombTimer();
}

void CBomb::Render()
{
}

void CBomb::Release()
{
}

void CBomb::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Player" ||
		pOtherCollider->GetObjName() == L"PlayerMissile")
	{
		float x = m_vecPos.x - pOtherCollider->GetPos().x;
		float y = m_vecPos.y - pOtherCollider->GetPos().y;

		if (abs(x) > abs(y))
		{
			m_vecPos.x += (x > 0 ? 1.f : -1.f) * m_fSpeed * DT;
		}
		else
		{
			m_vecPos.y += (y > 0 ? 1.f : -1.f) * m_fSpeed * DT;
		}
	}
}

void CBomb::OnCollisionStay(CCollider* pOtherCollider)
{
	
}

void CBomb::OnCollisionExit(CCollider* pOtherCollider)
{
	
}
