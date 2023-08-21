#include "Object.h"
#include "Animation.h"
#include <sstream>
using std::stringstream;

enum Estado {
	PLENO,
	HITED
};

class Player : public Object {
private:
	TileSet* tileset;
	Animation* animation;
	Sprite* sprite;
	Image* atack;
	int vel;
	stringstream text;

	// Imagens para os ícones das spells
	Image* iconQ;
	Image* xiconQ;
	Image* darkIconQ;
	Sprite* spriteQ;
	Image* iconW;
	Image* xiconW;
	Sprite* spriteW;
	Image* iconE;
	Image* xiconE;
	Sprite* spriteE;
	Image* iconR;
	Image* xiconR;
	Sprite* spriteR;

	// Variáveis pras spells
	bool spellQ;
	TileSet* tileSpellQ;
	bool spellW;
	TileSet* tileSpellW;
	bool spellE;
	TileSet* tileSpellE;
	bool spellR;
	TileSet* tileSpellR;

public:
	static int life;
	static uint state;
	static uint cdrQ, cdrW, cdrE, cdrR;

	Player();
	~Player();
	void Update();
	void Draw();
	void OnCollision(Object * obj);
};
