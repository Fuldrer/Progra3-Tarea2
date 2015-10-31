#include "Jugador3.h"

Jugador3::Jugador3(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    this->textures3.push_back(IMG_LoadTexture(renderer, "Personaje3/X_normal_run.png"));
    this->textures3.push_back(IMG_LoadTexture(renderer, "Personaje3/X_normal_run2.png"));
    this->textures3.push_back(IMG_LoadTexture(renderer, "Personaje3/X_normal_run3.png"));
    this->textures3.push_back(IMG_LoadTexture(renderer, "Personaje3/X_normal_run4.png"));
    this->textures3.push_back(IMG_LoadTexture(renderer, "Personaje3/X_normal_run5.png"));
    this->textures3.push_back(IMG_LoadTexture(renderer, "Personaje3/X_normal_run6.png"));
    this->textures3.push_back(IMG_LoadTexture(renderer, "Personaje3/X_normal_run7.png"));

    SDL_QueryTexture(this->textures3[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 10;
    rect.y = 10;

    current_texture=0;
}

Jugador3::~Jugador3()
{

}

void Jugador3::dibujar()
{
    SDL_RenderCopy(renderer, textures3[current_texture], NULL, &rect);
}

void Jugador3::logica()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

    if( currentKeyStates[ SDL_SCANCODE_H ] && frames%20==0 )
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
    if( currentKeyStates[ SDL_SCANCODE_F ] && frames%20==0 )
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
    if( currentKeyStates[ SDL_SCANCODE_T ] && frames%20==0)
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
    if( currentKeyStates[ SDL_SCANCODE_G ] && frames%20==0 )
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
        if(current_texture>=textures3.size())
            current_texture=0;
    }

    frames++;
}

