#pragma once

#include "entity.h"
#include "input.h"

class Button : public Entity {
public:
	//enum to determine the function of a button inside a vector
	enum buttonType {
		PLAY,
		OPTIONS,
		HIGHSCORES,
		QUIT,
		MUTE
	};

	//constructor
	Button();

	//override constructor that is more precise by giving
	//the type of the button making it easier to identify
	//when being pulled out of a vector
	Button(buttonType type);

	//deconstructor
	virtual ~Button();

	//update function
	virtual void update(double deltatime);

	//boolean isclicked that checks if the button is clicked
	bool isClicked();
	//boolean ishold that checks if the button is being held.
	bool isHold();

	//gets the enum type of the button
	int getType() { return type; }

private:
	//default of -1, doesnt do anything at this value
	//if the value gets higher behaiviour could alter
	//see constructor override and the BuildPauseMenu
	//function in MyScene.cpp for more information
	int type = -1;

	//boolean for isHold() function
	bool isHolding = false;
};
