#include "framework.h"
#include "CPlayerMissile.h"
#include "CMonster.h"

CPlayerMissile::CPlayerMissile()
{
	m_vecScale = Vector(10, 10);
	m_vecDir = Vector(0, 0);
	m_layer = Layer::PlayerMissile;
	m_strName = L"PlayerMissile";
	m_pTearsImage = nullptr;
	m_fVelocity = 300;
	m_fTimer;
	m_fMTimer = 0;
	m_fGravity = -100.0f;
	m_fZSpeed = 0.0f;
	m_fHeight = 20.0f;
	m_bIsHit = false;
}

CPlayerMissile::~CPlayerMissile()
{
}

void CPlayerMissile::Init()
{
	m_pTearsImage = RESOURCE->LoadImg(L"IsaacTears", L"Image\\Effect\\Isaac_Tears.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"None", m_pTearsImage, Vector(0.f, 0.f), Vector(64.f, 64.f), Vector(64.f, 0.f), 0, 1);
	m_pAnimator->CreateAnimation(L"Hit",  m_pTearsImage, Vector(0.f, 0.f), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.05f, 14, false);
	m_pAnimator->Play(L"None");

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Circle, Vector(8, 8), Vector(0, 0));
}

void CPlayerMissile::Update()
{
	Shot();
	CheckMissile();
	DeleteMissile();
}

void CPlayerMissile::Render()
{
}

void CPlayerMissile::Release()
{
}

void CPlayerMissile::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Wall" ||
		pOtherCollider->GetObjName() == L"DoorCollider" ||
		pOtherCollider->GetObjName() == L"Rock" ||
		pOtherCollider->GetObjName() == L"ÆøÅº")
	{
		Hit();
	}

	if (pOtherCollider->GetOwner()->GetLayer() == Layer::Monster)
	{
		CMonster* pMonster = (CMonster*)(pOtherCollider->GetOwner());
		pMonster->GetDamaged(PLAYERDAMAGE);
		Logger::Debug(to_wstring(PLAYERDAMAGE));
		DELETEOBJECT(this);
	}
}
