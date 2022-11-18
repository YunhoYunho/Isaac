#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

enum class DoorState
{
	Close,
	Open,

	Size
};

class CDoor : public CGameObject
{
public:
	CDoor();
	virtual ~CDoor();

private:
	CAnimator* m_pAnimator;

	CImage* m_pBrownDoorImage;
	CImage* m_pBossDoorImage;

	DoorState m_state;

	bool m_bIsClose;
	bool m_bIsOpen;
	
	DoorState m_doorState;
	wstring stateDoor;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

