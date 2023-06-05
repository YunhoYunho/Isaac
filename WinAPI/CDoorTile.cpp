#include "framework.h"
#include "CDoorTile.h"

CDoorTile::CDoorTile()
{
	m_vecScale = Vector(200, 100);
	m_layer = Layer::Tile;
	m_strName = L"DoorCollider";
	dir = CollisionDir::None;
	offset = 0.25f;
}

CDoorTile::~CDoorTile()
{
}

void CDoorTile::Init()
{
	CTile::Init();

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

	switch (dir)
	{
	case CollisionDir::Up:
	{
		RENDER->Text(
			L"Up",
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
		);
	}
	break;

	case CollisionDir::Down:
	{
		RENDER->Text(
			L"Down",
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
		);
	}
	break;

	case CollisionDir::Left:
	{
		RENDER->Text(
			L"Left",
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
		);
	}
	break;

	case CollisionDir::Right:
	{
		RENDER->Text(
			L"Right",
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
		);
	}
	break;

	case CollisionDir::None:
	{
		RENDER->Text(
			L"",
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
		);
	}
	break;
	}
}

void CDoorTile::Release()
{
	CTile::Release();
}

void CDoorTile::OnCollisionEnter(CCollider* pOther)
{
}

void CDoorTile::OnCollisionStay(CCollider* pOther)
{
	if ((INROOM1 && (false == ROOM1CLEAR)) || (INROOM2 && (false == ROOM2CLEAR)))
	{
		// 땅타일과 충돌했을 경우 처리
		if (pOther->GetObjName() == L"Player" 
			|| pOther->GetObjName() == L"Monster"
			|| pOther->GetObjName() == L"Gish")
		{
			PushObject(pOther);
		}
	}
	
}

void CDoorTile::OnCollisionExit(CCollider* pOther)
{
}
