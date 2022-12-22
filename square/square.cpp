#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main (int argc, char* args[])
{
    SDL_Window* window = NULL;

    SDL_Surface* screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else {
        //Create window
        window = SDL_CreateWindow
        (
            "Fenêtre d'Axel", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
        );
        if (window == NULL)
        {
            printf("Window could not be created ! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            //get window surface
            screenSurface = SDL_GetWindowSurface(window);

            //fill the surface with white
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

            //update the surface
            SDL_UpdateWindowSurface(window);

            //hack to keep window open. We learn later how to do this more clean
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    //destroy the window
    SDL_DestroyWindow(window);

    //quit DSL subsystems
    SDL_Quit();

    return 0;
}