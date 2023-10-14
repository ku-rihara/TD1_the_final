#include <Novice.h>
//#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Functions.h"



float DotProduct(float AstartX, float AstartY, float AendX, float AendY, float BstartX, float BstartY, float BendX, float BendY) {
	float VectorAX = AendX - AstartX;
	float VectorAY = AendY - AstartY;
	float VectorBX = BendX - BstartX;
	float VectorBY = BendY - BstartY;
	return VectorAX * VectorBX + VectorAY * VectorBY;
}

float CrossProduct(float AstartX, float AstartY, float AendX, float AendY, float BstartX, float BstartY, float BendX, float BendY) {
	float VectorAX = AendX - AstartX;
	float VectorAY = AendY - AstartY;
	float VectorBX = BendX - BstartX;
	float VectorBY = BendY - BstartY;
	return VectorAX * VectorBY - VectorAY * VectorBX;
}

float MAX(float x, float y) {

	if (x > y) {
		return x;
	}
	else {
		return y;
	}
	
}

float pNorm(float x, float y, float p) {
	if (p > 255) {
		x = fabsf((float)x);
		y = fabsf((float)y);
		float norm2 = MAX(x, y);
		return norm2;
	}
	float norm = 0;
	x = sqrtf(x * x);
	y = sqrtf(y * y);
	x = powf(x, p);
	y = powf(y, p);
	norm = x + y;
	norm = powf(norm, 1.0f / p);
	return norm;
}

float GetRadian(float AstartX, float AstartY, float AendX, float AendY, float BstartX, float BstartY, float BendX, float BendY) {
	float Dot = DotProduct(AstartX, AstartY, AendX, AendY, BstartX, BstartY, BendX, BendY);
	float VectorAX = AendX - AstartX;
	float VectorAY = AendY - AstartY;
	float Dis1 = pNorm(VectorAX, VectorAY, 2);
	float VectorBX = BendX - BstartX;
	float VectorBY = BendY - BstartY;
	float Dis2 = pNorm(VectorBX, VectorBY, 2);
	float costheta = Dot / (Dis1 * Dis2);
	float radian = acosf(costheta);
	return radian;
}

float GetDegree(float radian) {
	float degree = radian * 180.0f / (float)M_PI;
	return degree;
}

float GetDis(float x1, float y1, float x2, float y2) {
	float DisX = x2 - x1;
	float DisY = y2 - y1;
	return sqrtf(DisX * DisX + DisY * DisY);
}

float Normalize(float startX, float startY, float endX, float endY, int n) {
	float VectorX = endX - startX;
	float VectorY = endY - startY;
	float length = GetDis(startX, startY, endX, endY);
	float normalizedX = 0;
	float normalizedY = 0;
	if (length != 0.0f) {
		normalizedX = VectorX / length;
		normalizedY = VectorY / length;
	}
	if (n == 1) {
		return normalizedX;
	}
	if (n == 2) {
		return normalizedY;
	}
	return 0;
}

float Clamp(float n, float min, float max) {
	if (n > max) {
		return max;
	}
	if (n < min) {
		return min;
	}
	return n;
}

float isBoxCollisionBeta(float leftTopX1, float leftTopY1, float rightBottomX1, float rightBottomY1, float leftTopX2, float leftTopY2, float rightBottomX2, float rightBottomY2) {
	if (leftTopX2 < rightBottomX1 && leftTopX1 < rightBottomX2) {
		if (rightBottomY2 > leftTopY1 && rightBottomY1 > leftTopY2) {
			return 1;
		}
	}
	return 0;
}

float isCircleCollision(float posX1, float posY1, float posX2, float posY2, int radius1, int radius2) {
	float Dis = GetDis(posX1, posY1, posX2, posY2);
	if (Dis < radius1 + radius2) {
		return 1;
	}
	return 0;
}

float CC(float posY) {
	
	return -posY;
}

float LeftTopX(float posX, float width) {
	return posX - width / 2;
}

float LeftTopY(float posY, float height) {
	return posY - height / 2;
}

float RightBottomX(float posX, float width) {
	return posX + width / 2;
}

float RightBottomY(float posY, float height) {
	return posY + height / 2;
}

float RightTopX(float posX, float width) {
	return posX + width / 2;
}

float RightTopY(float posY, float height) {
	return posY - height / 2;
}

float LeftBottomX(float posX, float width) {
	return posX - width / 2;
}

float LeftBottomY(float posY, float height) {
	return posY + height / 2;
}

float CenterC(float leftTopX, float leftTopY, float width, float height, int n) {
	float centerX = 0;
	float centerY = 0;
	centerX = leftTopX + width / 2;
	centerY = leftTopY + height / 2;
	if (n == 1) {
		return centerX;
	}
	if (n == 2) {
		return centerY;
	}
	else {
		return 0;
	}
}

float isBoxCollision(float posX1, float posY1, float posX2, float posY2, float width, float height, float width2, float height2) {
	float leftTopX1 = LeftTopX(posX1, width);
	float leftTopY1 = LeftTopY(posY1, height);
	float leftTopX2 = LeftTopX(posX2, width2);
	float leftTopY2 = LeftTopY(posY2, height2);
	float rightBottomX1 = RightBottomX(posX1, width);
	float rightBottomY1 = RightBottomY(posY1, height);
	float rightBottomX2 = RightBottomX(posX2, width2);
	float rightBottomY2 = RightBottomY(posY2, height2);
	if (leftTopX2 < rightBottomX1 && leftTopX1 < rightBottomX2) {
		if (rightBottomY2 > leftTopY1 && rightBottomY1 > leftTopY2) {
			return 1;
		}
	}
	return 0;
}

float IsOutOfScreen(float posX, float posYn, int ScreenSizeX, int ScreenSizeY) {
	if (posX<0 || posX>ScreenSizeX || posYn<0 || posYn>ScreenSizeY) {
		return 1;
	}
	else {
		return 0;
	}
}

float BoxPointCollision(float BoxLtX, float BoxLtY, float BoxRbX, float BoxRbY, int pointX, int pointY) {
	if (BoxLtX<pointX && BoxRbX>pointX) {
		if (BoxLtY<pointY && BoxRbY>pointY) {
			return 1;
		}
	}
	return 0;
}

void Shake(float& randomX, float& randomY, bool& isShake, int& timeR, int rangeX, int rangeY) {


	if (isShake == false) {
		randomX = 0;
		randomY = 0;
	}
	timeR--;
	if (timeR <= 0) {
		isShake = false;
		randomX = 0;
		randomY = 0;
	}
	else {
		randomX = float(rand() % (rangeX * 2) - rangeX);
		randomY = float(rand() % (rangeY * 2) - rangeY);
	}
}
float easeOutBounce(float x) {
	const float n1 = 7.5625f;
	const float d1 = 2.75f;

	if (x < 1 / d1) {
		return n1 * x * x;
	}
	else if (x < 2 / d1) {
		return n1 * (x -= 1.5f / d1) * x + 0.75f;
	}
	else if (x < 2.5f / d1) {
		return n1 * (x -= 2.25f / d1) * x + 0.9375f;
	}
	else {
		return n1 * (x -= 2.625f / d1) * x + 0.984375f;
	}
}

void SceneChange(float& posY1, float& posY2, bool& isSceneChange, float& randomX) {

	static float t = 0;
	static float tt = 0;
	static float x = 0;
	static float xx = 0;
	static int time = 0;
	static int timep = 0;
	static int timeS = 48;
	float random = 0;
	static bool isBack = false;
	static bool isShake = false;

	if (isSceneChange == true) {

		if (t <= 1) {
			x += 0.01f;
		}
		posY1 = (1.0f - t) * -360 + t * 355;
		posY2 = (1.0f - t) * 1080 + t * 365;
	}
	if (t >= 1) {
		isSceneChange = false;
		x = 0;
		timep = 1;
	}

	time += timep;
	if (time > 0 && time < 50) {
		isShake = true;
		Shake(randomX, random, isShake, timeS, 20, 10);
	}

	if (time == 50) {
		isBack = true;
	}

	if (isBack == true) {
		xx += 0.01f;
		posY1 = (1.0f - tt) * 355 + tt * -400;
		posY2 = (1.0f - tt) * 365 + tt * 1080;
	}
	if (tt >= 1) {
		t = 0;
		tt = 0;
		x = 0;
		xx = 0;
		time = 0;
		timep = 0;
		timeS = 48;
		random = 0;
		isBack = false;
		isShake = false;

	}

	t = easeOutBounce(x);
	tt = easeOutBounce(xx);

}

