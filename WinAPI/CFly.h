#pragma once
#include "CMonster.h"

class CImage;
class CAnimator;

enum class FlyState
{
	Move,
	Dead,

	Size
};

class CFly : public CMonster
{
public:
	CFly();
	virtual ~CFly();

private:
	CAnimator* m_pAnimator;
	CImage* m_pFlyImage;

	FlyState m_stateFly;

	FlyState m_FlyState;
	wstring stateFly;

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

