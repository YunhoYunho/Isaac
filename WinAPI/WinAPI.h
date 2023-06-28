#pragma once

#include "resource.h"

//========================================
//##    전역변수(인스턴스, 윈도우 핸들)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;

//========================================
//##			윈도우 설정				##
//========================================

#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//========================================
//##			게임씬 그룹				##
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
//##				레이어				##
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
//##				타일					##
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
//##				상태				##
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
