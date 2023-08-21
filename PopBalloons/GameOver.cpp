#include "GameOver.h"
#include "Player.h"
#include "telaInicial.h"

void GameOver::Init()
{
    background = new Sprite("Resources/GameOver.png"); // placeholder
}

// ------------------------------------------------------------------------------

void GameOver::Update()
{
    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();
    
    if( window->KeyDown(VK_RETURN))
        Engine::Next<TelaInicial>();
} 

// ------------------------------------------------------------------------------

void GameOver::Draw()
{
    background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
} 

// ------------------------------------------------------------------------------

void GameOver::Finalize()
{
    delete background;
}

