#include "GameOver.h"
#include "Player.h"

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
    
    //if( window->KeyDown('R'))
        //Engine::Next<QualéaTelaInicial?>();
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

