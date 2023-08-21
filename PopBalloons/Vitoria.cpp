#include "Vitoria.h"
#include "Engine.h"
#include "telaInicial.h"


void Vitoria::Init()
{
    audio = new Audio();
    audio->Add(44, "Resources/GameWin.wav");
    fundo = new Sprite("Resources/TelaFinal.png");
    text = new Font("Resources/FixedSys30.png");
    text->Spacing(65);
    audio->Play(44);
}

void Vitoria::Update()
{

    if (ctrlKeySPC && window->KeyUp(VK_SPACE)) {
        ctrlKeySPC = false;
        Engine::Next<TelaInicial>();
    }
    else if (window->KeyDown(VK_SPACE)) {
        ctrlKeySPC = true;
    }

    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    if (!dw) {
        fm++;
        if (fm >= mfm) {
            dw = true;
            fm = 0;
        }
    }
}

void Vitoria::Draw()
{
    Color Black(0.0f, 0.0f, 0.0f, 1.0f);
    Color White(1.0f, 1.0f, 1.0f, 1.0f);
    fundo->Draw(window->CenterX(), window->CenterY(), Layer::BACK);

    text->Draw(300, 220, "WINNER!!", White, Layer::FRONT, 0.75f);
    text->Draw(310, 300, "Thanks to play this game", White, Layer::UPPER, 0.25f);
    if (dw) {
        text->Draw(295, 400, "PRESS SPACE TO RESTART THE GAME", White, Layer::UPPER, 0.20f);
        text->Draw(296, 400, "PRESS SPACE TO RESTART THE GAME", Black, Layer::FRONT, 0.20f);
        fm++;
        if (fm >= mfm) {
            dw = false;
            fm = 0;
        }
        
    }
    
}

void Vitoria::Finalize()
{
    delete audio;
    delete fundo;
    delete text;
}

