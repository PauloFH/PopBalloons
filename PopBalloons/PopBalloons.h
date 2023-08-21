#include "Engine.h"
#include "Game.h"
#include "Font.h"
#include "Sprite.h"
#include "Resources.h"
#include "Scene.h"
#include <string.h>


enum ObjTypes
{
    PLAYER,           
    BALLOON,
    ATACK,
    SPELLQ,
    SPELLW,
    SPELLE,
    SPELLR
};

class PopBalloons : public Game
{
private:
    Sprite* background;
    Sprite* gram;
    Sprite* life;
    Sprite* wall;
    Font* placar;
    string placarDraw;

public:
    int pontuacao;
    static Scene* scene;
    void Init();
    void Update();
    void Draw();
    void Finalize();
    int random(int low, int high);
};

