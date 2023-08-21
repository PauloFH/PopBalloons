/**********************************************************************************
// FontDemo
// 
// Criação:     07 Out 2011
// Atualização: 16 Ago 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Testa a classe Font com exibição de texto com diversas fontes.
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

Scene* PopBalloons::scene = nullptr;
std::random_device rd;
std::mt19937 gen(rd());

void PopBalloons::Init()
{
    Balloon::pontuacao = 0;
    pontuacao = "";
    placarDraw = "Placar: ";
    placar = new Font("Resources/FixedSys30.png");
    placar->Spacing(80);    
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
    for (int i = 0; i < 10; i++) {
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
    /*
    balloon = new Balloon();
    balloon->MoveTo(200, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(300, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(400, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(500, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(600, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(700, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(800, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(900, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(100, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(200, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(300, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(400, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(500, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(300, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(400, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(500, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(600, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(700, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(800, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(900, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(1000, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(1100, random(800, 2000));
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(1200, random(800, 2000));
    scene->Add(balloon, MOVING);
    */
}

// ------------------------------------------------------------------------------

void PopBalloons::Update()
{
    
    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    scene->Update();
    scene->CollisionDetection();

    if (window->KeyDown('N') || Player::life <= 0)
        Engine::Next<GameOver>();
} 
// ------------------------------------------------------------------------------

void PopBalloons::Draw() {
    pontuacao = std::to_string(Balloon::pontuacao);
    Color black(0.0f, 0.0f, 0.0f, 1.0f);
    placar->Draw(100, 50, placarDraw + pontuacao , black);
    life->Draw(20, 20, Layer::UPPER);
    background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    wall->Draw(window->CenterX(), window->CenterY() + 275, Layer::MIDDLE);
    gram->Draw(window->CenterX(), window->CenterY() + 350, Layer::UPPER);
    scene->Draw();

} 

// ------------------------------------------------------------------------------

void PopBalloons::Finalize()
{
    delete wall;
    delete gram;
    delete background;
    delete scene;
}

int PopBalloons::random(int low, int high)
{
     std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

