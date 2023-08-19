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

#include "Engine.h"
#include "Game.h"
#include "Font.h"
#include "Sprite.h"
#include "Resources.h"
#include "Scene.h"
#include "Balloon.h"

// ------------------------------------------------------------------------------

class PopBalloons: public Game
{
private:
    Scene* scene;
    Balloon* balloon;
    
public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

// ------------------------------------------------------------------------------

void PopBalloons::Init()
{
    scene = new Scene();
    balloon = new Balloon();

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

