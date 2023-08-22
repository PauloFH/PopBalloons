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
    if (!dw) {
        fm++;
        if (fm >= mfm) {
            dw = true;
            fm = 0;
        }
    }

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
    Color Black(0.0f, 0.0f, 0.0f, 1.0f);
    Color White(1.0f, 1.0f, 1.0f, 1.0f);
    background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);

    if (dw) {
        font->Draw(200, 480, "PRESS SPACE TO RESTART THE GAME", White, Layer::UPPER, 0.3f);
        font->Draw(201, 480, "PRESS SPACE TO RESTART THE GAME", Black, Layer::UPPER, 0.3f);
        fm++;
        if (fm >= mfm) {
            dw = false;
            fm = 0;
        }

    }
    font->Draw(200, 480, "PRESS SPACE TO RESTART THE GAME", Color(1.0f, 1.0f, 1.0f, 1.0f), Layer::UPPER, 0.3f);
} 

// ------------------------------------------------------------------------------

void GameOver::Finalize()
{
    delete audio;
    delete background;
    delete font;
}

