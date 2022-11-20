#include "framework.h"
#include "CPlayer.h"

#include "WinAPI.h"
#include "CInputManager.h"
#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CEventManager.h"
#include "CResourceManager.h"
#include "CCollider.h"
#include "CImage.h"
#include "CAnimator.h"

#include "CPlayerMissile.h"

CPlayer::CPlayer()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Player;
	m_strName = L"플레이어";

	m_pBodyImage = nullptr;

	m_pHeadImage = nullptr;
	m_pShotImage = nullptr;

	m_pHurtImage = nullptr;
	m_pDeadImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);
	m_bIsMove = false;
	m_bIsShot = false;
	m_bIsHurt = false;
	m_bIsDead = false;
	m_bIsWall = false;

	m_HP = 3;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Init()
{
	m_pBodyImage = RESOURCE->LoadImg(L"PlayerBody", L"Image\\Unit\\IsaacBody.png");
															
	m_pHeadImage = RESOURCE->LoadImg(L"PlayerHead", L"Image\\Unit\\IsaacHead.png");
	m_pShotImage = RESOURCE->LoadImg(L"PlayerShot", L"Image\\Unit\\IsaacShot.png");
												
	m_pHurtImage = RESOURCE->LoadImg(L"PlayerHurt", L"Image\\Unit\\IsaacHurt.png");
	m_pDeadImage = RESOURCE->LoadImg(L"PlayerDead", L"Image\\Unit\\IsaacDead.png");


	m_pAnimatorBody = new CAnimator;
	m_pAnimatorHead = new CAnimator;

	m_pAnimatorBody->CreateAnimation(L"BodyIdleUp", m_pBodyImage, Vector(385.f, 0.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorBody->CreateAnimation(L"BodyIdleRightUp", m_pBodyImage, Vector(0.f, 251.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorBody->CreateAnimation(L"BodyIdleRight", m_pBodyImage, Vector(0.f, 251.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorBody->CreateAnimation(L"BodyIdleRightDown", m_pBodyImage, Vector(0.f, 251.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorBody->CreateAnimation(L"BodyIdleDown", m_pBodyImage, Vector(0.f, 0.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorBody->CreateAnimation(L"BodyIdleLeftDown", m_pBodyImage, Vector(0.f, 127.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorBody->CreateAnimation(L"BodyIdleLeft", m_pBodyImage, Vector(0.f, 127.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorBody->CreateAnimation(L"BodyIdleLeftUp", m_pBodyImage, Vector(0.f, 127.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0, 1);

	m_pAnimatorBody->CreateAnimation(L"BodyUp", m_pBodyImage, Vector(385.f, 0.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0.1f, 5);
	m_pAnimatorBody->CreateAnimation(L"BodyRightUp", m_pBodyImage, Vector(0.f, 251.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0.1f, 10);
	m_pAnimatorBody->CreateAnimation(L"BodyRight", m_pBodyImage, Vector(0.f, 251.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0.1f, 10);
	m_pAnimatorBody->CreateAnimation(L"BodyRightDown", m_pBodyImage, Vector(0.f, 251.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0.1f, 10);
	m_pAnimatorBody->CreateAnimation(L"BodyDown", m_pBodyImage, Vector(0.f, 0.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0.1f, 5);
	m_pAnimatorBody->CreateAnimation(L"BodyLeftDown", m_pBodyImage, Vector(0.f, 127.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0.1f, 10);
	m_pAnimatorBody->CreateAnimation(L"BodyLeft", m_pBodyImage, Vector(0.f, 127.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0.1f, 10);
	m_pAnimatorBody->CreateAnimation(L"BodyLeftUp", m_pBodyImage, Vector(0.f, 127.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0.1f, 10);

	m_pAnimatorHead->CreateAnimation(L"HeadUp", m_pHeadImage, Vector(154.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorHead->CreateAnimation(L"HeadRightIdleUp", m_pHeadImage, Vector(77.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorHead->CreateAnimation(L"HeadRight", m_pHeadImage, Vector(77.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorHead->CreateAnimation(L"HeadRightIdleDown", m_pHeadImage, Vector(77.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorHead->CreateAnimation(L"HeadDown", m_pHeadImage, Vector(0.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorHead->CreateAnimation(L"HeadLeftIdleDown", m_pHeadImage, Vector(231.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorHead->CreateAnimation(L"HeadLeft", m_pHeadImage, Vector(231.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorHead->CreateAnimation(L"HeadLeftIdleUp", m_pHeadImage, Vector(231.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1);

	m_pAnimatorHead->CreateAnimation(L"ShotUp", m_pShotImage, Vector(308.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0.2f, 2);
	m_pAnimatorHead->CreateAnimation(L"ShotRight", m_pShotImage, Vector(154.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0.2f, 2);
	m_pAnimatorHead->CreateAnimation(L"ShotDown", m_pShotImage, Vector(0.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0.2f, 2);
	m_pAnimatorHead->CreateAnimation(L"ShotLeft", m_pShotImage, Vector(462.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0.2f, 2);

	m_pAnimatorHead->CreateAnimation(L"Hurt", m_pHurtImage, Vector(0.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1, false);

	m_pAnimatorHead->CreateAnimation(L"Dead", m_pDeadImage, Vector(0.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0.3f, 5, false);

	m_pAnimatorBody->CreateAnimation(L"None", m_pDeadImage, Vector(0.f, 0.f), Vector(1.f, 1.f), Vector(1.f, 0.f), 0, 1, false);

	m_pAnimatorHead->Play(L"HeadDown");
	m_pAnimatorBody->Play(L"BodyIdleDown");

	AddComponent(m_pAnimatorBody);
	AddComponent(m_pAnimatorHead);

	m_playerState = PlayerState::Idle;

	AddCollider(ColliderType::Rect, Vector(57, 66), Vector(0, 8));
}

void CPlayer::Update()
{
	m_bIsMove = false;
	NowPlayerPosition();

	switch (m_playerState)
	{
	case PlayerState::Idle:
		m_bIsWall = true;
		stateHead = L"HeadDown";
		stateBody = L"BodyIdleDown";

		if (BUTTONUP('A'))
		{
			stateBody = L"BodyIdleLeft";
		}

		if (BUTTONUP('D'))
		{
			stateBody = L"BodyIdleRight";
		}

		if (BUTTONUP('W'))
		{
			stateBody = L"BodyIdleUp";
		}

		if (BUTTONUP('S'))
		{
			stateBody = L"BodyIdleDown";
		}

	case PlayerState::Move:
		if (BUTTONSTAY('A'))
		{
			m_vecPos.x -= m_fSpeed * DT;
			m_bIsMove = true;
			m_vecMoveDir.x = -1;
			stateBody = L"BodyLeft";
			stateHead = L"HeadLeft";
		}
		else if (BUTTONSTAY('D'))
		{
			m_vecPos.x += m_fSpeed * DT;
			m_bIsMove = true;
			m_vecMoveDir.x = +1;
			stateBody = L"BodyRight";
			stateHead = L"HeadRight";

		}
		else
		{
			m_vecMoveDir.x = 0;
		}

		if (BUTTONSTAY('W'))
		{
			m_vecPos.y -= m_fSpeed * DT;
			m_bIsMove = true;
			m_vecMoveDir.y = +1;
			stateBody = L"BodyUp";
			stateHead = L"HeadUp";

		}
		else if (BUTTONSTAY('S'))
		{
			m_vecPos.y += m_fSpeed * DT;
			m_bIsMove = true;
			m_vecMoveDir.y = -1;
			stateBody = L"BodyDown";
			stateHead = L"HeadDown";

		}
		else
		{
			m_vecMoveDir.y = 0;
		}

		if (false == m_bIsMove)
		{
			m_playerState = PlayerState::Idle;
		}

	case PlayerState::Shot:
		if (BUTTONSTAY(VK_LEFT))
		{
			m_bIsShot = true;
			stateHead = L"ShotLeft";
			ShotTime();
		}

		if (BUTTONSTAY(VK_RIGHT))
		{
			m_bIsShot = true;
			stateHead = L"ShotRight";
			ShotTime();
		}

		if (BUTTONSTAY(VK_UP))
		{
			m_bIsShot = true;
			stateHead = L"ShotUp";
			ShotTime();
		}

		if (BUTTONSTAY(VK_DOWN))
		{
			m_bIsShot = true;
			stateHead = L"ShotDown";
			ShotTime();
		}

		if (false == m_bIsMove)
		{
			m_playerState = PlayerState::Move;
		}

		if (BUTTONUP('A'))
		{
			stateHead = L"HeadLeft";
		}

		if (BUTTONUP('D'))
		{
			stateHead = L"HeadRight";
		}

		if (BUTTONUP('W'))
		{
			stateHead = L"HeadUp";
		}

		if (BUTTONUP('S'))
		{
			stateHead = L"HeadDown";
		}

	case PlayerState::Hurt:
		if (BUTTONDOWN('T'))
		{
			m_bIsHurt = true;
			m_HP--;
			stateHead = L"Hurt";
			stateBody = L"None";
		}

		if (BUTTONSTAY('A') || BUTTONSTAY('D') || BUTTONSTAY('W') || BUTTONSTAY('S'))
		{
			m_playerState = PlayerState::Move;
		}

		if (BUTTONUP('A') || BUTTONUP('D') || BUTTONUP('W') || BUTTONUP('S'))
		{
			m_playerState = PlayerState::Idle;
		}

		if (BUTTONDOWN(VK_LEFT) || BUTTONDOWN(VK_RIGHT) || BUTTONDOWN(VK_UP) || BUTTONDOWN(VK_DOWN) ||
			BUTTONUP(VK_LEFT) || BUTTONUP(VK_RIGHT) || BUTTONUP(VK_UP) || BUTTONUP(VK_DOWN))
		{
			m_playerState = PlayerState::Shot;
		}

		if (BUTTONDOWN('Y'))
		{
			m_playerState = PlayerState::Hurt;
		}

	case PlayerState::Dead:
		if (m_HP <= 0 || BUTTONDOWN('Y'))
		{
			stateHead = L"Dead";
			stateBody = L"None";
		}

		AnimatorUpdate();
		PrevPlayerPosition();
	}

	if (m_HP <= 0)
	{
		m_playerState = PlayerState::Dead;
		m_HP = 0;
	}
}

void CPlayer::Render()
{
}

void CPlayer::Release()
{
}

void CPlayer::AnimatorUpdate()
{
	m_pAnimatorBody->Play(stateBody, false);
	m_pAnimatorHead->Play(stateHead, false);
}

void CPlayer::CreateMissile()
{
	Logger::Debug(L"미사일 생성");

	CPlayerMissile* pMissile = new CPlayerMissile();
	pMissile->SetPos(m_vecPos);

	if (BUTTONSTAY(VK_LEFT))
	{
		pMissile->SetDir(Vector(-1, 0));
	}

	if (BUTTONSTAY(VK_RIGHT))
	{
		pMissile->SetDir(Vector(1, 0));
	}

	if (BUTTONSTAY(VK_UP))
	{
		pMissile->SetDir(Vector(0, -1));
	}

	if (BUTTONSTAY(VK_DOWN))
	{
		pMissile->SetDir(Vector(0, 1));
	}
	ADDOBJECT(pMissile);
}

void CPlayer::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Wall")
	{
		m_bIsWall = true;
		m_playerState = PlayerState::Move;

		if (m_vecPos.x <= WINSIZEX)
		{
			m_vecPos.x += 0.5f;
			m_vecPos.y -= 0.5f;
		}

		else if (m_vecPos.y <= WINSIZEY)
		{
			m_vecPos.x -= 0.5f;
			m_vecPos.y -= 0.5f;
		}
	}

	if (pOtherCollider->GetObjName() == L"MonsterMissile")
	{
		m_HP--;
	}

}

void CPlayer::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CPlayer::OnCollisionExit(CCollider* pOtherCollider)
{
}

void CPlayer::KeyBoardRead()
{
}

void CPlayer::ShotTime()
{
	if (m_fTimer == 0)
	{
		CreateMissile();
	}

	m_fTimer += DT;

	if (m_fTimer > 0.25f)
	{
		m_fTimer = 0;
	}

}

void CPlayer::NowPlayerPosition()
{
	PLAYERPOS = m_vecPos;
}

void CPlayer::PrevPlayerPosition()
{
	GAME->PrevPlayerPos = m_vecPos;
}
