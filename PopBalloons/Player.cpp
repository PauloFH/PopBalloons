#include "Player.h"
#include "PopBalloons.h"
#include "Atack.h"

Player::Player() {
	tileset = new TileSet("Resources/player.png", 95.89, 143, 1, 6);
	animation = new Animation(tileset, 0.25f, true);

	// chargin atack
	atack = new Image("Resources/atack.png");

	MoveTo(window->CenterX(), window->CenterY() + 180, Layer::FRONT);

	vel = 200;

	BBox(new Rect(-36, -64, 35, 63));
	type = PLAYER;
}

Player::~Player() {
	delete tileset;
	delete animation;
	delete atack;
}

void Player::Update() {
	animation->NextFrame();

	if (window->KeyDown(VK_LEFT)) {
		Translate(-vel * gameTime, 0);
	}
	if (window->KeyDown(VK_RIGHT)) {
		Translate(vel * gameTime, 0);
	}
	if (window->KeyPress(VK_LBUTTON)) {
		Atack* hit = new Atack(atack, window->MouseY());
		hit->MoveTo(x, y);
		PopBalloons::scene->Add(hit, MOVING);
	}

}

void Player::OnCollision(Object* obj) {

}