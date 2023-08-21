#include "Balloon.h"
#include "PopBalloons.h"
#include "Spell.h"
#include "Player.h"
#include "Lifes.h"

//---------------------------------------------------------------------------------------------------------

int Balloon::pontuacao = 0;

Balloon::Balloon() {

	tileset = new TileSet("Resources/balloon.png", 86, 90, 6, 6);
	animation = new Animation(tileset, 0.1f, true);
	vel = 40;
	uint normal[2] = { 0, 1 };
	uint pop[6] = { 0, 1, 2, 3, 4, 5 };

	animation->Add(NORMAL, normal, 2);
	animation->Add(POP, pop, 6);

	MoveTo(window->CenterX(), window->CenterY(), Layer::LOWER);

	BBox(new Rect(-28, -34, 27, 33));
	type = BALLOON;

}

Balloon::~Balloon() {
	delete tileset;
	delete animation;
}

void Balloon::Update() {

	Translate(0, -vel * gameTime);

	if (y + tileset->TileHeight() < 0) {
		PopBalloons::scene->Delete();
		text.str("");

		text << "balloon deletado" << ".\n";;
		OutputDebugString(text.str().c_str());

		Player::state = 1;
		Player::life--;
		Lifes::takeDamage = true;

		text.str("");

		text << Player::life << ".\n";;
		OutputDebugString(text.str().c_str());
	}

	animation->Select(state);
	animation->NextFrame();

	if (animation->Frame() == 5) {
		PopBalloons::scene->Delete();
		pontuacao = pontuacao + 1;
	}
}

void Balloon::OnCollision(Object * obj) {
	if (obj->Type() == ATACK) {
		state = POP;
		PopBalloons::scene->Remove(obj, ATACK);
	}
	if (obj->Type() == SPELLQ) {
		state = POP;
	}
}