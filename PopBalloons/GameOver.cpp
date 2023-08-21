#include "GameOver.h"
#include "Player.h"
#include "telaInicial.h"

void GameOver::Init()
{   
    audio = new Audio();
    audio->Add(GAMEOVER, "Resources/Game_Lose.wav");
   // audio->Add(CRY, "Resources/cry.wav");
    background = new Sprite("Resources/GameOver.png");
    audio->Play(GAMEOVER);

}

// ------------------------------------------------------------------------------

void GameOver::Update()
{
   // audio->Play(CRY);
    if (ctrlKeySPC && window->KeyUp(VK_SPACE)) {
        ctrlKeySPC = false;
        Engine::Next<TelaInicial>();
    }
    else if (window->KeyDown(VK_SPACE)) {
        ctrlKeySPC = true;
    }

    if( window->KeyDown(VK_ESCAPE))
        window->Close();
    if (window->KeyDown(VK_RETURN))
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
    delete audio;
}

