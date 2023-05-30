#pragma once
#include "CPickupItem.h"

class CPickupHeart : public CPickupItem
{
public:
	CPickupHeart();
	virtual ~CPickupHeart();

private:
	CImage* m_pHeartImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};
