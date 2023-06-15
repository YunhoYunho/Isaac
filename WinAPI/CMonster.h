#pragma once
#include "CGameObject.h"
#include "CExplosion.h"
#include "CPlayerMissile.h"

class CMonster : public CGameObject
{
public:
	CMonster();
	virtual ~CMonster();

	virtual CMonster* Clone() = 0;

	bool up;
	bool down;
	bool left;
	bool right;

	bool m_bIsShot;
	bool m_bIsDead;

	int deadCount = 0;
	float m_HP;
	float m_MaxHP;

	float m_fSpeed = 200.0f;
	float m_fTimer = 0;
	float fCooltime;
	float m_fRange = 0;

	float targetDist;

	CExplosion* pExplosion;
	CPlayerMissile* pPlayerMissile;

public:
	Vector m_vecMoveDir;
	Vector m_vecLookDir;
	Vector m_vecPlayerPos;

public:
	void DustEffect();
	void GetDamaged(float value);
	void BossDead();
	void Dead();
	void DeadCount();
	void Trace();
	void PingPong();
	void CreateMissile();

	void TargetDist();
	void TargetPos();
	float m_fShotTimer;
	float m_fShotSpeed;

public:
	Vector GetLookDir();
	void SetLookDir(Vector vecLookDir);
	void SetMoveDir(Vector vecMoveDir);
	
private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};
