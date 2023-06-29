#include "framework.h"
#include "CPlayer.h"

#include "CPlayerMissile.h"
#include "CShieldMissile.h"
#include "CBomb.h"
#include "CPickupHeart.h"
#include "CChest.h"
#include "CNormalChest.h" 
#include "CGoldenChest.h"
#include "CPassiveItem.h"

CPlayer::CPlayer()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Player;
	m_strName = L"Player";
	m_playerState = PlayerState::Idle;
	
	pMissile = nullptr;
	m_pBodyImage = nullptr;
	m_pHeadImage = nullptr;
	m_pShotImage = nullptr;
	m_pHurtImage = nullptr;
	m_pDeadImage = nullptr;
	m_pGetItemImage = nullptr;
	m_pAppearItemImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);

	m_HP = 3;
	m_MaxHP = 5;
	m_iBomb = 1;
	m_iKey = 1;

	m_bIsShieldTears = false;
	m_bIsTripleShot = false;
	m_bIsHitReady = true;
	m_bIsLTeleport = false;
	m_bIsRTeleport = false;
	m_bIsUTeleport = false;
	m_bIsDTeleport = false;
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
	m_pGetItemImage = RESOURCE->LoadImg(L"PlayerGetItem", L"Image\\Unit\\IsaacGetItem.png");

	pHurt = RESOURCE->LoadSound(L"Hurt", L"Sound\\Isaac\\Hurt.wav");
	pDead = RESOURCE->LoadSound(L"Dead", L"Sound\\Isaac\\Dies.wav");
	pGetItem = RESOURCE->LoadSound(L"GetItem", L"Sound\\Isaac\\GetItem.wav");

	m_pAnimatorBody = new CAnimator;
	m_pAnimatorHead = new CAnimator;

	m_pAnimatorBody->CreateAnimation(L"BodyIdleUp", m_pBodyImage, Vector(385.f, 0.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorBody->CreateAnimation(L"BodyIdleRight", m_pBodyImage, Vector(0.f, 251.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorBody->CreateAnimation(L"BodyIdleDown", m_pBodyImage, Vector(0.f, 0.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorBody->CreateAnimation(L"BodyIdleLeft", m_pBodyImage, Vector(0.f, 127.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0, 1);

	m_pAnimatorBody->CreateAnimation(L"BodyUp", m_pBodyImage, Vector(385.f, 0.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0.1f, 5);
	m_pAnimatorBody->CreateAnimation(L"BodyRight", m_pBodyImage, Vector(0.f, 251.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0.1f, 10);
	m_pAnimatorBody->CreateAnimation(L"BodyDown", m_pBodyImage, Vector(0.f, 0.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0.1f, 5);
	m_pAnimatorBody->CreateAnimation(L"BodyLeft", m_pBodyImage, Vector(0.f, 127.f), Vector(77.f, 127.f), Vector(77.f, 0.f), 0.1f, 10);

	m_pAnimatorHead->CreateAnimation(L"HeadUp", m_pHeadImage, Vector(154.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorHead->CreateAnimation(L"HeadRight", m_pHeadImage, Vector(77.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorHead->CreateAnimation(L"HeadDown", m_pHeadImage, Vector(0.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1);
	m_pAnimatorHead->CreateAnimation(L"HeadLeft", m_pHeadImage, Vector(231.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1);

	m_pAnimatorHead->CreateAnimation(L"ShotUp", m_pShotImage, Vector(308.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0.2f, 2);
	m_pAnimatorHead->CreateAnimation(L"ShotRight", m_pShotImage, Vector(154.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0.2f, 2);
	m_pAnimatorHead->CreateAnimation(L"ShotDown", m_pShotImage, Vector(0.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0.2f, 2);
	m_pAnimatorHead->CreateAnimation(L"ShotLeft", m_pShotImage, Vector(462.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0.2f, 2);

	m_pAnimatorHead->CreateAnimation(L"TakeHit", m_pHurtImage, Vector(0.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0.1f, 10, false);
	m_pAnimatorHead->CreateAnimation(L"Dead", m_pDeadImage, Vector(0.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0.2f, 5, false);
	m_pAnimatorHead->CreateAnimation(L"GetItem", m_pGetItemImage, Vector(0.f, 0.f), Vector(77.f, 77.f), Vector(77.f, 0.f), 0, 1, false);
	m_pAnimatorBody->CreateAnimation(L"None", m_pDeadImage, Vector(0.f, 0.f), Vector(1.f, 1.f), Vector(1.f, 0.f), 0, 1, false);

	m_pAnimatorHead->Play(L"HeadDown");
	m_pAnimatorBody->Play(L"BodyIdleDown");

	AddComponent(m_pAnimatorBody);
	AddComponent(m_pAnimatorHead);
	AddMissile();
	AddCollider(ColliderType::Rect, Vector(57, 60), Vector(0, 8));
}

void CPlayer::Update()
{
	PlayerPos();
	PlayerHP();
	PlayerMaxHP();
	PlayerDamage();
	PlayerShotSpeed();
	PlayerBomb();
	PlayerKey();
	CreateBomb();
	CheckHit();
	LRTeleport();
	UDTeleport();

	CreateHeart();
	CreateChest();

	if (m_HP <= 0)
	{
		stateBody = L"None";
		stateHead = L"Dead";
		RemoveCollider();
	}

	else
	{
		switch (m_playerState)
		{
		case PlayerState::Idle:
			IdleUpdate();
		case PlayerState::Move:
			MoveUpdate();
		case PlayerState::Shot:
			ShotUpdate();
			break;
		case PlayerState::TakeHit:
			TakeHitUpdate();
			break;
		case PlayerState::GetItem:
			GetItemUpdate();
			break;
		}
	}
	AnimatorUpdate();
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

void CPlayer::IdleUpdate()
{
	stateHead = L"HeadDown";
	stateBody = L"BodyIdleDown";

	if (GetLookDir().x == -1)
	{
		stateHead = L"HeadLeft";
		stateBody = L"BodyIdleLeft";
	}
	else if (GetLookDir().x == +1)
	{
		stateHead = L"HeadRight";
		stateBody = L"BodyIdleRight";
	}
	if (GetLookDir().y == -1)
	{
		stateHead = L"HeadUp";
		stateBody = L"BodyIdleUp";
	}
	else if (GetLookDir().y == +1)
	{
		stateHead = L"HeadDown";
		stateBody = L"BodyIdleDown";
	}
}

void CPlayer::MoveUpdate()
{
	if (m_vecMoveDir.Length() > 0)
		m_vecLookDir = m_vecMoveDir;

	if (BUTTONSTAY('A'))
	{
		m_vecMoveDir.x = -1;
	}
	else if (BUTTONSTAY('D'))
	{
		m_vecMoveDir.x = +1;
	}
	else
	{
		m_vecMoveDir.x = 0;
	}

	if (BUTTONSTAY('W'))
	{
		m_vecMoveDir.y = -1;
	}
	else if (BUTTONSTAY('S'))
	{
		m_vecMoveDir.y = +1;
	}
	else
	{
		m_vecMoveDir.y = 0;
	}

	m_vecPos += m_vecMoveDir.Normalized() * m_fSpeed * DT;

	MoveState();
}

void CPlayer::ShotUpdate()
{
	if (BUTTONSTAY(VK_LEFT) || BUTTONSTAY(VK_RIGHT) || BUTTONSTAY(VK_UP) || BUTTONSTAY(VK_DOWN))
	{
		CreateMissile();
	}

	else
	{
		m_playerState = PlayerState::Idle;
	}
}

void CPlayer::TakeHitUpdate()
{
	fCooltime += DT;

	stateHead = L"TakeHit";
	stateBody = L"None";

	if (fCooltime > 0.5f)
	{
		m_playerState = PlayerState::Idle;
		fCooltime = 0;
	}
}

void CPlayer::GetItemUpdate()
{
	fCooltime += DT;

	stateHead = L"GetItem";
	stateBody = L"None";

	RemoveCollider();

	if (fCooltime > 1.0f)
	{
		m_playerState = PlayerState::Idle;
		AddCollider(ColliderType::Rect, Vector(57, 60), Vector(0, 8));
		fCooltime = 0;
	}
}

void CPlayer::MoveState()
{
	if (BUTTONSTAY('A'))
	{
		stateBody = L"BodyLeft";
	}
	else if (BUTTONSTAY('D'))
	{
		stateBody = L"BodyRight";
	}

	if (BUTTONSTAY('W'))
	{
		stateBody = L"BodyUp";

	}
	else if (BUTTONSTAY('S'))
	{
		stateBody = L"BodyDown";
	}
}

void CPlayer::ShotState()
{
	if (BUTTONSTAY(VK_LEFT))
	{
		stateHead = L"ShotLeft";
	}

	if (BUTTONSTAY(VK_RIGHT))
	{
		stateHead = L"ShotRight";
	}

	if (BUTTONSTAY(VK_UP))
	{
		stateHead = L"ShotUp";
	}

	if (BUTTONSTAY(VK_DOWN))
	{
		stateHead = L"ShotDown";
	}
}

void CPlayer::HurtState()
{
	m_playerState = PlayerState::TakeHit;

	TakeDamage();

	if (m_HP > 0)
	{
		SOUND->Play(pHurt, 1.0f, false);

		m_fSTimer += DT;

		if (m_fSTimer > 1.0f)
		{
			SOUND->Pause(pHurt);
			m_fSTimer = 0;
		}
	}

	if (m_HP <= 0)
	{
		SOUND->Play(pDead, 1.0f, false);

		m_fTimer += DT;

		if (m_fTimer > 1.0f)
		{
			SOUND->Pause(pDead);
			m_fTimer = 0;
		}
	}
}

void CPlayer::AddMissile()
{
	m_vecMissiles.clear();
	m_vecMissiles.emplace_back(new CPlayerMissile());
	m_vecMissiles.emplace_back(new CShieldMissile());
}

void CPlayer::CreateMissile()
{
	if (m_fTimer == 0)
	{
		NormalShot();

		if (true == m_bIsTripleShot)
		{
			TripleShot();
		}
	}

	m_fTimer += DT;

	if (m_fTimer > m_fShotSpeed)
	{
		m_fTimer = 0;
	}

	ShotState();
}


void CPlayer::SelectTears()
{
	pMissile = true != m_bIsShieldTears ?
		m_vecMissiles[0]->Clone() : m_vecMissiles[1]->Clone();
	pMissile->SetPos(m_vecPos);
}

void CPlayer::NormalShot()
{
	SelectTears();

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

void CPlayer::TripleShot()
{
	CMissile* pMissile2 = pMissile->Clone();
	CMissile* pMissile3 = pMissile->Clone();

	if (BUTTONSTAY(VK_LEFT))
	{
		pMissile2->SetDir(Vector(-1, 1));
		pMissile3->SetDir(Vector(-1, -1));
	}

	if (BUTTONSTAY(VK_RIGHT))
	{
		pMissile2->SetDir(Vector(1, 1));
		pMissile3->SetDir(Vector(1, -1));
	}

	if (BUTTONSTAY(VK_UP))
	{
		pMissile2->SetDir(Vector(1, -1));
		pMissile3->SetDir(Vector(-1, -1));
	}

	if (BUTTONSTAY(VK_DOWN))
	{
		pMissile2->SetDir(Vector(1, 1));
		pMissile3->SetDir(Vector(-1, 1));
	}
	ADDOBJECT(pMissile2);
	ADDOBJECT(pMissile3);
}

void CPlayer::TakeDamage()
{
	m_HP -= 1;
	m_bIsHitReady = false;
}

void CPlayer::CheckHit()
{
	if (false == m_bIsHitReady)
	{
		fCooltime += DT;

		if (fCooltime > 1.0f)
		{
			fCooltime = 0;
			m_bIsHitReady = true;
		}
	}
}

void CPlayer::CreateBomb()
{
	if (BUTTONDOWN('E'))
	{
		if (GetBomb() > 0)
		{
			Logger::Debug(L"气藕 积己");
			CBomb* pBomb = new CBomb();
			pBomb->SetPos(m_vecPos);
			pBomb->m_bIsPressE = true;
			SetBomb(-1);
			ADDOBJECT(pBomb);
		}
	}
}

void CPlayer::CreateHeart()
{
	if (BUTTONDOWN('K'))
	{
		Logger::Debug(L"窍飘 积己");
		CPickupHeart* pPickupHeart = new CPickupHeart();
		pPickupHeart->SetPos(Vector(800, WINSIZEY * 0.3f));
		ADDOBJECT(pPickupHeart);
	}
}

void CPlayer::CreateChest()
{
	if (BUTTONDOWN('C'))
	{
		Logger::Debug(L"惑磊 积己");
		CNormalChest* pNormalChest = new CNormalChest();
		pNormalChest->SetPos(Vector(700, WINSIZEY * 0.3f));
		ADDOBJECT(pNormalChest);
	}

	if (BUTTONDOWN('V'))
	{
		Logger::Debug(L"炔陛惑磊 积己");
		CGoldenChest* pGoldenChest = new CGoldenChest();
		pGoldenChest->SetPos(Vector(600, WINSIZEY * 0.3f));
		ADDOBJECT(pGoldenChest);
	}
}

void CPlayer::GetItem(CGameObject* pOtherCollider)
{
	m_vecPos = Vector(PLAYERPOS.x, PLAYERPOS.y - 30);

	m_fTimer += DT;

	if (m_fTimer > 0.7f)
	{
		DELETEOBJECT(pOtherCollider);
	}
}

void CPlayer::LRTeleport()
{
	if (true == m_bIsLTeleport)
	{
		CAMERA->LTeleport();
		m_vecPos.x += 350.0f;
		m_bIsLTeleport = false;
	}

	else if (true == m_bIsRTeleport)
	{
		CAMERA->RTeleport();
		m_vecPos.x -= 350.0f;
		m_bIsRTeleport = false;
	}
}

void CPlayer::UDTeleport()
{
	if (true == m_bIsUTeleport)
	{
		CAMERA->UTeleport();
		m_vecPos.y -= 280.0f;
		m_bIsUTeleport = false;
	}

	else if (true == m_bIsDTeleport)
	{
		CAMERA->DTeleport();
		m_vecPos.y += 280.0f;
		m_bIsDTeleport = false;
	}
}

void CPlayer::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Monster" ||
		pOtherCollider->GetObjName() == L"Boomfly" ||
		pOtherCollider->GetObjName() == L"Gish" ||
		pOtherCollider->GetObjName() == L"MonsterMissile")
	{
		if (true == m_bIsHitReady)
		{
			HurtState();
		}
	}

	if (pOtherCollider->GetOwner()->GetLayer() == Layer::PassiveItem)
	{
		CPassiveItem* pPassiveItem = dynamic_cast<CPassiveItem*>(pOtherCollider->GetOwner());
		if (pPassiveItem != nullptr)
		{
			m_playerState = PlayerState::GetItem;
			SOUND->Play(pGetItem, 1.0f, false);
			pPassiveItem->Activate(this);
		}
	}

	if (pOtherCollider->GetOwner()->GetLayer() == Layer::PickupItem)
	{
		CPickupItem* pPickupItem = dynamic_cast<CPickupItem*>(pOtherCollider->GetOwner());
		if (pPickupItem != nullptr)
		{
			pPickupItem->Activate(this);
		}
	}

	if (pOtherCollider->GetObjName() == L"LRTeleport")
	{
		if (PLAYERPOS.x <= pOtherCollider->GetPos().x)
		{
			m_bIsLTeleport = true;
		}

		else
		{
			m_bIsRTeleport = true;
		}
	}

	if (pOtherCollider->GetObjName() == L"UDTeleport")
	{
		if (PLAYERPOS.y <= pOtherCollider->GetPos().y)
		{
			m_bIsDTeleport = true;
		}

		else
		{
			m_bIsUTeleport = true;
		}
	}
}

void CPlayer::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CPlayer::OnCollisionExit(CCollider* pOtherCollider)
{
}

void CPlayer::PlayerPos()
{
	PLAYERPOS = GetPos();
}

void CPlayer::PlayerHP()
{
	PLAYERHP = GetHP();
}

void CPlayer::PlayerMaxHP()
{
	PLAYERMAXHP = GetMaxHP();
}

void CPlayer::PlayerDamage()
{
	PLAYERDAMAGE = GetDamage();
}

void CPlayer::PlayerShotSpeed()
{
	PLAYERSHOTSPEED = GetShotSpeed();
}

void CPlayer::PlayerBomb()
{
	PLAYERBOMB = GetBomb();
}

void CPlayer::PlayerKey()
{
	PLAYERKEY = GetKey();
}
