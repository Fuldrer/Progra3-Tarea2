#ifndef JUGADOR2_H
#define JUGADOR2_H

#include<SDL.h>
#include<SDL_image.h>
#include<vector>

using namespace std;

class Jugador2
{
    public:
        SDL_Renderer* renderer;
        vector <SDL_Texture*> textures2;
        SDL_Rect rect;
        int current_texture;
        int frames;
        Jugador2(SDL_Renderer* renderer);
        virtual ~Jugador2();
        void dibujar();
        void logica();
    protected:
    private:
};

#endif // JUGADOR2_H
