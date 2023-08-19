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
    ATACK
};

class PopBalloons : public Game
{
private:
    Sprite* background;
    Sprite* life;

public:
    static Scene* scene;

    void Init();
    void Update();
    void Draw();
    void Finalize();
};

