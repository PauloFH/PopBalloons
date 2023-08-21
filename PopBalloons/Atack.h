#include "Object.h"
#include "Image.h"
#include "Sprite.h"
#include <sstream>
#include "Audio.h"
using std::stringstream;

class Atack : public Object {

private:
	Audio * audio;
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