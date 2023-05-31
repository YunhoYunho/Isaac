#pragma once
#include "CChest.h"

class CNormalChest : public CChest
{
public:
	CNormalChest();
	virtual ~CNormalChest();

private:
	CImage* m_pNormalChestImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

