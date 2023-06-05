#pragma once
#include "CMonster.h"

class CImage;
class CAnimator;

class CBaby : public CMonster
{
public:
	CBaby();
	virtual ~CBaby();

	CMonster* Clone() { return new CBaby(*this); }

private:
	CAnimator* m_pAnimator;
	CImage* m_pBabyImage;
	CImage* m_pBabyDeadImage;

	wstring stateBaby;

	float m_fRange = 0;

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

