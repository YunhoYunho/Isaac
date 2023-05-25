#include "framework.h"
#include "CBomb.h"

CBomb::CBomb()
{
	m_vecScale = Vector(10, 10);
	m_layer = Layer::Bomb;
	m_strName = L"ÆøÅº";
	
	m_pBombImage = nullptr;
	m_pSparkImage = nullptr;

	m_fCooltime = 0;
}

CBomb::~CBomb()
{
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

	AddCollider(ColliderType::Circle, Vector(8, 8), Vector(0, 0));
}

void CBomb::Update()
{
	m_fCooltime += DT;

	if (m_fCooltime > 3.0f)
	{
		m_pBombAnimator->Stop();
		m_pSparkAnimator->Stop();
	}
}

void CBomb::Render()
{
}

void CBomb::Release()
{
}

void CBomb::OnCollisionEnter(CCollider* pOtherCollider)
{
}
