#pragma once
#include "CMissile.h"

class CPlayerMissile : public CMissile
{
public:
	CPlayerMissile();
	virtual ~CPlayerMissile();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
};