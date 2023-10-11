#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include"FunctionK.h"
#include"FunctionS.h"
#include"Move.h"

const char kWindowTitle[] = "LC1A_11_クリハラ_ケイタ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);


	//マップ40x26
	int map[3][100][26]{

		{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		
		},

		{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		}
	};


	MAINCHARACTER main{};///プレイヤーの初期化
	ENEMYCHARACTER enemy{};///敵の初期化
	MAPCHIP mapchip{};///マップチップの初期化
	BACKGROUND background{};///背景の初期化
	DISTANCE distance{};
	FLAG flag{};

	///トンネリング防止の変数初期化
	Vector2 e{};
	Vector2 f{};
	Vector2 Linedistance{};
	
	///プレイヤーの初期座標
	main.worldPos.x = 200;
	main.worldPos.y = 200;

	///プレイヤーのそれぞれ頂点の中心からの幅
	main.vertexWide.LeftTop = { 48,48 };
	main.vertexWide.RightTop = { 48,48 };
	main.vertexWide.LeftBottom = { 48,48 };
	main.vertexWide.RightBottom = { 48,48 };

	///敵の半径
	main.radius = 24;
	

	///敵の位置初期化
	for (int i = 0; i < 10; i++) {

		///敵の半径
		enemy.radius[i] = 24;

		enemy.worldPos[i].x = 800;
		enemy.worldPos[i].y = 500+float(i)*120;

		///エネミーのそれぞれ頂点の中心からの幅
		enemy.vertexWide[i].LeftTop = { 48,48 };
		enemy.vertexWide[i].RightTop = { 48,48 };
		enemy.vertexWide[i].LeftBottom = { 48,48 };
		enemy.vertexWide[i].RightBottom = { 48,48 };
	}

	main.scale = 1.0f;

	///前背景の初期化
	background.flont1.y = 720;
	background.flont2.y = 0;
	background.back1.y = 720;
	background.back2.y = 0;

	

	main.velocity = 5;

	///プレイヤーの画面上に映し続ける座標
	main.kameraPos.y = 100;

	///画像初期化
	int frontBackGround;
	int BackGround;

	mapchip.Handle = Novice::LoadTexture("white1x1.png");///マップチップの画像
	frontBackGround = Novice::LoadTexture("./Resources./Images./backGroudTest.png");
	BackGround = Novice::LoadTexture("./Resources./Images./backGroundTest2.png");


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここか

		///↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓背景またはスクロールの処理始め↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


		///前背景の移動
		background.flont1.y -= main.velocity * 0.1f;
		background.flont2.y -= main.velocity * 0.1f;

		///後ろ背景の移動
		background.back1.y -= main.velocity * 0.05f;
		background.back2.y -= main.velocity * 0.05f;


		///前背景の無限スクロール
		if (background.flont1.y <= 0) {

			background.flont1.y = 720;
			background.flont2.y = 0;
		}

		///後ろ背景の無限スクロール
		if (background.back1.y <= 0) {

			background.back1.y = 720;
			background.back2.y = 0;
		}

		///マップのループ
		if (mapchip.worldPos.y <= -4800) {
			main.worldPos.y = 0;

			///壊れたマップの復元
			for (int i = 0; i < 100; i++) {

				for (int j = 0; j < 26; j++) {

					if (map[mapchip.number][i][j] == 3) {

						map[mapchip.number][i][j] = 1;

					}
				}
			}
		}

		///↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑背景またはスクロールの処理終わり↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑


		///↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓頂点の座標計算ここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


		///プレイヤーの4頂点の座標計算
		main.vertexPos.LeftTop = LeftTopVertex(main.screenPos, main.vertexWide.LeftTop, 0, main.scale);
		main.vertexPos.LeftBottom = LeftBottomVertex(main.screenPos, main.vertexWide.LeftBottom, 0, main.scale);
		main.vertexPos.RightTop = RightTopVertex(main.screenPos, main.vertexWide.RightTop, 0, main.scale);
		main.vertexPos.RightBottom = RightBottomVertex(main.screenPos, main.vertexWide.RightBottom, 0, main.scale);


		///敵の頂点の座標計算
		for (int i = 0; i < 10; i++) {
	
			enemy.vertexPos[i].LeftTop = LeftTopVertex(enemy.screenPos[i], enemy.vertexWide[i].LeftTop, 0, 1);
			enemy.vertexPos[i].LeftBottom = LeftBottomVertex(enemy.screenPos[i], enemy.vertexWide[i].LeftBottom, 0, 1);
			enemy.vertexPos[i].RightTop = RightTopVertex(enemy.screenPos[i], enemy.vertexWide[i].RightTop, 0, 1);
			enemy.vertexPos[i].RightBottom = RightBottomVertex(enemy.screenPos[i], enemy.vertexWide[i].RightBottom, 0, 1);
	

			///敵の移動前の座標
			enemy.oldWorldPos[i].x = enemy.worldPos[i].x;
				
			enemy.oldWorldPos[i].y = enemy.worldPos[i].y;

		}

		main.oldworldPos.x = main.worldPos.x;
		main.oldworldPos.y = main.worldPos.y;

		///スケールを掛けてく
		/*main.height = 48*main.scale;
		main.width =48* main.scale;
		main.radius = 24*main.scale;*/

		mapchip.size = 48*main.scale;
		

		///↑↑↑↑↑↑↑↑↑↑↑↑頂点の座標計算ここから↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

		///プレイヤーのX軸の動き
		PlayerMove(main);


		///プレイヤーのY軸の動き

		if (flag.isFallStop == 0) {

			main.acceleration = 0.01f;
		}

		main.velocity += main.acceleration;

		main.worldPos.y += main.velocity;

		if (flag.isFallColl == 0) {

			///急降下するとき速度を保存
			if (keys[DIK_SPACE] && flag.isFallHighSpeed == 0) {

				main.velocitySave = main.velocity;

				flag.isFallHighSpeed = 1;
			}

			///急降下
			if (flag.isFallHighSpeed == 1) {

				main.velocity = 28;

				///急降下をやめる時は保存した速度になう速度を代入
				if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE]) {

					main.velocity = main.velocitySave;
					flag.isFallHighSpeed = 0;
				}
			}
		}

		///マップチップに衝突したら高速降下をいったん止める

		if (flag.isFallColl == 1) {

			flag.isFallHighSpeed = 0;

			main.fallCollTime += 1;

			if (main.fallCollTime == 40) {

				main.fallCollTime = 0;
				flag.isFallColl = 0;
			}
		}

		///↓↓↓↓↓↓↓↓トンネリングを防ぐ処理（カプセル作成）↓↓↓↓↓↓↓↓↓↓
		for (int i = 0; i < 10; i++) {

			enemy.distance[i].x = enemy.worldPos[i].x - main.worldPos.x;
			enemy.distance[i].y = enemy.worldPos[i].y - main.worldPos.y;

		}

		Linedistance.x = main.worldPos.x - main.oldworldPos.x;
		Linedistance.y = main.worldPos.y - main.oldworldPos.y;

		e = normalize(Linedistance);

		for (int i = 0; i < 10; i++) {

			main.time = dot(enemy.distance[i].x, e.x, enemy.distance[i].y, e.y)/length(Linedistance.x, Linedistance.y);

		}

		main.time = Clamp(main.time, 0, 1);

		f.x = (1.0f - main.time) * main.oldworldPos.x + main.time * main.worldPos.x;
		f.y = (1.0f - main.time) * main.oldworldPos.y + main.time * main.worldPos.y;

		///↑↑↑↑↑↑↑↑↑↑↑トンネリングを防ぐ処理（カプセル作成）↑↑↑↑↑↑↑↑↑↑↑↑↑

		for (int i = 0; i < 10; i++) {

			if (flag.isEnemyDeath[i] == 0) {

				///敵とプレイヤーのカプセルの距離
				distance.enemyANDplayer[i] = length(enemy.worldPos[i].x - f.x, enemy.worldPos[i].y - f.y);

			}

			///急降下してない状態で当たったら
			if (distance.enemyANDplayer[i] <= enemy.radius[i] + main.radius && flag.isEnemyDeath[i] == 0 && flag.isFallHighSpeed == 0) {

				flag.isDamage = 1;

			}
			
			///敵を倒す処理
			if (distance.enemyANDplayer[i] <= enemy.radius[i]+main.radius && flag.isEnemyDeath[i] == 0&&flag.isFallHighSpeed==1) {

				flag.isEnemyDeath[i] = 1;
				main.ScaleSave = main.scale;
				flag.isScaleUp = 1;
				Sleep(120);		
			}

			if (flag.isEnemyDeath[i] == 1) {
				
				///敵が死ぬ処理
			}
		}

		///ダメージ受けた時の処理
		if (flag.isDamage == 1&& flag.isDamageColl == 0) {

			main.ScaleSave = main.scale;
			main.scaleUpEasing.time = 0;
			flag.isScaleDown = 1;
			flag.isDamageColl = 1;
			flag.isDamage = 0;

		}

		
		///ダメ―ジ受けた時のクールタイム1秒
		if (flag.isDamageColl == 1) {

			main.damageCollTime += 1;

			if (main.damageCollTime == 60) {

				flag.isDamageColl = 0;
			}
		}


		///プレイヤーが小さくなってしまう処理
		if (flag.isScaleDown == 1&& flag.isScaleUp == 0) {

			main.scaleDownEasing.time += 0.01f;

			main.scale = easeOutSine(main.scaleDownEasing, main.scale, main.ScaleSave - 0.5f);

			if (main.scaleDownEasing.time > 1.0f) {

				main.scaleDownEasing.isEasing = 0;
				flag.isScaleDown = 0;

			}
		}

		///プレイヤーが大きくなる処理
		if (flag.isScaleUp == 1&& flag.isScaleDown == 0) {

			main.scaleUpEasing.time += 0.01f;

			main.scale = easeOutSine(main.scaleUpEasing, main.scale, main.ScaleSave + 0.5f);

			if (main.scaleUpEasing.time > 1.0f) {

				main.scaleUpEasing.isEasing = 0;
				flag.isScaleUp = 0;

			}
		}

	
	  ///↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓マップチップの当たり判定ここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓
	
		main.worldMax.y = MAX(main.worldPos.y, main.oldworldPos.y);


		///int型に変換したワールド座標X（マップチップとの衝突時に空いてしまう隙間を埋めるため）
		main.fitMapSize.inty = int(main.worldMax.y / 24);
		main.fitMapSize.inty = (main.fitMapSize.inty * 24);


		main.fitOldMapSize.intx = int(main.oldworldPos.x / 6);
		main.fitOldMapSize.intx = (main.fitOldMapSize.intx * 6);


		///int型に変換したワールド座標Y（マップチップとの衝突時に空いてしまう隙間を埋めるため）
		main.fitOldMapSize.inty = int(main.oldworldPos.y /24);
		main.fitOldMapSize.inty = (main.fitOldMapSize.inty * 24);


		///マップチップの番号の取得
		main.mapNumber.LeftTop = LeftTopMapNum(main.worldPos, main.height, main.width, mapchip.size);
		main.mapNumber.LeftBottom = LeftBottomMapNum(main.worldPos, main.height, main.width, mapchip.size);
		main.mapNumber.RightTop = RightTopMapNum(main.worldPos, main.height, main.width, mapchip.size);
		main.mapNumber.RightBottom = RightBottomMapNum(main.worldPos, main.height, main.width, mapchip.size);


		///移動前のマップチップの番号の取得
		main.oldMapNumber.LeftTop = LeftTopMapNum(main.oldworldPos, main.height, main.width, mapchip.size);
		main.oldMapNumber.LeftBottom = LeftBottomMapNum(main.oldworldPos, main.height, main.width, mapchip.size);
		main.oldMapNumber.RightTop = RightTopMapNum(main.oldworldPos, main.height, main.width, mapchip.size);
		main.oldMapNumber.RightBottom = RightBottomMapNum(main.oldworldPos, main.height, main.width, mapchip.size);


		///自機の４頂点のどれかが当たっている時
		if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x)] == 1 || map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] == 1 ||
			map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x)] == 1 || map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] == 1) {


			if (map[mapchip.number][int(main.oldMapNumber.RightTop.y)][int(main.mapNumber.RightTop.x)] != 1 && map[mapchip.number][int(main.oldMapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] != 1 &&
				map[mapchip.number][int(main.oldMapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x)] != 1 && map[mapchip.number][int(main.oldMapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] != 1) {

				///ｙ軸に当たった時の斜め反応
				main.worldPos.y = float(main.fitMapSize.inty);
				main.velocity = 3;
				main.acceleration = 0;
				 flag.isFallStop = 1;
				 flag.isFallColl = 1;
				 flag.isDamage = 1;


				 ///マップの破壊（どしゃん）
				 if (map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] == 1) {

					 map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] = 3;

				 }

				 ///マップの破壊（どしゃん）
				 if (map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] == 1) {

					 map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] = 3;

				 }

			}

			else if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.oldMapNumber.RightTop.x)] != 1 && map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.oldMapNumber.RightBottom.x)] != 1 &&
				map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.oldMapNumber.LeftTop.x)] != 1 && map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.oldMapNumber.LeftBottom.x)] != 1) {

				     ///ｘ軸に当たった時の斜め反応
				     main.worldPos.x = float(main.fitOldMapSize.intx);
			     }

			else {

				///それ以外の反応

				main.worldPos.x = float(main.fitOldMapSize.intx);
				main.worldPos.y = float(main.fitMapSize.inty);
				main.velocity = 3;
				main.acceleration = 0;
				flag.isFallStop = 1;
				flag.isDamage = 1;


				///マップの破壊（どしゃん）
				if (map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] == 1) {

					map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] = 3;

				}
				///マップの破壊（どしゃん）
				if (map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] == 1) {

					map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] = 3;

				}
			}
		}

		else {

			flag.isFallStop = 0;
		}


		///急降下時のマップチップの当たり判定
		if (keys[DIK_SPACE]) {

			for (int y = int(main.oldMapNumber.LeftTop.y); y <= int(main.mapNumber.RightBottom.y); y++) {

				for (int x = int(main.oldMapNumber.LeftTop.x); x <= int(main.mapNumber.RightBottom.x); x++) {

					if (map[mapchip.number][y][x] == 1 && flag.isMoveAbove == 0) {

						flag.isMoveAbove = 1;
						
					}

					if (flag.isMoveAbove == 1) {
						
						main.fitOldMapSize.inty += 4;
						
					}

					///マップの破壊
					if (map[mapchip.number][y][x] == 1) {

						main.worldPos.y = float(main.fitOldMapSize.inty);
    					main.velocity = 3;
						main.acceleration = 0;

						map[mapchip.number][y][x] = 3;

					}					
				}
			}
		}

		else {
			flag.isMoveAbove = 0;
		}


		///↑↑↑↑↑↑↑マップチップの当たり判定ここから↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑


		///↓↓↓↓↓↓↓↓↓座標変換↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


		///プレイヤーのY軸のスクロールする座標
		main.scrollPos.y = main.worldPos.y - main.kameraPos.y;

		///プレイヤーのY軸の画面に映る座標
		main.screenPos.y = main.worldPos.y - main.scrollPos.y;

		///マップチップのY軸の座標
		mapchip.worldPos.y = -(main.worldPos.y - main.kameraPos.y);


		///座標変換というより名前をスクリーンに変えただけ
		main.screenPos.x = main.worldPos.x;
		mapchip.screenPos.y = mapchip.worldPos.y;

		///敵の座標変換
		for (int i = 0; i < 10; i++) {

			enemy.screenPos[i].x = enemy.worldPos[i].x;
			enemy.screenPos[i].y = enemy.worldPos[i].y + mapchip.worldPos.y;

		}

		///
		/// ↑更新処理ここまで
		///

		/// ↓描画処理ここから
		///

		///背景の描画
		Novice::DrawSprite(0, int(background.back1.y), BackGround, 1, 1, 0, WHITE);
		Novice::DrawSprite(0, int(background.back2.y), BackGround, 1, 1, 0, WHITE);
		Novice::DrawSprite(0, int(background.flont1.y), frontBackGround, 1, 1, 0, WHITE);
		Novice::DrawSprite(0, int(background.flont2.y), frontBackGround, 1, 1, 0, WHITE);


		///マップチップの描画
		for (int i = 0; i < 100; i++) {

			for (int j = 0; j < 26; j++) {

				if ((j * 48.0f) >= -48 && (j * 48.0f) <= 1328 && (i * 48.0f + mapchip.screenPos.y) >= -48 && (i * 48.0f + mapchip.screenPos.y) <= 768) {

					if (map[mapchip.number][i][j] == 1) {

						Novice::DrawQuad(int((j * 48.0f)), int((i * 48.0f + mapchip.screenPos.y)), int((j * 48.0f + 48.0f)), int((i * 48.0f + mapchip.screenPos.y)), int((j * 48.0f)), int((i * 48.0f + mapchip.screenPos.y + 48.0f)), int((j * 48.0f + 48.0f)), int((i * 48.0f + mapchip.screenPos.y + 48.0f)), 0, 0, 24, 24, mapchip.Handle, WHITE);

					}
				}
			}

		}

		///敵の描画
		for (int i = 0; i < 10; i++) {
			
				newDrawQuad(enemy.vertexPos[i].LeftTop, enemy.vertexPos[i].RightTop, enemy.vertexPos[i].LeftBottom, enemy.vertexPos[i].RightBottom, 0, 0, 48, 48, mapchip.Handle, WHITE);		
		}
		  
		///プレイヤーの描画
		newDrawQuad(main.vertexPos.LeftTop, main.vertexPos.RightTop, main.vertexPos.LeftBottom, main.vertexPos.RightBottom ,0, 0, 48, 48, mapchip.Handle, WHITE);


		Novice::DrawLine(0, int(main.worldPos.y+mapchip.worldPos.y), 1280, int(main.worldPos.y + mapchip.worldPos.y),  RED );

		Novice::DrawLine(0, int(main.oldworldPos.y+ mapchip.worldPos.y), 1280, int(main.oldworldPos.y + mapchip.worldPos.y),  WHITE);

		for (int i = 0; i < 10; i++) {

			if (distance.enemyANDplayer[i] <= 48&&flag.isEnemyDeath[i] == 1) {

				///プレイヤーの描画
				newDrawQuad(main.vertexPos.LeftTop, main.vertexPos.RightTop, main.vertexPos.LeftBottom, main.vertexPos.RightBottom, 0, 0, 48, 48, mapchip.Handle, RED);

			}
		}

		newScreenPrintf(0, 0, flag.isScaleUp);
		newScreenPrintf(0, 20, flag.isScaleDown);
		newScreenPrintf(0, 40, main.vertexWide.LeftBottom.x);
		


		///
		/// ↑描画処理ここまで
		///

		/// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

