#include <Novice.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "Functions.h"
#include "Particle.h"
#include"FunctionK.h"


void KamiParticle(Particle& par, float posX, float posY, float dirX, float dirY, float range1,float range2) {
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	static float speedX[5][50] = { 100 };
	static float speedY[5][50] = { 0 };
	static int count = 0;
	static float x[5][50] = { 0 };
	static float t[5][50] = { 0 };
	static float randomX[5][50] = { 0 };



	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 50; j++) {
			if (par.isActive[i][j] == true) {
				x[i][j] += randomX[i][j];
				t[i][j] = 1.0f - powf(2, -10 * x[i][j] / 1000);
				speedY[i][j] = (1.0f - t[i][j]) * speedY[i][j] + t[i][j] * 4;
				speedX[i][j] = (1.0f - t[i][j]) * speedX[i][j] + t[i][j] * 0.5f;
				par.pos[i][j].x += par.dir[i][j].x * speedX[i][j];
				par.pos[i][j].y += par.dir[i][j].y * speedY[i][j];

				par.width[i][j] += par.widthp[i][j];
				par.height[i][j] += par.heightp[i][j];

				if (par.randomSlope[i][j] >= 50) {
					par.slope[i][j] -= 0.03f;
				}
				if (par.randomSlope[i][j] <= 50) {
					par.slope[i][j] += 0.03f;
				}

				if (par.width[i][j] <= -12 || par.width[i][j] >= 12) {
					par.widthp[i][j] *= -1;
				}
				if (par.height[i][j] <= -12 || par.height[i][j] >= 12) {
					par.heightp[i][j] *= -1;
				}
			}
			else if (par.isTrigger == 1) {
				par.pos[i][j].x = posX;
				par.pos[i][j].y = posY;
				speedX[i][j] = float(rand() % 90 + 20);
				speedY[i][j] = float(rand() % 90 + 20);

				randomX[i][j] = float(rand() % 5 + 1);
				par.randomDir[i][j].x = float(rand() % 1000 * dirX);
				par.randomDir[i][j].y = float(rand() % 1000 * dirY);
				par.dir[i][j].x = Normalize(0, 30, par.randomDir[i][j].x, par.randomDir[i][j].y, 1);
				par.dir[i][j].y = Normalize(0, 30, par.randomDir[i][j].x, par.randomDir[i][j].y, 2);
				par.dir[i][j].x = Clamp(par.dir[i][j].x, range1, range2);
				par.dir[i][j].y = Clamp(par.dir[i][j].y, range1, range2);

				par.randomColor[i][j] = rand() % 5;
				if (par.randomColor[i][j] == 0) {
					par.color[i][j] = 0xB0941EFF;
				}
				if (par.randomColor[i][j] == 1) {
					par.color[i][j] = 0x3422D7FF;
				}
				if (par.randomColor[i][j] == 2) {
					par.color[i][j] = 0xCD062EFF;
				}
				if (par.randomColor[i][j] == 3) {
					par.color[i][j] = 0xDDECDBFF;
				}
				if (par.randomColor[i][j] == 4) {
					par.color[i][j] = 0x13EC49FF;
				}

				par.randomRadius[i][j] = float(rand() % 20 - 10);
				par.width[i][j] = par.randomRadius[i][j];
				par.height[i][j] = par.randomRadius[i][j];
				par.widthp[i][j] = -0.3f;
				par.heightp[i][j] = -0.3f;

				par.randomSlope[i][j] = float(rand() % 100);
				par.slope[i][j] = par.randomSlope[i][j];

				par.isActive[i][j] = true;
				break;
			}
			if (IsOutOfScreen(par.pos[i][j].x, par.pos[i][j].y, 1280, 720) == 1) {
				par.isActive[i][j] = false;
				x[i][j] = 0;
				t[i][j] = 0;
				par.width[i][j] = 0;
				par.height[i][j] = 0;
				par.widthp[i][j] = 0;
				par.heightp[i][j] = 0;
				par.isTrigger = false;
			}
		}
	}
}