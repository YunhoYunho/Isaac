#include "framework.h"
#include "CMissile.h"

#include "CRenderManager.h"
#include "CTimeManager.h"
#include "CEventManager.h"
#include "CCollider.h"

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

void CMissile::Init()
{
}

void CMissile::Update()
{
}

void CMissile::Fire()
{
	m_vecPos += m_vecDir * m_fVelocity * DT;
}

void CMissile::DeleteMissile()
{
	Vector pos;
	pos = CAMERA->GetLookAt();

	if (m_vecPos.x < pos.x - 720 ||
		m_vecPos.x > pos.x + 720 ||
		m_vecPos.y < 0 ||
		m_vecPos.y > WINSIZEY)
		DELETEOBJECT(this);
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
