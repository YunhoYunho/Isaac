#pragma once
#include "CPassiveItem.h"

class CShieldTears : public CPassiveItem
{
public:
	CShieldTears();
	virtual ~CShieldTears();

	void Activate(CPlayer* pPlayer) override;

private:
	CImage* m_pShieldTearsImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

