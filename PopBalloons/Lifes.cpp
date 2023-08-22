#include "Lifes.h"
#include "Player.h"

uint Lifes::takeDamage = 0;

Lifes::Lifes() {
	tileset = new TileSet("Resources/lifes.png", 210, 37, 6, 6);
	animation = new Animation(tileset, 0.1f, false);

	takeDamage = 0;

	MoveTo(120, 30);
}

Lifes::~Lifes() {
	delete tileset;
	delete animation;
}

void Lifes::Update() {
	while (takeDamage != 0) {
		animation->NextFrame();
		takeDamage--;
	}
}

void Lifes::OnCollision(Object* obj) {

}