#include "Object.h"
#include "Animation.h"


class Player : public Object {
private:
	TileSet* tileset;
	Animation* animation;
	Sprite* sprite;
	Image* atack;
	int vel;

public:
	Player();
	~Player();

	void Update();
	void Draw();
	void OnCollision(Object * obj);
};

inline void Player::Draw()
{
	animation->Draw(x, y, z);
}