#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

class Lifes : public Object {
private:
	TileSet* tileset;
	Animation* animation;
public:
	static uint takeDamage;

	Lifes();
	~Lifes();

	void Update();
	void Draw();
	void OnCollision(Object* obj);
};

inline void Lifes::Draw() {
	animation->Draw(x, y, z);
}