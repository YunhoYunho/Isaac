#pragma once
#include "CMissile.h"

class CPlayerMissile : public CMissile
{
public:
	CPlayerMissile();
	virtual ~CPlayerMissile();

private:
	CAnimator* m_pAnimator;
	CImage* m_pTearsImage;

	float m_fCooltime;
	bool m_bIsHit;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void CheckDestroyMissile();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
};