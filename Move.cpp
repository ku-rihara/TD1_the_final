#include <Novice.h>
#include <math.h>
#include "FunctionK.h"
#include "FunctionS.h"
#include "Move.h"

void PlayerMove(MAINCHARACTER& main) {

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	static float dirX = 0;
	static float velocityTmp = 6;



	/*main.velocity = 0;
	main.acceleration = 1.0002f;*/

	static bool isAccelerating = false;

	if (isAccelerating == false) {
		if (keys[DIK_A] || keys[DIK_LEFT]) {
			dirX--;
		}
		if (keys[DIK_D] || keys[DIK_RIGHT]) {
			dirX++;
		}
	}
	main.worldPos.x += dirX * velocityTmp;

	

	if (keys[DIK_SPACE]) {
		
	
		isAccelerating = true;
	}
	else {

		isAccelerating = false;
	}

	dirX = 0;

	Novice::ScreenPrintf(0, 200, "acceleration=%f", main.acceleration);
}

