#pragma once
#include "CChest.h"

class CGoldenChest : public CChest
{
public:
	CGoldenChest();
	virtual ~CGoldenChest();

private:
	CImage* m_pGoldenChestImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

