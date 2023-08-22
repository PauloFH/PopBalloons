#include "Level2.h"
#include "Cat.h"
#include "Balloon.h"
#include "Lifes.h"
#include "Player.h"
#include <random>
#include "GameOver.h"
#include "PopBalloons.h"
#include "Vitoria.h"

Scene * Level2::scene2;
std::random_device rdm;
std::mt19937 generation(rdm());

void Level2::Init() {

    balloonAudio2 = new Audio();
    balloonAudio2->Add(POPBALLOON_, "Resources/PopBalloon.wav");

    catAudio2 = new Audio();
    catAudio2->Add(CAT, "Resources/cat.wav");

    audio = new Audio();
    audio->Add(MENUAUDIO, "Resources/game_thame.wav");
    audio->Add(LAUGHT, "Resources/laugh_witch.wav");
    audio->Add(CHILDS,"Resources/child.wav" );
    pontuacao2 = "";
    placarDraw = "Score: ";
    placar = new Font("Resources/FixedSys30.png");
    placar->Spacing(65);

    background = new Sprite("Resources/nightbg.png");
    gram = new Sprite("Resources/gram.png");
    wall = new Sprite("Resources/wall.png");

    tileBalloonRed2 = new TileSet("Resources/balloon.png", 86, 90, 6, 6);
    tileBalloonBlue2 = new TileSet("Resources/blueBalloon.png", 86, 90, 6, 6);

    scene2 = new Scene();

    Lifes* lifes = new Lifes();
    scene2->Add(lifes, STATIC);

    Cat* cat = new Cat(catAudio2, LEFTCAT);
    scene2->Add(cat, STATIC);

    Player* player2 = new Player();
    Player::life = 5;
    Player::state = PLENO;

    // Definindo tempo de cdr das skills pra começarem disponíveis
    Player::cdrQ = 60 * 6;
    Player::cdrW = 60 * 15;
    Player::cdrE = 60 * 10;
    Player::cdrR = 60 * 3;

    // Placar
    Balloon::quantidade = 0;
    Balloon::pontuacao = 0;
    scene2->Add(player2, MOVING);

    Balloon* balloon;

    for (int i = 0; i < 80; i++) {
        balloon = new Balloon(balloonAudio2, BLUE, tileBalloonBlue2);
        balloon->MoveTo(random(80, 900), random(500, 1000));
        scene2->Add(balloon, STATIC);
    }
    audio->Play(MENUAUDIO);

}

void Level2::Finalize() {
    delete placar;
    delete balloonAudio2;
    delete catAudio2;
    delete background;
    delete gram;
    delete wall;
    delete tileBalloonRed2;
    delete tileBalloonBlue2;
    delete audio;
    delete scene2;
}

void Level2::Update() {

    frames++;
    child++;

    if (frames >= laught) {
        lg = true;

    }
    if (lg) {
        frames = 0;
        audio->Play(LAUGHT);
        lg = false;

    }
    if (child >= 800) {
        ch = true;

    }
    if (ch) {
        child = 0;
        audio->Play(CHILDS);
        ch = false;

    }

    scene2->Update();
    scene2->CollisionDetection();

    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();


    if (Balloon::quantidade == 0 || (window->KeyPress('G'))) {
        Engine::Next<Vitoria>();
    }

    if (window->KeyPress('N') || Player::life <= 0)
        Engine::Next<GameOver>();
}

void Level2::Draw() {
    pontuacao2 = std::to_string(Balloon::pontuacao);
    string qtd = std::to_string(Balloon::quantidade);
    Color black(0.0f, 0.0f, 0.0f, 1.0f);
    placar->Draw(700, 30, placarDraw + pontuacao2, black, Layer::UPPER, 0.3f);
    placar->Draw(700, 60, qtd, black, Layer::UPPER, 0.3f);
    background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    wall->Draw(window->CenterX(), window->CenterY() + 275, Layer::MIDDLE);
    gram->Draw(window->CenterX(), window->CenterY() + 350, Layer::UPPER);
    scene2->Draw();
}

int Level2::random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(generation);
}
