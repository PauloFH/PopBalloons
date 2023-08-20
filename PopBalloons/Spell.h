#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

enum Spells {
	Q,
	W
};

class Spell : public Object {
private:
	TileSet* tileset;
	Animation* animation;
	int posX;
	int posY;
	uint spellType;
public:
	Spell(TileSet* tileset, int posX, int posY, uint spellType);
	~Spell();

	void Update();
	void Draw();
	void OnCollision(Object* object);
};

inline void Spell::Draw() {
	animation->Draw(x, y, z);
}