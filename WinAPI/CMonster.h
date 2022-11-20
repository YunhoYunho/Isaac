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
	float m_fTimer = 0;
public:
	Vector m_vecMoveDir;
	Vector m_vecLookDir;
	Vector m_vecPlayerPosition;

protected:
	void CreateMissile();
	void ShotTime();

	float m_fShotTimer;
	float m_fShotSpeed;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

