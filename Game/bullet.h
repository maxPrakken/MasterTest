#pragma once

#include <entity.h>

class Bullet : public Entity {
public:

	Bullet();
	virtual ~Bullet();
	virtual void update(double deltatime);

	Vector2 direction;

private:

	float speed;
};