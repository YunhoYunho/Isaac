#include "framework.h"
#include "CMonster.h"

#include "CRenderManager.h"
#include "CCollider.h"

#include "CMonsterMissile.h"

CMonster::CMonster()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);

	m_bIsMove = false;
	m_bIsShot = false;
	m_bIsDead = false;
}

CMonster::~CMonster()
{
}

void CMonster::Init()
{
	AddCollider(ColliderType::Rect, Vector(90, 90), Vector(0, 0));
}

void CMonster::Update()
{
}

void CMonster::Render()
{
	RENDER->FrameRect(
		m_vecPos.x - m_vecScale.x * 0.5f,
		m_vecPos.y - m_vecScale.y * 0.5f,
		m_vecPos.x + m_vecScale.x * 0.5f,
		m_vecPos.y + m_vecScale.y * 0.5f);
}

void CMonster::Release()
{
}

void CMonster::CreateMissile()
{
	Logger::Debug(L"�� �̻��� ����");

	CMonsterMissile* pMissile = new CMonsterMissile();
	pMissile->SetPos(m_vecPos);
	pMissile->SetDir(m_vecPlayerPosition);
	ADDOBJECT(pMissile);
}

void CMonster::ShotTime()
{
	if (m_fTimer == 0)
	{
		CreateMissile();
	}

	m_fTimer += DT;

	if (m_fTimer > 0.25f)
	{
		m_fTimer = 0;
	}

}

void CMonster::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"�÷��̾�")
	{
		Logger::Debug(L"���Ͱ� �÷��̾�� �浹����");
	}
	else if (pOtherCollider->GetObjName() == L"�̻���")
	{
		Logger::Debug(L"���Ͱ� �̻��ϰ� �浹����");
	}
}

void CMonster::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CMonster::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"�÷��̾�")
	{
		Logger::Debug(L"���Ͱ� �÷��̾�� �浹����");
	}
	else if (pOtherCollider->GetObjName() == L"�̻���")
	{
		Logger::Debug(L"���Ͱ� �̻��ϰ� �浹����");
	}
}
