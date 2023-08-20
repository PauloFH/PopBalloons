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
#include "GameOver.h"
#include "Balloon.h"
#include "Player.h"
#include "Cat.h"
#include <iostream>
#include <random>

Scene* PopBalloons::scene = nullptr;
std::random_device rd;
std::mt19937 gen(rd());

void PopBalloons::Init()
{



    background = new Sprite("Resources/background.png");
    gram = new Sprite("Resources/gram.png");
    wall = new Sprite("Resources/wall.png");
    life = new Sprite("Resources/life.png");

    scene = new Scene();

    Cat* cat = new Cat();
    scene->Add(cat, STATIC);

    Player* player = new Player();
    scene->Add(player, MOVING);

    Balloon* balloon = new Balloon();
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(100, random(800,2000));
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
}

// ------------------------------------------------------------------------------

void PopBalloons::Update()
{
    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    scene->Update();
    scene->CollisionDetection();

    if (window->KeyDown('N'))
        Engine::Next<GameOver>();
} 

// ------------------------------------------------------------------------------

void PopBalloons::Draw()
{
    life->Draw(20, 20, Layer::UPPER);
    background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    wall->Draw(window->CenterX(), window->CenterY() + 375, Layer::MIDDLE);
    gram->Draw(window->CenterX(), window->CenterY() + 450, Layer::UPPER);
    scene->Draw();

} 

// ------------------------------------------------------------------------------

void PopBalloons::Finalize()
{
    delete life;
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

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(1280, 896);
    engine->window->Color(200, 24, 240);
    engine->window->Title("Pop Balloons");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new PopBalloons());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

