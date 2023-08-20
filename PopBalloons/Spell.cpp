#include "Spell.h"
#include "PopBalloons.h"

Spell::Spell(TileSet* tset, int posX, int posY, uint sType) {

	MoveTo(posX, posY);
	spellType = sType;
	tileset = tset;

	// Explosão
	if (spellType == Q) {
		animation = new Animation(tileset, 0.01f, false);
		BBox(new Circle(tileset->Height() / 2));
		type = SPELLQ;
	}

	// Campo gravitacional
	if (spellType == W) {
		animation = new Animation(tileset, 0.1f, false);
		BBox(new Circle(tileset->Height() * 2));
		type = SPELLW;
	}

	
}

Spell::~Spell() {
	delete animation;
}

void Spell::Update() {
	animation->NextFrame();

	if (animation->Frame() == 27 && spellType == Q) {
		PopBalloons::scene->Delete();
	}

	if (animation->Frame() == 59 && spellType == W) {
		PopBalloons::scene->Delete();
	}

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
	}
}