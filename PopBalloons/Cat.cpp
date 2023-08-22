#include "Cat.h"
#include "Balloon.h"

Cat::Cat(Audio* catAudio, uint ctStt) {
    frames = 0;
    tileset = new TileSet("Resources/cat.png", 48, 48, 15, 30);
    animation = new Animation(tileset, 0.5f, true);

    uint leftcat[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    uint rightcat[15] = { 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15 };
    animation->Add(LEFTCAT, leftcat, 15);
    animation->Add(RIGHTCAT, rightcat, 15);
    stateCat = ctStt;

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
        audio->Play(CAT);
        controlador = false;
    }
    animation->Select(stateCat);
    animation->NextFrame();


}

void Cat::OnCollision(Object* obj) {

}