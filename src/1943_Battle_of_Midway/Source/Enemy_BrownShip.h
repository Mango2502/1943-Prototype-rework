#ifndef __ENEMY_BROWNSHIP_H__
#define __ENEMY_BROWNSHIP_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_BrownShip : public Enemy
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_BrownShip(int x, int y);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update(float deltaTime) override;

private:
	

	// The position (as ratio) in the wave at a specific moment
	float waveRatio = 0.0f;

	// The speed at which the wave ratio is increased
	float waveRatioSpeed = 0.025f;

	// The original spawning position. The wave will be calculated from that
	int spawn_y = 0;

	// The total height of the wave
	int waveHeight = 50;

	// The enemy animation
	Animation flyAnim, flyFlip, flyBack, flyFlip1;

	// The path that will define the position in the world
	Path path;
};

#endif // __ENEMY_BROWNSHIP_H__