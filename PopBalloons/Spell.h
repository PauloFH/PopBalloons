#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

class Spell : public Object {
private:
	Animation* animation;
	int posX;
	int posY;
public:
	Spell(TileSet* tileset, int posX, int posY);
	~Spell();

	void Update();
	void Draw();
	void OnCollision(Object* object);
};

inline void Spell::Draw() {
	animation->Draw(x, y, z);
}