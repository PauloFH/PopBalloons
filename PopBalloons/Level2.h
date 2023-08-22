#include "Engine.h"
#include "Game.h"
#include "Font.h"
#include "Sprite.h"
#include "Resources.h"
#include "Scene.h"
#include <string.h>
#include "Audio.h"


class Level2 : public Game
{
private:
    Audio* audio;
    Sprite* background;
    Sprite* gram;
    Sprite* wall;
    Font* placar;
    string placarDraw;
    TileSet* tileBalloonRed2;
    TileSet* tileBalloonBlue2;
    Audio* balloonAudio2;
    Audio* catAudio2;
    int frames;
    int child;
    bool ch = false;
    int laught = 600;
    bool lg = false;

public:
    string pontuacao2;
    static Scene* scene2;
    void Init();
    void Update();
    void Draw();
    void Finalize();
    int random(int low, int high);
};