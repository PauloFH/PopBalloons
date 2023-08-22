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
#include "Font.h"

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
    Sprite* skills = nullptr;
    Sprite* click = nullptr;
    TileSet * tileset = nullptr;
    Balloon * balloon = nullptr;
    Font* text = nullptr;
    int fm = 0;
    int mfm = 30;
    bool dw = false;
    bool ini;
    int time;
public:
    static Scene * sceneI;           // gerenciador de cena

    void Init();   // inicializa��o
    void Update(); // atualiza��o
    void Draw();   // desenho
    void Finalize();  // finaliza��o
};
// ---------------------------------------------------------------------------------

#endif