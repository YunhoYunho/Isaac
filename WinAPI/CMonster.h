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

	Vector m_vecMonLookAt;		// 몬스터가 현재 보고있는 위치
	Vector m_vecPlayerPos;		// 타겟(플레이어)목표 위치
	CGameObject* m_pPlayerObj;	// 몬스터가 추적할 타겟(플레이어)

	float m_fTimeToPlayer;		// 몬스터가 타겟(플레이어)까지 가는데 남은 시간

public:
	Vector GetMonLookAt();
	Vector GetPlayerPos();
	CGameObject* GetPlayerObj();

	// 오브젝트를 지정할 경우 목표위치는 목표 오브젝트의 위치로 지정됨
	void SetPlayerPos(Vector playerPos, float timeToPlayer = 0);	// 몬스터의 목표 위치 지정
	void SetPlayerObj(CGameObject* pPlayerObj);						// 몬스터의 목표 오브젝트 지정

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

