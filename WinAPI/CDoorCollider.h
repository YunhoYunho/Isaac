#pragma once
#include "CGameObject.h"

class CDoorCollider : public CGameObject
{
public:
	CDoorCollider();
	virtual ~CDoorCollider();

private:
	void Remove();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

