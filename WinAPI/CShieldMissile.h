#pragma once
#include "CMissile.h"

class CShieldMissile : public CMissile
{
public:
	CShieldMissile();
	virtual ~CShieldMissile();

	CMissile* Clone() { return new CShieldMissile(*this); }

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
};
