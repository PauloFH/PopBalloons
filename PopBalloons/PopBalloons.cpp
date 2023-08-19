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

Scene* PopBalloons::scene = nullptr;

void PopBalloons::Init()
{
    scene = new Scene();

    Player* player = new Player();
    scene->Add(player, MOVING);

    Balloon* balloon = new Balloon();
    scene->Add(balloon, MOVING);

    balloon = new Balloon();
    balloon->MoveTo(100, 300);
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
} 

// ------------------------------------------------------------------------------

void PopBalloons::Draw()
{
    scene->Draw();
    scene->DrawBBox();
} 

// ------------------------------------------------------------------------------

void PopBalloons::Finalize()
{
    delete scene;
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
    engine->window->Size(600, 474);
    engine->window->Color(200, 24, 240);
    engine->window->Title("Font Demo");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new PopBalloons());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

