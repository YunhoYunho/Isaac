#include "framework.h"
#include "CMonsterMissile.h"

CMonsterMissile::CMonsterMissile()
{
	m_vecScale = Vector(10, 10);
	m_vecDir = Vector(0, 0);
	m_fVelocity = 300;
	m_layer = Layer::MonsterMissile;
	m_strName = L"MonsterMissile";
	m_pTearsImage = nullptr;
	m_fVelocity = 300.0f;
	m_fTimer;
	m_fMTimer = 0;
	m_fGravity = -100.0f;
	m_fZSpeed = 0.0f;
	m_fHeight = 20.0f;
	m_bIsHit = false;
}

CMonsterMissile::~CMonsterMissile()
{
}

void CMonsterMissile::Init()
{
	m_pTearsImage = RESOURCE->LoadImg(L"MonsterTears", L"Image\\Effect\\Monster_Tears.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"None", m_pTearsImage, Vector(0.f, 0.f), Vector(64.f, 64.f), Vector(64.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"Hit", m_pTearsImage, Vector(0.f, 0.f), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.05f, 14, false);
	m_pAnimator->Play(L"None");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Circle, Vector(8, 8), Vector(0, 0));
}

void CMonsterMissile::Update()
{
	Shot();
	CheckMissile();
	DeleteMissile();
}

void CMonsterMissile::Render()
{
}

void CMonsterMissile::Release()
{
}

void CMonsterMissile::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Wall" ||
		pOtherCollider->GetObjName() == L"DoorCollider" ||
		pOtherCollider->GetObjName() == L"Rock" ||
		pOtherCollider->GetObjName() == L"Player" ||
		pOtherCollider->GetObjName() == L"ShieldMissile")
	{
		Hit();
	}
}