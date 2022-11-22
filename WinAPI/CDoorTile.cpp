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
	// 문과 충돌했을 경우 처리
}

void CDoorTile::OnCollisionStay(CCollider* pOther)
{
	// 문과 충돌했을 경우 처리
}

void CDoorTile::OnCollisionExit(CCollider* pOther)
{
	// 문과 충돌했을 경우 처리
}
