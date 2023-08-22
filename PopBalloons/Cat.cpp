#include "Cat.h"

Cat::Cat(Audio* catAudio) {
    frames = 0;
    tileset = new TileSet("Resources/cat.png", 48, 48, 15, 15);
    animation = new Animation(tileset, 0.5f, true);
    audio = catAudio;
    MoveTo(900, 505);

}

Cat::~Cat() {
    delete tileset;
    delete animation;
}

void Cat::Update() {

    frames++;

    if (frames >= ctFrames) {
        controlador = true;
    }

    if (controlador) {
        frames = 0;
        audio->Play(100);
        controlador = false;
    }
    animation->NextFrame();

}

void Cat::OnCollision(Object* obj) {

}