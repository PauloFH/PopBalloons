/**********************************************************************************
// tela Inicial (Arquivo de Cabeçalho)
//
// Criação:     20 Agosto 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Jogo POP BALLOONS - Projeto 1 unidade
//
**********************************************************************************/

#ifndef _TELA_INICIAL_
#define  _TELA_INICIAL_

// ---------------------------------------------------------------------------------
// Inclusões
#include "Engine.h"
#include "Game.h"
#include "Font.h"
#include "Sprite.h"
#include "Resources.h"
#include "Scene.h"
#include "Animation.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class TelaInicial : public Game
{
private:
    Sprite * backg = nullptr;
    Font   * title = nullptr;
    Font   * subtitle = nullptr;
   TileSet * tileset = nullptr;
   Player* player = nullptr;
    Sprite * ButtonPlay = nullptr;
    Sprite * ButtonQuit = nullptr;
public:
    static Scene* scene;           // gerenciador de cena

    void Init();   // inicialização
    void Update(); // atualização
    void Draw();   // desenho
    void Finalize();  // finalização
};
// ---------------------------------------------------------------------------------

#endif