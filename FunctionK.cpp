#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include"FunctionK.h"


void VectorScreenPrintf(int x, int y, Vector2 vector) {

	Novice::ScreenPrintf(x, y, "%.02f", vector, x);
	Novice::ScreenPrintf(x + 60, y, "%.02f", vector, y);
}

void newDrawQuad(Vector2 LeftTop, Vector2 RigthTop, Vector2 LeftBottom, Vector2 RigthBottom,  float startx, float starty, float DrawWidth, float DrawHeigth, int Handle, int Color) {

	Novice::DrawQuad(int(LeftTop.x), int(LeftTop.y), int(RigthTop.x), int(RigthTop.y), int(LeftBottom.x), int(LeftBottom.y), int(RigthBottom.x), int(RigthBottom.y), int(startx), int(starty), int(DrawWidth), int(DrawHeigth), Handle, Color);
}


Vector2 LeftTopVertex(Vector2 center, Vector2  LeftTopvertex, float theta, float scale) {

	Vector2 result;
	
	LeftTopvertex.x =-LeftTopvertex.x / 2;
	LeftTopvertex.y = -LeftTopvertex.y / 2;
		

	result.x = center.x + (LeftTopvertex.x * cosf(theta) - LeftTopvertex.y * sinf(theta)) * scale;
	result.y = center.y + (LeftTopvertex.x * sinf(theta) + LeftTopvertex.y * cosf(theta)) * scale;
	
	return result;
}

Vector2 LeftBottomVertex(Vector2 center, Vector2  LeftBottomvertex, float theta, float scale) {

	Vector2 result;

	LeftBottomvertex.x = -LeftBottomvertex.x / 2;
	LeftBottomvertex.y = LeftBottomvertex.y / 2;


	result.x = center.x + (LeftBottomvertex.x * cosf(theta) - LeftBottomvertex.y * sinf(theta)) * scale;
	result.y = center.y + (LeftBottomvertex.x * sinf(theta) + LeftBottomvertex.y * cosf(theta)) * scale;

	return result;
}

Vector2 RightTopVertex(Vector2 center, Vector2  RightTopvertex, float theta, float scale) {

	Vector2 result;

	RightTopvertex.x = RightTopvertex.x / 2;
	RightTopvertex.y = -RightTopvertex.y / 2;


	result.x = center.x + (RightTopvertex.x * cosf(theta) - RightTopvertex.y * sinf(theta)) * scale;
	result.y = center.y + (RightTopvertex.x * sinf(theta) + RightTopvertex.y * cosf(theta)) * scale;

	return result;
}

Vector2 RightBottomVertex(Vector2 center, Vector2  RightBottomvertex, float theta, float scale) {

	Vector2 result;

	RightBottomvertex.x = RightBottomvertex.x / 2;
	RightBottomvertex.y = RightBottomvertex.y / 2;


	result.x = center.x + (RightBottomvertex.x * cosf(theta) - RightBottomvertex.y * sinf(theta)) * scale;
	result.y = center.y + (RightBottomvertex.x * sinf(theta) + RightBottomvertex.y * cosf(theta)) * scale;

	return result;
}


Vector2 LeftTopMapNum(Vector2 worldpos, float heigth, float width, float size ) {

	Vector2 mapnum;

	mapnum.y = (worldpos.y - (heigth / 2)) / size;

	mapnum.x = (worldpos.x - (width / 2)) / size;
	
	return mapnum;
}

Vector2 LeftBottomMapNum(Vector2 worldpos, float heigth, float width, float size) {

	Vector2 mapnum;

	mapnum.y = (worldpos.y + (heigth / 2 - 1)) / size;

	mapnum.x = (worldpos.x - (width / 2)) / size;

	return mapnum;

}

Vector2 RightTopMapNum(Vector2 worldpos, float heigth, float width, float size) {

	Vector2 mapnum;

	mapnum.y = (worldpos.y - (heigth / 2)) / size;

	mapnum.x = (worldpos.x + (width / 2 - 1)) / size;

	return mapnum;

}

Vector2 RightBottomMapNum(Vector2 worldpos, float heigth, float width, float size) {

	Vector2 mapnum;

	mapnum.y = (worldpos.y + (heigth / 2 - 1)) / size;

	mapnum.x = (worldpos.x + (width / 2 - 1)) / size;

	return mapnum;

}

void newScreenPrintf(int x, int y, float num) {

	Novice::ScreenPrintf(x, y, "%.02f", num);
}

void newScreenPrintf(int x, int y, int num) {

	Novice::ScreenPrintf(x, y, "%d", num);

}

void newDrawBox(float x, float y, float width,float heigth,int color) {

	Novice::DrawBox(int(x), int(y), int(width), int(heigth), 0.0f, color, kFillModeSolid);

}


float easeInSine(Easing x, float start, float end) {

	x.result = cosf((x.time * float(M_PI))/2);

	return (1 - x.result) * start + x.result * end;
}

float easeOutSine(Easing x, float start, float end) {

	x.result =sinf((x.time * float(M_PI))/ 2);

	return (1 - x.result) * start + x.result * end;
}

float easeInBack(Easing x, float start, float end) {
	float c1 = 1.70158f;
	float c3 = c1 + 1;

	x.result = c3 * x.time * x.time * x.time - c1 * x.time * x.time;

	return (1 - x.result) * start + x.result * end;
}

float easeOutBack(Easing x, float start, float end) {

	float c1 = 1.70158f;
	float c3 = c1 + 1;

	x.result = 1 + c3 *powf(x.time - 1, 3) + c1 *powf(x.time - 1, 2);


	return (1 - x.result) * start + x.result * end;

}


Vector2 normalize(Vector2 pos) {

	Vector2 result;

	float c = sqrtf(pos.x * pos.x + pos.y * pos.y);

	result.x = pos.x / c;
	result.y = pos.y / c;
	
	return result;
}

float dot(float dx, float ex, float dy, float ey) {
	return dx * ex + dy * ey;
}

float length(float a, float b) {
	return sqrtf(a * a + b * b);
}


