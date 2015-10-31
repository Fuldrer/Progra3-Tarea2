#include "Jugador2.h"

Jugador2::Jugador2(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    this->textures2.push_back(IMG_LoadTexture(renderer, "Personaje2/rt1.png"));
    this->textures2.push_back(IMG_LoadTexture(renderer, "Personaje2/rt2.png"));
    //this->textures2.push_back(IMG_LoadTexture(renderer, "Personaje2/agumonsprite3.png"));
    //this->textures2.push_back(IMG_LoadTexture(renderer, "Personaje2/agumonsprite4.png"));
    //this->textures2.push_back(IMG_LoadTexture(renderer, "Personaje2/agumonsprite5.png"));
    //this->textures2.push_back(IMG_LoadTexture(renderer, "Personaje2/agumonsprite6.png"));
    //this->textures2.push_back(IMG_LoadTexture(renderer, "Personaje2/agumonsprite7.png"));

    SDL_QueryTexture(this->textures2[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 10;
    rect.y = 10;

    current_texture=0;
}

Jugador2::~Jugador2()
{
    //dtor
}

void Jugador2::dibujar()
{
    SDL_RenderCopy(renderer, textures2[current_texture], NULL, &rect);
}

void Jugador2::logica()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

    if( currentKeyStates[ SDL_SCANCODE_L ] && frames%20==0 )
    {
        if(currentKeyStates[ SDL_SCANCODE_LSHIFT])
        {
            rect.x+=5;
        }
        else
        {
            rect.x+=1;
        }
    }
    if( currentKeyStates[ SDL_SCANCODE_J ] && frames%20==0 )
    {
        if(currentKeyStates[ SDL_SCANCODE_LSHIFT])
        {
            rect.x-=5;
        }
        else
        {
            rect.x-=1;
        }
    }
    if( currentKeyStates[ SDL_SCANCODE_I ] && frames%20==0)
    {
        if(currentKeyStates[ SDL_SCANCODE_LSHIFT])
        {
            rect.y-=5;
        }
        else
        {
            rect.y-=1;
        }
    }
    if( currentKeyStates[ SDL_SCANCODE_K ] && frames%20==0)
    {
        if(currentKeyStates[ SDL_SCANCODE_LSHIFT])
        {
            rect.y+=5;
        }
        else
        {
            rect.y+=1;
        }
    }

    if(frames%500==0)
    {
        current_texture++;
        if(current_texture>=textures2.size())
            current_texture=0;
    }

    frames++;
}
