#include "Engine.h"
#include "Game.h"
#include "Font.h"
#include "Sprite.h"
#include "Resources.h"
#include "Scene.h"



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
   
public:
    static Scene* scene;
    void Init();
    void Update();
    void Draw();
    void Finalize();
    int random(int low, int high);
};

