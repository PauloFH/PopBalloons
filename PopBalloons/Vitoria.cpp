#include "Vitoria.h"
#include "Engine.h"
#include "telaInicial.h"


void Vitoria::Init()
{
    audio = new Audio();
    audio->Add(40, "Resources/Game_Lose.wav");
    fundo = new Sprite("Resources/TelaFinal.png");
    text = new Font("Resources/FixedSys30.png");
    text->Spacing(65);
}

void Vitoria::Update()
{
    // audio->Play(CRY);
    if (ctrlKeySPC && window->KeyUp(VK_SPACE)) {
        ctrlKeySPC = false;
        Engine::Next<TelaInicial>();
    }
    else if (window->KeyDown(VK_SPACE)) {
        ctrlKeySPC = true;
    }

    if (window->KeyDown(VK_ESCAPE))
        window->Close();
}

void Vitoria::Draw()
{
    Color black(0.0f, 0.0f, 0.0f, 1.0f);
    fundo->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    text->Draw(200, 480, "PRESS SPACE TO RESTART THE GAME", black, Layer::UPPER, 0.3f);
}

void Vitoria::Finalize()
{
}

