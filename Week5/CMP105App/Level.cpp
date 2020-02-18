#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	
	// initialise game objects
	zombTexture.loadFromFile("gfx/animZombie.png");
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(100, 100);
	zombie.setTexture(&zombTexture);

	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setSize(sf::Vector2f(15,21));
	mario.setPosition(200, 200);
	mario.setTexture(&marioTexture);

	float speed = 100.f;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

int done = 0;

// Update game objects
void Level::update(float dt)
{
	zombie.update(dt);

	if (input->isKeyDown(sf::Keyboard::Left) && zombie.getPosition().x > 0) {
		zombie.move(-(speed * dt), 0);
		zombie.flip(true);
	}
	else if (input->isKeyDown(sf::Keyboard::Right) && zombie.getPosition().x < window->getSize().x - 25) {
		zombie.move((speed * dt), 0);
		zombie.flip(false);
	}


	if (input->isKeyDown(sf::Keyboard::A) && mario.getPosition().x > 0) {
		mario.move(-(speed * dt), 0);
		mario.flip(true);
		mario.Walk(dt);
	}
	else if (input->isKeyDown(sf::Keyboard::D) && mario.getPosition().x < window->getSize().x - 25) {
		mario.move((speed * dt), 0);
		mario.flip(false);
		mario.Walk(dt);
	}
	else {
		mario.Stand(dt);
	}
	
	if (input->isKeyDown(sf::Keyboard::S)) {
		mario.Duck(dt, done);
		done = 1;
	}

	if (input->isKeyDown(sf::Keyboard::S) == false) {
		done = 0;
	}

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(zombie);
	window->draw(mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}