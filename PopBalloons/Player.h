#include "Object.h"
#include "Animation.h"
#include <sstream>
#include "Audio.h"
using std::stringstream;

enum Estado {
	PLENO,
	HITED
};
enum Sounds {
	ATTACK,
	SPELL_EXPLOSION,
	SPELL_PUXAR,
	SPELL_WALL,
	SPELL_WIND,
	DAMEGE
};

class Player : public Object {
private:
	Audio * audio;
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

public:
	static int life;
	static uint state;

	Player();
	~Player();
	void Update();
	void Draw();
	void OnCollision(Object * obj);
};

inline void Player::Draw(){animation->Draw(x, y, z);};

