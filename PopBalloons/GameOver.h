#include "Engine.h"
#include "Game.h"
#include "Sprite.h"
#include "Audio.h"
#include "Font.h"

enum SoundEnd {
	GAMEOVER,
	CRY
};

class GameOver : public Game
{
private:
	Sprite* background;
	bool ctrlKeySPC = false;
	Audio* audio;
	Font* font;
	int fm = 0;
	int mfm = 30;
	bool dw = false;
public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};