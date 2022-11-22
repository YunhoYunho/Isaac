#include "framework.h"
#include "CDoorTile.h"

#include "CResourceManager.h"
#include "CRenderManager.h"
#include "CCollider.h"

#include "CPlayer.h"
#include "CMonster.h"

CDoorTile::CDoorTile()
{
}

CDoorTile::~CDoorTile()
{
}

void CDoorTile::Init()
{
	CTile::Init();

	m_strName = L"Wall";
	m_layer = Layer::Door;

	AddCollider(ColliderType::Rect,
		Vector(CTile::TILESIZE, CTile::TILESIZE),
		Vector(CTile::TILESIZE / 2, CTile::TILESIZE / 2));
}

void CDoorTile::Update()
{
	CTile::Update();
}

void CDoorTile::Render()
{
	CTile::Render();

	ComponentRender();
}

void CDoorTile::Release()
{
	CTile::Release();
}

void CDoorTile::OnCollisionEnter(CCollider* pOther)
{
	// ���� �浹���� ��� ó��
}

void CDoorTile::OnCollisionStay(CCollider* pOther)
{
	// ���� �浹���� ��� ó��
}

void CDoorTile::OnCollisionExit(CCollider* pOther)
{
	// ���� �浹���� ��� ó��
}
