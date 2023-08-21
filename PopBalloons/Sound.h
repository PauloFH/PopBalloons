#ifndef _SOUND_H_
#define _SOUND_H_

//------------------------------------------------------------------------------------------
#include <xaudio2.h>
#include <string>
using std::string;
//---------------------------------------------------------------------------

class Sound {
private:
	WAVEFORMATEXTENSIBLE soundFormat;
	XAUDIO2_BUFFER soundBuffer; 
	IXAudio2SourceVoice* sourceVoice;

    HRESULT FindChunk(HANDLE hFile,
        DWORD fourcc,
        DWORD& dwChunkSize,
        DWORD& dwChunkDataPosition);     // localiza blocos no arquivo RIFF

    HRESULT ReadChunkData(HANDLE hFile,
        void* buffer,
        DWORD buffersize,
        DWORD bufferoffset);          // lê blocos do arquivo para um buffer

    friend class Audio;
public:
    Sound(string fileName);                               // construtor
    ~Sound(); 
};
//------------------------------------------------------------------------------
#endif // !_SOUND_h_
