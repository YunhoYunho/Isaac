#pragma once

#include "resource.h"

//========================================
//##    ��������(�ν��Ͻ�, ������ �ڵ�)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;

//========================================
//##			������ ����				##
//========================================

#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//========================================
//##			���Ӿ� �׷�				##
//========================================

enum class GroupScene
{
	Title,
	TileTool,
	StageLoading,
	Stage01,
	Loading,
	Ending,

	Size,
};

//========================================
//##				���̾�				##
//========================================

enum class Layer
{
	Default,
	Tile,
	Title,
	GroundTile,
	Obstacle,
	Teleport,
	DoorControl,
	DoorFrame,
	DoorCollider,
	Rock,
	Missile,
	Monster,
	ItemRock,
	Chest,
	EndingChest,
	PickupItem,
	EnterEffect,
	MonsterMissile,
	Player,
	PlayerMissile,
	ShieldMissile,
	Bomb,
	Explosion,
	PassiveItem,
	PlayerHP,
	HUD,
	Ui,
	Loading,
	Ending,

	Size,
};

//========================================
//##				Ÿ��					##
//========================================

enum class TypeTile
{
	None,
	Ground,
	Door,
	Platform,
	Wall,

	Size,
};

//========================================
//##				����				##
//========================================

enum class PlayerState
{
	Idle,
	Move,
	Shot,
	TakeHit,
	GetItem,

	Size,
};

enum class MonsterState
{
	Ready,
	Move,
	Shot,
	Jump,
	Dead,

	Size,
};
