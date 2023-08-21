#include "Cat.h"

Cat::Cat() {
    tileset = new TileSet("Resources/cat.png", 48, 48, 15, 15);
    animation = new Animation(tileset, 0.5f, true);

    MoveTo(900, 505);
}

Cat::~Cat() {
    delete tileset;
    delete animation;
}

void Cat::Update() {
    animation->NextFrame();
}

void Cat::OnCollision(Object* obj) {

}