#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

class Cat : public Object {
private:
	TileSet* tileset;
	Animation* animation;

public:
	Cat();
	~Cat();

	void Update();
	void Draw();
	void OnCollision(Object* obj);
};

inline void Cat::Draw() {
	animation->Draw(x, y, z);
}