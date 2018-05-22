#pragma once

#include "../MXP3/include/scene.h"

#include <sceneManager.h>

#include "grid.h"
#include "Player.h"
#include "bullet.h"
#include "Button.h"
#include "Slider.h"

#include <typeinfo>
#include <iostream>

class optionsMenu : public Scene {
public:
	//constructor
	optionsMenu();
	
	//deconstructor
	virtual ~optionsMenu();

	//update function
	virtual void update(double deltatime);

	void buttonClickCheck();
	Slider* getAudioSlider() { return audioSlider; }

private:
	Button* backButton;
	Button* muteButton;
	Slider* audioSlider;

	bool muteClicked = false;

	std::vector<Button*>buttonVector;
};