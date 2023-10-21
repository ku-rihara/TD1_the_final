#pragma once

struct Vector2A {
	float x;
	float y;
};

struct AcceleratingEffect {
	Vector2A pos[5][50];
	Vector2A pos2[5][50];
	Vector2A randomPos[5][50];
	float length[5][50];
	float lengthp[5][50];
	bool isActive[5][50];
	bool isTrigger;
	int activeTime[5][50];
};

const int iMax2 = 1;
const int jMax2 = 101;

void acceleratingEffect(AcceleratingEffect& ac, float length, float lenghtM, const int iMax, const int jMax);
