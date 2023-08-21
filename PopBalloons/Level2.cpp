#include "Level2.h"
#include "Cat.h"
#include "Balloon.h"
#include "Lifes.h"
#include "Player.h"
#include <random>
#include "GameOver.h"
#include "PopBalloons.h"

Scene * Level2::scene2;
std::random_device rdm;
std::mt19937 generation(rdm());

void Level2::Init() {

    balloonAudio = new Audio();
    balloonAudio->Add(POPBALLOON_, "Resources/PopBalloon.wav");

    audio = new Audio();
    audio->Add(MENUAUDIO, "Resources/game_thame.wav");

    Player::life = 5;
    Player::state = PLENO;

    // Definindo tempo de cdr das skills como um valor muito alto, pra começarem disponíveis
    Player::cdrQ = 60 * 6;
    Player::cdrW = 60 * 15;
    Player::cdrE = 60 * 10;
    Player::cdrR = 60 * 3;

    // Placar
    Balloon::pontuacao = 0;
    pontuacao2 = "";
    placarDraw = "Placar: ";
    placar = new Font("Resources/FixedSys30.png");
    placar->Spacing(65);

    background = new Sprite("Resources/nightbg.png");
    gram = new Sprite("Resources/gram.png");
    wall = new Sprite("Resources/wall.png");

    tileBalloonRed = new TileSet("Resources/balloon.png", 86, 90, 6, 6);
    tileBalloonBlue = new TileSet("Resources/blueBalloon.png", 86, 90, 6, 6);

    scene2 = new Scene();

    Lifes* lifes = new Lifes();
    scene2->Add(lifes, STATIC);

    Cat* cat = new Cat();
    scene2->Add(cat, STATIC);

    Player* player = new Player();
    scene2->Add(player, MOVING);

    Balloon* balloon;

    for (int i = 0; i < 10; i++) {
        balloon = new Balloon(balloonAudio, BLUE, tileBalloonBlue);
        balloon->MoveTo(random(80, 900), random(500, 800));
        scene2->Add(balloon, MOVING);
    }

    for (int i = 0; i < 20; i++) {
        balloon = new Balloon(balloonAudio, BLUE, tileBalloonBlue);
        balloon->MoveTo(random(80, 900), random(800, 1200));
        scene2->Add(balloon, MOVING);
    }

    for (int i = 0; i < 20; i++) {
        balloon = new Balloon(balloonAudio, BLUE, tileBalloonBlue);
        balloon->MoveTo(random(80, 900), random(1200, 1500));
        scene2->Add(balloon, MOVING);
    }
    for (int i = 0; i < 100; i++) {
        balloon = new Balloon(balloonAudio, BLUE, tileBalloonBlue);
        balloon->MoveTo(random(80, 900), random(1500, 3000));
        scene2->Add(balloon, MOVING);
    }
    audio->Play(MENUAUDIO);

}

void Level2::Finalize() {
    delete balloonAudio;
    delete background;
    delete gram;
    delete wall;
    delete scene2;
    delete tileBalloonRed;
    delete tileBalloonBlue;
    delete audio;
}

void Level2::Update() {

    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    scene2->Update();
    scene2->CollisionDetection();

    if (window->KeyDown('N') || Player::life <= 0)
        Engine::Next<GameOver>();
}

void Level2::Draw() {
    pontuacao2 = std::to_string(Balloon::pontuacao);
    Color black(0.0f, 0.0f, 0.0f, 1.0f);
    placar->Draw(700, 30, placarDraw + pontuacao2, black, Layer::UPPER, 0.3f);
    background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    wall->Draw(window->CenterX(), window->CenterY() + 275, Layer::MIDDLE);
    gram->Draw(window->CenterX(), window->CenterY() + 350, Layer::UPPER);
    scene2->Draw();
    scene2->DrawBBox();
}

int Level2::random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(generation);
}
