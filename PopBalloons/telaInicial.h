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
#include "Sprite.h"
#include "Resources.h"
#include "Scene.h"
#include "TileSet.h"
#include "Gif.h"
#include "Balloon.h"
#include "Audio.h"

// ---------------------------------------------------------------------------------

enum Soundsinto {INTRO};
// ---------------------------------------------------------------------------------

class TelaInicial : public Game
{
private:
    Audio  * audio   = nullptr;
    Sprite* background = nullptr;
    Sprite* gram = nullptr;
    Sprite* wall = nullptr;
    Sprite* nome = nullptr;
    TileSet * tileset = nullptr;
    Balloon * balloon = nullptr;
    bool ini;
    int time;
public:
    static Scene * sceneI;           // gerenciador de cena

    void Init();   // inicialização
    void Update(); // atualização
    void Draw();   // desenho
    void Finalize();  // finalização
};
// ---------------------------------------------------------------------------------

#endif