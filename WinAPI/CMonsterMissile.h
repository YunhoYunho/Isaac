#pragma once
#include "CMissile.h"

class CMonsterMissile : public CMissile
{
public:
	CMonsterMissile();
	virtual ~CMonsterMissile();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
};