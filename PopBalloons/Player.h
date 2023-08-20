#include "Object.h"
#include "Animation.h"
#include <sstream>
using std::stringstream;


class Player : public Object {
private:
	TileSet* tileset;
	Animation* animation;
	Sprite* sprite;
	Image* atack;
	int vel;
	stringstream text;
	bool spellQ;
	TileSet* tileSpellQ;
	bool spellW;
	TileSet* tileSpellW;
	bool spellE;
	TileSet* tileSpellE;
	bool spellR;
	TileSet* tileSpellR;
	int lastClick;

public:
	Player();
	~Player();

	void Update();
	void Draw();
	void OnCollision(Object * obj);
	Player(TileSet * tileset);
};

inline void Player::Draw()
{
	animation->Draw(x, y, z);
}