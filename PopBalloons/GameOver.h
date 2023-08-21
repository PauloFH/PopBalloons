#include "Engine.h"
#include "Game.h"
#include "Sprite.h"

class GameOver : public Game
{
private:
	Sprite* background;
	bool ctrlKeySPC = false;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};