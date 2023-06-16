#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

class CPlayer : public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

private:
	CAnimator* m_pAnimatorBody;
	CAnimator* m_pAnimatorHead;

	// 바디
	CImage* m_pBodyImage;
	// 헤드
	CImage* m_pHeadImage;
	CImage* m_pShotImage;
	// 공통
	CImage* m_pHurtImage;
	CImage* m_pDeadImage;

	CImage* m_pGetItemImage;

	CImage* m_pAppearItemImage;
	
	Vector m_vecMoveDir;
	Vector m_vecLookDir;
	
	CSound* pHurt = RESOURCE->LoadSound(L"Hurt", L"Sound\\Isaac\\Hurt.wav");
	CSound* pDead = RESOURCE->LoadSound(L"Dead", L"Sound\\Isaac\\Dies.wav");
	CSound* pGetItem = RESOURCE->LoadSound(L"GetItem", L"Sound\\Isaac\\GetItem.wav");

	PlayerState m_playerState;
	wstring stateBody;
	wstring stateHead;

private:
	int m_HP;
	int m_MaxHP;
	int m_iBomb;
	int m_iKey;
	int m_iCount = 0;

	float m_fSpeed = 200.0f;
	float m_fDamage = 20.0f;
	float m_fShotSpeed = 0.25f;

	float m_fTimer = 0;
	float fCooltime = 0;
	float m_fSTimer = 0;

	bool m_bIsTripleShot;
	bool m_bIsHit;
	bool m_bIsColliderOff;
	bool m_bIsLTeleport;
	bool m_bIsRTeleport;
	bool m_bIsUTeleport;
	bool m_bIsDTeleport;

public:
	void IdleUpdate();
	void MoveUpdate();
	void ShotUpdate();
	void TakeHitUpdate();
	void GetItemUpdate();

	void MoveState();
	void ShotState();
	void HurtState();

	void TakeDamage();
	void CheckCollider();

	void GetItem(CGameObject* pOtherCollider);
	void LRTeleport();
	void UDTeleport();

	Vector GetLookDir() { return m_vecLookDir; }
	void SetLookDir(Vector vecLookDir) { m_vecLookDir = vecLookDir; }
	void SetMoveDir(Vector vecMoveDir) { m_vecMoveDir = vecMoveDir; }

	int GetHP() { return m_HP; }
	void SetHP(int hp) { m_HP += hp; }

	int GetMaxHP() { return m_MaxHP; }
	void SetMaxHP(int maxHP) { m_MaxHP = maxHP; }

	int GetBomb() { return m_iBomb; }
	void SetBomb(int bomb) { m_iBomb = bomb; }

	int GetKey() { return m_iKey; }
	void SetKey(int key) { m_iKey += key; }

	float GetShotSpeed() { return m_fShotSpeed; }
	void SetShotSpeed(float shotSpeed) { m_fShotSpeed += shotSpeed; }

	float GetDamage() { return m_fDamage; }
	void SetDamage(float damage) { m_fDamage += damage; }

	bool GetTripleShot() { return m_bIsTripleShot; }
	void SetTripleShot(bool tripleShot) { m_bIsTripleShot = tripleShot; }

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
	void CreateMissile();
	void CreateBomb();

	void CreateHeart();
	void CreateChest();

	void NormalShot();
	void TripleShot();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;

private:
	void PlayerPos();
	void PlayerHP();
	void PlayerMaxHP();
	void PlayerBomb();
	void PlayerKey();
};
