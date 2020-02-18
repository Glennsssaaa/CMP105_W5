#include "Mario.h"

Mario::Mario() {
	stand.addFrame(sf::IntRect(0, 0, 15, 21));
	stand.setFrameSpeed(1.f / 10.f);

	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));

	walk.setFrameSpeed(1.f / 10.f);

	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	ducked.addFrame(sf::IntRect(16, 41, 16, 20));

	duck.setFrameSpeed(.5f / 10.f);
}

Mario::~Mario() {

}

void Mario::update(float dt) {
	
}

void Mario::flip(bool flipped) {
	if (flipped == true) {
		walk.setFlipped(true);
		duck.setFlipped(true);
		ducked.setFlipped(true);
		stand.setFlipped(true);
	}
	else if (flipped == false) {
		walk.setFlipped(false);
		duck.setFlipped(false);
		ducked.setFlipped(false);
		stand.setFlipped(false);
	}
}

void Mario::Walk(float dt) {
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}

void Mario::Duck(float dt, int done) {
	if (done == 0) {
		duck.animate(dt);
		done = 1;
	}
	else {
		ducked.animate(dt);
	}
	setTextureRect(duck.getCurrentFrame());
}

void Mario::Stand(float dt) {
	stand.animate(dt);
	setTextureRect(stand.getCurrentFrame());
}