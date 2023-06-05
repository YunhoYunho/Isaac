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

	wstring state = L"MoveLeft";
	MonsterState m_gishState;

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

	void CheckDir();
	bool targetDir;

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

