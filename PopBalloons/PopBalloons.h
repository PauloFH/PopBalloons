#include "Engine.h"
#include "Game.h"
#include "Font.h"
#include "Sprite.h"
#include "Resources.h"
#include "Scene.h"
#include <string.h>
#include "Audio.h"


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
enum Sonds {
    MENUAUDIO,
    LAUGHT,
    CHILDS,
    BALLOONT
};
class PopBalloons : public Game
{
private:
    Audio  * audio;
    Sprite * background;
    Sprite * gram;
    Sprite * wall;
    Font   * placar;
    string placarDraw;
    int frames;
    int child;
    bool ch = false;
    int laught = 600;
    bool lg = false;

public:
    string pontuacao;
    static Scene* scene;
    void Init();
    void Update();
    void Draw();
    void Finalize();
    int random(int low, int high);
};

