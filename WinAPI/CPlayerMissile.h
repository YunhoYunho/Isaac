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

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;

public:
	void SetDir(Vector dir);
	void SetVelocity(float velocity);
};