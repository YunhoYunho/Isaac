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
}

CMonsterMissile::~CMonsterMissile()
{
}

void CMonsterMissile::Init()
{
	m_pTearsImage = RESOURCE->LoadImg(L"MonsterTears", L"Image\\Effect\\Monster_Tears.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"None", m_pTearsImage, Vector(0.f, 0.f), Vector(64.f, 64.f), Vector(64.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"Hit", m_pTearsImage, Vector(0.f, 0.f), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1f, 14, false);
	m_pAnimator->Play(L"None");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Circle, Vector(8, 8), Vector(0, 0));
}

void CMonsterMissile::Update()
{
	Fire();
}

void CMonsterMissile::Render()
{
}

void CMonsterMissile::Release()
{
}

void CMonsterMissile::OnCollisionEnter(CCollider* pOtherCollider)
{
	//Logger::Debug(L"미사일이 충돌체와 부딪혀 사라집니다.");
	DELETEOBJECT(this);
}

void CMonsterMissile::SetDir(Vector dir)
{
	m_vecDir = dir.Normalized();
}

void CMonsterMissile::SetVelocity(float velocity)
{
	m_fVelocity = velocity;
}