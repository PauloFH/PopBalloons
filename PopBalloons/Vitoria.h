#ifndef _VITORIA_H_
#define _VITORIA_H_

//--------------------------------------------------------------------------------------------------------------
#include "Game.h"
#include "Sprite.h"
#include "Audio.h"
#include "Font.h"
//--------------------------------------------------------------------------------------------------------------

class Vitoria : public Game {
	private:
		Audio  * audio;
		Sprite * fundo;
		Font   * text;
		bool ctrlKeySPC = false;
	public:

		void Init();
		void Update();
		void Draw();
		void Finalize();

};
#endif // !_VITORIA_H_
