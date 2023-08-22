#include "Gif.h"

Gif::Gif(){
	tile = new TileSet("Resources/text.png",1,3);
	ani = new Animation(tile, 0.10f, true);
	MoveTo(window->CenterX(), window->CenterY() + 50, Layer::FRONT);
}

Gif::~Gif(){
	delete ani;
	delete tile;
}

void Gif::Update(){
	ani->NextFrame();

}


Gif::Gif(TileSet* tile){
	this->ani = new Animation(tile, 0.10f, true);
	MoveTo(window->CenterX(), window->CenterY() + 280, Layer::FRONT);
}
