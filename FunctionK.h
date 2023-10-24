#pragma once

const int tutorial = 0;
const int barriaItem = 1;
const int speedbeam = 2;
const int enemynum = 60;
const int itemnum = 30;
const int piecesnum = 30;
const int mapnumm = 7;

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
	float nextCount;
	float isback;
	int colltime;
};

struct SHAKE {

	Vector2 random;
	int shakeTime;
	bool isShake;
};

struct Mask {
	Vector2 pos;
	Vector2 endPos;
	float radius;
	bool isPause;
	bool isBack;
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
	float scaleUpPlus;
	float ScaleSave;
	int fallCollTime;
	int damageCollTime;
	int hitBackTime;
	int tutorialtime;
	int startTime;
	int ishajimata;
	int Handle;	
};

struct ENEMYCHARACTER {
	
	Vertex vertexPos[enemynum];
	Vertex vertexWide[enemynum];
	Vector2 worldPos[mapnumm][enemynum];
	Vector2 screenPos[mapnumm][enemynum];
	Vector2 distance[enemynum];
	Vector2 Spone[mapnumm];
	Easing easing;
	float scale[enemynum];
	float radius[enemynum];
	int hitConbo;
	int conboCollTime;
	int Handle;
};

struct ITEM {

	Vertex vertexPos[itemnum];
	Vertex vertexWide[itemnum];
	Vector2 worldPos[mapnumm][itemnum];
	Vector2 screenPos[mapnumm][itemnum];
	Vector2 distance[itemnum];
	Vector2 Spone[mapnumm];
	Easing easing;
	float radius[itemnum];
	int Have;
	int Handle;	
};

struct PIECES {

	Vertex vertexPos[piecesnum];
	Vertex vertexWide[piecesnum];
	Vector2 worldPos[mapnumm][piecesnum];
	Vector2 screenPos[mapnumm][piecesnum];
	Vector2 distance[piecesnum];
	Vector2 Spone[mapnumm];
	Easing easing;
	float radius[piecesnum];
	int Have;
	int Handle;
	float scale;
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
	int time;
	int Have;
	int Handle;
	float scale;
};


struct DISTANCE {

	float enemyANDplayer[enemynum];
	float itemANDplayer[itemnum];
	int beamANDenemy[enemynum];

};

struct FLAG {
	bool isMoveAbove;
	bool isPlayerEnemyColligion;
	bool isEnemyDeath[mapnumm][enemynum];
	bool isPiecesNone[piecesnum];
	bool isItemNone[itemnum];
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
	bool isBeamShot;
	bool scaleUpget;
	bool isGameStart;
	bool isTutorialSkip;
	bool isStageChange;
	bool isStop;
	bool isStopNext;
	bool isHowtoPlay1;
	bool isHowtoPlay2;
	bool isHowtoPlay3;
	bool isHowtoPlay4;
	bool isTutorialGo;
	bool isFever;
	bool isfeverTimedown;
	int ZoomLevel;
};

struct MAPCHIP {

	Vector2 ScrollPos;
	Vector2 worldPos;
	Vertex pos;
	Vertex wide;
	Easing zoomInOut;
	float zoomScale;
	float saveScale;
	int number;
	float size;
	int Handle;
};

struct SCORE {

	int num;
	int enemycount;
	float saveNum;
	float saveNum2;
	float realNum;
	float realNum2;
	float linearTime;
	float linearTime2;
	float feverTime;
	float upnum;
	Vector2 allpos;
	int number[7];
	int plusScore[5];
	int plusnum;
	int kasuri;
	bool iskasuri;
	bool isChange;
	bool isChange2;
	bool isDown;
};

struct BACKGROUND {

	Vector2 flont1;
	Vector2 flont2;
	Vector2 back1;
	Vector2 back2;
};

struct NUMBER {
	Vector2 pos;
	Vector2 limitdownpos;
	int secondcount;
	int minutecount;
	int second;
	int second10;
	int minute;
	int stoptimer;
	int leftover;
	int Handle;
	int limitHandle;
	int limitdownHandle;
	int color;
	int iszero;

	Easing e;
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

float Liner(Easing x, float start, float end);

float easeInSine(Easing x, float start,float end);

float easeOutSine(Easing x, float start, float end);

float easeOutBack1(Easing x, float start, float end);

float easeInBack(Easing x, float start, float end);

float easeOutCirc(Easing x, float start, float end);

float easeInQuart(Easing x, float start, float end);

float easeInOutBack(Easing x, float start, float end);

Vector2 normalize(Vector2 pos);

float dot(float dx, float ex, float dy, float ey);

float length(float a, float b);

float easeOutBack(float x);

void MaskProcess(Vector2& pos, const Vector2& endPos, float& radius, bool& isPause, bool& isBack,float endradius);


