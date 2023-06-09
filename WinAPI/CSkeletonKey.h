#pragma once
#include "CPassiveItem.h"

class CSkeletonKey : public CPassiveItem
{
public:
	CSkeletonKey();
	virtual ~CSkeletonKey();

	void Activate(CPlayer* pPlayer) override;

private:
	CImage* m_pSkeletonKeyImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

