#include "framework.h"
#include "CMissile.h"

#include "CMonster.h"

CMissile::CMissile()
{
	m_vecScale = Vector(10, 10);
	m_vecDir = Vector(0, 0);
	m_fVelocity = 300;
	m_layer = Layer::Missile;
	m_strName = L"¹Ì»çÀÏ";
}

CMissile::~CMissile()
{
}

void CMissile::Shot()
{
	m_fMTimer += DT;

	Fire();

	if (m_fMTimer > 0.3f)
	{
		m_fZSpeed += m_fGravity * DT;
		m_fHeight += m_fZSpeed * DT;
		m_vecPos.y -= m_fZSpeed * DT;

		if (m_fHeight < 0)
		{
			Hit();
		}
	}
}

void CMissile::Fire()
{
	m_vecPos += m_vecDir * m_fVelocity * DT;
}

void CMissile::Hit()
{
	m_pAnimator->Play(L"Hit");
	m_fZSpeed = 0;
	m_fVelocity = 0;
	m_bIsHit = true;
}

void CMissile::CheckMissile()
{
	if (true == m_bIsHit)
	{
		m_fTimer += DT;

		if (m_fTimer > 0.7f)
		{
			DELETEOBJECT(this);
		}
	}
}

void CMissile::DeleteMissile()
{
	Vector pos;
	pos = CAMERA->GetLookAt();

	if (m_vecPos.x < pos.x - 720 ||
		m_vecPos.x > pos.x + 720 ||
		m_vecPos.y < pos.y - 720 ||
		m_vecPos.y > pos.y + 720)
		DELETEOBJECT(this);
}

void CMissile::UsePlayerCollider(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Wall" ||
		pOtherCollider->GetObjName() == L"DoorCollider" ||
		pOtherCollider->GetObjName() == L"Rock" ||
		pOtherCollider->GetObjName() == L"Bomb")
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

void CMissile::Init()
{
}

void CMissile::Update()
{
}

void CMissile::Render()
{
	RENDER->FrameCircle(
		m_vecPos.x,
		m_vecPos.y,
		m_vecScale.x);
}

void CMissile::Release()
{
}

void CMissile::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CMissile::SetDir(Vector dir)
{
	m_vecDir = dir.Normalized();
}

void CMissile::SetVelocity(float velocity)
{
	m_fVelocity = velocity;
}
