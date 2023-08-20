#include "Player.h"
#include "PopBalloons.h"
#include "Atack.h"
#include "Spell.h"

Player::Player() {
	tileset = new TileSet("Resources/player.png", 95.89, 143, 1, 6);
	animation = new Animation(tileset, 0.25f, true);

	// chargin atack
	atack = new Image("Resources/atack.png");

	//charging spells
	tileSpellQ = new TileSet("Resources/spell.png", 96, 96, 28, 28);
	tileSpellW = new TileSet("Resources/spellW.png", 64, 64, 60, 60);

	MoveTo(window->CenterX(), window->CenterY() + 380, Layer::FRONT);

	vel = 200;

	BBox(new Rect(-36, -64, 35, 63));
	type = PLAYER;
}

Player::~Player() {
	delete tileset;
	delete animation;
	delete atack;
	delete tileSpellQ;
	delete tileSpellW;
}

void Player::Update() {
	animation->NextFrame();

	// Movimentação
	if (window->KeyDown(VK_LEFT)) {
		Translate(-vel * gameTime, 0);
	}
	if (window->KeyDown(VK_RIGHT)) {
		Translate(vel * gameTime, 0);
	}
	if (window->KeyDown('A')) {
		Translate(-vel * gameTime, 0);
	}
	if (window->KeyDown('D')) {
		Translate(vel * gameTime, 0);
	}

	// Bloquear passagem
	if (x + tileset->TileWidth() / 2.0f > window->Width())
		MoveTo(window->Width() - tileset->TileWidth() / 2.0f, y);

	if (x - tileset->TileWidth() / 2.0f < 0)
		MoveTo(tileset->TileWidth() / 2.0f, y);

	// Basic atack
	if (window->KeyPress(VK_LBUTTON)) {
		Atack* hit = new Atack(atack, window->MouseY());
		hit->MoveTo(x, y);
		PopBalloons::scene->Add(hit, MOVING);
	}

	// Spell Q
	if (window->KeyPress('Q')) {
		spellQ = true;
	}
	if (spellQ) {
		Spell* power = new Spell(tileSpellQ, window->MouseX(), window->MouseY(), Q);
		PopBalloons::scene->Add(power, MOVING);
		text.str("");

		text << "poder invocado" << ".\n";;
		OutputDebugString(text.str().c_str());
		spellQ = false;
	}

	// Spell W
	if (window->KeyPress('W')) {
		spellW = true;
	}
	if (spellW) {
		Spell* power = new Spell(tileSpellW, window->MouseX(), window->MouseY(), W);
		PopBalloons::scene->Add(power, MOVING);
		text.str("");

		text << "poder W invocado" << ".\n";;
		OutputDebugString(text.str().c_str());
		spellW = false;
	}

	// Duplo atk
	if (window->KeyPress(VK_RBUTTON)) {
		std::vector<Atack*> hits;
		hits.push_back(new Atack(atack, window->MouseY()));
		hits.push_back(new Atack(atack, window->MouseY()));
		hits[0]->MoveTo(x - 10, y);
		hits[1]->MoveTo(x + 10, y);

		PopBalloons::scene->Add(hits[0], MOVING);
		PopBalloons::scene->Add(hits[1], MOVING);
	}

}

void Player::OnCollision(Object* obj) {

}

Player::Player(TileSet *  tileset) {
	this->tileset = tileset;
	animation = new Animation(this->tileset, 0.15f, true);
	MoveTo(window->CenterX(), window->CenterY() + 380, Layer::FRONT);

}