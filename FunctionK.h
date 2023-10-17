#pragma once

const int mapx = 66;
const int mapy = 100;
const int barriaItem = 1;
const int speedbeam = 2;
const int enemynum = 10;

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
	float easingTime;
	float result;
	float easingPlus;
	
};

struct SHAKE {

	Vector2 random;
	int shakeTime;
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
	Vector2 saveWorldPos;
	Vector2 oldworldPos;
	Vector2 worldMax;
	inVector2 fitMapSize;
	inVector2 fitOldMapSize;
	Vector2 screenPos;
	Vector2 kameraPos;
	Vector2 scrollPos;
	Vector2  velocity;
	Vector2  velocitySave;
	Vector2 acceleration;
	Vector2 afterimageWorldPos[3];
	Vector2 afterimageScreenPos[3];
	Vertex afterimagePos[3];
	Easing scaleUp;
	Easing scaleDown;
    SHAKE  damage;
	float rotate;
	float time;
	float sideDamageTime;
	float width;
	float height;
	float radius;
	float drawScale;
	float totalScale;
	float ScaleSave;
	int fallCollTime;
	int damageCollTime;
	int hitBackTime;
	int Handle;
	
};

struct ENEMYCHARACTER {
	
	Vertex vertexPos[enemynum];
	Vertex vertexWide[enemynum];
	Vector2 worldPos[enemynum];
	Vector2 screenPos[enemynum];
	Vector2 distance[enemynum];
	Easing easing;
	float scale[enemynum];
	float radius[enemynum];
	int hitConbo;
	int conboCollTime;
	int Handle;
};

struct ITEM {

	Vertex vertexPos[10];
	Vertex vertexWide[10];
	Vector2 worldPos[10];
	Vector2 screenPos[10];
	Vector2 distance[10];
	Easing easing;
	float radius[10];
	int Have;
	int Handle;	
};

struct BEAM {

	Vertex vertexPos;
	Vertex vertexWide;
	Vector2 worldPos;
	Vector2 screenPos;
	Vector2 oldWorldPos;  
	Vector2 distance;
	Easing easing;
	float radius;
	float rotate;
	int Have;
	int Handle;
};


struct DISTANCE {

	float enemyANDplayer[enemynum];
	float itemANDplayer[10];
	int beamANDenemy[enemynum];

};

struct FLAG {
	bool isMoveAbove;
	bool isPlayerEnemyColligion;
	bool isEnemyDeath[enemynum];
	bool isFallStop;
	bool isFallHighSpeed;
	bool isFallColl;
	bool isDamage;
	bool isDamageColl;
	bool isScaleUp;
	bool isScaleDown;
	bool isHit;
	bool isConboChain;
	bool isMapZoomInOut;
	bool isAnticipation;
	bool isLeftDamage;
	bool isRightDamage;
	bool isHitBack;
	bool isItemGet;
	bool isSceneChange;
	int ZoomLevel;
};

struct MAPCHIP {

	Vector2 ScrollPos;
	Vector2 worldPos;
	Vertex pos;
	Vertex wide;
	Easing zoomInOut;
	float scale;
	float saveScale;
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

float easeOutCirc(Easing x, float start, float end);

float easeInQuart(Easing x, float start, float end);

float easeInOutBack(Easing x, float start, float end);

Vector2 normalize(Vector2 pos);

float dot(float dx, float ex, float dy, float ey);

float length(float a, float b);



