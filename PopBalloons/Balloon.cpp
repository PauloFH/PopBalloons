#include "Balloon.h";
#include "PopBalloons.h"
#include "Spell.h"
#include "Player.h"
#include "Lifes.h"

//---------------------------------------------------------------------------------------------------------
int Balloon::quantidade = 0;
int Balloon::pontuacao = 0;

Balloon::Balloon(Audio* bllnAudio, uint bllnType = 0, TileSet* tset = new TileSet("Resources/balloon.png", 86, 90, 6, 6)) {
	audio = bllnAudio;
	balloonType = bllnType;

	tileset = tset;
	quantidade++;
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
	delete animation;
	quantidade--;
}

void Balloon::Update() {

	animation->Select(state);
	animation->NextFrame();

	Translate(0, -vel * gameTime);

	if (y + tileset->TileHeight() / 2 < 0) {
		PopBalloons::scene->Delete();
		text.str("");

		text << "balloon deletado" << ".\n";;
		OutputDebugString(text.str().c_str());

		Player::state = HITED;
		Player::life--;
		Lifes::takeDamage = true;

		text.str("");

		text << Player::life << ".\n";;
		OutputDebugString(text.str().c_str());
	}

	// não deixa sair da tela
	if (x + tileset->TileWidth() / 2.0f > window->Width())
		MoveTo(window->Width() - tileset->TileWidth() / 2.0f, y);

	if (x - tileset->TileWidth() / 2.0f < 0)
		MoveTo(tileset->TileWidth() / 2.0f, y);

	if (animation->Frame() == 5 && balloonType == RED) {
		audio->Play(POPBALLOON_);
		PopBalloons::scene->Delete();
		pontuacao = pontuacao + 1;
	}
	if (animation->Frame() == 5 && balloonType == BLUE) {
		{
			audio->Play(POPBALLOON_);
			PopBalloons::scene->Delete();
			Balloon* newBalloon = new Balloon(audio, RED);
			newBalloon->MoveTo(x, y);
			PopBalloons::scene->Add(newBalloon, BALLOON);
		} 
	}
}

void Balloon::OnCollision(Object * obj) {
	if (balloonType == RED && obj->Type() == ATACK) {

		state = POP;
		PopBalloons::scene->Delete(obj, ATACK);
	} else if (balloonType == BLUE && obj->Type() == ATACK) {
		state = POP;
		PopBalloons::scene->Delete(obj, ATACK);
	}
	if (obj->Type() == SPELLQ) {
		state = POP;
	}
	
}