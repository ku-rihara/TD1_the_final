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

Vector2 LeftTopVertex(Vector2 center, Vector2  LeftTopvertex, float theta, Vector2 scawle) {

	Vector2 result;

	LeftTopvertex.x = -LeftTopvertex.x / 2;
	LeftTopvertex.y = -LeftTopvertex.y / 2;


	result.x = center.x + (LeftTopvertex.x * cosf(theta) - LeftTopvertex.y * sinf(theta)) * scawle.x;
	result.y = center.y + (LeftTopvertex.x * sinf(theta) + LeftTopvertex.y * cosf(theta)) * scawle.y;

	return result;

}

Vector2 LeftBottomVertex(Vector2 center, Vector2  LeftBottomvertex, float theta, Vector2 scawle) {

	Vector2 result;

	LeftBottomvertex.x = -LeftBottomvertex.x / 2;
	LeftBottomvertex.y = LeftBottomvertex.y / 2;


	result.x = center.x + (LeftBottomvertex.x * cosf(theta) - LeftBottomvertex.y * sinf(theta)) * scawle.x;
	result.y = center.y + (LeftBottomvertex.x * sinf(theta) + LeftBottomvertex.y * cosf(theta)) * scawle.y;

	return result;

}

Vector2 RightTopVertex(Vector2 center, Vector2  RightTopvertex, float theta, Vector2 scawle) {
	Vector2 result;

	RightTopvertex.x = RightTopvertex.x / 2;
	RightTopvertex.y = -RightTopvertex.y / 2;


	result.x = center.x + (RightTopvertex.x * cosf(theta) - RightTopvertex.y * sinf(theta)) * scawle.x;
	result.y = center.y + (RightTopvertex.x * sinf(theta) + RightTopvertex.y * cosf(theta)) * scawle.y;

	return result;
}

Vector2 RightBottomVertex(Vector2 center, Vector2  RightBottomvertex, float theta, Vector2 scawle) {

	Vector2 result;

	RightBottomvertex.x = RightBottomvertex.x / 2;
	RightBottomvertex.y = RightBottomvertex.y / 2;


	result.x = center.x + (RightBottomvertex.x * cosf(theta) - RightBottomvertex.y * sinf(theta)) * scawle.x;
	result.y = center.y + (RightBottomvertex.x * sinf(theta) + RightBottomvertex.y * cosf(theta)) * scawle.y;

	return result;
}




Vector2 LeftTopMapNum(Vector2 worldpos,float scale, float heigth, float width, float size ) {

	Vector2 mapnum;

	mapnum.y = ((worldpos.y*scale) - (heigth / 2)) / size;

	mapnum.x = ((worldpos.x * scale) - (width / 2)) / size;
	
	return mapnum;
}

Vector2 LeftBottomMapNum(Vector2 worldpos, float scale, float heigth, float width, float size) {

	Vector2 mapnum;

	mapnum.y = ((worldpos.y * scale) + (heigth / 2 - 1)) / size;

	mapnum.x = ((worldpos.x * scale) - (width / 2)) / size;

	return mapnum;

}

Vector2 RightTopMapNum(Vector2 worldpos, float scale, float heigth, float width, float size) {

	Vector2 mapnum;

	mapnum.y = ((worldpos.y * scale) - (heigth / 2)) / size;

	mapnum.x = ((worldpos.x * scale) + (width / 2 - 1)) / size;

	return mapnum;

}

Vector2 RightBottomMapNum(Vector2 worldpos, float scale, float heigth, float width, float size) {

	Vector2 mapnum;

	mapnum.y = ((worldpos.y * scale) + (heigth / 2 - 1)) / size;

	mapnum.x = ((worldpos.x * scale) + (width / 2 - 1)) / size;

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

float Liner(Easing x, float start, float end) {

	return (1 - x.easingTime) * start + x.easingTime * end;
}

float easeInSine(Easing x, float start, float end) {

	x.result = 1-cosf((x.easingTime * float(M_PI))/2);

	return (1 - x.result) * start + x.result * end;
}

float easeOutSine(Easing x, float start, float end) {

	x.result =sinf((x.easingTime * float(M_PI))/ 2);

	return (1 - x.result) * start + x.result * end;
}

float easeInBack(Easing x, float start, float end) {
	float c1 = 1.70158f;
	float c3 = c1 + 1;

	x.result = c3 * x.easingTime * x.easingTime * x.easingTime - c1 * x.easingTime * x.easingTime;

	return (1 - x.result) * start + x.result * end;
}

float easeOutBack1(Easing x, float start, float end) {

	float c1 = 1.70158f;
	float c3 = c1 + 1;

	x.result = 1 + c3 *powf(x.easingTime - 1, 3) + c1 *powf(x.easingTime - 1, 2);


	return (1 - x.result) * start + x.result * end;

}

float easeOutCirc(Easing x, float start, float end) {


	x.result = sqrtf(1 - powf(x.easingTime - 1, 2));

	return (1 - x.result) * start + x.result * end;
}

float easeInQuart(Easing x, float start, float end) {

	x.result = x.easingTime * x.easingTime * x.easingTime * x.easingTime;

	return (1 - x.result) * start + x.result * end;

}

float easeInOutBack(Easing x, float start, float end) {

	const float c1 = 1.70158f;
	const float c2 = c1 * 1.525f;

	if (x.easingTime < 0.5f) {

		x.result = (powf(2 * x.easingTime, 2) * ((c2 + 1) * 2 * x.easingTime - c2)) / 2;

	}
	else {

		x.result = (powf(2 * x.easingTime - 2, 2) * ((c2 + 1) * (x.easingTime * 2 - 2) + c2) + 2) / 2;
	}

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


void MaskProcess(Vector2& pos, const Vector2& endPos, float& radius, bool& isPause, bool& isBack,float endradius) {
	static float x = 0;
	static float xp = 0;
	static float t = 0;
	static float radx = 0;
	static float radxp = 0;
	static float radt = 0;
	static float backx = 0;
	static float backxp = 0;
	static float backt = 0;

	if (isPause == true) {
		xp = 0.02f;
		radxp = 0.01f;
		if (t >= 0.99f) {
			t = 1.0f;
			xp = 0;
		}
		if (radt >= 0.99f) {
			radt = 1.0f;
			radxp = 0;
		}
		x += xp;
		radx += radxp;
		t = x;
		radt = easeOutBack(radx);
		pos.x = (1.0f - t) * pos.x + t * endPos.x;
		pos.y = (1.0f - t) * pos.y + t * endPos.y;
		radius = (1.0f - radt) * radius + radt * endradius;
	}
	else {
		x = 0;
		radx = 0;
		t = 0;
		radt = 0;
		pos.x = 640;
		pos.y = 320;
		if (isBack == true) {
			backxp = 0.02f;
			if (backt >= 0.99f) {
				backt = 0;
				backxp = 0;
				backx = 0;
				isBack = false;
				radius = 800;
			}
			backx += backxp;
			backt = easeOutBack(backx);
			radius = (1.0f - backt) * endradius + backt * 800;
		}
	}
	
}

float easeOutBack(float x) {
	const float c1 = 1.70158f;
	const float c3 = c1 + 1;
	return 1 + c3 * powf(x - 1, 3) + c1 * powf(x - 1, 2);
}
