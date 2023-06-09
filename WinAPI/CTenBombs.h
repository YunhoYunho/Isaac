#pragma once
#include "CPassiveItem.h"

class CTenBombs : public CPassiveItem
{
public:
	CTenBombs();
	virtual ~CTenBombs();

	void Activate(CPlayer* pPlayer) override;

private:
	CImage* m_pTenBombsImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

