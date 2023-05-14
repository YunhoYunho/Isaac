#pragma once
#include "CMonster.h"

class CImage;
class CAnimator;

class CGish : public CMonster
{
public:
	CGish();
	virtual ~CGish();

private:
	CAnimator* m_pAnimator;
	CImage* m_pGishLeftImage;
	CImage* m_pGishRightImage;

	wstring stateGish;

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

