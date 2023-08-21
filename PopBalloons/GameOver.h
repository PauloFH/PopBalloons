#include "Engine.h"
#include "Game.h"
#include "Sprite.h"
#include "Audio.h"

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
public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};