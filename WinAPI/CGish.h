#pragma once
#include "CMonster.h"

class CImage;
class CAnimator;

class CGish : public CMonster
{
public:
	CGish();
	virtual ~CGish();

	CMonster* Clone() { return new CGish(*this); }

private:
	CAnimator* m_pAnimator;
	CImage* m_pGishLeftImage;
	CImage* m_pGishRightImage;

	wstring state = L"IdleLeft";
	MonsterState m_gishState;
	MonsterState m_curState;
	MonsterState m_preState;
	void ChangeState(MonsterState state);

private:
	void ActionUpdate();
	void ChangeUpdate();

	void ReadyUpdate();
	void MoveUpdate();
	void ShotUpdate();
	void JumpUpdate();
	void DeadUpdate();

	void MoveState();
	void ShotState();
	void DeadState();

	void Jumping();
	void Up(bool up);
	void Down(bool down);
	void CheckDir();

	void SavePos();

	bool m_bIsEle = false;

	float m_fSaveTimer = 0;

	float savePlayerPosX;
	float savePlayerPosY;
	int saveCount;

	bool m_bIsTouchDown;

	bool targetDir;
	bool m_bIsShot;
	int moveCount;
	float m_fTraceTimer;
	float m_fJumpTimer;
	float m_fStopTimer = 0;

public:
	float GetHP();
	float GetMaxHP();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

