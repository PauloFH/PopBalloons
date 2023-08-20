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
// -----------------------------------------------------------------------------

Scene * TelaInicial::scene = nullptr;

// -----------------------------------------------------------------------------
void TelaInicial::Init()
{

    backg = new Sprite("Resources/fi.png"); // fundo completo
    tileset = new TileSet("Resources/menu.png", 94.5, 142, 6, 60);; //animação do player na tela de inicio
    player = new Player(tileset);
    scene = new Scene();
    scene->Add(player, STATIC);


}

void TelaInicial::Update()

{
    
    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();
    if (window->KeyDown(VK_HOME)) {

    }
    scene->Update();
}

void TelaInicial::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();

}

void TelaInicial::Finalize()
{
    delete backg;
    delete tileset;
    delete scene;
}


