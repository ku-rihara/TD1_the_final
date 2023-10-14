#pragma once

struct Vector2 {

	float x;
	float y;

};



struct Vertex {

	Vector2 LeftTop;
	Vector2 LeftBottom;
	Vector2 RightTop;
	Vector2 RightBottom;

};


struct inVector2 {
	int intx;
	int inty;
};


struct Easing {

	int isEasing;
	float time;
	float result;
	
};

struct SHAKE {

	Vector2 random;
	int time;
	bool isShake;
};

struct SceneChangeP {
	Vector2 pos1;
	Vector2 pos2;
	Vector2 center1;
	Vector2 center2;
	Vector2 random;
	bool isSceneChange;
};

struct MAINCHARACTER {
 
	 Vertex vertexPos;
	 Vertex vertexWide;
	 Vertex mapNumber;
	 Vertex oldMapNumber;
	Vector2 worldPos;
	Vector2 oldworldPos;
	Vector2 worldMax;
	inVector2 fitMapSize;
	inVector2 fitOldMapSize;
	Vector2 screenPos;
	Vector2 kameraPos;
	Vector2 scrollPos;
	Easing scaleUpEasing;
	Easing scaleDownEasing;
    SHAKE  damageShake;
	float time;
	float  velocity;
	float  velocitySave;
	float acceleration;
	float width;
	float height;
	float radius;
	int fallCollTime;
	int damageCollTime;
	float drawScale;
	float totalScale;
	float ScaleSave;
	int Handle;
	
};

struct ENEMYCHARACTER {
	
	Vertex vertexPos[10];
	Vertex vertexWide[10];
	Vector2 worldPos[10];
	Vector2 screenPos[10];
	Vector2 oldWorldPos[10];
	Vector2 distance[10];
	Easing easing[10];
	float  velocity[10];
	float accelaration[10];
	float radius[10];
	int hitConbo;
	int conboCollTime;


};

struct DISTANCE {

	float enemyANDplayer[10];

};

struct FLAG {
	int isMoveAbove;
	int isPlayerEnemyColligion;
	int isEnemyDeath[10];
	int isFallStop;
	int isFallHighSpeed;
	int isFallColl;
	int isDamage;
	int isDamageColl;
	int isScaleUp;
	int isScaleDown;
	int isHit;
	int isConboChain;
	int isMapZoomOut;
	int ZoomRock;
};

struct MAPCHIP {

	Vector2 ScrollPos;
	Vector2 worldPos;
	Vertex pos;
	Vertex wide;
	Easing zoomOutEasing;
	float scale;
	int number;
	float size;
	int Handle;

};

struct BACKGROUND {

	Vector2 flont1;
	Vector2 flont2;
	Vector2 back1;
	Vector2 back2;
};

enum Scene {

	TITLE,
	PLAY,
	RESULT,
};

void VectorScreenPrintf(int x, int y, Vector2 vector);

Vector2 LeftTopVertex(Vector2 center, Vector2  LeftTopvertex, float theta, float scale);

Vector2 LeftBottomVertex(Vector2 center, Vector2  LeftBottomvertex, float theta, float scale);

Vector2 RightTopVertex(Vector2 center, Vector2  RightTopvertex, float theta, float scale);

Vector2 RightBottomVertex(Vector2 center, Vector2  RightBottomvertex, float theta, float scale);

Vector2 LeftTopMapNum(Vector2 worldpos, float scale, float heigth, float width, float size);

Vector2 LeftBottomMapNum(Vector2 worldpos, float scale, float heigth, float width, float size);

Vector2 RightTopMapNum(Vector2 worldpos, float scale, float heigth, float width, float size);

Vector2 RightBottomMapNum(Vector2 worldpos, float scale, float heigth, float width, float size);

void newDrawQuad(Vector2 LeftTop, Vector2 RigthTop, Vector2 LeftBottom, Vector2 RigthBottom, float startx, float starty, float DrawWidth, float DrawHeigth, int Handle, int Color);

void newScreenPrintf(int x, int y, float num);

void newScreenPrintf(int x, int y, int num);

void newDrawBox(float x, float y, float width, float heigth, int color);

float easeInSine(Easing x, float start,float end);

float easeOutSine(Easing x, float start, float end);

float easeOutBack(Easing x, float start, float end);

float easeInBack(Easing x, float start, float end);

Vector2 normalize(Vector2 pos);

float dot(float dx, float ex, float dy, float ey);

float length(float a, float b);



