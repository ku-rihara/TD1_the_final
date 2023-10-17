#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include"FunctionK.h"
#include"FunctionS.h"


const char kWindowTitle[] = "LC1A_11_クリハラ_ケイタ_タイトル";




// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	///シェイクスピア
	srand(unsigned int(time(nullptr)));


	//マップ40x26
	int map[3][mapy][mapx]{

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
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,},
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
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},
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
	ENEMYCHARACTER target{};///敵のターゲット
	ITEM item{};///アイテム
	BEAM beam{};///ビームアイテム
	MAPCHIP mapchip{};///マップチップの初期化
	BACKGROUND background{};///背景の初期化
	DISTANCE distance{};
	FLAG flag{};
	///トンネリング防止の変数初期化
	Vector2 e{};
	Vector2 f{};
	Vector2 Linedistance{};
	Easing Anticipation{};
	Easing afterimage{};
	Easing enemyTarget[enemynum]{};

	SceneChangeP sc{
		{0,0},
		{0,0},
		{640,-320},
		{640,1080},
		0,
		false
	};


	///↓↓↓↓↓↓↓↓↓画像初期化↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
	int frontBackGround;
	int BackGround;
	int sceneChangeHandle;
	int sceneChangeHandle2;
	
	main.Handle = Novice::LoadTexture("./Resources./Images./player1-3.png");
	enemy.Handle= Novice::LoadTexture("./Resources./Images./enemy.png");
	target.Handle= Novice::LoadTexture("./Resources./Images./target.png");
	mapchip.Handle = Novice::LoadTexture("./Resources./Images./block.png");///マップチップの画像
	item.Handle = Novice::LoadTexture("white1x1.png");
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
			
			SceneChange(sc.center1.y, sc.center2.y, sc.isSceneChange, flag.isSceneChange, sc.random.x);
	
			if (flag.isSceneChange == 1) {

				///プレイヤーの初期座標
				main.worldPos.x = 900;
				main.worldPos.y = 200;

				///プレイヤーのそれぞれ頂点の中心からの幅
				main.vertexWide.LeftTop = { 48,48 };
				main.vertexWide.RightTop = { 48,48 };
				main.vertexWide.LeftBottom = { 48,48 };
				main.vertexWide.RightBottom = { 48,48 };

				///プレイヤーのそれぞれ頂点の中心からの幅
				beam.vertexWide.LeftTop = { 48,48 };
				beam.vertexWide.RightTop = { 48,48 };
				beam.vertexWide.LeftBottom = { 48,48 * 13 };
				beam.vertexWide.RightBottom = { 48,48 * 13 };

				///敵の半径
				main.radius = 24;

				///敵の位置初期化
				for (int i = 0; i < enemynum; i++) {

					///敵の半径
					enemy.radius[i] = 24;

					enemy.worldPos[i].x = 1300;
					enemy.worldPos[i].y = 900 + float(i) * 200;


					///エネミーのそれぞれ頂点の中心からの幅
					enemy.vertexWide[i].LeftTop = { 48,48 };
					enemy.vertexWide[i].RightTop = { 48,48 };
					enemy.vertexWide[i].LeftBottom = { 48,48 };
					enemy.vertexWide[i].RightBottom = { 48,48 };

					///エネミーのそれぞれ頂点の中心からの幅
					target.vertexWide[i].LeftTop = { 48,48 };
					target.vertexWide[i].RightTop = { 48,48 };
					target.vertexWide[i].LeftBottom = { 48,48 };
					target.vertexWide[i].RightBottom = { 48,48 };

					enemyTarget[i].easingPlus = 0.01f;
				}

				enemy.easing.easingPlus = 0.01f;



				for (int i = 0; i < 10; i++) {

					///敵の半径
					item.radius[i] = 24;
					item.worldPos[i].x = 1800;
					item.worldPos[i].y = 900 + float(i) * 200;


					///アイテムの中心からの頂点
					item.vertexWide[i].LeftTop = { 48,48 };
					item.vertexWide[i].RightTop = { 48,48 };
					item.vertexWide[i].LeftBottom = { 48,48 };
					item.vertexWide[i].RightBottom = { 48,48 };
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
				main.velocity.y = 5;

				
				///プレイヤーの画面上に映し続ける座標
				main.kameraPos.x = 600;
				main.kameraPos.y = 200;



				Scene += 1;

			}

				break;

		case PLAY:

			

			///↓↓↓↓↓↓↓↓ゲームプレイ中の処理ここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

			sc.pos1.x = LeftTopX(sc.center1.x, 1320);
			sc.pos2.x = LeftTopX(sc.center2.x, 1320);
			sc.pos1.y = LeftTopY(sc.center1.y, 720);
			sc.pos2.y = LeftTopY(sc.center2.y, 720);


			SceneChange(sc.center1.y, sc.center2.y, sc.isSceneChange, flag.isSceneChange, sc.random.x);

			///前背景の移動
			background.flont1.y -= main.velocity.y * 0.1f;
			background.flont2.y -= main.velocity.y * 0.1f;

			///後ろ背景の移動
			background.back1.y -= main.velocity.y * 0.05f;
			background.back2.y -= main.velocity.y * 0.05f;


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
			if (mapchip.ScrollPos.y <= -mapchip.size * mapy) {
				main.worldPos.y = 0;

				for (int i = 0; i < 3; i++) {

					main.afterimageWorldPos[i].x = main.worldPos.x;
					main.afterimageWorldPos[i].y = main.worldPos.y;
				}

				for (int i = 0; i < enemynum; i++) {

					enemyTarget[i].easingTime=0;

				}

				///壊れたマップの復元
				for (int i = 0; i < mapy; i++) {

					for (int j = 0; j < mapx; j++) {

						if (map[mapchip.number][i][j] == 3) {

							map[mapchip.number][i][j] = 1;
						}
					}
				}
			}

			///↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑背景またはスクロールの処理終わり↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑


			///↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓頂点の座標計算ここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


			///プレイヤーの4頂点の座標計算
			main.vertexPos.LeftTop = LeftTopVertex(main.screenPos, main.vertexWide.LeftTop, main.rotate, main.drawScale);
			main.vertexPos.LeftBottom = LeftBottomVertex(main.screenPos, main.vertexWide.LeftBottom, main.rotate, main.drawScale);
			main.vertexPos.RightTop = RightTopVertex(main.screenPos, main.vertexWide.RightTop, main.rotate, main.drawScale);
			main.vertexPos.RightBottom = RightBottomVertex(main.screenPos, main.vertexWide.RightBottom, main.rotate, main.drawScale);

			///残像4頂点の座標計算
			for (int i = 0; i < 3; i++) {

				main.afterimagePos[i].LeftTop = LeftTopVertex(main.afterimageScreenPos[i], main.vertexWide.LeftTop, main.rotate, main.drawScale);
				main.afterimagePos[i].LeftBottom = LeftBottomVertex(main.afterimageScreenPos[i], main.vertexWide.LeftBottom, main.rotate, main.drawScale);
				main.afterimagePos[i].RightTop = RightTopVertex(main.afterimageScreenPos[i], main.vertexWide.RightTop, main.rotate, main.drawScale);
				main.afterimagePos[i].RightBottom = RightBottomVertex(main.afterimageScreenPos[i], main.vertexWide.RightBottom, main.rotate, main.drawScale);
			}

			///敵の頂点の座標計算
			for (int i = 0; i < enemynum; i++) {

				enemy.vertexPos[i].LeftTop = LeftTopVertex(enemy.screenPos[i], enemy.vertexWide[i].LeftTop, 0, mapchip.scale);
				enemy.vertexPos[i].LeftBottom = LeftBottomVertex(enemy.screenPos[i], enemy.vertexWide[i].LeftBottom, 0, mapchip.scale);
				enemy.vertexPos[i].RightTop = RightTopVertex(enemy.screenPos[i], enemy.vertexWide[i].RightTop, 0, mapchip.scale);
				enemy.vertexPos[i].RightBottom = RightBottomVertex(enemy.screenPos[i], enemy.vertexWide[i].RightBottom, 0, mapchip.scale);

				///ターゲットの座標計算
				target.vertexPos[i].LeftTop = LeftTopVertex(enemy.screenPos[i], target.vertexWide[i].LeftTop, 0, target.scale[i]*mapchip.scale);
				target.vertexPos[i].LeftBottom = LeftBottomVertex(enemy.screenPos[i], target.vertexWide[i].LeftBottom, 0, target.scale[i]*mapchip.scale);
				target.vertexPos[i].RightTop = RightTopVertex(enemy.screenPos[i], target.vertexWide[i].RightTop, 0, target.scale[i]*mapchip.scale);
				target.vertexPos[i].RightBottom = RightBottomVertex(enemy.screenPos[i], target.vertexWide[i].RightBottom, 0, target.scale[i]*mapchip.scale);


				///敵がふわふわ動くイージング
				enemy.easing.easingTime += enemy.easing.easingPlus;

				if (enemy.easing.easingTime >= 1) {

					enemy.easing.easingPlus = -enemy.easing.easingPlus;
				}

				enemy.vertexWide[i].LeftTop.y = easeInSine(enemy.easing, 40, 48);
				enemy.vertexWide[i].RightTop.y = easeInSine(enemy.easing, 40, 48);


				///ターゲットのイージング
				if ((enemy.screenPos[i].x) >= -mapchip.size && (enemy.screenPos[i].x) <= 1280 + mapchip.size && (enemy.screenPos[i].y) >= -mapchip.size && (enemy.screenPos[i].y) <= 720 + mapchip.size) {

					enemyTarget[i].easingTime += enemyTarget[i].easingPlus;

					if (enemyTarget[i].easingTime >= 1) {

						enemyTarget[i].easingTime = 1;
					}

					target.scale[i] = easeOutBack(enemyTarget[i], 0, 1.3f);
				
				}


				enemy.radius[i] = 24 * mapchip.scale;
				item.radius[i] = 24 * mapchip.scale;
			}

			for (int i = 0; i < 10; i++) {

				///アイテムの頂点座標
				item.vertexPos[i].LeftTop = LeftTopVertex(item.screenPos[i], item.vertexWide[i].LeftTop, 0, mapchip.scale);
				item.vertexPos[i].LeftBottom = LeftBottomVertex(item.screenPos[i], item.vertexWide[i].LeftBottom, 0, mapchip.scale);
				item.vertexPos[i].RightTop = RightTopVertex(item.screenPos[i], item.vertexWide[i].RightTop, 0, mapchip.scale);
				item.vertexPos[i].RightBottom = RightBottomVertex(item.screenPos[i], item.vertexWide[i].RightBottom, 0, mapchip.scale);
			}

			///ビームの頂点座標
			beam.vertexPos.LeftTop = LeftTopVertex(beam.screenPos, beam.vertexWide.LeftTop, beam.rotate, main.drawScale);
			beam.vertexPos.LeftBottom = LeftBottomVertex(beam.screenPos, beam.vertexWide.LeftBottom, beam.rotate, main.drawScale);
			beam.vertexPos.RightTop = RightTopVertex(beam.screenPos, beam.vertexWide.RightTop, beam.rotate, main.drawScale);
			beam.vertexPos.RightBottom = RightBottomVertex(beam.screenPos, beam.vertexWide.RightBottom, beam.rotate, main.drawScale);


			main.oldworldPos.x = main.worldPos.x;
			main.oldworldPos.y = main.worldPos.y;


			///スケールを掛けてく
			main.height = 48 * main.drawScale;
			main.width = 48 * main.drawScale;
			main.radius = 24 * main.drawScale;
			mapchip.size = 48 * mapchip.scale;

			///↑↑↑↑↑↑↑↑↑↑↑↑頂点の座標計算ここから↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑


			///プレイヤーのX軸の動き-----------------------------------------------------------------------------------------------------------------------------------------

			if (flag.isLeftDamage == 0 && flag.isRightDamage == 0 && flag.isMapZoomInOut == 0) {

				if (keys[DIK_A] || keys[DIK_LEFT]) {
					main.worldPos.x += -6;
				}

				if (keys[DIK_D] || keys[DIK_RIGHT]) {
					main.worldPos.x += 6;
				}
			}

			if (flag.isLeftDamage == 1) {

				main.sideDamageTime += 1;

				main.worldPos.x += 18 * 0.3f;

				if (main.sideDamageTime >= 60) {

					flag.isLeftDamage = 0;
					main.sideDamageTime = 0;
				}
			}

			if (flag.isRightDamage == 1) {

				main.sideDamageTime += 1;
				main.worldPos.x -= 18 * 0.3f;

				if (main.sideDamageTime >= 60) {

					flag.isRightDamage = 0;
					main.sideDamageTime = 0;
				}
			}

			///プレイヤーのY軸の動き----------------------------------------------------------------------------

			if (flag.isFallStop == 0 && flag.isHitBack == 0) {

				main.acceleration.y = 0.01f;
			}

			///加速度足していき
			main.velocity.y += main.acceleration.y;

			///座標に速度を足していく
			main.worldPos.y += main.velocity.y;


			///急降下していい状態の時
			if (flag.isFallColl == 0 && flag.isHitBack == 0) {

				if (keys[DIK_SPACE] && flag.isAnticipation == 0 && flag.isFallHighSpeed == 0) {

					main.velocitySave = main.velocity;///急降下するとき速度を保存
					main.ScaleSave = main.drawScale;
					main.saveWorldPos.y = main.worldPos.y;
					mapchip.saveScale = mapchip.scale;
					Anticipation.easingPlus = 0.1f;

					flag.isAnticipation = 1;///高速降下予備動作発動
				}


				///予備動作始め
				if (flag.isAnticipation == 1 && flag.isFallHighSpeed == 0) {

					Anticipation.easingTime += Anticipation.easingPlus;

					main.worldPos.y = easeOutSine(Anticipation, main.saveWorldPos.y, main.saveWorldPos.y - 50);


					if (Anticipation.easingTime >= 1.0f) {

						Anticipation.easingPlus = -Anticipation.easingPlus;
					}

					if (Anticipation.easingTime < 0) {

						Anticipation.easingTime = 0;
						flag.isAnticipation = 0;
						flag.isFallHighSpeed = 1;
					}

					///早期キャンセル
					if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] || flag.isDamage == 1) {

						main.velocity = main.velocitySave;
						flag.isFallHighSpeed = 0;
						flag.isAnticipation = 0;
						Anticipation.easingTime = 0;
						main.worldPos.y = main.saveWorldPos.y - 10;
					}
				}

				///急降下する
				if (flag.isFallHighSpeed == 1 && flag.isAnticipation == 0) {

					main.velocity.y = 28;

					///急降下をやめる時は保存した速度になう速度を代入
					if (keys[DIK_SPACE] == 0 || flag.isDamage == 1) {

						main.velocity = main.velocitySave;
						flag.isFallHighSpeed = 0;
					}
				}
			}

			///プレイヤーのY軸の動き------------------------------------------------------------------------------------------


			///残像の動き------------------------------------------------------------------------------------------------------------------

			for (int i = 0; i < 3; i++) {

				afterimage.easingTime = 0.25f;

				main.afterimageWorldPos[0].x = easeOutSine(afterimage, main.afterimageWorldPos[0].x, main.worldPos.x);
				main.afterimageWorldPos[0].y = easeOutSine(afterimage, main.afterimageWorldPos[0].y, main.worldPos.y - 10);

				if (i >= 1) {

					main.afterimageWorldPos[i].x = easeOutSine(afterimage, main.afterimageWorldPos[i].x, main.afterimageWorldPos[i - 1].x);
					main.afterimageWorldPos[i].y = easeOutSine(afterimage, main.afterimageWorldPos[i].y, main.afterimageWorldPos[i - 1].y - 1);
				}
			}

			///残像の動き------------------------------------------------------------------------------------------------------------------


			///↓↓↓↓↓↓↓↓トンネリングを防ぐ処理（カプセル作成）↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

		/*	for (int i = 0; i < 10; i++) {

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
			f.y = (1.0f - main.time) * main.oldworldPos.y + main.time * main.worldPos.y;*/

			///↑↑↑↑↑↑↑↑↑↑↑トンネリングを防ぐ処理（カプセル作成）↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑


			///敵との当たり判定とかダメージを受けた時の処理とか複雑―な処理------------------------------------------------------------


			for (int i = 0; i < enemynum; i++) {

				if (flag.isEnemyDeath[i] == 0) {

					///敵とプレイヤーのカプセルの距離
					distance.enemyANDplayer[i] = length(main.worldPos.x - enemy.worldPos[i].x, main.worldPos.y - enemy.worldPos[i].y);
					distance.beamANDenemy[i] = isBoxCollisionBeta(beam.vertexPos.LeftTop.x, beam.vertexPos.LeftTop.y, beam.vertexPos.RightBottom.x, beam.vertexPos.RightBottom.y, enemy.vertexPos[i].LeftTop.x, enemy.vertexPos[i].LeftTop.y, enemy.vertexPos[i].RightBottom.x, enemy.vertexPos[i].RightBottom.y);


					///急降下してない状態で当たったら
					if (distance.enemyANDplayer[i] <= enemy.radius[i] + main.radius && flag.isFallHighSpeed == 0) {

						flag.isDamage = 1;
						flag.isEnemyDeath[i] = 1;
					}

					///敵を倒す処理
					if (distance.enemyANDplayer[i] <= enemy.radius[i] + main.radius && flag.isFallHighSpeed == 1 || distance.beamANDenemy[i] == 1 && item.Have == speedbeam) {

						flag.isEnemyDeath[i] = 1;
						flag.isHit = 1;
						main.ScaleSave = main.drawScale;
						flag.isScaleUp = 1;
						Sleep(120);
					}
				}

				if (flag.isEnemyDeath[i] == 1) {

					///敵が死ぬ処理----++++++エフェクトとか
				}
			}

			for (int i = 0; i < 10; i++) {

				distance.itemANDplayer[i] = length(main.worldPos.x - item.worldPos[i].x, main.worldPos.y - item.worldPos[i].y);

				///アイテム拾ったら
				if (distance.itemANDplayer[i] <= item.radius[i] + main.radius) {

					flag.isItemGet = 1;
				}

			}

			///アイテム取った――
			if (flag.isItemGet == 1) {

				item.Have = 2;
				flag.isItemGet = 0;
			}

			///アイテムパタ―ン---------------------------------------------------------------------------------------------------------------------------------

			///ビームを拾ったとき
			if (item.Have == speedbeam) {

				beam.worldPos = main.worldPos;

			}












			///アイテムパタ-ン---------------------------------------------------------------------------------------------------------------------------------


			///ダメージ受けた時の処理
			if (flag.isDamage == 1 && flag.isDamageColl == 0) {

				main.ScaleSave = main.drawScale;
				mapchip.saveScale = mapchip.scale;
				main.scaleUp.easingTime = 0;
				main.scaleDown.easingTime = 0;
				flag.isDamageColl = 1;
				flag.isHitBack = 1;
				flag.isDamage = 0;
				main.velocity.y = -15;
				flag.isHitBack = 1;


				if (item.Have != barriaItem) {

					flag.isScaleDown = 1;
					main.totalScale -= 0.2f;
				}

				else if (item.Have == 1) {

					item.Have = 0;
				}
			}

			if (flag.isHitBack == 1) {

				main.acceleration.y = 0.4f;///加速度いったん無くす

				main.hitBackTime += 1;

				if (main.hitBackTime >= 40) {

					main.velocity.y = 3;
					main.acceleration.y = 0.01f;
					flag.isHitBack = 0;
					main.hitBackTime = 0;
				}
			}

			///ダメ―ジ受けた時のクールタイム1秒
			if (flag.isDamageColl == 1) {

				flag.isDamage = 0;
				main.damageCollTime += 1;

				if (main.damageCollTime >= 50) {

					flag.isDamageColl = 0;
					main.damageCollTime = 0;
				}
			}

			///ダメージを受けたら高速降下をいったん止める

			if (flag.isFallColl == 1) {

				flag.isFallHighSpeed = 0;
				flag.isAnticipation = 0;

				main.fallCollTime += 1;

				if (main.fallCollTime >= 50) {

					main.fallCollTime = 0;
					flag.isFallColl = 0;
				}
			}

			///プレイヤーが小さくなってしまう処理
			if (flag.isScaleDown == 1) {

				main.scaleDown.easingTime += 0.05f;

				main.drawScale = easeOutBack(main.scaleDown, main.ScaleSave, main.ScaleSave - 0.2f);

				if (main.scaleDown.easingTime >= 1.0f) {

					main.scaleDown.easingTime = 1;

					if (main.scaleDown.easingTime == 1) {

						main.scaleDown.easingTime = 0;
						flag.isScaleDown = 0;
					}
				}
			}

			///プレイヤーが大きくなる処理
			if (flag.isScaleUp == 1) {

				main.scaleUp.easingTime += 0.05f;

				main.drawScale = easeOutBack(main.scaleUp, main.ScaleSave, main.ScaleSave + 0.2f);

				if (main.scaleUp.easingTime >= 1.0f) {

					main.scaleUp.easingTime = 1;
				}
				if (main.scaleUp.easingTime == 1.0f) {

					flag.isScaleUp = 0;
					main.scaleUp.easingTime = 0;
				}
			}

			///敵との当たり判定とかダメージを受けた時の処理とか複雑―な処理------------------------------------------------------------


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

			///大きさに合わせカメラズーム------------------------------------------------------------------------------

			if (flag.isDamageColl == 0) {

				if (flag.isMapZoomInOut == 0) {

					///記録Level0
					if (main.totalScale < 2.0f && flag.ZoomLevel == 1) {

						flag.isMapZoomInOut = 1;
						flag.ZoomLevel = 0;
						main.ScaleSave = main.drawScale;
						main.saveWorldPos.y = main.worldPos.y;
						mapchip.saveScale = mapchip.scale;
					}

					///Level1
					if (main.totalScale >= 2.0f && flag.ZoomLevel == 0) {

						flag.isMapZoomInOut = 1;
						flag.ZoomLevel = 1;
						main.ScaleSave = main.drawScale;
						main.saveWorldPos.y = main.worldPos.y;
						mapchip.saveScale = mapchip.scale;
					}
				}

				///実際に行う
				if (flag.isMapZoomInOut == 1) {

					mapchip.zoomInOut.easingTime += 0.02f;

					if (flag.ZoomLevel == 0) {

						mapchip.scale = easeInSine(mapchip.zoomInOut, mapchip.saveScale, mapchip.saveScale + 0.3f);
						main.drawScale = easeInSine(mapchip.zoomInOut, main.ScaleSave, main.ScaleSave + 0.3f);
						main.worldPos.y = easeInSine(mapchip.zoomInOut, main.saveWorldPos.y, main.saveWorldPos.y);
					}

					else if (flag.ZoomLevel == 1) {

						mapchip.scale = easeInSine(mapchip.zoomInOut, mapchip.saveScale, mapchip.saveScale - 0.3f);
						main.drawScale = easeInSine(mapchip.zoomInOut, main.ScaleSave, main.ScaleSave - 0.3f);
						main.worldPos.y = easeInSine(mapchip.zoomInOut, main.saveWorldPos.y, main.saveWorldPos.y);
					}

					if (mapchip.zoomInOut.easingTime >= 1.0f) {

						mapchip.zoomInOut.easingTime = 1;
					}

					if (mapchip.zoomInOut.easingTime == 1) {
						mapchip.zoomInOut.easingTime = 0;
						flag.isMapZoomInOut = 0;
					}
				}
			}

			///大きさに合わせカメラズーム------------------------------------------------------------------------------


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
			main.mapNumber.LeftTop = LeftTopMapNum(main.worldPos, mapchip.scale, main.height, main.width, mapchip.size);
			main.mapNumber.LeftBottom = LeftBottomMapNum(main.worldPos, mapchip.scale, main.height, main.width, mapchip.size);
			main.mapNumber.RightTop = RightTopMapNum(main.worldPos, mapchip.scale, main.height, main.width, mapchip.size);
			main.mapNumber.RightBottom = RightBottomMapNum(main.worldPos, mapchip.scale, main.height, main.width, mapchip.size);


			///移動前のマップチップの番号の取得
			main.oldMapNumber.LeftTop = LeftTopMapNum(main.oldworldPos, mapchip.scale, main.height, main.width, mapchip.size);
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

					flag.isFallStop = 1;///急降下いったん止める
					flag.isFallColl = 1;
					flag.isDamage = 1;///ダメージを受ける
					main.damage.isShake = 1;///シェイクを開始する
					main.damage.shakeTime = 30;///シェイクの時間を決める


					///マップの破壊（どしゃん）
					if (map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] == 1) {

						map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] = 3;

						if (map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x) + 1] == 1) {

							map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x) + 1] = 3;

						}
					}

					///マップの破壊（どしゃん）
					if (map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] == 1) {

						map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] = 3;

						if (map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x) - 1] == 1) {

							map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x) - 1] = 3;

						}
					}
				}

				else if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.oldMapNumber.RightTop.x)] != 1 && map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.oldMapNumber.RightBottom.x)] != 1 &&
					map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.oldMapNumber.LeftTop.x)] != 1 && map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.oldMapNumber.LeftBottom.x)] != 1) {


					///ｘ軸に当たった時の斜め反応
					main.worldPos.x = float(main.fitOldMapSize.intx);


					///マップの破壊（どしゃん）
					if (map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] == 1) {

						map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] = 3;

						flag.isLeftDamage = 1;
						flag.isDamage = 1;///ダメージを受ける
						main.damage.isShake = 1;///シェイクを開始する
						main.damage.shakeTime = 30;///シェイクの時間を決める
					}

					///マップの破壊（どしゃん）
					if (map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] == 1) {

						map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] = 3;

						flag.isRightDamage = 1;
						flag.isDamage = 1;///ダメージを受ける
						main.damage.isShake = 1;///シェイクを開始する
						main.damage.shakeTime = 30;///シェイクの時間を決める
					}
				}

				else {

					///それ以外の反応
					main.worldPos.x = float(main.fitOldMapSize.intx);
					main.worldPos.y = float(main.fitMapSize.inty);

					flag.isFallStop = 1;///急降下いったん止める
					flag.isDamage = 1;///ダメージを受ける
					flag.isFallColl = 1;
					main.damage.isShake = 1;///シェイクを開始する
					main.damage.shakeTime = 30;///シェイクの時間を決める


					///マップの破壊（どしゃん）
					if (map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] == 1) {

						map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] = 3;


						if (map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x) + 1] == 1) {

							map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x) + 1] = 3;

						}
					}

					///マップの破壊（どしゃん）
					if (map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] == 1) {

						map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] = 3;

						if (map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x) - 1] == 1) {

							map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x) - 1] = 3;

						}
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
							flag.isDamage = 1;///ダメージを受ける

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

			Shake(main.damage.random.x, main.damage.random.y, main.damage.isShake, main.damage.shakeTime, 20, 20);


			///↑↑↑↑↑↑↑↑↑↑↑↑↑演出系ここまで↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑


			///↓↓↓↓↓↓↓↓↓ ↓↓↓↓↓座標変換↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


			///プレイヤーのY軸のスクロールする座標
			main.scrollPos.x = main.worldPos.x - main.kameraPos.x;
			main.scrollPos.y = main.worldPos.y - main.kameraPos.y;

			///プレイヤーのY軸の画面に映る座標
			main.screenPos.x = main.worldPos.x - main.scrollPos.x;
			main.screenPos.y = main.worldPos.y - main.scrollPos.y;

			mapchip.ScrollPos.x = main.kameraPos.x - (main.worldPos.x * mapchip.scale);
			mapchip.ScrollPos.y = main.kameraPos.y - (main.worldPos.y * mapchip.scale);


			///敵の座標変換
			for (int i = 0; i < enemynum; i++) {

				enemy.screenPos[i].x = (enemy.worldPos[i].x * mapchip.scale) + mapchip.ScrollPos.x;
				enemy.screenPos[i].y = (enemy.worldPos[i].y * mapchip.scale) + mapchip.ScrollPos.y;


			}

			for (int i = 0; i < 10; i++) {

				item.screenPos[i].x = (item.worldPos[i].x * mapchip.scale) + mapchip.ScrollPos.x;
				item.screenPos[i].y = (item.worldPos[i].y * mapchip.scale) + mapchip.ScrollPos.y;

			}

			for (int i = 0; i < 3; i++) {

				main.afterimageScreenPos[i].x = (main.afterimageWorldPos[i].x * mapchip.scale) + mapchip.ScrollPos.x;
				main.afterimageScreenPos[i].y = (main.afterimageWorldPos[i].y * mapchip.scale) + mapchip.ScrollPos.y;

			}

			///ビームの座標変換
			beam.screenPos.x = (beam.worldPos.x * mapchip.scale) + mapchip.ScrollPos.x;
			beam.screenPos.y = (beam.worldPos.y * mapchip.scale) + mapchip.ScrollPos.y;


			break;

		case RESULT:

			break;
			}


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
				Novice::DrawSprite(int(0 + main.damage.random.x), int(background.back1.y + main.damage.random.y), BackGround, 1, 1, 0, WHITE);
				Novice::DrawSprite(int(0 + main.damage.random.x), int(background.back2.y + main.damage.random.y), BackGround, 1, 1, 0, WHITE);
				Novice::DrawSprite(0, int(background.flont1.y + main.damage.random.y), frontBackGround, 1, 1, 0, WHITE);
				Novice::DrawSprite(0, int(background.flont2.y + main.damage.random.y), frontBackGround, 1, 1, 0, WHITE);


				///マップチップの描画
				for (int i = 0; i < mapy; i++) {

					for (int j = 0; j < mapx; j++) {

						if ((j * mapchip.size + mapchip.ScrollPos.x) >= -mapchip.size && (j * mapchip.size + mapchip.ScrollPos.x) <= 1280 + mapchip.size && (i * mapchip.size + mapchip.ScrollPos.y) >= -mapchip.size && (i * mapchip.size + mapchip.ScrollPos.y) <= 720 + mapchip.size) {

							if (map[mapchip.number][i][j] == 1) {

								Novice::DrawQuad(int((mapchip.ScrollPos.x + (j * mapchip.size + main.damage.random.x))), int((mapchip.ScrollPos.y + (i * mapchip.size + main.damage.random.y))), int((mapchip.ScrollPos.x + (j * mapchip.size + mapchip.size + main.damage.random.x))), int((mapchip.ScrollPos.y + (i * mapchip.size + main.damage.random.y))), int((mapchip.ScrollPos.x + (j * mapchip.size + main.damage.random.x))), int((mapchip.ScrollPos.y + (i * mapchip.size + mapchip.size + main.damage.random.y))), int((mapchip.ScrollPos.x + (j * mapchip.size + mapchip.size + main.damage.random.x))), int((mapchip.ScrollPos.y + (i * mapchip.size + mapchip.size + main.damage.random.y))), 0, 0, 48, 48, mapchip.Handle, WHITE);

							}
						}
					}
				}


				///ビーム
				newDrawQuad(beam.vertexPos.LeftTop, beam.vertexPos.RightTop, beam.vertexPos.LeftBottom, beam.vertexPos.RightBottom, 0, 0, 48, 48 * 30, item.Handle, WHITE);

				///アイテムの描画
				for (int i = 0; i < 10; i++) {

					newDrawQuad(item.vertexPos[i].LeftTop, item.vertexPos[i].RightTop, item.vertexPos[i].LeftBottom, item.vertexPos[i].RightBottom, 0, 0, 48, 48, item.Handle, WHITE);
				}

				///敵の描画
				for (int i = 0; i < enemynum; i++) {

					if (flag.isEnemyDeath[i] == 0) {

						newDrawQuad(enemy.vertexPos[i].LeftTop, enemy.vertexPos[i].RightTop, enemy.vertexPos[i].LeftBottom, enemy.vertexPos[i].RightBottom, 0, 0, 48, 48, enemy.Handle, WHITE);

						newDrawQuad(target.vertexPos[i].LeftTop, target.vertexPos[i].RightTop, target.vertexPos[i].LeftBottom, target.vertexPos[i].RightBottom, 0, 0, 48, 48, target.Handle, WHITE);

					}
				}


				///残像の描画
				for (int i = 0; i < 3; i++) {

					Novice::DrawEllipse(int(main.afterimageScreenPos[i].x), int(main.afterimageScreenPos[i].y), int(24 * main.drawScale), int(24 * main.drawScale), 0, 0xff000011, kFillModeSolid);
				}

				///プレイヤーの描画
				newDrawQuad(main.vertexPos.LeftTop, main.vertexPos.RightTop, main.vertexPos.LeftBottom, main.vertexPos.RightBottom, 0, 0, 48, 48, main.Handle, WHITE);



				///かわいいシーン遷移
				Novice::DrawSprite(int(sc.pos1.x + sc.random.x), int(sc.pos1.y), sceneChangeHandle, 1, 1, 0.0f, 0xFFFFFFFF);
				Novice::DrawSprite(int(sc.pos2.x + sc.random.x), int(sc.pos2.y), sceneChangeHandle2, 1, 1, 0.0f, 0xFFFFFFFF);


				newScreenPrintf(0, 0, mapchip.saveScale);
				newScreenPrintf(0, 20, item.Have);
				newScreenPrintf(0, 40, distance.beamANDenemy[2]);
				newScreenPrintf(0, 60, main.totalScale);
				newScreenPrintf(0, 80, flag.isFallColl);
				newScreenPrintf(0, 100, main.velocity.y);

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

