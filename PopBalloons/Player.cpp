#include "Player.h"
#include "PopBalloons.h"
#include "Atack.h"
#include "Spell.h"

int Player::life = 5;
uint Player::state = PLENO;
uint Player::cdrQ, Player::cdrW, Player::cdrE, Player::cdrR;

Player::Player() {
	audio = new Audio();
	audio->Add(ATTACK,"Resources/Spell_attack.wav");
	audio->Add(DAMEGE, "Resources/damege.wav");
	audio->Add(SPELL_EXPLOSION, "Resources/Spell_Explosion.wav");
	audio->Add(SPELL_WALL, "Resources/Spell_wall.wav");
	audio->Add(SPELL_PUXAR, "Resources/Spell_puxar.wav");
	audio->Add(SPELL_WIND, "Resources/wind.wav");

	atkAudio = new Audio();
	atkAudio->Add(1, "Resources/Spell_attack.wav");

	tileset = new TileSet("Resources/playercomplet.png", 95.89, 143, 1, 9);
	animation = new Animation(tileset, 0.25f, true);
	uint pleno[6] = { 0, 1, 2, 3, 4, 5 };
	uint hited[3] = { 6, 7, 8 };
	animation->Add(PLENO, pleno, 6);
	animation->Add(HITED, hited, 3);

	text.str("");

	text << life << ".\n";
	OutputDebugString(text.str().c_str());

	// charging atack
	atack = new Image("Resources/atack.png");

	// charging icons 
	iconQ = new Image("Resources/iconQ.png");
	xiconQ = new Image("Resources/XiconQ.png");
	darkIconQ = new Image("Resources/darkIconQ.png");
	spriteQ = new Sprite(iconQ);
	iconW = new Image("Resources/iconW.png");
	xiconW = new Image("Resources/XiconW.png");
	spriteW = new Sprite(iconW);
	iconE = new Image("Resources/iconE.png");
	xiconE = new Image("Resources/XiconE.png");
	spriteE = new Sprite(iconE);
	iconR = new Image("Resources/iconR.png");
	xiconR = new Image("Resources/XiconR.png");
	spriteR = new Sprite(iconR);

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
	delete atkAudio;
	delete tileSpellQ;
	delete tileSpellW;
	delete tileSpellE;
	delete tileSpellR;
	delete audio;
	delete iconQ;
	delete xiconQ;
	delete darkIconQ;
	delete spriteQ;
	delete iconW;
	delete xiconW;
	delete spriteW;
	delete iconE;
	delete xiconE;
	delete spriteE;
	delete iconR;
	delete xiconR;
	delete spriteR;
}

void Player::Update() {

	// muda os estados
	if (state == HITED && animation->Frame() == 8) {
		audio->Play(DAMEGE);
		state = PLENO;
	}

	animation->Select(state);
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
	if (x + tileset->TileWidth() / 2.0f > window->Width()) {
		MoveTo(window->Width() - tileset->TileWidth() / 2.0f, y);
	}
	if (x - tileset->TileWidth() / 2.0f < 0) {
		MoveTo(tileset->TileWidth() / 2.0f, y);
	}
	// Basic atack
	if (window->KeyPress(VK_LBUTTON)) {

		Atack* hit = new Atack(atkAudio, atack, window->MouseY());
		hit->MoveTo(x, y);
		PopBalloons::scene->Add(hit, MOVING);
		
	}

	// Spell Q
	if ((cdrQ >= 6 * 60)) {
		spriteQ = new Sprite(iconQ);
	}
	else {
		int cdr = cdrQ / 60; // retorna o valor, em segundos, que faltam pra retornar a skill
	}
	if (window->KeyPress('Q') && (cdrQ >= 6 * 60)) {
		spellQ = true;
		cdrQ = 0;
		spriteQ = new Sprite(xiconQ);
	}
	if (spellQ) {
		audio->Play(SPELL_EXPLOSION);
		Spell* power = new Spell(tileSpellQ, window->MouseX(), window->MouseY(), Q);
		PopBalloons::scene->Add(power, MOVING);
		spellQ = false;
	}

	// Spell W
	if ((cdrW >= 15 * 60)) {
		spriteW = new Sprite(iconW);
	}
	if (window->KeyPress('W') && (cdrW >= 15 * 60)) {
		spellW = true;
		cdrW = 0;
		spriteW = new Sprite(xiconW);
	}
	if (spellW) {

		audio->Play(SPELL_PUXAR);
		Spell* power = new Spell(tileSpellW, window->MouseX(), window->MouseY(), W);
		PopBalloons::scene->Add(power, MOVING);
		spellW = false;
	}

	// Spell E
	if ((cdrE >= 10 * 60)) {
		spriteE = new Sprite(iconE);
	}
	if (window->KeyPress('E') && (cdrE >= 10 * 60)) {
		spellE = true;
		cdrE = 0;
		spriteE = new Sprite(xiconE);
	}
	if (spellE) {
		audio->Play(SPELL_WALL);
		Spell* power = new Spell(tileSpellE, window->MouseX(), window->MouseY(), E);
		PopBalloons::scene->Add(power, MOVING);
		spellE = false;
	}

	// Spell R
	if ((cdrR >= 3 * 60)) {
		spriteR = new Sprite(iconR);
	}
	if (window->KeyPress('R') && (cdrR >= 3 * 60)) {
		spellR = true;
		cdrR = 0;
		spriteR = new Sprite(xiconR);
	}
	if (spellR) {
		audio->Play(SPELL_WIND);
		Spell* power = new Spell(tileSpellR, window->MouseX(), window->MouseY(), R, x);
		PopBalloons::scene->Add(power, MOVING);
		spellR = false;
	}

		cdrQ++;
		cdrW++;
		cdrE++;
		cdrR++;
};


void Player::Draw() {
	animation->Draw(x, y, z);
	spriteQ->Draw(660, 635, Layer::FRONT);
	spriteW->Draw(730, 635, Layer::FRONT);
	spriteE->Draw(800, 635, Layer::FRONT);
	spriteR->Draw(870, 635, Layer::FRONT);
};

void Player::OnCollision(Object* obj){

}
