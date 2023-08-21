#include "GameOver.h"
#include "Player.h"
#include "telaInicial.h"

void GameOver::Init()
{
    background = new Sprite("Resources/GameOver.png");
}

// ------------------------------------------------------------------------------

void GameOver::Update()
{
    if (ctrlKeySPC && window->KeyUp(VK_SPACE)) {
        ctrlKeySPC = false;
        Engine::Next<TelaInicial>();
    }
    else if (window->KeyDown(VK_SPACE)) {
        ctrlKeySPC = true;
    }

    if( window->KeyDown(VK_ESCAPE))
        window->Close();
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

