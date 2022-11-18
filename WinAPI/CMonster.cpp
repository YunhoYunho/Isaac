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

	m_vecLookAt = Vector(0, 0);
	m_vecTargetPos = Vector(0, 0);
	m_pTargetObj = nullptr;
	m_fTimeToTarget = 0;
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
	// ������ ���ӿ�����Ʈ�� ���� ���
	if (nullptr != m_pTargetObj)
	{
		if (m_pTargetObj->GetReserveDelete())
		{
			// ������ ���ӿ�����Ʈ�� ���������� ��� ���� ����
			m_pTargetObj = nullptr;
		}
		else
		{
			// ������ ���ӿ�����Ʈ�� ���� ��� ���ӿ�����Ʈ�� ��ġ�� ��ǥ��ġ�� ����
			SetTargetPos(m_pTargetObj->GetPos());
		}
	}

	// ��ǥ ��ġ�� �̵�
	MoveToTarget();
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

	if (m_bIsShot)
	{
		CMonsterMissile* pMissile = new CMonsterMissile();
		pMissile->SetPos(m_vecPos);
		pMissile->SetDir(m_vecTargetPos);
		ADDOBJECT(pMissile);
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

Vector CMonster::GetLookAt()
{
	return m_vecLookAt;
}

Vector CMonster::GetTargetPos()
{
	return m_vecTargetPos;
}

CGameObject* CMonster::GetTargetObj()
{
	return m_pTargetObj;
}

void CMonster::SetTargetPos(Vector targetPos, float timeToTarget)
{
	m_vecTargetPos = targetPos;
	m_fTimeToTarget = timeToTarget;
}

void CMonster::SetTargetObj(CGameObject* pTargetObj)
{
	m_pTargetObj = pTargetObj;
}

void CMonster::Scroll(Vector dir, float velocity)
{
	// ��ũ���� ���� ũ�Ⱑ ���� ��� �������� ����
	if (dir.Magnitude() == 0)
		return;

	// ��ũ���� ��ǥ ��ġ�� ������ġ���� ��ũ�� �������� ������ ��ġ
	m_vecTargetPos = m_vecLookAt;
	m_vecTargetPos += dir.Normalized() * velocity * DT;
	m_fTimeToTarget = 0;	// ��ũ���� �ð����� ���� ���� �ﰢ �̵�
}

void CMonster::MoveToTarget()
{
	m_fTimeToTarget -= DT;

	if (m_fTimeToTarget <= 0)
	{
		// ��ǥ��ġ���� ���� �ð��� ���� ��� �������� ������ġ ����
		m_vecLookAt = m_vecTargetPos;
	}
	else
	{
		// ��ǥ��ġ���� ���� �ð��� ���� ���
		// ���������� �����ð���ŭ�� �ӵ��� �̵�
		// �̵��Ÿ� = �ӷ� * �ð�
		// �ӷ� = (������ - �����) / �ҿ�ð�
		// �ð� = �����Ӵ����ð�
		m_vecLookAt += (m_vecTargetPos - m_vecLookAt) / m_fTimeToTarget * DT;
	}
}
