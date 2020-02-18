#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Mario : public GameObject
{
public:
	Mario();
	~Mario();

	void update(float dt) override;
	void flip(bool flipped);
	void Walk(float dt);
	void Duck(float dt, int done);
	void Stand(float dt);

protected:
	Animation walk;
	Animation swim;
	Animation duck;
	Animation stand;
	Animation ducked;
};

