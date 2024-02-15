#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_AUDIO);

    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;

    if (argc < 2) {
        printf("Usage: %s <soundfile>\n", argv[0]);
        return 1;
    }

    if (SDL_LoadWAV(argv[1], &wavSpec, &wavBuffer, &wavLength) == NULL) {
        fprintf(stderr, "Could not open %s: %s\n", argv[1], SDL_GetError());
        return 1;
    }

    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    if (deviceId == 0) {
        fprintf(stderr, "Failed to open audio: %s\n", SDL_GetError());
        return 1;
    }

    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    if (success < 0) {
        fprintf(stderr, "Could not queue audio: %s\n", SDL_GetError());
        return 1;
    }

    SDL_PauseAudioDevice(deviceId, 0);

    SDL_Delay(wavSpec.duration);

    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);

    SDL_Quit();

    return 0;
}
