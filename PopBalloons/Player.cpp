#include "Player.h"
#include "PopBalloons.h"

Player::Player() {
	tileset = new TileSet("Resources/B_witch_idle.png", 32, 48, 1, 6);
	animation = new Animation(tileset, 0.25f, true);

	MoveTo(window->CenterX(), window->CenterY() + 150, 0.0f);

	vel = 200;

	BBox(new Rect(-16, -24, 15, 23));
	type = PLAYER;
}

Player::~Player() {
	delete tileset;
	delete animation;
}

void Player::Update() {
	animation->NextFrame();

	if (window->KeyDown(VK_UP)) {
		Translate(0, -vel * gameTime);
	}
	if (window->KeyDown(VK_DOWN)) {
		Translate(0, vel * gameTime);
	}
	if (window->KeyDown(VK_LEFT)) {
		Translate(-vel * gameTime, 0);
	}
	if (window->KeyDown(VK_RIGHT)) {
		Translate(vel * gameTime, 0);
	}

}

void Player::OnCollision(Object* obj) {

}