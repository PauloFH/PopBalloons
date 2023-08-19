#include "Balloon.h";

Balloon::Balloon() {
	tileset = new TileSet("Resources/balloon.png", 86, 90, 6, 6);
	animation = new Animation(tileset, 0.05f, true);

	MoveTo(window->CenterX(), window->CenterY(), 0.0f);
}

Balloon::~Balloon() {
	delete tileset;
	delete animation;
}

void Balloon::Update() {
	animation->NextFrame();
}

void Balloon::OnCollision() {

}