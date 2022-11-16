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
	Vector m_vecTargetDir;

	Vector m_vecMonLookAt;		// ���Ͱ� ���� �����ִ� ��ġ
	Vector m_vecPlayerPos;		// Ÿ��(�÷��̾�)��ǥ ��ġ
	CGameObject* m_pPlayerObj;	// ���Ͱ� ������ Ÿ��(�÷��̾�)

	float m_fTimeToPlayer;		// ���Ͱ� Ÿ��(�÷��̾�)���� ���µ� ���� �ð�

public:
	Vector GetMonLookAt();
	Vector GetPlayerPos();
	CGameObject* GetPlayerObj();

	// ������Ʈ�� ������ ��� ��ǥ��ġ�� ��ǥ ������Ʈ�� ��ġ�� ������
	void SetPlayerPos(Vector playerPos, float timeToPlayer = 0);	// ������ ��ǥ ��ġ ����
	void SetPlayerObj(CGameObject* pPlayerObj);						// ������ ��ǥ ������Ʈ ����

	void Trace(Vector dir, float velocity);

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
};

