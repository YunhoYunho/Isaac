#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
public:
	CMissile();
	virtual ~CMissile();

protected:
	Vector m_vecDir;
	float m_fVelocity;
	float m_fDamage;

	float m_fTimer;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;

public:
	void SetDir(Vector dir);
	void SetVelocity(float velocity);
};