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
#include "Vitoria.h"

Scene* PopBalloons::scene = nullptr;
std::random_device rd;
std::mt19937 gen(rd());

void PopBalloons::Init()
{
    audio = new Audio();
    audio->Add(MENUAUDIO, "Resources/game_thame.wav");
    
    Balloon::pontuacao = 0;
    Player::life = 5;
    Player::state = PLENO;
    // Definindo tempo de cdr das skills como um valor muito alto, pra começarem disponíveis
    Player::cdrQ = 60 * 6;
    Player::cdrW = 60 * 15;
    Player::cdrE = 60 * 10;
    Player::cdrR = 60 * 3;
    pontuacao = "";
    placarDraw = "Placar: ";
    placar = new Font("Resources/FixedSys30.png");
    placar->Spacing(65);    
    background = new Sprite("Resources/cloudybg.png");
    gram = new Sprite("Resources/gram.png");
    wall = new Sprite("Resources/wall.png");
    scene = new Scene();

    Lifes* lifes = new Lifes();
    scene->Add(lifes, STATIC);

    Cat* cat = new Cat();
    scene->Add(cat, STATIC);
  
    Player* player = new Player();
    scene->Add(player, MOVING);
   
    Balloon * balloon;
    for (int i = 0; i < 1; i++) {
        balloon = new Balloon();
        balloon->MoveTo(random(80,900), random(500,800));
        scene->Add(balloon, MOVING);
     }
   
    for (int i = 0; i < 20; i++) {
      balloon = new Balloon();
      balloon->MoveTo(random(80, 900), random(800, 1200));
      scene->Add(balloon, MOVING);
    }

    for (int i = 0; i < 20; i++) {
        balloon = new Balloon();
        balloon->MoveTo(random(80, 900), random(1200, 1500));
        scene->Add(balloon, MOVING);
    }
    for (int i = 0; i < 100; i++) {
        balloon = new Balloon();
        balloon->MoveTo(random(80, 900), random(1500, 3000));
        scene->Add(balloon, MOVING);
    }
  
    audio->Play(MENUAUDIO);
}

// ------------------------------------------------------------------------------

void PopBalloons::Update()
{

    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    scene->Update();
    scene->CollisionDetection();

    if (Balloon::quantidade == 0 || (window->KeyDown('G'))) {

        Engine::Next<Vitoria>();
    }

    if (window->KeyDown('N') || Player::life <= 0){
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
    scene->DrawBBox();
} 

// ------------------------------------------------------------------------------

void PopBalloons::Finalize()
{
    delete wall;
    delete gram;
    delete background;
    delete scene;
    delete audio;
}

int PopBalloons::random(int low, int high)
{
     std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

