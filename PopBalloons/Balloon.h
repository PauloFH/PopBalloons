#include "Object.h";
#include "Sprite.h";
#include "TileSet.h"
#include "Animation.h"
#include <sstream>
#include "Audio.h"
using std::stringstream;

enum State {NORMAL, POP};
enum BalloonType {RED, BLUE};

enum SondBalloon {
	POPBALLOON_, 
	CAT
};

class Balloon : public Object {

private:
	Audio* audio;
	TileSet* tileset = nullptr;
	Animation* animation = nullptr;
	uint state;
	uint balloonType;
	stringstream text;
	int vel;


public:
	static int quantidade; //Quantidade de balões na fase
	static int pontuacao;
	Balloon(Audio* bllnAudio, uint bllnType, TileSet* tset);
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