#pragma once
#include "CItem.h"

class CPickupItem : public CItem
{
public:
	CPickupItem();
	virtual ~CPickupItem();

protected:
	bool m_bIsContact = false;

	void Contact();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

