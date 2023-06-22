#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
public:
	CMissile();
	virtual ~CMissile();

protected:
	CAnimator* m_pAnimator;
	CImage* m_pTearsImage;
	Vector m_vecDir;
	float m_fVelocity;
	float m_fTimer;
	float m_fMTimer = 0;
	float m_fGravity = 100.0f;
	float m_fZSpeed = 0.0f;
	float m_fHeight = 20.0f;
	bool m_bIsHit;

	void Shot();
	void Fire();
	void Hit();
	void CheckMissile();
	void DeleteMissile();

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