#pragma once
#include "CDoorTeleport.h"

class CDoorBossTeleport : public CDoorTeleport
{
public:
	CDoorBossTeleport();
	virtual ~CDoorBossTeleport();

	void CheckTouch();

	bool m_bIsTouch;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

