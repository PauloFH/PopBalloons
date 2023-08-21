#include "Object.h"
#include "TileSet.h"
#include "Animation.h"
#include <sstream>
using std::stringstream;

enum Spells {
	Q,
	W,
	E,
	R
};

enum Direction {
	TOLEFT,
	TORIGHT
};

class Spell : public Object {
private:
	TileSet* tileset;
	Animation* animation;
	int posX;
	int posY;
	uint spellType;
	uint time;
	uint direction = TOLEFT;
	stringstream text;
public:
	Spell(TileSet* tileset, int posX, int posY, uint spellType);
	Spell(TileSet* tileset, int posX, int posY, uint spellType, uint direction);
	~Spell();

	void Update();
	void Draw();
	void OnCollision(Object* object);
};

inline void Spell::Draw() {
	animation->Draw(x, y, z);
}