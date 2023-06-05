#include "framework.h"
#include "CGroundTile.h"

#include "CResourceManager.h"
#include "CRenderManager.h"
#include "CCollider.h"

#include "CPlayer.h"
#include "CMonster.h"

CGroundTile::CGroundTile()
{
	m_vecScale = Vector(200, 100);
	m_layer = Layer::Tile;
	m_strName = L"Wall";
	dir = CollisionDir::None;
	offset = 0.25f;
}

CGroundTile::~CGroundTile()
{
}

void CGroundTile::PushObject(CCollider* pOther)
{
	// Player가 충돌 중일 경우 밀어내기 연산
	CPlayer* pPlayer = static_cast<CPlayer*>(pOther->GetOwner());

	dir = GetCollisionDir(pOther);

	switch (GetCollisionDir(pOther))
	{
	case CollisionDir::Up:
	{
		pPlayer->SetPos(
			pPlayer->GetPos().x,
			GetCollider()->GetPos().y
			- (GetCollider()->GetScale().y + pOther->GetScale().y) * 0.5f + offset
			- pOther->GetOffsetPos().y
		);
	}
	break;

	case CollisionDir::Down:
	{
		pPlayer->SetPos(
			pPlayer->GetPos().x,
			GetCollider()->GetPos().y
			+ (GetCollider()->GetScale().y + pOther->GetScale().y) * 0.5f - offset
			- pOther->GetOffsetPos().y
		);
	}
	break;

	case CollisionDir::Left:
	{
		pPlayer->SetPos(
			GetCollider()->GetPos().x
			- (GetCollider()->GetScale().x + pOther->GetScale().x) * 0.5f + offset
			- pOther->GetOffsetPos().x,
			pPlayer->GetPos().y
		);
	}
	break;

	case CollisionDir::Right:
	{
		pPlayer->SetPos(
			GetCollider()->GetPos().x
			+ (GetCollider()->GetScale().x + pOther->GetScale().x) * 0.5f - offset
			- pOther->GetOffsetPos().x,
			pPlayer->GetPos().y
		);
	}
	break;
	}
}

void CGroundTile::Init()
{
	CTile::Init();

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

void CGroundTile::Release()
{
	CTile::Release();
}

void CGroundTile::OnCollisionEnter(CCollider* pOther)
{
	// 땅타일과 충돌했을 경우 처리
}

void CGroundTile::OnCollisionStay(CCollider* pOther)
{
	// 땅타일과 충돌했을 경우 처리
	if (pOther->GetObjName() == L"Player" || pOther->GetObjName() == L"Monster"
		|| pOther->GetObjName() == L"Gish")
	{
		PushObject(pOther);
	}
}

void CGroundTile::OnCollisionExit(CCollider* pOther)
{
	// 땅타일과 충돌했을 경우 처리
}

struct ColliderInfo
{
	Vector pos;
	Vector scale;

	float left;
	float right;
	float up;
	float down;

	ColliderInfo(Vector pos, Vector scale)
	{
		this->pos = pos;
		this->scale = scale;

		left = pos.x - scale.x * 0.5f;
		right = pos.x + scale.x * 0.5f;
		up = pos.y - scale.y * 0.5f;
		down = pos.y + scale.y * 0.5f;
	}
};

typename CGroundTile::CollisionDir CGroundTile::GetCollisionDir(CCollider* pOther)
{
	ColliderInfo obj = ColliderInfo(GetCollider()->GetPos(), GetCollider()->GetScale());
	ColliderInfo other = ColliderInfo(pOther->GetPos(), pOther->GetScale());

	if (((obj.scale.x + other.scale.x) * 0.5f - abs(obj.pos.x - other.pos.x) < offset * 4
		&& ((obj.scale.y + other.scale.y) * 0.5f - abs(obj.pos.y - other.pos.y)) < offset * 4))
	{
		return CollisionDir::None;
	}
	else if (((obj.scale.x + other.scale.x) * 0.5f - abs(obj.pos.x - other.pos.x))
		< (obj.scale.y + other.scale.y) * 0.5f - abs(obj.pos.y - other.pos.y))
	{
		if (obj.pos.x > other.pos.x && obj.left < other.right - offset)
			return CollisionDir::Left;
		if (obj.pos.x < other.pos.x && obj.right > other.left + offset)
			return CollisionDir::Right;
	}
	else
	{
		if (obj.pos.y > other.pos.y && obj.up < other.down - offset)
			return CollisionDir::Up;
		if (obj.pos.y < other.pos.y && obj.down > other.up + offset)
			return CollisionDir::Down;
	}

	return CollisionDir::None;
}
