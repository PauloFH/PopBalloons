#include "Lifes.h"
#include "Player.h"

bool Lifes::takeDamage = false;

Lifes::Lifes() {
	tileset = new TileSet("Resources/lifes.png", 210, 37, 6, 6);
	animation = new Animation(tileset, 0.1f, false);

	takeDamage = false;

	MoveTo(270, 30);
}

Lifes::~Lifes() {
	delete tileset;
	delete animation;
}

void Lifes::Update() {
	if (takeDamage) {
		animation->NextFrame();
		takeDamage = false;
	}
}

void Lifes::OnCollision(Object* obj) {

}