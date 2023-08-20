
#ifndef _GIF_H_
#define  _GIF_H_ 
//-----------------------------------------------------------------------------------------

#include "Object.h"
#include "TileSet.h"
#include "Animation.h"
//-----------------------------------------------------------------------------------------

class Gif : public Object {
private:
	TileSet   * tile = nullptr;
	Animation * ani  = nullptr;
public:
	Gif();
	~Gif();
	 void Update();
	 void Draw();
	Gif(TileSet* tile);
};

inline void Gif::Draw() { ani->Draw(x, y, z); };

#endif // _GIF_H_

