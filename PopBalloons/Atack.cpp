#include "Atack.h"
#include "PopBalloons.h"

Atack::Atack(Image* image, int posY) {
	untilY = posY;
	sprite = new Sprite(image);
	vel = 800;
	validAtack = 0;

	type = ATACK;
}

Atack::~Atack() {
	delete sprite;
}

void Atack::Update() {
	Translate(0, -vel * gameTime);

	if (y < window->CenterY() + 190) { // se sair do muro
		validAtack++;
	}

	if (validAtack == 1) {	// pra fazer só 1 vez
		BBox(new Rect(-6, -12.12, 5, 11.12));
		text.str("");

		text << "atack desenhado bbox" << ".\n";;
		OutputDebugString(text.str().c_str());
	}

	if (y < 0 || y < untilY) {
		PopBalloons::scene->Delete();
		text.str("");

		text << "atack deletado" << ".\n";;
		OutputDebugString(text.str().c_str());
	}
}

void Atack::OnCollision(Object * obj) {
}