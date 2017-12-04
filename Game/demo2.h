#pragma once

#include "../MXP3/include/scene.h"
#include "grid.h"
#include "player.h"

class Demo2 : public Scene {
public:
	Demo2();
	virtual ~Demo2();

	virtual void update(double deltatime);

private:
	void buildPlatform(Vector2 pos);

	void playerCheckGround();

	std::vector<Entity*>platformVector;

	Player* player;

	Grid* background;

	Entity* wallLeft;
	Entity* wallRight;
	Entity* wallTop;
	Entity* wallDown;
};