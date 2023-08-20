#include "Engine.h"
#include "Game.h"
#include "Sprite.h"

class GameOver : public Game
{
private:
	Sprite* background;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};