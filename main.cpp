
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

#include "Jugador.h"
#include "Jugador2.h"
#include "Jugador3.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character;
SDL_Rect rect_background,rect_character;

using namespace std;

int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 1440/*WIDTH*/, 720/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"esenario2.jpg");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    character = IMG_LoadTexture(renderer, "personaje.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = w;
    rect_character.h = h;

    //SDL_Texture* otro_personaje = IMG_LoadTexture(renderer,"otropersonaje.png");
    //SDL_Rect otro_rect;
    //otro_rect.x=150;
    //otro_rect.y=50;
    //otro_rect.w=32;
    //otro_rect.h=32;

    Jugador jugador(renderer);
    Jugador2 jugador2(renderer);
    Jugador3 jugador3(renderer);

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_character.x++;
            }
        }
        jugador.logica();
        jugador2.logica();
        jugador3.logica();

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        //SDL_RenderCopy(renderer, character, NULL, &rect_character);
        //SDL_RenderCopy(renderer, otro_personaje, NULL, &otro_rect);
        jugador.dibujar();
        jugador2.dibujar();
        jugador3.dibujar();
        SDL_RenderPresent(renderer);
    }

	return 0;
}
