#include "Object.h";
#include "Sprite.h";
#include "TileSet.h"
#include "Animation.h"

class Balloon : public Object {

private:
	TileSet* tileset = nullptr;
	Sprite* sprite = nullptr;
	Animation* animation = nullptr;

public:
	Balloon();
	~Balloon();

	void Update();
	void Draw();
	void OnCollision();

};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Balloon::Draw()
{
	animation->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------