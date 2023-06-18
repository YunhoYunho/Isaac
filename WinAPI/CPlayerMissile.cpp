#include "framework.h"
#include "CPlayerMissile.h"
#include "CMonster.h"

CPlayerMissile::CPlayerMissile()
{
	m_vecScale = Vector(10, 10);
	m_vecDir = Vector(0, 0);
	m_fVelocity = 300;
	m_layer = Layer::PlayerMissile;
	m_strName = L"PlayerMissile";

	m_pTearsImage = nullptr;

	m_fCooltime = 0;
	m_bIsHit = false;
	m_fDamage = 3.0f;
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
	Fire();
	CheckDestroyMissile();
}

void CPlayerMissile::Render()
{
}

void CPlayerMissile::Release()
{
}

void CPlayerMissile::CheckDestroyMissile()
{
	if (true == m_bIsHit)
	{
		m_fCooltime += DT;

		if (m_fCooltime > 0.7f)
		{
			DELETEOBJECT(this);
			//Logger::Debug(L"º®¿¡ ºÎµúÇô ´«¹° »èÁ¦");
		}
	}
}

void CPlayerMissile::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Wall" ||
		pOtherCollider->GetObjName() == L"DoorCollider" ||
		pOtherCollider->GetObjName() == L"Rock")
	{
		m_pAnimator->Play(L"Hit");
		m_fVelocity = 0;
		m_bIsHit = true;
	}

	if (pOtherCollider->GetOwner()->GetLayer() == Layer::Monster)
	{
		CMonster* pMonster = (CMonster*)(pOtherCollider->GetOwner());
		pMonster->GetDamaged(m_fDamage);

		DELETEOBJECT(this);
	}
}
