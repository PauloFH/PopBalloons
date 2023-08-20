#include "Player.h"
#include "PopBalloons.h"
#include "Atack.h"
#include "Spell.h"

int Player::life = 5;

Player::Player() {
	tileset = new TileSet("Resources/player.png", 95.89, 143, 1, 6);
	damage = new TileSet("Resources/playerDamage.png", 95.89, 143.84, 1, 3);
	animation = new Animation(tileset, 0.25f, true);

	text.str("");

	text << life << ".\n";
	OutputDebugString(text.str().c_str());

	// charging atack
	atack = new Image("Resources/atack.png");

	// charging spells
	tileSpellQ = new TileSet("Resources/spellQ.png", 164, 164, 28, 28);
	tileSpellW = new TileSet("Resources/spellW.png", 64, 64, 60, 60);
	tileSpellE = new TileSet("Resources/spellE.png", 203, 45, 3, 3);
	tileSpellR = new TileSet("Resources/spellR.png", 192, 128, 12, 24);

	MoveTo(window->CenterX(), window->CenterY() + 270, Layer::FRONT);

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
	delete tileSpellE;
	delete tileSpellR;
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

		text << "poder invocado" << ".\n";
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

		text << "poder W invocado" << ".\n";
		OutputDebugString(text.str().c_str());
		spellW = false;
	}

	if (window->KeyPress('E')) {
		spellE = true;
	}
	if (spellE) {
		Spell* power = new Spell(tileSpellE, window->MouseX(), window->MouseY(), E);
		PopBalloons::scene->Add(power, MOVING);
		text.str("");

		text << "poder E invocado" << ".\n";
		OutputDebugString(text.str().c_str());
		spellE = false;
	}

	if (window->KeyPress('R')) {
		spellR = true;
	}
	if (spellR) {
		Spell* power = new Spell(tileSpellR, window->MouseX(), window->MouseY(), R, x);
		PopBalloons::scene->Add(power, MOVING);
		text.str("");

		text << "poder R invocado" << ".\n";
		OutputDebugString(text.str().c_str());
		spellR = false;
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