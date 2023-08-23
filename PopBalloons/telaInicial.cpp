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

Scene * TelaInicial::sceneI;

// -----------------------------------------------------------------------------
void TelaInicial::Init()
{   
    background = new Sprite("Resources/cloudybg.png");
    gram = new Sprite("Resources/gram.png");
    wall = new Sprite("Resources/wall.png");
    nome = new Sprite("Resources/nome.png");
    tileset = new TileSet("Resources/menu.png", 94.5, 142, 6, 60);; //animação do player na tela de inicio
    skills = new Sprite("Resources/skills.png");
    click = new Sprite("Resources/click.png");
    audio = new Audio();
    audio->Add(INTRO,"Resources/into.wav");

    text = new Font("Resources/FixedSys30.png");
    text->Spacing(65);
    
    sceneI = new Scene();

    Gif * gif = new Gif(tileset);
    sceneI->Add(gif, STATIC);
    audio->Play(INTRO);

}

void TelaInicial::Update()
{
    if (!dw) {
        fm++;
        if (fm >= mfm) {
            dw = true;
            fm = 0;
        }
    }

    sceneI->Update();

    if (window->KeyDown(VK_SPACE)){
            Engine::Next<PopBalloons>();
    }
    
    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

}

void TelaInicial::Draw()
{
    background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    wall->Draw(window->CenterX(), window->CenterY() + 275, Layer::MIDDLE);
    gram->Draw(window->CenterX(), window->CenterY() + 350, Layer::UPPER);
    nome->Draw(window->CenterX(), window->CenterY() - 100, Layer::FRONT);
    skills->Draw(765, 635, Layer::FRONT);

    Color Black(0.0f, 0.0f, 0.0f, 1.0f);
    Color White(1.0f, 1.0f, 1.0f, 1.0f);

    text->Draw(70, 570, "A - Move to Left", White, Layer::FRONT, 0.2f);
    text->Draw(70, 610, "D - Move to Right", White, Layer::FRONT, 0.2f);

    click->Draw(360, 575);
    text->Draw(345, 615, "Pop!", White, Layer::FRONT, 0.2f);

    text->Draw(660, 575, "Q", White, Layer::FRONT, 0.5f);
    text->Draw(730, 575, "W", White, Layer::FRONT, 0.5f);
    text->Draw(800, 575, "E", White, Layer::FRONT, 0.5f);
    text->Draw(867, 575, "R", White, Layer::FRONT, 0.5f);

    if (dw) {
        text->Draw(200, 375, "PRESS SPACE TO START THE GAME", White, Layer::UPPER, 0.3f);
        text->Draw(202, 375, "PRESS SPACE TO START THE GAME", Black, Layer::FRONT, 0.3f);
        fm++;
        if (fm >= mfm) {
            dw = false;
            fm = 0;
        }

    }

    sceneI->Draw();
}

void TelaInicial::Finalize()
{
    delete sceneI;
    delete background;
    delete gram;
    delete wall;
    delete nome;
    delete skills;
    delete click;
    delete tileset;
    delete audio;
    delete text;
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
    engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new TelaInicial());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------
