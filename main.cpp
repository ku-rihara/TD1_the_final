#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include"FunctionK.h"
#include"FunctionS.h"
#include"map.h"
#include "Particle.h"
#include"acceleratingEffect.h"

const char kWindowTitle[] = "LC1A_11_クリハラ_ケイタ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	///シェイクスピア
	srand(unsigned int(time(nullptr)));

	int Scene = 0;


	///構造体初期化
	MAINCHARACTER main{};///プレイヤーの初期化
	ENEMYCHARACTER enemy{};///敵の初期化
	ENEMYCHARACTER target{};///敵のターゲット
	ITEM item{};///アイテム
	PIECES pieces{};
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
	Easing fever{};
	SCORE score{};
	Mask mask {};
	BEAM box{};
	BEAM tutorialbord{};
	BEAM tutorialbord2{};
	BEAM tutorialbord3{};
	BEAM tutorialbord4{};
	AcceleratingEffect ac{};

	SceneChangeP sc{
		{0,0},
		{0,0},
		{640,-320},
		{640,1080},
		0,
		false
	};


	for (int r = 0; r < 7; r++) {
		
	///敵の位置ロード
    	for (int i = 0; i < enemynum; i++) {

		    if (flag.isEnemyDeath[i] == 0) {

			///敵を配置------------------------------
				for (int y = 0; y < mapy; y++) {

					for (int x = 0; x < mapx; x++) {

						if (map[r][y][x] == 4) {

							/// マップチップ番号に基づいて座標を設定
							enemy.Spone[r].x = float(x) * 49;
							enemy.Spone[r].y = float(y) * 48;

							/// 新しい敵を作成して座標を設定
							enemy.worldPos[r][i].x = enemy.Spone[r].x;
							enemy.worldPos[r][i].y = enemy.Spone[r].y;

							/// i をインクリメント
							i++;				
						}
					}
				}
			}
		}
	}


	for (int r = 0; r < 7; r++) {

		///アイテムの位置ロード
		for (int z = 0; z < itemnum; z++) {

			if (flag.isPiecesNone[z] == 0) {

				///アイテムを配置------------------------------
				for (int y = 0; y < mapy; y++) {

					for (int x = 0; x < mapx; x++) {

						if (map[r][y][x] == 5) {

							/// マップチップ番号に基づいて座標を設定
							item.Spone[r].x = float(x) * 48;
							item.Spone[r].y = float(y) * 48;

							/// 新しい敵を作成して座標を設定
							item.worldPos[r][z].x = item.Spone[r].x;
							item.worldPos[r][z].y = item.Spone[r].y;


							/// i をインクリメント
							z++;
						}
					}
				}
			}
		}

	}


	for (int r = 0; r < 7; r++) {

		///大きくなるかけらの位置ロード
		for (int p = 0; p < piecesnum; p++) {

			if (flag.isPiecesNone[p] == 0) {

				///アイテムを配置------------------------------
				for (int y = 0; y < mapy; y++) {

					for (int x = 0; x < mapx; x++) {

						if (map[r][y][x] == 6) {

							/// マップチップ番号に基づいて座標を設定
							pieces.Spone[r].x = float(x) * 48;
							pieces.Spone[r].y = float(y) * 48;

							/// 新しい敵を作成して座標を設定
							pieces.worldPos[r][p].x = pieces.Spone[r].x;
							pieces.worldPos[r][p].y = pieces.Spone[r].y;


							/// i をインクリメント
							p++;
						}
					}
				}
			}
		}
	}


	///敵のサイズ増え方
	main.scaleUpPlus = 0.5f;
	
	///↓↓↓↓↓↓↓↓↓画像初期化↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
	int frontBackGround;
	int BackGround;
	int sceneChangeHandle;
	int sceneChangeHandle2;
	int numberHandle;
	
	box.Handle= Novice::LoadTexture("white1x1.png");
	main.Handle = Novice::LoadTexture("./Resources./Images./player1-3.png");
	enemy.Handle = Novice::LoadTexture("./Resources./Images./enemy.png");
	target.Handle= Novice::LoadTexture("./Resources./Images./scope4.png");
	mapchip.Handle = Novice::LoadTexture("./Resources./Images./block.png");///マップチップの画像
	item.Handle = Novice::LoadTexture("./Resources./Images./SkillBox.png");
	beam.Handle= Novice::LoadTexture("white1x1.png");
	pieces.Handle= Novice::LoadTexture("./Resources./Images./point.png");
	numberHandle= Novice::LoadTexture("./Resources./Images./number.png");
	frontBackGround = Novice::LoadTexture("./Resources./Images./backgrondA.png");
	BackGround = Novice::LoadTexture("./Resources./Images./BackGroundB.png");
	sceneChangeHandle=Novice::LoadTexture("./Resources./Images./SceneChange1.png");
	sceneChangeHandle2=Novice::LoadTexture("./Resources./Images./SceneChange2.png");

	///ちゅーとりある　
	tutorialbord.Handle = Novice::LoadTexture("./Resources./Images./tutorial.png");
	tutorialbord2.Handle = Novice::LoadTexture("./Resources./Images./tutorial2.png");
	tutorialbord3.Handle = Novice::LoadTexture("./Resources./Images./tutorial3.png");
	tutorialbord4.Handle = Novice::LoadTexture("./Resources./Images./tutorial4.png");

	

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

			///シーンチェンジ
			SceneChange(sc.center1.y, sc.center2.y, sc.isSceneChange, flag.isSceneChange, sc.random.x);

			if (flag.isSceneChange == 1) {

				///プレイヤーの初期座標
				main.worldPos.x = 1600;
				main.worldPos.y = 584;

				///プレイヤーのそれぞれ頂点の中心からの幅
				main.vertexWide.LeftTop = { 48,48 };
				main.vertexWide.RightTop = { 48,48 };
				main.vertexWide.LeftBottom = { 48,48 };
				main.vertexWide.RightBottom = { 48,48 };

				///矩形
				box.vertexWide.LeftTop = { 48,48 };
				box.vertexWide.RightTop = { 48,48 };
				box.vertexWide.LeftBottom = { 48,48 };
				box.vertexWide.RightBottom = { 48,48 };

				///矩形
				tutorialbord.vertexWide.LeftTop = { 912,576 };
				tutorialbord.vertexWide.RightTop = { 912,576 };
				tutorialbord.vertexWide.LeftBottom = { 912,576 };
				tutorialbord.vertexWide.RightBottom = { 912,576 };

				///自機の半径
				main.radius = 24;

				///プレイヤーの画面上に映し続ける座標
				main.kameraPos.x = 600;
				main.kameraPos.y = 200;

				///プレイヤーの初期化
				main.velocity.y = 5;
				main.totalScale = 1.0f;
				main.drawScale = 1.5f;

				mapchip.size = 48;

				///ビームのそれぞれ頂点の中心からの幅
				beam.vertexWide.LeftTop = { 48,48 };
				beam.vertexWide.RightTop = { 48,48 };
				beam.vertexWide.LeftBottom = { 48,48 * 13 };
				beam.vertexWide.RightBottom = { 48,48 * 13 };

				///敵の初期化
				for (int i = 0; i < enemynum; i++) {

					///敵の半径
					enemy.radius[i] = 24;

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

					enemyTarget[i].easingPlus = 0.02f;
					enemy.easing.easingPlus = 0.1f;
					enemy.easing.easingTime = 0;
				}

				///
				for (int i = 0; i < itemnum; i++) {

					///アイテムの半径
					item.radius[i] = 24;

					///アイテムの中心からの頂点
					item.vertexWide[i].LeftTop = { 48,48 };
					item.vertexWide[i].RightTop = { 48,48 };
					item.vertexWide[i].LeftBottom = { 48,48 };
					item.vertexWide[i].RightBottom = { 48,48 };
				}

				for (int i = 0; i < piecesnum; i++) {

					///アイテムの半径
					pieces.radius[i] = 24;

					///アイテムの中心からの頂点
					pieces.vertexWide[i].LeftTop = { 48,48 };
					pieces.vertexWide[i].RightTop = { 48,48 };
					pieces.vertexWide[i].LeftBottom = { 48,48 };
					pieces.vertexWide[i].RightBottom = { 48,48 };
				}


				mapchip.scale = 0.8f;

				///前背景の初期化
				background.flont1.y = 720;
				background.flont2.y = 0;
				background.back1.y = 720;
				background.back2.y = 0;

			

				///重要変数初期化
				box.rotate = (1.0f / 4.0f) * float(M_PI);
				box.easing.easingPlus = 0.04f;
				box.screenPos.x = 640;
				box.screenPos.y = 320;
				box.scale = 0;
				box.easing.easingTime = 0;
				flag.isTutorialSkip = 0;
				box.easing.nextCount = 0;
				flag.isGameStart = 0;
				flag.isTutorialGo = 0;
				main.tutorialtime = 0;
				flag.isFallHighSpeed = 0;
				pieces.easing.easingPlus = 0.04f;
				pieces.easing.easingTime = 0;

				beam.time = 0;
				item.Have = 0;
				flag.isBeamShot = 0;
				flag.scaleUpget = 0;
				main.scaleUp.easingTime = 0;
				main.scaleDown.easingTime = 0;
				flag.isDamageColl = 0;
				flag.isDamage = 0;
				flag.isHitBack = 0;
				flag.isPlayerEnemyColligion = 0;
				flag.isScaleDown = 0;
				
				///ステージ切り替え
				flag.isStageChange = 0;
				mapchip.number = 0;
				
				score.enemycount = 0;
				fever.easingPlus = 0;
				fever.isEasing = 0;
				fever.isback = 0;
				fever.nextCount = 0;
				flag.isFever = 0;

				///チュートリアルのボードの
				tutorialbord.screenPos.x = 640;
				tutorialbord.screenPos.y = 350;
				tutorialbord.easing.easingPlus = 0.03f;	
				tutorialbord2.easing.easingPlus = 0.03f;
				tutorialbord3.easing.easingPlus = 0.03f;
				tutorialbord4.easing.easingPlus = 0.03f;
				flag.isHowtoPlay2 = 0;
				tutorialbord2.easing.easingTime = 0;
				tutorialbord2.scale = 0;
				flag.isHowtoPlay3 = 0;
				tutorialbord3.easing.easingTime = 0;
				tutorialbord3.scale = 0;
				flag.isHowtoPlay1 = 0;
				tutorialbord.easing.easingTime = 0;
				tutorialbord.scale = 0;
				flag.isHowtoPlay4 = 0;
				tutorialbord4.easing.easingTime = 0;
				tutorialbord4.scale = 0;

				Scene += 1;
			}
			///タイトル画面の処理ここまで-----------------------------------------------------------------------------------------------------------------

			break;

		case PLAY:

			///↓↓↓↓↓↓↓↓ゲームプレイ中の処理ここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

			sc.pos1.x = LeftTopX(sc.center1.x, 1320);
			sc.pos2.x = LeftTopX(sc.center2.x, 1320);
			sc.pos1.y = LeftTopY(sc.center1.y, 720);
			sc.pos2.y = LeftTopY(sc.center2.y, 720);

			SceneChange(sc.center1.y, sc.center2.y, sc.isSceneChange, flag.isSceneChange, sc.random.x);

			if (flag.isStop == 0&&flag.isGameStart==1) {
				///前背景の移動
				background.flont1.y -= main.velocity.y * 0.1f;
				background.flont2.y -= main.velocity.y * 0.1f;

				///後ろ背景の移動
				background.back1.y -= main.velocity.y * 0.05f;
				background.back2.y -= main.velocity.y * 0.05f;
			}

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
			if (mapchip.ScrollPos.y <= -mapchip.size * (mapy - 60) && mapchip.number != tutorial) {

				flag.isStageChange = 1;
			}
			

			if (flag.isStageChange == 1) {

				mapchip.number += 1;

				main.worldPos.y = 48 * 13;

				///残像の
				for (int i = 0; i < 3; i++) {

					main.afterimageWorldPos[i].x = main.worldPos.x;
					main.afterimageWorldPos[i].y = main.worldPos.y;
				}

				///敵を生き返らせる
				for (int i = 0; i < enemynum; i++) {

					enemyTarget[i].easingTime = 0;
					flag.isEnemyDeath[i] = 0;
				}

				///かけらを生き返らせる
				for (int p = 0; p < piecesnum; p++) {
					flag.isPiecesNone[p] = 0;
				}

				

				flag.isStageChange = 0;

				///壊れたマップの復元
				for (int y = 0; y < mapy; y++) {

					for (int x = 0; x < mapx; x++) {

						if (map[mapchip.number][y][x] == 3) {

							map[mapchip.number][y][x] = 1;
						}
					}
				}
			}

			///↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑背景またはスクロールの処理終わり↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑


			////↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓頂点の座標計算ここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
			//

			///プレイヤーの4頂点の座標計算
			main.vertexPos.LeftTop = LeftTopVertex(main.screenPos, main.vertexWide.LeftTop, main.rotate, mapchip.scale * main.drawScale);
			main.vertexPos.LeftBottom = LeftBottomVertex(main.screenPos, main.vertexWide.LeftBottom, main.rotate, mapchip.scale * main.drawScale);
			main.vertexPos.RightTop = RightTopVertex(main.screenPos, main.vertexWide.RightTop, main.rotate, mapchip.scale * main.drawScale);
			main.vertexPos.RightBottom = RightBottomVertex(main.screenPos, main.vertexWide.RightBottom, main.rotate, mapchip.scale * main.drawScale);

			///プレイヤーの4頂点の座標計算
			box.vertexPos.LeftTop = LeftTopVertex(box.screenPos, box.vertexWide.LeftTop, box.rotate, box.scale);
			box.vertexPos.LeftBottom = LeftBottomVertex(box.screenPos, box.vertexWide.LeftBottom, box.rotate, box.scale);
			box.vertexPos.RightTop = RightTopVertex(box.screenPos, box.vertexWide.RightTop, box.rotate, box.scale);
			box.vertexPos.RightBottom = RightBottomVertex(box.screenPos, box.vertexWide.RightBottom, box.rotate, box.scale);

			///プレイヤーの4頂点の座標計算
			tutorialbord.vertexPos.LeftTop = LeftTopVertex(tutorialbord.screenPos, tutorialbord.vertexWide.LeftTop, tutorialbord.rotate, tutorialbord.scale);
			tutorialbord.vertexPos.LeftBottom = LeftBottomVertex(tutorialbord.screenPos, tutorialbord.vertexWide.LeftBottom, tutorialbord.rotate, tutorialbord.scale);
			tutorialbord.vertexPos.RightTop = RightTopVertex(tutorialbord.screenPos, tutorialbord.vertexWide.RightTop, tutorialbord.rotate, tutorialbord.scale);
			tutorialbord.vertexPos.RightBottom = RightBottomVertex(tutorialbord.screenPos, tutorialbord.vertexWide.RightBottom, tutorialbord.rotate, tutorialbord.scale);

			///プレイヤーの4頂点の座標計算
			tutorialbord2.vertexPos.LeftTop = LeftTopVertex(tutorialbord.screenPos, tutorialbord.vertexWide.LeftTop, tutorialbord.rotate, tutorialbord2.scale);
			tutorialbord2.vertexPos.LeftBottom = LeftBottomVertex(tutorialbord.screenPos, tutorialbord.vertexWide.LeftBottom, tutorialbord.rotate, tutorialbord2.scale);
			tutorialbord2.vertexPos.RightTop = RightTopVertex(tutorialbord.screenPos, tutorialbord.vertexWide.RightTop, tutorialbord.rotate, tutorialbord2.scale);
			tutorialbord2.vertexPos.RightBottom = RightBottomVertex(tutorialbord.screenPos, tutorialbord.vertexWide.RightBottom, tutorialbord.rotate, tutorialbord2.scale);

			///プレイヤーの4頂点の座標計算
			tutorialbord3.vertexPos.LeftTop = LeftTopVertex(tutorialbord.screenPos, tutorialbord.vertexWide.LeftTop, tutorialbord.rotate, tutorialbord3.scale);
			tutorialbord3.vertexPos.LeftBottom = LeftBottomVertex(tutorialbord.screenPos, tutorialbord.vertexWide.LeftBottom, tutorialbord.rotate, tutorialbord3.scale);
			tutorialbord3.vertexPos.RightTop = RightTopVertex(tutorialbord.screenPos, tutorialbord.vertexWide.RightTop, tutorialbord.rotate, tutorialbord3.scale);
			tutorialbord3.vertexPos.RightBottom = RightBottomVertex(tutorialbord.screenPos, tutorialbord.vertexWide.RightBottom, tutorialbord.rotate, tutorialbord3.scale);

			///プレイヤーの4頂点の座標計算
			tutorialbord4.vertexPos.LeftTop = LeftTopVertex(tutorialbord.screenPos, tutorialbord.vertexWide.LeftTop, tutorialbord.rotate, tutorialbord4.scale);
			tutorialbord4.vertexPos.LeftBottom = LeftBottomVertex(tutorialbord.screenPos, tutorialbord.vertexWide.LeftBottom, tutorialbord.rotate, tutorialbord4.scale);
			tutorialbord4.vertexPos.RightTop = RightTopVertex(tutorialbord.screenPos, tutorialbord.vertexWide.RightTop, tutorialbord.rotate, tutorialbord4.scale);
			tutorialbord4.vertexPos.RightBottom = RightBottomVertex(tutorialbord.screenPos, tutorialbord.vertexWide.RightBottom, tutorialbord.rotate, tutorialbord4.scale);

			
			///残像4頂点の座標計算
			for (int i = 0; i < 3; i++) {

				main.afterimagePos[i].LeftTop = LeftTopVertex(main.afterimageScreenPos[i], main.vertexWide.LeftTop, main.rotate, main.drawScale);
				main.afterimagePos[i].LeftBottom = LeftBottomVertex(main.afterimageScreenPos[i], main.vertexWide.LeftBottom, main.rotate, main.drawScale);
				main.afterimagePos[i].RightTop = RightTopVertex(main.afterimageScreenPos[i], main.vertexWide.RightTop, main.rotate, main.drawScale);
				main.afterimagePos[i].RightBottom = RightBottomVertex(main.afterimageScreenPos[i], main.vertexWide.RightBottom, main.rotate, main.drawScale);
			}

			enemy.easing.easingTime += enemy.easing.easingPlus;

			if (enemy.easing.easingTime >= 1) {

				enemy.easing.easingPlus = -enemy.easing.easingPlus;
			}


			pieces.easing.easingTime += pieces.easing.easingPlus;

			if (pieces.easing.easingTime > 1|| pieces.easing.easingTime<0) {

				pieces.easing.easingPlus = -pieces.easing.easingPlus;
			}

			///kakeraがふわふわ動くイージング
			pieces.scale = easeOutBack1(pieces.easing, 0.8f, 1.0f);

			///敵の頂点の座標計算
			for (int i = 0; i < enemynum; i++) {

				enemy.vertexPos[i].LeftTop = LeftTopVertex(enemy.screenPos[mapchip.number][i], enemy.vertexWide[i].LeftTop, 0, 1.2f*mapchip.scale);
				enemy.vertexPos[i].LeftBottom = LeftBottomVertex(enemy.screenPos[mapchip.number][i], enemy.vertexWide[i].LeftBottom, 0, 1.2f * mapchip.scale);
				enemy.vertexPos[i].RightTop = RightTopVertex(enemy.screenPos[mapchip.number][i], enemy.vertexWide[i].RightTop, 0, 1.2f * mapchip.scale);
				enemy.vertexPos[i].RightBottom = RightBottomVertex(enemy.screenPos[mapchip.number][i], enemy.vertexWide[i].RightBottom, 0, 1.2f * mapchip.scale);

				///ターゲットの座標計算
				target.vertexPos[i].LeftTop = LeftTopVertex(enemy.screenPos[mapchip.number][i], target.vertexWide[i].LeftTop, 0, target.scale[i] * mapchip.scale);
				target.vertexPos[i].LeftBottom = LeftBottomVertex(enemy.screenPos[mapchip.number][i], target.vertexWide[i].LeftBottom, 0, target.scale[i] * mapchip.scale);
				target.vertexPos[i].RightTop = RightTopVertex(enemy.screenPos[mapchip.number][i], target.vertexWide[i].RightTop, 0, target.scale[i] * mapchip.scale);
				target.vertexPos[i].RightBottom = RightBottomVertex(enemy.screenPos[mapchip.number][i], target.vertexWide[i].RightBottom, 0, target.scale[i] * mapchip.scale);

				///敵がふわふわ動くイージング
				enemy.vertexWide[i].LeftTop.y = easeInSine(enemy.easing, 40, 48);
				enemy.vertexWide[i].RightTop.y = easeInSine(enemy.easing, 40, 48);

				

				///ターゲットのイージング
				if ((enemy.screenPos[mapchip.number][i].x) >= -10 && (enemy.screenPos[mapchip.number][i].x) <= 1280 && (enemy.screenPos[mapchip.number][i].y) >= -10 && (enemy.screenPos[mapchip.number][i].y) <= 720) {

					enemyTarget[i].easingTime += enemyTarget[i].easingPlus;

					if (enemyTarget[i].easingTime >= 1) {

						enemyTarget[i].easingTime = 1;
					}

					target.scale[i] = easeOutBack1(enemyTarget[i], 0, 1.3f);
				}

				enemy.radius[i] = 24 * mapchip.scale;
			}

			for (int i = 0; i < itemnum; i++) {

				///アイテムの頂点座標
				item.vertexPos[i].LeftTop = LeftTopVertex(item.screenPos[mapchip.number][i], item.vertexWide[i].LeftTop, 0, mapchip.scale);
				item.vertexPos[i].LeftBottom = LeftBottomVertex(item.screenPos[mapchip.number][i], item.vertexWide[i].LeftBottom, 0, mapchip.scale);
				item.vertexPos[i].RightTop = RightTopVertex(item.screenPos[mapchip.number][i], item.vertexWide[i].RightTop, 0, mapchip.scale);
				item.vertexPos[i].RightBottom = RightBottomVertex(item.screenPos[mapchip.number][i], item.vertexWide[i].RightBottom, 0, mapchip.scale);

				item.radius[i] = 24 * mapchip.scale;

			}

			for (int i = 0; i < piecesnum; i++) {

				///大きくなるかけらの頂点座標
				pieces.vertexPos[i].LeftTop = LeftTopVertex(pieces.screenPos[mapchip.number][i], pieces.vertexWide[i].LeftTop, 0, pieces.scale*mapchip.scale);
				pieces.vertexPos[i].LeftBottom = LeftBottomVertex(pieces.screenPos[mapchip.number][i], pieces.vertexWide[i].LeftBottom, 0, pieces.scale* mapchip.scale);
				pieces.vertexPos[i].RightTop = RightTopVertex(pieces.screenPos[mapchip.number][i], pieces.vertexWide[i].RightTop, 0, pieces.scale*mapchip.scale);
				pieces.vertexPos[i].RightBottom = RightBottomVertex(pieces.screenPos[mapchip.number][i], pieces.vertexWide[i].RightBottom, 0, pieces.scale* mapchip.scale);

				pieces.radius[i] = 24 * mapchip.scale;


			}

			///ビームの頂点座標
			beam.vertexPos.LeftTop = LeftTopVertex(beam.screenPos, beam.vertexWide.LeftTop, beam.rotate, main.drawScale);
			beam.vertexPos.LeftBottom = LeftBottomVertex(beam.screenPos, beam.vertexWide.LeftBottom, beam.rotate, main.drawScale);
			beam.vertexPos.RightTop = RightTopVertex(beam.screenPos, beam.vertexWide.RightTop, beam.rotate, main.drawScale);
			beam.vertexPos.RightBottom = RightBottomVertex(beam.screenPos, beam.vertexWide.RightBottom, beam.rotate, main.drawScale);

			///１フレーム前の座標をきろく
			main.oldworldPos.x = main.worldPos.x;
			main.oldworldPos.y = main.worldPos.y;

			///スケールを掛けてく
			main.height = 47 * mapchip.scale * main.drawScale;
			main.width = 47 * mapchip.scale * main.drawScale;
			main.radius = 24 * mapchip.scale * main.drawScale;
			mapchip.size = 48 * mapchip.scale;


			///↑↑↑↑↑↑↑↑↑↑↑↑頂点の座標計算ここから↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
			

		///チュートリアル画面の処理
			if (mapchip.number == tutorial) {

				///チュートリアルが1.5秒後に始まる
				main.tutorialtime += 1;
				if (main.tutorialtime >= 90&&flag.isTutorialGo==0&& flag.isHowtoPlay1 == 0) {
					flag.isTutorialGo = 1;
				}

				//1
				if (main.worldPos.y >= 100&&flag.isHowtoPlay1==0&&flag.isTutorialGo==1) {
					flag.isFallHighSpeed = 0;
					flag.isStop = 1;
					flag.isHowtoPlay1 = 1;
				}
				//2
				if (main.worldPos.y >= 1000 && flag.isHowtoPlay2 == 0 ) {
					flag.isFallHighSpeed = 0;
					flag.isStop = 1;
					flag.isHowtoPlay2 = 1;
				}
				//3
				if (main.worldPos.y >= 2500 && flag.isHowtoPlay3 == 0) {
					flag.isFallHighSpeed = 0;
					flag.isStop = 1;
					flag.isHowtoPlay3 = 1;
				}

				//4
				if (main.worldPos.y >= 3400 && flag.isHowtoPlay4 == 0) {
					flag.isFallHighSpeed = 0;
					flag.isStop = 1;
					flag.isHowtoPlay4 = 1;
				}

				//最初のチュートリアル表示
				if (flag.isHowtoPlay1 == 1&&flag.isHowtoPlay2==0) {
				
					///イージングタイムを足していく
					tutorialbord.easing.easingTime += tutorialbord.easing.easingPlus;

					///１になったら１で固定する
					if (tutorialbord.easing.easingTime >= 1 && tutorialbord.easing.isback == 0) {

						tutorialbord.easing.easingTime = 1;

						///スペースキー押したらイージングを逆再生する
						if (keys[DIK_SPACE]) {
							tutorialbord.easing.isback = 1;
							tutorialbord.easing.easingPlus = -tutorialbord.easing.easingPlus;
						}
					}
					///逆再生時、０になったら０で固定する
					if (tutorialbord.easing.easingTime <= 0 && tutorialbord.easing.isback == 1) {

						tutorialbord.easing.easingTime = 0;

						flag.isStop = 0;
					}
						///スケールをイージングさせる
					tutorialbord.scale = easeOutBack1(tutorialbord.easing, 0, 1);					
				}

				//最初のチュートリアル表示
				if (flag.isHowtoPlay2 == 1&&flag.isHowtoPlay3==0) {

					///イージングタイムを足していく
					tutorialbord2.easing.easingTime += tutorialbord2.easing.easingPlus;

					///１になったら１で固定する
					if (tutorialbord2.easing.easingTime >= 1 && tutorialbord2.easing.isback == 0) {

						tutorialbord2.easing.easingTime = 1;

						///スペースキー押したらイージングを逆再生する
						if (keys[DIK_SPACE]) {
							tutorialbord2.easing.isback = 1;
							tutorialbord2.easing.easingPlus = -tutorialbord2.easing.easingPlus;
						}
					}
					///逆再生時、０になったら０で固定する
					if (tutorialbord2.easing.easingTime <= 0 && tutorialbord2.easing.isback == 1) {

						tutorialbord2.easing.easingTime = 0;
						flag.isStop = 0;
					}
					///スケールをイージングさせる
					tutorialbord2.scale = easeOutBack1(tutorialbord2.easing, 0, 1);

				}

				//最初のチュートリアル表示
				if (flag.isHowtoPlay3 == 1&& flag.isHowtoPlay4 == 0) {

					///イージングタイムを足していく
					tutorialbord3.easing.easingTime += tutorialbord3.easing.easingPlus;

					///１になったら１で固定する
					if (tutorialbord3.easing.easingTime >= 1 && tutorialbord3.easing.isback == 0) {

						tutorialbord3.easing.easingTime = 1;

						///スペースキー押したらイージングを逆再生する
						if (keys[DIK_SPACE]) {
							tutorialbord3.easing.isback = 1;
							tutorialbord3.easing.easingPlus = -tutorialbord3.easing.easingPlus;
						}
					}
					///逆再生時、０になったら０で固定する
					if (tutorialbord3.easing.easingTime <= 0 && tutorialbord3.easing.isback == 1) {

						tutorialbord3.easing.easingTime = 0;
						flag.isStop = 0;
					}
					///スケールをイージングさせる
					tutorialbord3.scale = easeOutBack1(tutorialbord3.easing, 0, 1);

				}

				//最初のチュートリアル表示
				if (flag.isHowtoPlay4 == 1&&flag.isTutorialSkip==0 ) {

					///イージングタイムを足していく
					tutorialbord4.easing.easingTime += tutorialbord4.easing.easingPlus;

					///１になったら１で固定する
					if (tutorialbord4.easing.easingTime >= 1 && tutorialbord4.easing.isback == 0&&flag.isTutorialSkip==0) {

						tutorialbord4.easing.easingTime = 1;

						///スペースキー押したらイージングを逆再生する
						if (keys[DIK_SPACE]) {
							flag.isTutorialSkip = 1;
						}
					}
					
					///スケールをイージングさせる
					tutorialbord4.scale = easeOutBack1(tutorialbord4.easing, 0, 1);
				}

				///飛ばすよ
				if (keys[DIK_K] && preKeys[DIK_K] == 0 && flag.isTutorialSkip == 0&&flag.isStop==0) {
					
					flag.isTutorialSkip = 1;
				}
			}

			///チュートリアルスキップ演出
			if (flag.isTutorialSkip == 1) {

				box.easing.easingTime += box.easing.easingPlus;
				box.rotate += 0.2f;

				if (box.easing.easingTime >= 1.0f && mapchip.number == tutorial) {

					box.easing.nextCount += 1;

					if (box.easing.nextCount >= 30) {

						///プレイヤーの初期座標
						main.worldPos.x = 1600;
						main.worldPos.y = 584;
						flag.isStageChange = 1;
						flag.isTutorialGo = 0;
						box.easing.easingPlus = -box.easing.easingPlus;
						main.totalScale = 1.0f;
						main.drawScale = 1.5f;
						tutorialbord4.easing.easingTime = 0;
						flag.isStop = 0;
					}
				}

				if (box.easing.easingTime <= 0) {
					box.easing.easingTime = 0;
					flag.isTutorialSkip = 0;
				}

				box.scale = Liner(box.easing, 0, 20);
			}

			///停止時にスピード記録
			if (flag.isStop == 1&&flag.isStopNext==0) {

				flag.isStopNext = 1;
			}

			///記録したら止める
			if (flag.isStopNext == 1) {
		
				///これで脱出できるかも
				if (flag.isStop == 0) {
					flag.isStop = 0;
					flag.isStopNext = 0;
				}
			}
		
			if (flag.isGameStart == 1 || flag.isTutorialGo==1) {

				///プレイヤーのX軸の動き-----------------------------------------------------------------------------------------------------------------------------------------

				if (flag.isLeftDamage == 0 && flag.isRightDamage == 0 && flag.isStop == 0&&fever.isEasing==0) {

					if (keys[DIK_A] || keys[DIK_LEFT]) {
						main.worldPos.x += -6;
					}

					if (keys[DIK_D] || keys[DIK_RIGHT]) {
						main.worldPos.x += 6;
					}
				}

				if (flag.isLeftDamage == 1) {

					main.sideDamageTime += 1;

					main.worldPos.x += 18 * 0.1f;

					if (main.sideDamageTime >= 60) {

						flag.isLeftDamage = 0;
						main.sideDamageTime = 0;
					}
				}

				if (flag.isRightDamage == 1) {

					main.sideDamageTime += 1;
					main.worldPos.x -= 18 * 0.1f;

					if (main.sideDamageTime >= 60) {

						flag.isRightDamage = 0;
						main.sideDamageTime = 0;
					}
				}

				///プレイヤーのY軸の動き----------------------------------------------------------------------------

				if (flag.isFallStop == 0 && flag.isHitBack == 0&&flag.isStop == 0) {

					main.acceleration.y = 0.005f;
				}

				else if(flag.isFallStop == 1 && flag.isStop == 1) {
					main.acceleration.y = 0;
				}
				if (flag.isStop == 0) {
					///加速度足していき
					main.velocity.y += main.acceleration.y;

					if (flag.isFallHighSpeed == 0 && flag.isAnticipation == 0 ) {
						///座標に速度を足していく
						main.worldPos.y += main.velocity.y;
					}
				}


				///急降下していい状態の時
				if (flag.isFallColl == 0 && flag.isHitBack == 0 && flag.isDamageColl == 0&& flag.isStop == 0) {


					if (keys[DIK_SPACE] && flag.isAnticipation == 0 && flag.isFallHighSpeed == 0 && item.Have != 2) {

						main.velocitySave = main.velocity;///急降下するとき速度を保存

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
						if (flag.isDamage == 1) {

							main.velocity = main.velocitySave;
							flag.isFallHighSpeed = 0;
							flag.isAnticipation = 0;
							Anticipation.easingTime = 0;

						}
					}

					///急降下する
					if (flag.isFallHighSpeed == 1 && flag.isAnticipation == 0&&  flag.isStop == 0) {

						ac.isTrigger = true;

						acceleratingEffect(ac, 5, 1, 1, 1);
						main.worldPos.y += 24;


						///急降下をやめる時は保存した速度になう速度を代入
						if (keys[DIK_SPACE] == 0 || flag.isDamage == 1 || item.Have == 2||flag.isStop==1) {
			
							flag.isFallHighSpeed = 0;
						}
					}
				}
			}

			///プレイヤーのY軸の動き------------------------------------------------------------------------------------------


			///残像の動き------------------------------------------------------------------------------------------------------------------

			


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

				if (flag.isEnemyDeath[i] == 0&&fever.isEasing==0) {

					///敵とプレイヤーのカプセルの距離
					distance.enemyANDplayer[i] = length(main.worldPos.x - enemy.worldPos[mapchip.number][i].x, main.worldPos.y - enemy.worldPos[mapchip.number][i].y);
					distance.beamANDenemy[i] = isBoxCollisionBeta(beam.vertexPos.LeftTop.x, beam.vertexPos.LeftTop.y, beam.vertexPos.RightBottom.x, beam.vertexPos.RightBottom.y, enemy.vertexPos[i].LeftTop.x, enemy.vertexPos[i].LeftTop.y, enemy.vertexPos[i].RightBottom.x, enemy.vertexPos[i].RightBottom.y);


					///急降下してない状態で当たったら
					if (distance.enemyANDplayer[i] <= enemy.radius[i] + main.radius && flag.isFallHighSpeed == 0) {
	   
						flag.isEnemyDeath[i] = 1;
					
					}

					///敵を倒す処理（）
					if (distance.enemyANDplayer[i] <= enemy.radius[i] + main.radius && flag.isFallHighSpeed == 1 || distance.beamANDenemy[i] == 1 && flag.isBeamShot == 1) {

						flag.isEnemyDeath[i] = 1;
						flag.isHit = 1;
					}
				}

				if (flag.isEnemyDeath[i] == 1) {

					///敵が死ぬ処理----++++++エフェクトとか
				}
			}

			
			for (int i = 0; i < itemnum; i++) {

				if (flag.isItemNone[i] == 0 && fever.isEasing == 0) {

					distance.itemANDplayer[i] = length(main.worldPos.x - item.worldPos[mapchip.number][i].x, main.worldPos.y - item.worldPos[mapchip.number][i].y);

					///アイテム拾ったら
					if (distance.itemANDplayer[i] <= item.radius[i] + main.radius) {

						flag.isItemGet = 1;
						flag.isItemNone[i] = 1;
					}
				}
			}

			///アイテム取った――
			if (flag.isItemGet == 1) {

				item.Have = rand()%2;
				flag.isItemGet = 0;
			}

			///アイテムパタ―ン---------------------------------------------------------------------------------------------------------------------------------

			///ビームを拾ったとき
			if (item.Have == speedbeam) {

				beam.time += 1;
				if (beam.time >= 1200) {
					beam.time = 0;
					item.Have = 0;	
				}

				if (keys[DIK_SPACE]) {
					beam.worldPos = main.worldPos;
					flag.isBeamShot = 1;
				}

				else {
					flag.isBeamShot = 0;
				}
			}
			else {
				flag.isBeamShot = 0;
			}

			///アイテムパタ-ン---------------------------------------------------------------------------------------------------------------------------------


			///かけらの当たり判定など
			for (int i = 0; i < piecesnum; i++) {

				if (flag.isPiecesNone[i] == 0&&fever.isEasing == 0) {

					distance.itemANDplayer[i] = length(main.worldPos.x - pieces.worldPos[mapchip.number][i].x, main.worldPos.y - pieces.worldPos[mapchip.number][i].y);

					///かけら拾ったら
					if (distance.itemANDplayer[i] <= pieces.radius[i] + main.radius) {

						main.ScaleSave = main.drawScale;
						flag.isScaleUp = 1;
						flag.scaleUpget = 1;
						flag.isPiecesNone[i] = 1;
					}
				}
			}

			if (flag.scaleUpget == 1) {

				main.totalScale += main.scaleUpPlus;
				flag.scaleUpget = 0;
			}
			
			///ダメージ受けた時の処理
			if (flag.isDamage == 1 && flag.isDamageColl == 0 && flag.isDamageColl == 0) {

				main.ScaleSave = main.drawScale;
				mapchip.saveScale = mapchip.scale;
				main.scaleUp.easingTime = 0;
				main.scaleDown.easingTime = 0;
				flag.isDamageColl = 1;
				flag.isDamage = 0;


				if (flag.isPlayerEnemyColligion == 0) {

					flag.isHitBack = 1;
					main.velocity.y = -10;
				}

				else if (flag.isPlayerEnemyColligion == 1) {
					flag.isPlayerEnemyColligion = 0;
					main.velocity.y = 3;
					main.acceleration.y = 0.01f;
				}

				if (item.Have != barriaItem) {

					flag.isScaleDown = 1;
					main.totalScale -= 0.2f;
				}

				else if (item.Have == 1) {

					item.Have = 0;
				}
			}

			///ヒットバックを開始する
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

				main.drawScale = easeOutBack1(main.scaleDown, main.ScaleSave, main.ScaleSave - 0.2f);

				if (main.scaleDown.easingTime >= 1.0f) {

					main.scaleDown.easingTime = 1;

					if (main.scaleDown.easingTime == 1) {

						main.scaleDown.easingTime = 0;
						flag.isScaleDown = 0;
					}
				}
			}

			///自機の大きさ1より小さければ固定
			if (main.drawScale < 1.3) {
				main.drawScale = 1.3f;
			}

			///プレイヤーが大きくなる処理
			if (flag.isScaleUp == 1) {

				main.scaleUp.easingTime += 0.05f;

				main.drawScale = easeOutBack1(main.scaleUp, main.ScaleSave, main.ScaleSave + main.scaleUpPlus);

				if (main.scaleUp.easingTime >= 1.0f) {

					main.scaleUp.easingTime = 1;
				}

				if (main.scaleUp.easingTime == 1.0f) {

					flag.isScaleUp = 0;
					main.scaleUp.easingTime = 0;
				}
			}

			///敵との当たり判定とかダメージを受けた時の処理とか複雑―な処理------------------------------------------------------------


			///スコア--------------------------------------------------------------------------------------------------------

			///ヒットカウントを足していく
			if (flag.isHit == 1) {

				enemy.hitConbo += 1;
				score.enemycount += 1;
				score.realNum += 10 * enemy.hitConbo;
				flag.isHit = 0;

				if (flag.isFever == 0) {
					score.feverTime += 20;
				}

				///スコアだよー
				score.saveNum = float(score.num);
				score.linearTime = 0;
				score.isUp = 1;
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
		
			///スコア上げ
			if (score.isUp==1) {

				score.linearTime += 0.02f;

				if (score.linearTime >= 1) {

					score.linearTime = 1;
				}

				score.num =int( (1 - score.linearTime) * score.saveNum + score.linearTime * score.realNum);
			}

			if (score.enemycount >= 5&&fever.isEasing==0&&flag.isFever==0) {

			
				fever.easingPlus = 0.03f;
				mapchip.saveScale = mapchip.scale;
				fever.isEasing = 1;
				main.saveWorldPos.y = main.worldPos.y;
				fever.isback = 0;
				fever.nextCount = 0;
				flag.isFever = 1;
				flag.isStop = 1;
			}

			///	フィーバーを始めようか
			if (fever.isEasing == 1) {

				fever.easingTime += fever.easingPlus;

				///でかくなったら止める
				if (fever.easingTime >= 1.0f&&fever.isback==0) {
					fever.easingTime = 1;
					fever.nextCount += 1;


					///一定以上時間経ったらで
					if (fever.nextCount >= 60) {
				
						fever.easingPlus = -fever.easingPlus;
						fever.isback = 1;
						fever.nextCount = 0;
					}
				}

				///イージング終わる
				if (fever.isback == 1&&flag.isfeverTimedown==0) {

					if (fever.easingTime <= 0) {
						flag.isStop = 0;
						fever.isEasing = 0;
						fever.easingTime = 0;
						fever.easingPlus = 0;
						flag.isfeverTimedown = 1;
					}
				}

				if (flag.ZoomLevel == 0) {

					mapchip.scale = Liner(fever, 0.8f, 2.0f);
				}

				else if (flag.ZoomLevel == 1) {

					mapchip.scale = Liner(fever, 0.6f, 2.0f);
			  	}
			}

			///フィーバー時の処理
			if (flag.isFever == 1) {

				if (flag.isfeverTimedown == 1) {

					score.feverTime -= 1;
				}

				if (score.feverTime <= 0) {
					score.feverTime = 0;
					flag.isFever = 0;
					score.enemycount = 0;
					flag.isfeverTimedown = 0;
				}
			}

			

			///スコア--------------------------------------------------------------------------------------------------------


			///大きさに合わせカメラズーム------------------------------------------------------------------------------

			if (flag.isDamageColl == 0) {

		
					///記録Level0
					if (main.totalScale < 5.0f && flag.ZoomLevel == 1) {

						flag.isMapZoomInOut = 1;
						flag.ZoomLevel = 0;
						
						mapchip.saveScale = mapchip.scale;
					}

					///Level1
					if (main.totalScale >= 5.0f && flag.ZoomLevel == 0) {

						flag.isMapZoomInOut = 1;
						flag.ZoomLevel = 1;
					
						mapchip.saveScale = mapchip.scale;
					}
				

				///実際に行う
				if (flag.isMapZoomInOut == 1) {

					mapchip.zoomInOut.easingTime += 0.04f;

					if (flag.ZoomLevel == 0) {

						mapchip.scale = Liner(mapchip.zoomInOut, mapchip.saveScale, 0.8f);
						/*main.drawScale = Liner(mapchip.zoomInOut, main.ScaleSave, main.ScaleSave + 0.3f);*/
					
					}

					else if (flag.ZoomLevel == 1) {

						mapchip.scale = Liner(mapchip.zoomInOut, mapchip.saveScale,0.6f);
					/*	main.drawScale = Liner(mapchip.zoomInOut, main.ScaleSave, main.ScaleSave - 0.3f);*/
						
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

					if (flag.isDamageColl == 0 && flag.isFever == 0) {
						///ｙ軸に当たった時の斜め反応
						main.worldPos.y = float(main.fitMapSize.inty - 10);

						flag.isFallStop = 1;///急降下いったん止める
						flag.isFallColl = 1;
						flag.isDamage = 1;///ダメージを受ける
						main.damage.isShake = 1;///シェイクを開始する
						main.damage.shakeTime = 30;///シェイクの時間を決める
					}

					if (flag.isFever == 1) {
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
						///マップの破壊（どしゃん）
						if (map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x)] == 1) {

							map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x)] = 3;


							if (map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x) + 1] == 1) {

								map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x) + 1] = 3;

							}
						}

						///マップの破壊（どしゃん）
						if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x)] == 1) {

							map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x)] = 3;

							if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x) - 1] == 1) {

								map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x) - 1] = 3;

							}
						}
					}
				}

			else if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.oldMapNumber.RightTop.x)] != 1 && map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.oldMapNumber.RightBottom.x)] != 1 &&
					map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.oldMapNumber.LeftTop.x)] != 1 && map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.oldMapNumber.LeftBottom.x)] != 1) {


					///ｘ軸に当たった時の斜め反応
					main.worldPos.x = float(main.fitOldMapSize.intx);

					if (flag.isDamageColl == 0&&flag.isFever==0) {
						///マップの破壊（どしゃん）
						if (map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] == 1) {

							flag.isLeftDamage = 1;
							flag.isDamage = 1;///ダメージを受ける
							main.damage.isShake = 1;///シェイクを開始する
							main.damage.shakeTime = 30;///シェイクの時間を決める
						}

						///マップの破壊（どしゃん）
						if (map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] == 1) {


							flag.isRightDamage = 1;
							flag.isDamage = 1;///ダメージを受ける
							main.damage.isShake = 1;///シェイクを開始する
							main.damage.shakeTime = 30;///シェイクの時間を決める
						}
					}

					else if (flag.isFever == 1) {

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
						///マップの破壊（どしゃん）
						if (map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x)] == 1) {

							map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x)] = 3;


							if (map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x) + 1] == 1) {

								map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x) + 1] = 3;

							}
						}

						///マップの破壊（どしゃん）
						if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x)] == 1) {

							map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x)] = 3;

							if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x) - 1] == 1) {

								map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x) - 1] = 3;

							}
						}
					}
				}

				else {

					///それ以外の反応
					main.worldPos.x = float(main.fitOldMapSize.intx);
					main.worldPos.y = float(main.fitMapSize.inty);

					if (flag.isFever == 0) {
						flag.isFallStop = 1;///急降下いったん止める
						flag.isDamage = 1;///ダメージを受ける
						flag.isFallColl = 1;
						main.damage.isShake = 1;///シェイクを開始する
						main.damage.shakeTime = 30;///シェイクの時間を決める
					}

					else if (flag.isFever == 1) {
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

						///マップの破壊（どしゃん）
						if (map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x)] == 1) {

							map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x)] = 3;


							if (map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x) + 1] == 1) {

								map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x) + 1] = 3;

							}
						}

						///マップの破壊（どしゃん）
						if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x)] == 1) {

							map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x)] = 3;

							if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x) - 1] == 1) {

								map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x) - 1] = 3;

							}
						}
					}
				}
			}

			else {

				flag.isFallStop = 0;
			}

			///自機の４頂点のどれかが当たっている時
			if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.mapNumber.RightTop.x)] == 9 || map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] == 9 ||
				map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x)] == 9 || map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] == 9) {


				if (map[mapchip.number][int(main.oldMapNumber.RightTop.y)][int(main.mapNumber.RightTop.x)] != 9 && map[mapchip.number][int(main.oldMapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] != 9 &&
					map[mapchip.number][int(main.oldMapNumber.LeftTop.y)][int(main.mapNumber.LeftTop.x)] != 9 && map[mapchip.number][int(main.oldMapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] != 9) {

					if (flag.isDamageColl == 0&&flag.isFever==0) {
						///ｙ軸に当たった時の斜め反応
						main.worldPos.y = float(main.fitMapSize.inty - 10);

						flag.isFallStop = 1;///急降下いったん止める
						flag.isFallColl = 1;
						flag.isDamage = 1;///ダメージを受ける
						main.damage.isShake = 1;///シェイクを開始する
						main.damage.shakeTime = 30;///シェイクの時間を決める
					}

				
				}

				else if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.oldMapNumber.RightTop.x)] != 9 && map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.oldMapNumber.RightBottom.x)] != 9 &&
					map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.oldMapNumber.LeftTop.x)] != 9 && map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.oldMapNumber.LeftBottom.x)] != 9) {


					if (flag.isFever == 0) {
						main.worldPos.x = float(main.fitOldMapSize.intx );

					}

					if (flag.isDamageColl == 0&&flag.isFever==0) {
						///マップの破壊（どしゃん）
						if (map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] == 9) {

							flag.isLeftDamage = 1;
							flag.isDamage = 1;///ダメージを受ける
							main.damage.isShake = 1;///シェイクを開始する
							main.damage.shakeTime = 30;///シェイクの時間を決める
						}

						///マップの破壊（どしゃん）
						if (map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] == 9) {


							flag.isRightDamage = 1;
							flag.isDamage = 1;///ダメージを受ける
							main.damage.isShake = 1;///シェイクを開始する
							main.damage.shakeTime = 30;///シェイクの時間を決める
						}
					}

					else if (flag.isFever == 1) {

						if (map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.mapNumber.LeftBottom.x)] == 9) {

							///ｘ軸に当たった時の斜め反応
							main.worldPos.x = float(main.fitOldMapSize.intx + (main.width));
						}

						if (map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.mapNumber.RightBottom.x)] == 9) {


							///ｘ軸に当たった時の斜め反応
							main.worldPos.x = float(main.fitOldMapSize.intx - ( main.width));
						}


					}
				}

				else {

					///それ以外の反応
					main.worldPos.x = float(main.fitOldMapSize.intx);
					main.worldPos.y = float(main.fitMapSize.inty);
					if (flag.isFever == 0) {
						flag.isFallStop = 1;///急降下いったん止める
						flag.isDamage = 1;///ダメージを受ける
						flag.isFallColl = 1;
						main.damage.isShake = 1;///シェイクを開始する
						main.damage.shakeTime = 30;///シェイクの時間を決める
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

						if (map[mapchip.number][y][x] == 1|| map[mapchip.number][y][x] == 9 && flag.isMoveAbove == 0) {

							flag.isMoveAbove = 1;
						}

						if (flag.isMoveAbove == 1) {

							main.fitOldMapSize.inty -= 4;
						}

						///マップの破壊
						if (map[mapchip.number][y][x] == 1) {

							main.worldPos.y = float(main.fitOldMapSize.inty)-4;


							if (flag.isDamageColl == 0&& flag.isFever == 0) {
								flag.isDamage = 1;///ダメージを受ける
							}

							if (flag.isFever == 1) {

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
					}
				}
			}

			else {
				flag.isMoveAbove = 0;
			}

			///↑↑↑↑↑↑↑マップチップの当たり判定ここまで↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

			///↓↓↓↓↓↓↓↓↓↓↓↓↓演出系ここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
			
			if (mapchip.number != tutorial) {

				if (keys[DIK_P] && preKeys[DIK_P] == 0) {

					if (mask.isPause == false) {
						mask.isPause = true;
						mask.isBack = false;
						main.velocitySave.y = main.velocity.y;
					}

					else {
						mask.isPause = false;
						mask.isBack = true;
					}
				}

				mask.pos.x = main.screenPos.x;
				mask.pos.y = main.screenPos.y;
				mask.endPos.x = main.screenPos.x;
				mask.endPos.y = main.screenPos.y;
				mask.radius = 800;

				MaskProcess(mask.pos, mask.endPos, mask.radius, mask.isPause, mask.isBack, 100);
			}
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

				enemy.screenPos[mapchip.number][i].x = (enemy.worldPos[mapchip.number][i].x * mapchip.scale) + mapchip.ScrollPos.x;
				enemy.screenPos[mapchip.number][i].y = (enemy.worldPos[mapchip.number][i].y * mapchip.scale) + mapchip.ScrollPos.y;
			}

			for (int z = 0; z < itemnum; z++) {

				item.screenPos[mapchip.number][z].x = (item.worldPos[mapchip.number][z].x * mapchip.scale) + mapchip.ScrollPos.x;
				item.screenPos[mapchip.number][z].y = (item.worldPos[mapchip.number][z].y * mapchip.scale) + mapchip.ScrollPos.y;

			}

			///かけら
			for (int p = 0; p < itemnum; p++) {

				pieces.screenPos[mapchip.number][p].x = (pieces.worldPos[mapchip.number][p].x * mapchip.scale) + mapchip.ScrollPos.x;
				pieces.screenPos[mapchip.number][p].y = (pieces.worldPos[mapchip.number][p].y * mapchip.scale) + mapchip.ScrollPos.y;

			}

			for (int i = 0; i < 3; i++) {

				main.afterimageScreenPos[i].x = (main.afterimageWorldPos[i].x * mapchip.scale) + mapchip.ScrollPos.x;
				main.afterimageScreenPos[i].y = (main.afterimageWorldPos[i].y * mapchip.scale) + mapchip.ScrollPos.y;

			}

			///ビームの座標変換
			beam.screenPos.x = (beam.worldPos.x * mapchip.scale) + mapchip.ScrollPos.x;
			beam.screenPos.y = (beam.worldPos.y * mapchip.scale) + mapchip.ScrollPos.y;


			///スコアかきかき
			/*score.number[0] = score.num / 1000000;
			score.num = int(score.num) % 1000000;

			score.number[1] = score.num / 100000;
			score.num = int(score.num) % 100000;

			score.number[2] = score.num / 10000;
			score.num = int(score.num) % 10000;

			score.number[3] = score.num / 1000;
			score.num = int(score.num) % 1000;

			score.number[4] = score.num / 100;
			score.num = int(score.num) % 100;

			score.number[5] = score.num / 10;
			score.num = int(score.num) % 10;

			score.number[6] = score.num / 1;
			score.num = int(score.num) % 1;*/

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

				if (mask.isPause == true) {

					Novice::SetBlendMode(BlendMode::kBlendModeNormal);
					Novice::DrawBox(0, 0, 1280, 800, 0.0f, BLACK, kFillModeSolid);

					if (mask.isPause == true || mask.isBack == true) {

						Novice::SetBlendMode(BlendMode::kBlendModeAdd);
						Novice::DrawEllipse(int(mask.pos.x), int(mask.pos.y), int(mask.radius), int(mask.radius), 0.0f, WHITE, kFillModeSolid);
						Novice::SetBlendMode(BlendMode::kBlendModeMultily);
					}
				}

				///背景の描画
				Novice::DrawSprite(int(0 + main.damage.random.x), int(background.back1.y + main.damage.random.y), BackGround, 1, 1, 0, WHITE);
				Novice::DrawSprite(int(0 + main.damage.random.x), int(background.back2.y + main.damage.random.y), BackGround, 1, 1, 0, WHITE);
				Novice::DrawSprite(int(0 + main.damage.random.x), int(background.flont1.y + main.damage.random.y), frontBackGround, 1, 1, 0, WHITE);
				Novice::DrawSprite(int(0 + main.damage.random.x), int(background.flont2.y + main.damage.random.y), frontBackGround, 1, 1, 0, WHITE);
				
				
				/*///急降下する
				if (flag.isFallHighSpeed == 1 && flag.isAnticipation == 0) {

					for (int i = 0; i < iMax2; i++) {
						for (int j = 0; j < jMax2; j++) {
							Novice::DrawLine(int(ac.pos[i][j].x), int(ac.pos[i][j].y), int(ac.pos2[i][j].x), int(ac.pos2[i][j].y), WHITE);
						}
					}
				}*/

				///アイテムの描画
				for (int i = 0; i < itemnum; i++) {

					if (flag.isItemNone[i] == 0 && fever.isEasing == 0) {

						if ((item.screenPos[mapchip.number][i].x) >= -mapchip.size && (item.screenPos[mapchip.number][i].x) <= 1280 + mapchip.size && (item.screenPos[mapchip.number][i].y) >= -mapchip.size && (item.screenPos[mapchip.number][i].y) <= 720 + mapchip.size) {

							newDrawQuad(item.vertexPos[i].LeftTop, item.vertexPos[i].RightTop, item.vertexPos[i].LeftBottom, item.vertexPos[i].RightBottom, 0, 0, 72, 72, item.Handle, WHITE);
						}
					}
				}

				///かけらの描画
				for (int i = 0; i < piecesnum; i++) {

					if (flag.isPiecesNone[i] == 0 && fever.isEasing == 0) {

						if ((pieces.screenPos[mapchip.number][i].x) >= -mapchip.size && (pieces.screenPos[mapchip.number][i].x) <= 1280 + mapchip.size && (pieces.screenPos[mapchip.number][i].y) >= -mapchip.size && (pieces.screenPos[mapchip.number][i].y) <= 720 + mapchip.size) {

							newDrawQuad(pieces.vertexPos[i].LeftTop, pieces.vertexPos[i].RightTop, pieces.vertexPos[i].LeftBottom, pieces.vertexPos[i].RightBottom, 0, 0, 48, 48, pieces.Handle, WHITE);
						}
					}
				}

				///敵の描画
				for (int i = 0; i < enemynum; i++) {

					if (flag.isEnemyDeath[i] == 0&&fever.isEasing==0) {


						if ((enemy.screenPos[mapchip.number][i].x) >= -mapchip.size && (enemy.screenPos[mapchip.number][i].x) <= 1280 + mapchip.size && (enemy.screenPos[mapchip.number][i].y) >= -mapchip.size && (enemy.screenPos[mapchip.number][i].y) <= 720 + mapchip.size) {

							newDrawQuad(enemy.vertexPos[i].LeftTop, enemy.vertexPos[i].RightTop, enemy.vertexPos[i].LeftBottom, enemy.vertexPos[i].RightBottom, 0, 0, 48, 48, enemy.Handle, WHITE);

							newDrawQuad(target.vertexPos[i].LeftTop, target.vertexPos[i].RightTop, target.vertexPos[i].LeftBottom, target.vertexPos[i].RightBottom, 0, 0, 48, 48, target.Handle, WHITE);
						}
					}
				}

				if (flag.isBeamShot == 1) {
					///ビーム
					newDrawQuad(beam.vertexPos.LeftTop, beam.vertexPos.RightTop, beam.vertexPos.LeftBottom, beam.vertexPos.RightBottom, 0, 0, 48, 48 * 30, beam.Handle, WHITE);
				}

				///マップチップの描画
				for (int i = 0; i < mapy; i++) {

					for (int j = 0; j < mapx; j++) {

						if ((j * mapchip.size + mapchip.ScrollPos.x) >= -mapchip.size && (j * mapchip.size + mapchip.ScrollPos.x) <= 1280 + mapchip.size && (i * mapchip.size + mapchip.ScrollPos.y) >= -mapchip.size && (i * mapchip.size + mapchip.ScrollPos.y) <= 720 + mapchip.size) {

							if (map[mapchip.number][i][j] == 1|| map[mapchip.number][i][j] == 9) {

								Novice::DrawQuad(int((mapchip.ScrollPos.x + (j * mapchip.size + main.damage.random.x))), int((mapchip.ScrollPos.y + (i * mapchip.size + main.damage.random.y))), int((mapchip.ScrollPos.x + (j * mapchip.size + mapchip.size + main.damage.random.x))), int((mapchip.ScrollPos.y + (i * mapchip.size + main.damage.random.y))), int((mapchip.ScrollPos.x + (j * mapchip.size + main.damage.random.x))), int((mapchip.ScrollPos.y + (i * mapchip.size + mapchip.size + main.damage.random.y))), int((mapchip.ScrollPos.x + (j * mapchip.size + mapchip.size + main.damage.random.x))), int((mapchip.ScrollPos.y + (i * mapchip.size + mapchip.size + main.damage.random.y))), 0, 0, 48, 48, mapchip.Handle, WHITE);
							}
						}
					}
				}
	
				if (mask.isPause == true) {
					Novice::SetBlendMode(BlendMode::kBlendModeAdd);
				}
				
				///プレイヤーの描画
				newDrawQuad(main.vertexPos.LeftTop, main.vertexPos.RightTop, main.vertexPos.LeftBottom, main.vertexPos.RightBottom, 0, 0, 48, 48, main.Handle, WHITE);

				/*for (int i = 0; i < 7; i++) {
				
						Novice::DrawSpriteRect(100, 100, score.number[i] * 48, 0, 48, 48, numberHandle, 1, 1, 0.0f, WHITE);

					}
				}*/

				///チュートリアル中の描画
				if (flag.isGameStart == 0) {

					if (flag.isStop == 1&& fever.isEasing ==0) {

						Novice::DrawBox(0, 0, 1280, 720, 0, 0x00000088, kFillModeSolid);

						///チュートリアルボードの描画
						newDrawQuad(tutorialbord.vertexPos.LeftTop, tutorialbord.vertexPos.RightTop, tutorialbord.vertexPos.LeftBottom, tutorialbord.vertexPos.RightBottom, 0, 0, 912, 576, tutorialbord.Handle, WHITE);

						///チュートリアルボードの描画
						newDrawQuad(tutorialbord2.vertexPos.LeftTop, tutorialbord2.vertexPos.RightTop, tutorialbord2.vertexPos.LeftBottom, tutorialbord2.vertexPos.RightBottom, 0, 0, 912, 576, tutorialbord2.Handle, WHITE);

						///チュートリアルボードの描画
						newDrawQuad(tutorialbord3.vertexPos.LeftTop, tutorialbord3.vertexPos.RightTop, tutorialbord3.vertexPos.LeftBottom, tutorialbord3.vertexPos.RightBottom, 0, 0, 912, 576, tutorialbord3.Handle, WHITE);

						///チュートリアルボードの描画
						newDrawQuad(tutorialbord4.vertexPos.LeftTop, tutorialbord4.vertexPos.RightTop, tutorialbord4.vertexPos.LeftBottom, tutorialbord4.vertexPos.RightBottom, 0, 0, 912, 576, tutorialbord4.Handle, WHITE);

					}
						///boxの描画
						newDrawQuad(box.vertexPos.LeftTop, box.vertexPos.RightTop, box.vertexPos.LeftBottom, box.vertexPos.RightBottom, 0, 0, 48, 48, box.Handle, WHITE);
				}

				///かわいいシーン遷移
				Novice::DrawSprite(int(sc.pos1.x + sc.random.x), int(sc.pos1.y), sceneChangeHandle, 1, 1, 0.0f, 0xFFFFFFFF);
				Novice::DrawSprite(int(sc.pos2.x + sc.random.x), int(sc.pos2.y), sceneChangeHandle2, 1, 1, 0.0f, 0xFFFFFFFF);


				newScreenPrintf(800, 0, main.worldPos.x);
				newScreenPrintf(800, 20, main.worldPos.y);
				newScreenPrintf(0, 0, mapchip.saveScale);
				newScreenPrintf(0, 20, item.Have);
				newScreenPrintf(0, 40, distance.beamANDenemy[2]);
				newScreenPrintf(0, 60, main.totalScale);
				newScreenPrintf(0, 80, main.drawScale);
				newScreenPrintf(0, 100, flag.isStop);
				newScreenPrintf(0, 120, score.enemycount);

				newScreenPrintf(600,0, score.num);

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

