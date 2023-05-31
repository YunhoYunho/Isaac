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

public:
	int m_HP;
	int m_MaxHP;
	int m_iBomb;
	int m_iKey;

	float m_fSpeed = 200.0f;
	float m_fDamage = 20.0f;
	float m_fTimer = 0;
	float fCooltime = 0;
	float m_fSTimer = 0;

	bool m_bIsTripleShot;
	bool m_bIsHit;
	bool m_bIsColliderOff;

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

	Vector GetLookDir();
	void SetLookDir(Vector vecLookDir);
	void SetMoveDir(Vector vecMoveDir);

	int GetHP();
	int GetMaxHP();

	int GetKey();

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
