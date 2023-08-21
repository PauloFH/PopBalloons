/**********************************************************************************
// tela Inicial (Arquivo de Cabe�alho)
//
// Cria��o:     20 Agosto 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Jogo POP BALLOONS - Projeto 1 unidade
//
**********************************************************************************/

#ifndef _TELA_INICIAL_
#define  _TELA_INICIAL_

// ---------------------------------------------------------------------------------
// Inclus�es
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
   Sprite  * backg   = nullptr;
   TileSet * tileset = nullptr;
   Gif     * gif     = nullptr;
   Gif     * title   = nullptr;
   Balloon * balloon = nullptr;
   bool ini;
   int time;
public:
    static Scene * scene;           // gerenciador de cena

    void Init();   // inicializa��o
    void Update(); // atualiza��o
    void Draw();   // desenho
    void Finalize();  // finaliza��o
};
// ---------------------------------------------------------------------------------

#endif