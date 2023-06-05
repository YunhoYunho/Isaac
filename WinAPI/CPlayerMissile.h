#pragma once
#include "CMissile.h"

class CPlayerMissile : public CMissile
{
public:
	CPlayerMissile();
	virtual ~CPlayerMissile();

	float m_fCooltime;
	bool m_bIsHit;

public:
	float m_fDamage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void CheckDestroyMissile();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
};