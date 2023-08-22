#include "Object.h"
#include "TileSet.h"
#include "Animation.h"
#include "Audio.h"

enum catState {
	LEFTCAT,
	RIGHTCAT
};

class Cat : public Object {
private:
	TileSet  * tileset;
	Animation* animation;
	Audio    * audio;
	int frames = 0;
	int ctFrames = 1600;
	bool controlador = false;
	uint stateCat;
public:
	Cat(Audio* catAudio, uint ctStt);
	~Cat();

	void Update();
	void Draw();
	void OnCollision(Object* obj);
};

inline void Cat::Draw() {
	animation->Draw(x, y, z);
}