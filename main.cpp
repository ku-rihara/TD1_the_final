#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include"FunctionK.h"
#include"FunctionS.h"
#include"Move.h"





const char kWindowTitle[] = "LC1A_11_クリハラ_ケイタ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	///シェイクスピア
	srand(unsigned int(time(nullptr)));

	//マップ40x26
	int map[3][100][66]{

		{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,01,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

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

	int Scene = 0;

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

	SceneChangeP sc{
		{0,0},
		{0,0},
		{640,-320},
		{640,1080},
		0,
		false
	};

	///プレイヤーの初期座標
	main.worldPos.x = 900;
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

		enemy.worldPos[i].x = 1300;
		enemy.worldPos[i].y = 900 + float(i) * 120;

		///エネミーのそれぞれ頂点の中心からの幅
		enemy.vertexWide[i].LeftTop = { 48,48 };
		enemy.vertexWide[i].RightTop = { 48,48 };
		enemy.vertexWide[i].LeftBottom = { 48,48 };
		enemy.vertexWide[i].RightBottom = { 48,48 };
	}

	main.drawScale = 1.0f;
	mapchip.scale = 1.0f;
	main.totalScale = 1.0f;

	///前背景の初期化
	background.flont1.y = 720;
	background.flont2.y = 0;
	background.back1.y = 720;
	background.back2.y = 0;

	mapchip.size = 48;

	main.velocity = 5;

	float screenCenterX = 1280 / 2; // 画面の中央X座標
	float screenCenterY = 720 / 2;  // 画面の中央Y座標

	


	///プレイヤーの画面上に映し続ける座標
	main.kameraPos.x = 600;
	main.kameraPos.y = 100;

	///↓↓↓↓↓↓↓↓↓画像初期化↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
	int frontBackGround;
	int BackGround;
	int sceneChangeHandle;
	int sceneChangeHandle2;
	
	main.Handle = Novice::LoadTexture("./Resources./Images./player1-3.png");
	mapchip.Handle = Novice::LoadTexture("white1x1.png");///マップチップの画像
	frontBackGround = Novice::LoadTexture("./Resources./Images./backGroudTest.png");
	BackGround = Novice::LoadTexture("./Resources./Images./backGroundTest2.png");
	sceneChangeHandle=Novice::LoadTexture("./Resources./Images./SceneChange1.png");
	sceneChangeHandle2=Novice::LoadTexture("./Resources./Images./SceneChange2.png");

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

		switch (Scene) {

		case TITLE:

			sc.pos1.x = LeftTopX(sc.center1.x, 1320);
			sc.pos2.x = LeftTopX(sc.center2.x, 1320);
			sc.pos1.y = LeftTopY(sc.center1.y, 720);
			sc.pos2.y = LeftTopY(sc.center2.y, 720);

			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				sc.isSceneChange = true;
			}

			SceneChange(sc.center1.y, sc.center2.y, sc.isSceneChange, sc.random.x);
			Scene += 1;
		
			break;


		case PLAY:

			///↓↓↓↓↓↓↓↓ゲームプレイ中の処理ここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

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
			if (mapchip.ScrollPos.y <= -mapchip.size * 100) {
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
			main.vertexPos.LeftTop = LeftTopVertex(main.screenPos, main.vertexWide.LeftTop, 0, main.drawScale);
			main.vertexPos.LeftBottom = LeftBottomVertex(main.screenPos, main.vertexWide.LeftBottom, 0, main.drawScale);
			main.vertexPos.RightTop = RightTopVertex(main.screenPos, main.vertexWide.RightTop, 0, main.drawScale);
			main.vertexPos.RightBottom = RightBottomVertex(main.screenPos, main.vertexWide.RightBottom, 0, main.drawScale);


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
			main.height = 48 * main.drawScale;
			main.width = 48 * main.drawScale;
			main.radius = 24 * main.drawScale;
			mapchip.size = 48 * mapchip.scale;

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

				if (main.fallCollTime >= 40) {

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

			///eを正規化
			e = normalize(Linedistance);

			for (int i = 0; i < 10; i++) {

				///内積
				main.time = dot(enemy.distance[i].x, e.x, enemy.distance[i].y, e.y) / length(Linedistance.x, Linedistance.y);

			}

			///０か１か
			main.time = Clamp(main.time, 0, 1);

			///フレーム間の線形補間
			f.x = (1.0f - main.time) * main.oldworldPos.x + main.time * main.worldPos.x;
			f.y = (1.0f - main.time) * main.oldworldPos.y + main.time * main.worldPos.y;

			///↑↑↑↑↑↑↑↑↑↑↑トンネリングを防ぐ処理（カプセル作成）↑↑↑↑↑↑↑↑↑↑↑↑↑

			for (int i = 0; i < 10; i++) {

				if (flag.isEnemyDeath[i] == 0) {

					///敵とプレイヤーのカプセルの距離
					distance.enemyANDplayer[i] = length(enemy.worldPos[i].x - f.x, enemy.worldPos[i].y - f.y);
				}

				///急降下してない状態で当たったら
				if (distance.enemyANDplayer[i] <= enemy.radius[i] + main.radius && flag.isEnemyDeath[i] == 0 && flag.isFallHighSpeed == 0 ) {

					flag.isDamage = 1;
				}

				///敵を倒す処理
				if (distance.enemyANDplayer[i] <= enemy.radius[i] + main.radius && flag.isEnemyDeath[i] == 0 && flag.isFallHighSpeed == 1) {

					flag.isEnemyDeath[i] = 1;
					flag.isHit = 1;
					main.ScaleSave = main.drawScale;
					flag.isScaleUp = 1;
					Sleep(120);
				}

				if (flag.isEnemyDeath[i] == 1) {

					///敵が死ぬ処理
				}
			}

			///ヒットカウントを足していく
			if (flag.isHit == 1) {

				enemy.hitConbo += 1;
				main.totalScale += 0.2f;

				flag.isHit = 0;
			}

			///１コンボしたらコンボチェインを発動
			if (enemy.hitConbo >= 1) {

				flag.isConboChain = 1;
				enemy.conboCollTime += 1;

				///２秒後にコンボ切る
				if (enemy.conboCollTime >= 120) {

					enemy.hitConbo = 0;
					enemy.conboCollTime = 0;
				}
			}

			///ダメージ受けた時の処理
			if (flag.isDamage == 1&& flag.isDamageColl==0) {

				main.ScaleSave = main.drawScale;
				main.scaleUpEasing.time = 0;
				main.scaleDownEasing.time = 0;
				flag.isScaleDown = 1;
				flag.isDamageColl = 1;
				flag.isDamage = 0;
				main.totalScale -= 0.2f;
			}

			///ダメ―ジ受けた時のクールタイム1秒
			if (flag.isDamageColl == 1) {

				main.damageCollTime += 1;

				if (main.damageCollTime >= 60) {

					flag.isDamageColl = 0;
					main.damageCollTime = 0;

				}
			}

			///プレイヤーが小さくなってしまう処理
			if (flag.isScaleDown == 1) {

				main.scaleDownEasing.time += 0.07f;

				main.drawScale =easeOutSine(main.scaleDownEasing, main.ScaleSave, main.ScaleSave - 0.2f);

				if (main.scaleDownEasing.time >= 1.0f) {

					main.scaleDownEasing.time = 1;

					if (main.scaleDownEasing.time == 1) {
			
						main.scaleDownEasing.time = 0;
						flag.isScaleDown = 0;

					}
				}
			}
	
			///プレイヤーが大きくなる処理
			if (flag.isScaleUp == 1) {

				main.scaleUpEasing.time += 0.07f;

				main.drawScale = easeOutBack(main.scaleUpEasing, main.ScaleSave, main.ScaleSave + 0.2f);

				if (main.scaleUpEasing.time >= 1.0f) {

					main.scaleUpEasing.time = 1;
				}

					if (main.scaleUpEasing.time == 1.0f) {
						
					    flag.isScaleUp = 0;
					    main.scaleUpEasing.time = 0;

				    }
			}

			///
			if (main.totalScale >= 1.8f&&flag.ZoomRock==0) {

				flag.isMapZoomOut = 1;
				flag.ZoomRock = 1;
				main.ScaleSave = main.drawScale;
			}

			if (flag.isMapZoomOut == 1) {

				mapchip.zoomOutEasing.time += 0.01f;

				mapchip.scale = easeOutSine(mapchip.zoomOutEasing, 1, 0.7f);
				main.drawScale = easeOutSine(mapchip.zoomOutEasing, main.drawScale, main.ScaleSave - 0.3f);


				if (mapchip.zoomOutEasing.time >= 1.0f) {

					mapchip.zoomOutEasing.time = 1;
				}

				if (mapchip.zoomOutEasing.time == 1) {
					flag.isMapZoomOut = 0;
					
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
			main.fitOldMapSize.inty = int(main.oldworldPos.y / 24);
			main.fitOldMapSize.inty = (main.fitOldMapSize.inty * 24);


		

			///マップチップの番号の取得
			main.mapNumber.LeftTop = LeftTopMapNum(main.worldPos,mapchip.scale, main.height, main.width, mapchip.size);
			main.mapNumber.LeftBottom = LeftBottomMapNum(main.worldPos, mapchip.scale, main.height, main.width, mapchip.size);
			main.mapNumber.RightTop = RightTopMapNum(main.worldPos, mapchip.scale, main.height, main.width, mapchip.size);
			main.mapNumber.RightBottom = RightBottomMapNum(main.worldPos, mapchip.scale, main.height, main.width, mapchip.size);


			///移動前のマップチップの番号の取得
			main.oldMapNumber.LeftTop = LeftTopMapNum(main.oldworldPos,mapchip.scale, main.height, main.width, mapchip.size);
			main.oldMapNumber.LeftBottom = LeftBottomMapNum(main.oldworldPos, mapchip.scale, main.height, main.width, mapchip.size);
			main.oldMapNumber.RightTop = RightTopMapNum(main.oldworldPos, mapchip.scale, main.height, main.width, mapchip.size);
			main.oldMapNumber.RightBottom = RightBottomMapNum(main.oldworldPos, mapchip.scale, main.height, main.width, mapchip.size);


			///自機の４頂点のどれかが当たっている時
			if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x)] == 1 || map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] == 1 ||
				map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x)] == 1 || map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] == 1) {


				if (map[mapchip.number][int(main.oldMapNumber.RightTop.y)][int(main.mapNumber.RightTop.x)] != 1 && map[mapchip.number][int(main.oldMapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] != 1 &&
					map[mapchip.number][int(main.oldMapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x)] != 1 && map[mapchip.number][int(main.oldMapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] != 1) {


					///ｙ軸に当たった時の斜め反応
					main.worldPos.y = float(main.fitMapSize.inty);
					main.velocity = 3;///速度落とす
					main.acceleration = 0;///加速度いったん無くす
					flag.isFallStop = 1;///急降下いったん止める
					flag.isFallColl = 1;
					flag.isDamage = 1;///ダメージを受ける
					main.damageShake.isShake = 1;///シェイクを開始する
					main.damageShake.time = 30;///シェイクの時間を決める


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
					main.velocity = 3;///速度落とす
					main.acceleration = 0;///加速度いったん無くす
					flag.isFallStop = 1;///急降下いったん止める
					flag.isDamage = 1;///ダメージを受ける
					flag.isFallColl = 1;
					main.damageShake.isShake = 1;///シェイクを開始する
					main.damageShake.time = 30;///シェイクの時間を決める


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

			///↑↑↑↑↑↑↑マップチップの当たり判定ここまで↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

			///↓↓↓↓↓↓↓↓↓↓↓↓↓演出系ここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

			Shake(main.damageShake.random.x, main.damageShake.random.y, main.damageShake.isShake, main.damageShake.time, 25, 25);



			///↑↑↑↑↑↑↑↑↑↑↑↑↑演出系ここまで↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

			

			///↓↓↓↓↓↓↓↓↓座標変換↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


			///プレイヤーのY軸のスクロールする座標
			main.scrollPos.x = main.worldPos.x - main.kameraPos.x;
			main.scrollPos.y = main.worldPos.y - main.kameraPos.y;

			///プレイヤーのY軸の画面に映る座標
			main.screenPos.x = main.worldPos.x - main.scrollPos.x;
			main.screenPos.y = main.worldPos.y - main.scrollPos.y;



			///マップチップのY軸の座標
			
			
			 screenCenterX = 1280 / 2; // 画面の中央X座標
			 screenCenterY = 720 / 2;  // 画面の中央Y座標
			

			// 4. 新しいスクロール位置を計算
			
			mapchip.ScrollPos.x = 600 - (main.worldPos.x * mapchip.scale);
			mapchip.ScrollPos.y = 100 - (main.worldPos.y * mapchip.scale);

		
			///敵の座標変換
			for (int i = 0; i < 10; i++) {

				enemy.screenPos[i].x = enemy.worldPos[i].x + mapchip.ScrollPos.x;
				enemy.screenPos[i].y = enemy.worldPos[i].y + mapchip.ScrollPos.y;

			}

			break;

			case RESULT:

				break;
		}

		///
		/// ↑更新処理ここまで
		///

		/// ↓描画処理ここから
	

		switch (Scene) {

		case TITLE:
			///タイトル画面の描画

			Novice::DrawSprite(int(sc.pos1.x + sc.random.x), int(sc.pos1.y), sceneChangeHandle, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(int(sc.pos2.x + sc.random.x), int(sc.pos2.y), sceneChangeHandle2, 1, 1, 0.0f, 0xFFFFFFFF);

			break;

		case PLAY:

			///背景の描画
			Novice::DrawSprite(int(0 + main.damageShake.random.x), int(background.back1.y + main.damageShake.random.y), BackGround, 1, 1, 0, WHITE);
			Novice::DrawSprite(int(0 + main.damageShake.random.x), int(background.back2.y + main.damageShake.random.y), BackGround, 1, 1, 0, WHITE);
			Novice::DrawSprite(0, int(background.flont1.y + main.damageShake.random.y), frontBackGround, 1, 1, 0, WHITE);
			Novice::DrawSprite(0, int(background.flont2.y + main.damageShake.random.y), frontBackGround, 1, 1, 0, WHITE);


			///マップチップの描画
			for (int i = 0; i < 100; i++) {

				for (int j = 0; j < 66; j++) {

					if ((j * mapchip.size + mapchip.ScrollPos.x) >= -mapchip.size && (j * mapchip.size + mapchip.ScrollPos.x) <= 1280 + mapchip.size && (i * mapchip.size + mapchip.ScrollPos.y) >= -mapchip.size && (i * mapchip.size + mapchip.ScrollPos.y) <= 720 + mapchip.size) {

						if (map[mapchip.number][i][j] == 1) {

							Novice::DrawQuad(int((mapchip.ScrollPos.x+(j * mapchip.size  + main.damageShake.random.x))), int((mapchip.ScrollPos.y+(i * mapchip.size  + main.damageShake.random.y))), int((mapchip.ScrollPos.x+(j * mapchip.size  + mapchip.size + main.damageShake.random.x))), int((mapchip.ScrollPos.y+(i * mapchip.size  + main.damageShake.random.y))), int((mapchip.ScrollPos.x+(j * mapchip.size + main.damageShake.random.x))), int((mapchip.ScrollPos.y+(i * mapchip.size  + mapchip.size + main.damageShake.random.y))), int((mapchip.ScrollPos.x+(j * mapchip.size  + mapchip.size + main.damageShake.random.x))), int((mapchip.ScrollPos.y+(i * mapchip.size  + mapchip.size + main.damageShake.random.y))), 0, 0, 24, 24, mapchip.Handle, WHITE);

						}
					}
				}
			}

			///敵の描画
			for (int i = 0; i < 10; i++) {

				if (flag.isEnemyDeath[i] == 0) {

					newDrawQuad(enemy.vertexPos[i].LeftTop, enemy.vertexPos[i].RightTop, enemy.vertexPos[i].LeftBottom, enemy.vertexPos[i].RightBottom, 0, 0, 48, 48, mapchip.Handle, WHITE);
				}
			}

			///プレイヤーの描画
			newDrawQuad(main.vertexPos.LeftTop, main.vertexPos.RightTop, main.vertexPos.LeftBottom, main.vertexPos.RightBottom, 0, 0, 48, 48, main.Handle, WHITE);


			Novice::DrawLine(0, int(main.worldPos.y + mapchip.ScrollPos.y), 1280, int(main.worldPos.y + mapchip.ScrollPos.y), RED);

			Novice::DrawLine(0, int(main.oldworldPos.y + mapchip.ScrollPos.y), 1280, int(main.oldworldPos.y + mapchip.ScrollPos.y), WHITE);

			

			newScreenPrintf(0, 0, flag.isScaleUp);
			newScreenPrintf(0, 20, main.worldPos.x);
			newScreenPrintf(0, 40, main.scaleDownEasing.time);
			newScreenPrintf(0, 60, main.totalScale);
			newScreenPrintf(0, 80, main.oldMapNumber.LeftTop.x);
			newScreenPrintf(0, 100, main.mapNumber.LeftTop.x);

			break;


		case RESULT:

			break;

		}

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

