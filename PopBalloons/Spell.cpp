#include "Spell.h"
#include "PopBalloons.h"

Spell::Spell(TileSet* tset, int posX, int posY, uint sType) {

	MoveTo(posX, posY);
	spellType = sType;
	tileset = tset;

	// Tempo decorrido
	time = 0;

	// Explosão
	if (spellType == Q) {
		animation = new Animation(tileset, 0.01f, false);
		BBox(new Circle(tileset->Height() / 2));
		type = SPELLQ;
	}

	// Campo gravitacional
	if (spellType == W) {
		animation = new Animation(tileset, 0.1f, true);
		BBox(new Circle(tileset->Height() * 2));
		type = SPELLW;
	}

	// Barreira de pedras
	if (spellType == E) {
		animation = new Animation(tileset, 0.1f, false);
		BBox(new Rect(-98.5, -19.5, 97.5, 18.5));
		type = SPELLE;
	}
	
}

Spell::Spell(TileSet* tset, int posX, int posY, uint sType, uint posPerson) {

	MoveTo(posX, posY);
	spellType = sType;
	tileset = tset;

	// Tempo decorrido
	time = 0;

	// Correnteza de vento
	if (spellType == R) {
		animation = new Animation(tileset, 0.1f, false);
		uint toRight[12] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
		uint toLeft[12] = { 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12 };
		animation->Add(TORIGHT, toRight, 12);
		animation->Add(TOLEFT, toLeft, 12);
		if (posPerson > posX) {
			direction = TORIGHT;
			BBox(new Rect(-120, -63.5, 239, 62.5));
		}
		else {
			direction = TOLEFT;
			BBox(new Rect(-240, -63.5, 119, 62.5));
		}
		type = SPELLR;
	}
}

Spell::~Spell() {
	delete animation;
}

void Spell::Update() {
	animation->Select(direction);
	animation->NextFrame();

	if (animation->Frame() == 27 && spellType == Q) {
		PopBalloons::scene->Delete();
	}

	if (time >= 10 / gameTime && spellType == W) {
		PopBalloons::scene->Delete();
	}

	if (spellType == E && time >= 10 / gameTime) {
		PopBalloons::scene->Delete();
	}

	if (spellType == R && (animation->Frame() == 11 || animation->Frame() == 12)) {
		PopBalloons::scene->Delete();
	}

	time++;
}

void Spell::OnCollision(Object * obj) {
	if (obj->Type() == BALLOON) {
		if (spellType == W) {
			if (obj->X() > x) {
				obj->Translate(-20 * gameTime, 0);
			}
			if (obj->X() < x) {
				obj->Translate(20 * gameTime, 0);
			}
			if (obj->Y() > y) {
				obj->Translate(0, -20 * gameTime);
			}
			if (obj->Y() < y) {
				obj->Translate(0, 20 * gameTime);
			}
		}
		if (spellType == E) {
			if (obj->Y() < y + tileset->Height() * 2.0f) {
				obj->MoveTo(obj->X(), y + tileset->Height() * 1.15f);
			}
		}
		if (spellType == R) {
			if (direction == TOLEFT) {
				obj->Translate(-100 * gameTime, 0);
			}
			if (direction == TORIGHT) {
				obj->Translate(100 * gameTime, 0);
			}
			obj->Translate(0, 120 * gameTime);
		}
	}
}