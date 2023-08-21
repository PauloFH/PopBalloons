#include "Object.h"
#include "Image.h"
#include "Sprite.h"
#include <sstream>
#include "Audio.h"
using std::stringstream;

class Atack : public Object {

private:
	
	Sprite* sprite;
	int vel;
	int untilY;
	stringstream text;
public:
	Atack(Image * image, int untilY);
	~Atack();
	static Audio* audio;
	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Atack::Draw() {
	sprite->Draw(x, y, z);
}