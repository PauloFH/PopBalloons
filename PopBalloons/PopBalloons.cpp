/**********************************************************************************
// FontDemo
// 
// Criação:     07 Out 2011
// Atualização: 16 Ago 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   POPBALLOONS.
//
**********************************************************************************/

#include "PopBalloons.h"
#include "Balloon.h"
#include "Player.h"
#include "GameOver.h"
#include "Cat.h"
#include "Lifes.h"
#include <iostream>
#include <random>
//#include "Level2.h"
#include "Vitoria.h"

Scene* PopBalloons::scene;
std::random_device rd;
std::mt19937 gen(rd());

void PopBalloons::Init()
{
    balloonAudio = new Audio();
    balloonAudio->Add(POPBALLOON_, "Resources/PopBalloon.wav");
    catAudio = new Audio();
    catAudio->Add(CAT, "Resources/cat.wav");
    frames = 0;
    child = 0;
    audio = new Audio();
    audio->Add(MENUAUDIO, "Resources/game_thame.wav");
    audio->Add(LAUGHT, "Resources/laugh_witch.wav");
    audio->Add(CHILDS, "Resources/child.wav");
    
    Balloon::quantidade = 0;
    Balloon::pontuacao = 0;
    Player::life = 5;
    Player::state = PLENO;
    // Definindo tempo de cdr das skills como um valor muito alto, pra começarem disponíveis
    Player::cdrQ = 60 * 6;
    Player::cdrW = 60 * 15;
    Player::cdrE = 60 * 10;
    Player::cdrR = 60 * 3;
    pontuacao = "";
    placarDraw = "Score: ";
    placar = new Font("Resources/FixedSys30.png");
    placar->Spacing(65);    
    background = new Sprite("Resources/cloudybg.png");
    gram = new Sprite("Resources/gram.png");
    wall = new Sprite("Resources/wall.png");
    tileBalloonRed = new TileSet("Resources/balloon.png", 86, 90, 6, 6);
    tileBalloonBlue = new TileSet("Resources/blueBalloon.png", 86, 90, 6, 6);

    scene = new Scene();

    Lifes* lifes = new Lifes();
    scene->Add(lifes, STATIC);

    Cat* cat = new Cat(catAudio, LEFTCAT);
    scene->Add(cat, STATIC);


    cat = new Cat(catAudio, RIGHTCAT);
    scene->Add(cat, STATIC);
    cat->MoveTo(100, 505);
  
    Player* player = new Player();
    scene->Add(player, MOVING);
   
    Balloon * balloon;

    for (int i = 0; i < 10; i++) {
        balloon = new Balloon(balloonAudio, RED, tileBalloonRed);
        balloon->MoveTo(random(80, 900), random(500, 800));
        scene->Add(balloon, MOVING);
    }

    for (int i = 0; i < 20; i++) {
        balloon = new Balloon(balloonAudio, RED, tileBalloonRed);
        balloon->MoveTo(random(80, 900), random(800, 1200));
        scene->Add(balloon, MOVING);
    }

    for (int i = 0; i < 15; i++) {
        balloon = new Balloon(balloonAudio, BLUE, tileBalloonBlue);
        balloon->MoveTo(random(80, 900), random(1200, 1500));
        scene->Add(balloon, MOVING);
    }
    for (int i = 0; i < 35; i++) {
        balloon = new Balloon(balloonAudio, RED, tileBalloonRed);
        balloon->MoveTo(random(80, 900), random(1500, 3000));
        scene->Add(balloon, MOVING);
    }
    for (int i = 0; i < 20; i++) {
        balloon = new Balloon(balloonAudio, BLUE, tileBalloonBlue);
        balloon->MoveTo(random(80, 900), random(2000, 3000));
        scene->Add(balloon, MOVING);
    }
    for (int i = 0; i < 20; i++) {
        balloon = new Balloon(balloonAudio, RED, tileBalloonRed);
        balloon->MoveTo(random(80, 900), random(1500, 3000));
        scene->Add(balloon, MOVING);
    }

  
  
    audio->Play(MENUAUDIO);
}

// ------------------------------------------------------------------------------

void PopBalloons::Update()
{

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

    scene->Update();
    scene->CollisionDetection();

    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();
  
    /*if ((window->KeyPress('2'))) {
        Engine::Next<Level2>();

    }*/

    if (Balloon::quantidade == 0 || (window->KeyPress('G'))) {
        Engine::Next<Vitoria>();
    }

    if (window->KeyPress('N') || Player::life <= 0){
        Engine::Next<GameOver>();
    }


} 
// ------------------------------------------------------------------------------

void PopBalloons::Draw() {
    pontuacao = std::to_string(Balloon::pontuacao);
    string qt = std::to_string(Balloon::quantidade);
    Color black(0.0f, 0.0f, 0.0f, 1.0f);
    placar->Draw(700, 30, placarDraw + pontuacao , black, Layer::UPPER, 0.3f);
    placar->Draw(700, 60, qt , black, Layer::UPPER, 0.3f);
    background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    wall->Draw(window->CenterX(), window->CenterY() + 275, Layer::MIDDLE);
    gram->Draw(window->CenterX(), window->CenterY() + 350, Layer::UPPER);
    scene->Draw();
} 

// ------------------------------------------------------------------------------

void PopBalloons::Finalize()
{
    delete scene;
    delete placar;
    delete balloonAudio;
    delete catAudio;
    delete wall;
    delete gram;
    delete background;
    delete tileBalloonRed;
    delete tileBalloonBlue;
    delete audio;
}

int PopBalloons::random(int low, int high)
{
     std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

