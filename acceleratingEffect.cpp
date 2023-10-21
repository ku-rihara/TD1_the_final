#include <Novice.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Functions.h"
#include "acceleratingEffect.h"

void acceleratingEffect(AcceleratingEffect& ac,float length,float lenghtM,const int iMax,const int jMax ) {
	if (ac.isTrigger == true) {
		for (int i = 0; i < iMax; i++) {
			for (int j = 0; j < jMax; j++) {
				if (ac.isActive[i][j] == true) {
					ac.activeTime[i][j]--;
					ac.length[i][j] -= ac.lengthp[i][j];
					ac.pos2[i][j].y += ac.length[i][j];
					if (ac.activeTime[i][j] <= 0) {
						ac.isActive[i][j] = false;
						ac.pos[i][j].x = -100;
						ac.pos[i][j].y = -100;
						ac.pos2[i][j].x = -100;
						ac.pos2[i][j].y = -100;
					}
				}
				else {
					ac.randomPos[i][j].x = float(rand() % 1280);
					ac.randomPos[i][j].y = float(rand() % 720);
					ac.pos[i][j].x = ac.randomPos[i][j].x;
					ac.pos[i][j].y = ac.randomPos[i][j].y;
					ac.pos2[i][j].y = ac.pos[i][j].y;
					ac.pos2[i][j].x = ac.pos[i][j].x;
					ac.length[i][j] = -length;
					ac.lengthp[i][j] = lenghtM;
					ac.activeTime[i][j] = 20;
					ac.isActive[i][j] = true;
					break;
				}
			}
		}
	}
	else {
		for (int i = 0; i < iMax; i++) {
			for (int j = 0; j < jMax; j++) {
				ac.activeTime[i][j]--;
				ac.length[i][j] -= ac.lengthp[i][j];
				ac.pos2[i][j].y += ac.length[i][j];
				if (ac.activeTime[i][j] <= 0) {
					ac.isActive[i][j] = false;
					ac.pos[i][j].x = -100;
					ac.pos[i][j].y = -100;
					ac.pos2[i][j].x = -100;
					ac.pos2[i][j].y = -100;
				}
			}
		}
	}
}