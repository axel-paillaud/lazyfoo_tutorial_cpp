#include <stdio.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//the window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

bool init() {
    //Initialization flag
    bool succes = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { //-1 is error
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        succes = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window could not be created ! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return succes;
}

bool loadMedia()
{
    bool succes = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP
}