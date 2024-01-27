#include "sound.h"

Music current_music;
float musicManagerVolume = 0.5f;

void MusicManagerLoad(const char* path)
{
    if(IsMusicReady(current_music))
    {
        StopMusicStream(current_music);
        UnloadMusicStream(current_music);
    }
    current_music = LoadMusicStream(path);
    current_music.looping = true;
    PlayMusicStream(current_music);
    SetMusicVolume(current_music, musicManagerVolume);
}

void MusicManagerUpdate(void)
{
    if(IsMusicReady(current_music))
        UpdateMusicStream(current_music);
}

void MusicManagerUnload(void)
{
    if(IsMusicReady(current_music))
    {
        StopMusicStream(current_music);
        UnloadMusicStream(current_music);
    }
}

void MusicManageSetVolume(float volume)
{   
    musicManagerVolume = volume;
    SetMusicVolume(current_music, volume);
}
