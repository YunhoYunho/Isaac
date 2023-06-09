#pragma once
#include "CPassiveItem.h"

class CPlayer;

class CMeat : public CPassiveItem
{
public:
	CMeat();
	virtual ~CMeat();

	void Activate(CPlayer* pPlayer) override;

private:
	CImage* m_pMeatImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

