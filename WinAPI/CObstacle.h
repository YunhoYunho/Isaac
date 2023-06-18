#pragma once
#include "CGameObject.h"

class CObstacle : public CGameObject
{
public:
	enum class CollisionDir { Up, Down, Left, Right, None };

public:
	CObstacle();
	virtual ~CObstacle();

public:
	CollisionDir dir;
	float		 offset;

	void PushObject(CCollider* pOther);

public:
	CollisionDir GetCollisionDir(CCollider* pOther);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

private:
	void OnCollisionEnter(CCollider* pOther) override;
	void OnCollisionStay(CCollider* pOther) override;
	void OnCollisionExit(CCollider* pOther) override;
};

