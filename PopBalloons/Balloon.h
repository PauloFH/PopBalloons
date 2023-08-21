#include "Object.h";
#include "Sprite.h";
#include "TileSet.h"
#include "Animation.h"
#include <sstream>
using std::stringstream;

enum State {NORMAL, POP};

class Balloon : public Object {

private:
	TileSet* tileset = nullptr;
	Sprite* sprite = nullptr;
	Animation* animation = nullptr;
	uint state;
	stringstream text;
	int vel;

public:
	Balloon();
	~Balloon();

	void Update();
	void Draw();
	void OnCollision(Object * obj);

};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Balloon::Draw()
{
	animation->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------