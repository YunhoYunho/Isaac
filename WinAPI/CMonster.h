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
	Vector			m_vecLookAt;		// 카메라가 현재 보고있는 위치
	Vector			m_vecTargetPos;		// 카메라의 목표 위치
	CGameObject*	m_pTargetObj;		// 카메라가 추적할 오브젝트

	float			m_fTimeToTarget;	// 카메라가 목적지까지 가는데 남은시간

public:
	Vector			GetLookAt();
	Vector			GetTargetPos();
	CGameObject*	GetTargetObj();

	// 오브젝트를 지정할 경우 목표위치는 목표 오브젝트의 위치로 지정됨
	void SetTargetPos(Vector targetPos, float timeToTarget = 0);	// 카메라의 목표 위치 지정
	void SetTargetObj(CGameObject* pTargetObj);						// 카메라의 목표 오브젝트 지정

	void Scroll(Vector dir, float velocity);		// 카메라 스크롤

private:
	void MoveToTarget();
};

