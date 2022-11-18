#pragma once
#include "CGameObject.h"
class CMonster : public CGameObject
{
public:
	CMonster();
	virtual ~CMonster();

	bool m_bIsMove;
	bool m_bIsShot;
	bool m_bIsDead;

	float m_fSpeed = 200.0f;
	float m_fAttack;
	float m_HP;
	float m_Damage;

public:
	Vector m_vecMoveDir;
	Vector m_vecLookDir;

protected:
	void CreateMissile();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;


public:
	Vector			m_vecLookAt;		// ī�޶� ���� �����ִ� ��ġ
	Vector			m_vecTargetPos;		// ī�޶��� ��ǥ ��ġ
	CGameObject*	m_pTargetObj;		// ī�޶� ������ ������Ʈ

	float			m_fTimeToTarget;	// ī�޶� ���������� ���µ� �����ð�

public:
	Vector			GetLookAt();
	Vector			GetTargetPos();
	CGameObject*	GetTargetObj();

	// ������Ʈ�� ������ ��� ��ǥ��ġ�� ��ǥ ������Ʈ�� ��ġ�� ������
	void SetTargetPos(Vector targetPos, float timeToTarget = 0);	// ī�޶��� ��ǥ ��ġ ����
	void SetTargetObj(CGameObject* pTargetObj);						// ī�޶��� ��ǥ ������Ʈ ����

	void Scroll(Vector dir, float velocity);		// ī�޶� ��ũ��

private:
	void MoveToTarget();
};

