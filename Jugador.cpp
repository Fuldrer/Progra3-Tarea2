#include "Jugador.h"

Jugador::Jugador(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    this->textures.push_back(IMG_LoadTexture(renderer, "Personaje/down1.png"));
    this->textures.push_back(IMG_LoadTexture(renderer, "Personaje/down2.png"));

    SDL_QueryTexture(this->textures[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 0;
    rect.y = 0;

    current_texture=0;
}

Jugador::~Jugador()
{
    //dtor
}

void Jugador::dibujar()
{
    SDL_RenderCopy(renderer, textures[current_texture], NULL, &rect);
}

void Jugador::logica()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

    if( currentKeyStates[ SDL_SCANCODE_RIGHT ] && frames%20==0 )
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
    if( currentKeyStates[ SDL_SCANCODE_LEFT ] && frames%20==0 )
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
    if( currentKeyStates[ SDL_SCANCODE_UP ] && frames%20==0 )
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
    if( currentKeyStates[ SDL_SCANCODE_DOWN ] && frames%20==0 )
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
        if(current_texture>=textures.size())
            current_texture=0;
    }

    frames++;
}
