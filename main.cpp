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
	SCORE score{};
	Mask mask {};
	BEAM box{};
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
							enemy.Spone[r].x = float(x) * 48;
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
	
	box.Handle= Novice::LoadTexture("white1x1.png");
	main.Handle = Novice::LoadTexture("./Resources./Images./player1-3.png");
	enemy.Handle = Novice::LoadTexture("./Resources./Images./enemy.png");
	target.Handle= Novice::LoadTexture("./Resources./Images./scope4.png");
	mapchip.Handle = Novice::LoadTexture("./Resources./Images./block.png");///マップチップの画像
	item.Handle = Novice::LoadTexture("./Resources./Images./SkillBox.png");
	beam.Handle= Novice::LoadTexture("white1x1.png");
	pieces.Handle= Novice::LoadTexture("white1x1.png");
	frontBackGround = Novice::LoadTexture("./Resources./Images./BackGround4.png");
	BackGround = Novice::LoadTexture("./Resources./Images./BackGround2.png");
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
			
			///シーンチェンジ
			SceneChange(sc.center1.y, sc.center2.y, sc.isSceneChange, flag.isSceneChange, sc.random.x);
	
			if (flag.isSceneChange == 1) {

				///プレイヤーの初期座標
				main.worldPos.x = 1400;
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

				///自機の半径
				main.radius = 24;

				///プレイヤーの画面上に映し続ける座標
				main.kameraPos.x = 600;
				main.kameraPos.y = 200;

				///プレイヤーの初期化
				main.velocity.y = 5;
				main.totalScale = 1.0f;
				main.drawScale = 1.5f;


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

				mapchip.size = 48;


				///重要変数初期化
				box.rotate = (1.0f / 4.0f) * float(M_PI);
				box.easing.easingPlus = 0.04f;
				box.screenPos.x = 640;
				box.screenPos.y = 320;

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
			if (mapchip.ScrollPos.y <= -mapchip.size * (mapy-60)&&mapchip.number!=tutorial) {
			
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

				/*///壊れたマップの復元
				for (int y = 0; y < mapy; y++) {

					for (int x = 0; x < mapx; x++) {

						if (map[mapchip.number][y][x] == 3) {

							map[mapchip.number][y][x] = 1;
						}
					}
				}*/

			}


			///↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑背景またはスクロールの処理終わり↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑


			///↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓頂点の座標計算ここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


			///プレイヤーの4頂点の座標計算
			main.vertexPos.LeftTop = LeftTopVertex(main.screenPos, main.vertexWide.LeftTop, main.rotate, mapchip.scale *main.drawScale);
			main.vertexPos.LeftBottom = LeftBottomVertex(main.screenPos, main.vertexWide.LeftBottom, main.rotate, mapchip.scale *main.drawScale);
			main.vertexPos.RightTop = RightTopVertex(main.screenPos, main.vertexWide.RightTop, main.rotate, mapchip.scale *main.drawScale);
			main.vertexPos.RightBottom = RightBottomVertex(main.screenPos, main.vertexWide.RightBottom,main.rotate, mapchip.scale * main.drawScale);

			///プレイヤーの4頂点の座標計算
			box.vertexPos.LeftTop = LeftTopVertex(box.screenPos, box.vertexWide.LeftTop, box.rotate, box.scale);
			box.vertexPos.LeftBottom = LeftBottomVertex(box.screenPos, box.vertexWide.LeftBottom, box.rotate, box.scale);
			box.vertexPos.RightTop = RightTopVertex(box.screenPos, box.vertexWide.RightTop, box.rotate,  box.scale);
			box.vertexPos.RightBottom = RightBottomVertex(box.screenPos, box.vertexWide.RightBottom, box.rotate,  box.scale);

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


			///敵の頂点の座標計算
			for (int i = 0; i < enemynum; i++) {

				enemy.vertexPos[i].LeftTop = LeftTopVertex(enemy.screenPos[mapchip.number][i], enemy.vertexWide[i].LeftTop, 0, mapchip.scale);
				enemy.vertexPos[i].LeftBottom = LeftBottomVertex(enemy.screenPos[mapchip.number][i], enemy.vertexWide[i].LeftBottom, 0, mapchip.scale);
				enemy.vertexPos[i].RightTop = RightTopVertex(enemy.screenPos[mapchip.number][i], enemy.vertexWide[i].RightTop, 0, mapchip.scale);
				enemy.vertexPos[i].RightBottom = RightBottomVertex(enemy.screenPos[mapchip.number][i], enemy.vertexWide[i].RightBottom, 0, mapchip.scale);

				///ターゲットの座標計算
				target.vertexPos[i].LeftTop = LeftTopVertex(enemy.screenPos[mapchip.number][i], target.vertexWide[i].LeftTop, 0, target.scale[i]*mapchip.scale);
				target.vertexPos[i].LeftBottom = LeftBottomVertex(enemy.screenPos[mapchip.number][i], target.vertexWide[i].LeftBottom, 0, target.scale[i]*mapchip.scale);
				target.vertexPos[i].RightTop = RightTopVertex(enemy.screenPos[mapchip.number][i], target.vertexWide[i].RightTop, 0, target.scale[i]*mapchip.scale);
				target.vertexPos[i].RightBottom = RightBottomVertex(enemy.screenPos[mapchip.number][i], target.vertexWide[i].RightBottom, 0, target.scale[i]*mapchip.scale);
			
				///敵がふわふわ動くイージング
				enemy.vertexWide[i].LeftTop.y = easeInSine(enemy.easing, 40, 48);
				enemy.vertexWide[i].RightTop.y = easeInSine(enemy.easing, 40, 48);


				///ターゲットのイージング
				if ((enemy.screenPos[mapchip.number][i].x) >= -10 && (enemy.screenPos[mapchip.number][i].x) <= 1280 && (enemy.screenPos[mapchip.number][i].y) >= -10 && (enemy.screenPos[mapchip.number][i].y) <= 720 ) {

					enemyTarget[i].easingTime += enemyTarget[i].easingPlus;

					if (enemyTarget[i].easingTime >= 1) {

						enemyTarget[i].easingTime = 1;
					}

					target.scale[i] = easeOutBack1(enemyTarget[i], 0, 1.4f);		
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
				pieces.vertexPos[i].LeftTop = LeftTopVertex(pieces.screenPos[mapchip.number][i], pieces.vertexWide[i].LeftTop, 0, mapchip.scale);
				pieces.vertexPos[i].LeftBottom = LeftBottomVertex(pieces.screenPos[mapchip.number][i], pieces.vertexWide[i].LeftBottom, 0, mapchip.scale);
				pieces.vertexPos[i].RightTop = RightTopVertex(pieces.screenPos[mapchip.number][i], pieces.vertexWide[i].RightTop, 0, mapchip.scale);
				pieces.vertexPos[i].RightBottom = RightBottomVertex(pieces.screenPos[mapchip.number][i], pieces.vertexWide[i].RightBottom, 0, mapchip.scale);

				pieces.radius[i] = 24 * mapchip.scale;
			}

			///ビームの頂点座標
			beam.vertexPos.LeftTop = LeftTopVertex(beam.screenPos, beam.vertexWide.LeftTop, beam.rotate, main.drawScale);
			beam.vertexPos.LeftBottom = LeftBottomVertex(beam.screenPos, beam.vertexWide.LeftBottom, beam.rotate, main.drawScale);
			beam.vertexPos.RightTop = RightTopVertex(beam.screenPos, beam.vertexWide.RightTop, beam.rotate, main.drawScale);
			beam.vertexPos.RightBottom = RightBottomVertex(beam.screenPos, beam.vertexWide.RightBottom, beam.rotate, main.drawScale);


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

			///飛ばすよ
				if (keys[DIK_K] && preKeys[DIK_K] == 0&& flag.isTutorialSkip ==0 ) {
					
					flag.isTutorialSkip = 1;		
				}		
			}
			
			///チュートリアルスキップ演出
			if (flag.isTutorialSkip == 1) {

				box.easing.easingTime += box.easing.easingPlus;
				box.rotate += 0.2f;

				if (box.easing.easingTime >= 1.0f&&mapchip.number==tutorial) {

					box.easing.nextCount += 1;
					
					if (box.easing.nextCount >= 30) {
						///プレイヤーの初期座標
						main.worldPos.x = 1600;
						main.worldPos.y = 584;
						flag.isStageChange = 1;
						box.easing.easingPlus = -box.easing.easingPlus;			
					}
				}

				if (box.easing.easingTime <= 0) {
					box.easing.easingTime = 0;
					flag.isTutorialSkip = 0;
					
				}

				box.scale = Liner(box.easing, 0, 20);
			
			}

			///ステージ開始の処理

			if (flag.isGameStart == 1 || mapchip.number == tutorial) {
				///プレイヤーのX軸の動き-----------------------------------------------------------------------------------------------------------------------------------------

				if (flag.isLeftDamage == 0 && flag.isRightDamage == 0) {

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

				if (flag.isFallStop == 0 && flag.isHitBack == 0) {

					main.acceleration.y = 0.005f;
				}

				///加速度足していき
				main.velocity.y += main.acceleration.y;

				///座標に速度を足していく
				main.worldPos.y += main.velocity.y;

				
				
					

				///急降下していい状態の時
				if (flag.isFallColl == 0 && flag.isHitBack == 0 && flag.isDamageColl == 0) {


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
					if (flag.isFallHighSpeed == 1 && flag.isAnticipation == 0) {

						ac.isTrigger = true;

						acceleratingEffect(ac, 5, 1, 1, 1);
						main.velocity.y = 24;


						///急降下をやめる時は保存した速度になう速度を代入
						if (keys[DIK_SPACE] == 0 || flag.isDamage == 1 || item.Have == 2) {

							main.velocity = main.velocitySave;
							flag.isFallHighSpeed = 0;
						}
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
					distance.enemyANDplayer[i] = length(main.worldPos.x - enemy.worldPos[mapchip.number][i].x, main.worldPos.y - enemy.worldPos[mapchip.number][i].y);
					distance.beamANDenemy[i] = isBoxCollisionBeta(beam.vertexPos.LeftTop.x, beam.vertexPos.LeftTop.y, beam.vertexPos.RightBottom.x, beam.vertexPos.RightBottom.y, enemy.vertexPos[i].LeftTop.x, enemy.vertexPos[i].LeftTop.y, enemy.vertexPos[i].RightBottom.x, enemy.vertexPos[i].RightBottom.y);


					///急降下してない状態で当たったら
					if (distance.enemyANDplayer[i] <= enemy.radius[i] + main.radius && flag.isFallHighSpeed == 0) {

						flag.isDamage = 1;
						flag.isPlayerEnemyColligion = 1;
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

				distance.itemANDplayer[i] = length(main.worldPos.x - item.worldPos[mapchip.number][i].x, main.worldPos.y - item.worldPos[mapchip.number][i].y);

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

				if (flag.isPiecesNone[i] == 0) {

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
			if (flag.isDamage == 1 && flag.isDamageColl == 0&&flag.isDamageColl == 0) {

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
				score.realNum += 10 * enemy.hitConbo;
				flag.isHit = 0;

				///スコアだよー
				score.saveNum = score.num;
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

				score.num = (1 - score.linearTime) * score.saveNum + score.linearTime * score.realNum;
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

					if (flag.isDamageColl == 0) {
						///ｙ軸に当たった時の斜め反応
						main.worldPos.y = float(main.fitMapSize.inty-10);

						flag.isFallStop = 1;///急降下いったん止める
						flag.isFallColl = 1;
						flag.isDamage = 1;///ダメージを受ける
						main.damage.isShake = 1;///シェイクを開始する
						main.damage.shakeTime = 30;///シェイクの時間を決める
					}

					/*///マップの破壊（どしゃん）
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
					}*/
				}

			else if (map[mapchip.number][int(main.mapNumber.RightTop.y)][int(main.oldMapNumber.RightTop.x)] != 1 && map[mapchip.number][int(main.mapNumber.RightBottom.y)][int(main.oldMapNumber.RightBottom.x)] != 1 &&
					map[mapchip.number][int(main.mapNumber.LeftTop.y)][int(main.oldMapNumber.LeftTop.x)] != 1 && map[mapchip.number][int(main.mapNumber.LeftBottom.y)][int(main.oldMapNumber.LeftBottom.x)] != 1) {


					///ｘ軸に当たった時の斜め反応
					main.worldPos.x = float(main.fitOldMapSize.intx);

					if (flag.isDamageColl == 0) {
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


					/*///マップの破壊（どしゃん）
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
					}*/
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

							main.fitOldMapSize.inty -= 4;
						}

						///マップの破壊
						if (map[mapchip.number][y][x] == 1) {

							main.worldPos.y = float(main.fitOldMapSize.inty);
							if (flag.isDamageColl == 0) {
								flag.isDamage = 1;///ダメージを受ける
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
			/*	Novice::DrawSprite(0, int(background.flont1.y + main.damage.random.y), frontBackGround, 1, 1, 0, WHITE);
				Novice::DrawSprite(0, int(background.flont2.y + main.damage.random.y), frontBackGround, 1, 1, 0, WHITE);
				*/
				
				///急降下する
				if (flag.isFallHighSpeed == 1 && flag.isAnticipation == 0) {

					for (int i = 0; i < iMax2; i++) {
						for (int j = 0; j < jMax2; j++) {
							Novice::DrawLine(int(ac.pos[i][j].x), int(ac.pos[i][j].y), int(ac.pos2[i][j].x), int(ac.pos2[i][j].y), WHITE);
						}
					}
				}
				///アイテムの描画
				for (int i = 0; i < itemnum; i++) {

					if ((item.screenPos[mapchip.number][i].x) >= mapchip.size && (item.screenPos[mapchip.number][i].x) <= 1280 + mapchip.size && (item.screenPos[mapchip.number][i].y) >= -mapchip.size && (item.screenPos[mapchip.number][i].y) <= 720 + mapchip.size) {

						newDrawQuad(item.vertexPos[i].LeftTop, item.vertexPos[i].RightTop, item.vertexPos[i].LeftBottom, item.vertexPos[i].RightBottom, 0, 0, 48, 48, item.Handle, WHITE);
					}
				}

				///かけらの描画
				for (int i = 0; i < piecesnum; i++) {

					if ((pieces.screenPos[mapchip.number][i].x) >= mapchip.size && (pieces.screenPos[mapchip.number][i].x) <= 1280 + mapchip.size && (pieces.screenPos[mapchip.number][i].y) >= -mapchip.size && (pieces.screenPos[mapchip.number][i].y) <= 720 + mapchip.size) {

						newDrawQuad(pieces.vertexPos[i].LeftTop, pieces.vertexPos[i].RightTop, pieces.vertexPos[i].LeftBottom, pieces.vertexPos[i].RightBottom, 0, 0, 48, 48, pieces.Handle, WHITE);
					}
				}

				///敵の描画
				for (int i = 0; i < enemynum; i++) {

					if (flag.isEnemyDeath[i] == 0) {


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

							if (map[mapchip.number][i][j] == 1) {

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

				
				///boxの描画
				newDrawQuad(box.vertexPos.LeftTop, box.vertexPos.RightTop, box.vertexPos.LeftBottom, box.vertexPos.RightBottom, 0, 0, 48, 48, box.Handle, WHITE);


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
				newScreenPrintf(0, 100, main.velocity.y);

				newScreenPrintf(600,0, int(score.num));

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

