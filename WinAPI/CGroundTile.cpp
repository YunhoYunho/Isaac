#include "framework.h"
#include "CGroundTile.h"

#include "CResourceManager.h"
#include "CRenderManager.h"
#include "CCollider.h"
#include "CObstacle.h"

#include "CPlayer.h"
#include "CMonster.h"

CGroundTile::CGroundTile()
{
}

CGroundTile::~CGroundTile()
{
}

void CGroundTile::Init()
{
	CTile::Init();

	m_strName = L"Wall";
	m_layer = Layer::GroundTile;

	AddCollider(ColliderType::Rect,
		Vector(CTile::TILESIZE, CTile::TILESIZE),
		Vector(CTile::TILESIZE / 2, CTile::TILESIZE / 2));
}

void CGroundTile::Update()
{
	CTile::Update();
}

void CGroundTile::Render()
{
	CTile::Render();

	ComponentRender();
}

void CGroundTile::Release()
{
	CTile::Release();
}

void CGroundTile::OnCollisionEnter(CCollider* pOther)
{
	// ��Ÿ�ϰ� �浹���� ��� ó��
}

void CGroundTile::OnCollisionStay(CCollider* pOther)
{
	// ��Ÿ�ϰ� �浹���� ��� ó��
	if (pOther->GetObjName() == L"�÷��̾�")
	{
		CObstacle* OnCollisionStay();
	}

	if (pOther->GetObjName() == L"Boomfly")
	{
		CObstacle* OnCollisionStay();
	}
}

void CGroundTile::OnCollisionExit(CCollider* pOther)
{
	// ��Ÿ�ϰ� �浹���� ��� ó��
}
