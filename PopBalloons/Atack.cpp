#include "Atack.h"
#include "PopBalloons.h"

Atack::Atack(Image* image, int posY) {
	audio = new Audio();
	audio->Add(1, "Resources/Spell_attack.wav");
	untilY = posY;
	sprite = new Sprite(image);
	vel = 800;

	BBox(new Rect(-6, -12.12, 5, 11.12));
	type = ATACK;
	audio->Play(1);
}

Atack::~Atack() {
	delete sprite;
}

void Atack::Update() {
	Translate(0, -vel * gameTime);
	if (y < 0 || y < untilY) {
		PopBalloons::scene->Delete();
		text.str("");

		text << "atack deletado" << ".\n";;
		OutputDebugString(text.str().c_str());
	}
}

void Atack::OnCollision(Object * obj) {

}