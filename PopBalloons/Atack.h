#include "Object.h"
#include "Image.h"
#include "Sprite.h"
#include <sstream>
using std::stringstream;

class Atack : public Object {

private:
	Sprite* sprite;
	int vel;
	int untilY;
	uint validAtack;
	stringstream text;
public:
	Atack(Image * image, int untilY);
	~Atack();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Atack::Draw() {
	sprite->Draw(x, y, z);
}