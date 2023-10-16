#pragma once

struct Vector2 {
	float x;
	float y;
};

struct Particle {
	Vector2 pos[5][50];
	Vector2 dir[5][50];
	Vector2 randomDir[5][50];
	float randomRadius[5][50];
	float randomSlope[5][50];
	float slope[5][50];
	int randomColor[5][50];
	float width[5][50];
	float height[5][50];
	float widthp[5][50];
	float heightp[5][50];
	unsigned int color[5][50];
	bool isActive[5][50];
	bool isTrigger;
	int activeTime;
};

void KamiParticle(Particle& par, float posX, float posY, float dirX, float dirY,float range1,float range2);