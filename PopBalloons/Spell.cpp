#include "Spell.h"
#include "PopBalloons.h"

Spell::Spell(TileSet* tileset, int posX, int posY) {

	animation = new Animation(tileset, 0.01f, false);

	MoveTo(posX, posY);
	BBox(new Circle(48));
	type = SPELL;
}

Spell::~Spell() {
	delete animation;
}

void Spell::Update() {
	animation->NextFrame();

	if (animation->Frame() == 27) {
		PopBalloons::scene->Delete();
	}
}

void Spell::OnCollision(Object * obj) {

}