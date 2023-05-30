#pragma once
#include "CGameObject.h"
#include "CNormalChest.h"

class CGoldenChest : public CNormalChest
{
public:
	CGoldenChest();
	virtual ~CGoldenChest();

private:
	CAnimator* m_pAnimator;
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

