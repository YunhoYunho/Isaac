#include "framework.h"
#include "CShieldMissile.h"
#include "CMonster.h"
#include "CMonsterMissile.h"

CShieldMissile::CShieldMissile()
{
	m_vecScale = Vector(10, 10);
	m_vecDir = Vector(0, 0);
	m_layer = Layer::ShieldMissile;
	m_strName = L"ShieldMissile";
	m_pTearsImage = nullptr;
	m_fVelocity = 300;
	m_fTimer;
	m_fMTimer = 0;
	m_fGravity = -100.0f;
	m_fZSpeed = 0.0f;
	m_fHeight = 20.0f;
	m_bIsHit = false;
}

CShieldMissile::~CShieldMissile()
{
}

void CShieldMissile::Init()
{
	m_pTearsImage = RESOURCE->LoadImg(L"IsaacTears", L"Image\\Effect\\Isaac_Shield_Tears.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"None_Shield", m_pTearsImage, Vector(0.f, 0.f), Vector(64.f, 64.f), Vector(64.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"Hit", m_pTearsImage, Vector(64.f, 0.f), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.05f, 14, false);
	m_pAnimator->Play(L"None_Shield");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Circle, Vector(9, 9), Vector(0, 0));
}

void CShieldMissile::Update()
{
	Shot();
	CheckMissile();
	DeleteMissile();
}

void CShieldMissile::Render()
{
}

void CShieldMissile::Release()
{
}

void CShieldMissile::OnCollisionEnter(CCollider* pOtherCollider)
{
	UsePlayerCollider(pOtherCollider);

	if (pOtherCollider->GetOwner()->GetLayer() == Layer::MonsterMissile)
	{
		CMonsterMissile* pMonsterMissile = (CMonsterMissile*)(pOtherCollider->GetOwner());
		DELETEOBJECT(pMonsterMissile);
	}
}
