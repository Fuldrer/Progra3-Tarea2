#ifndef JUGADOR3_H
#define JUGADOR3_H

#include<SDL.h>
#include<SDL_image.h>
#include<vector>

using namespace std;

class Jugador3
{
    public:
        SDL_Renderer* renderer;
        vector <SDL_Texture*> textures3;
        SDL_Rect rect;
        int current_texture;
        int frames;
        Jugador3(SDL_Renderer* renderer);
        virtual ~Jugador3();
        void dibujar();
        void logica();
    protected:
    private:
};

#endif // JUGADOR3_H
