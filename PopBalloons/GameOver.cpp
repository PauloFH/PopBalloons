#include "GameOver.h"
#include "Player.h"
#include "telaInicial.h"

void GameOver::Init()
{   
    audio = new Audio();
    audio->Add(GAMEOVER, "Resources/Game_Lose.wav");
    background = new Sprite("Resources/GameOver.png");
    audio->Play(GAMEOVER);
    font = new Font("Resources/FixedSys30.png");
    font->Spacing(65);
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
} 

// ------------------------------------------------------------------------------

void GameOver::Draw()
{
    Color black(0.0f, 0.0f, 0.0f, 1.0f);
    background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    font->Draw(200, 480, "PRESS SPACE TO RESTART THE GAME", Color(1.0f, 1.0f, 1.0f, 1.0f), Layer::UPPER, 0.3f);
} 

// ------------------------------------------------------------------------------

void GameOver::Finalize()
{
    delete background;
    delete audio;
    delete font;
}

