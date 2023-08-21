
#ifndef _AUDIO_H_
#define _AUDIO_H_

// ---------------------------------------------------------------------------------

#include "Sound.h"                              // guarda o som no formato WAVE
#include "Types.h"                              // tipos específicos da engine
#include <XAudio2.h>                            // XAudio2 API
#include <unordered_map>                        // tabela de dispersão
#include <string>                               // tipo string da STL
using std::unordered_map;
using std::string;

// ---------------------------------------------------------------------------------

class Audio
{
private:
    IXAudio2* audioEngine;                      // sistema de áudio (engine)
    IXAudio2MasteringVoice* masterVoice;        // dispositivo principal de áudio
    unordered_map<uint, Sound*> sounds;         // coleção de sons

public:
    Audio();                                    // construtor
    ~Audio();                                   // destrutor

    void Add(uint id, string filename);         // adiciona um som <id, filename>
    void Play(uint id);                         // reproduz som através do seu id
};

// ---------------------------------------------------------------------------------

#endif