/**********************************************************************************
// tela Inicial (Arquivo de Cabeçalho)
//
// Criação:     20 Agosto 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Jogo POP BALLOONS - Projeto 1 unidade
//
**********************************************************************************/

#include "telaInicial.h"
#include "PopBalloons.h"
// -----------------------------------------------------------------------------

Scene * TelaInicial::scene = nullptr;

// -----------------------------------------------------------------------------
void TelaInicial::Init()
{   
    backg = new Sprite("Resources/fi.png"); // fundo completo
    tileset = new TileSet("Resources/menu.png", 94.5, 142, 6, 60);; //animação do player na tela de inicio
    audio = new Audio();
    audio->Add(INTRO,"Resources/into.wav");
    
    
    gif = new Gif(tileset);
   scene = new Scene();
   scene->Add(gif, STATIC);
    title = new Gif();
    scene->Add(title, STATIC);
    audio->Play(INTRO);

}

void TelaInicial::Update()
{    
    if (window->KeyDown(VK_SPACE)){
            Engine::Next<PopBalloons>();
    }
    
    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

  

   scene->Update();
}

void TelaInicial::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();

}

void TelaInicial::Finalize()
{
    //delete scene;
    delete backg;
    delete tileset;
    delete audio;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine* engine = new Engine();

    // configura motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(968, 680);
    engine->window->Color(200, 24, 240);
    engine->window->Title("Pop Balloons");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new TelaInicial());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------
