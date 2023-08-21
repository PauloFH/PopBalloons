#include "Object.h";
#include "Sprite.h";
#include "TileSet.h"
#include "Animation.h"
#include <sstream>
#include "Audio.h"
using std::stringstream;

enum State {NORMAL, POP};

enum SondBalloon {
	POPBALLOON_
};

class Balloon : public Object {

private:
	static Audio* audio;
	TileSet* tileset = nullptr;
	Sprite* sprite = nullptr;
	Animation* animation = nullptr;
	uint state;
	stringstream text;
	int vel;


public:
	static int quantidade; //Quantidade de bal�es na fase
	static int pontuacao;
	Balloon();
	~Balloon();

	void Update();
	void Draw();
	void OnCollision(Object * obj);

};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Balloon::Draw()
{
	animation->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------