#pragma once
#include "CMonster.h"

class CImage;
class CAnimator;

class CBoomfly : public CMonster
{
public:
	CBoomfly();
	virtual ~CBoomfly();

	CMonster* Clone() { return new CBoomfly(*this); }

private:
	CAnimator* m_pAnimator;
	CImage* m_pBoomflyImage;
	CExplosion* pExplosion;

	wstring stateBoomfly;

	float m_fTimer;
	bool m_bIsExplosion;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
	
	void BoomTrigger();
	void Boom();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

