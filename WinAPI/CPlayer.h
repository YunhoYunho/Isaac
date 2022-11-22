#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

enum class PlayerState
{
	Idle,
	Move,
	Shot,
	Hurt,
	Dead,

	Size
};

class CPlayer : public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	int m_iHP;

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

	PlayerState m_state;

	Vector m_vecMoveDir;
	Vector m_vecLookDir;
	
	CSound* pHurt = RESOURCE->LoadSound(L"Hurt", L"Sound\\Isaac\\Hurt.wav");
	CSound* pDead = RESOURCE->LoadSound(L"Dead", L"Sound\\Isaac\\Dies.wav");

public:
	bool m_bIsMove;
	bool m_bIsShot;
	bool m_bIsHurt;
	bool m_bIsDead;

	float m_fSpeed = 200.0f;
	float m_fDamage = 2;
	float m_fTimer = 0;

	PlayerState m_playerState;
	wstring stateBody;
	wstring stateHead;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
	void CreateMissile();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;

private:
	void NowPlayerPosition();
	void PrevPlayerPosition();
	void NowPlayerHP();
};
