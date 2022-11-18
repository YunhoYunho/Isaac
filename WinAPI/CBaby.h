#pragma once
#include "CMonster.h"

class CImage;
class CAnimator;

enum class BabyState
{
	Move,
	Shot,
	Dead,

	Size
};

class CBaby : public CMonster
{
public:
	CBaby();
	virtual ~CBaby();

private:
	CAnimator* m_pAnimator;
	CImage* m_pBabyImage;
	CImage* m_pBabyDeadImage;

	BabyState m_stateBaby;

	BabyState m_BabyState;
	wstring stateBaby;

	bool up;
	bool down;
	bool left;
	bool right;

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

