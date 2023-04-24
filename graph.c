#include "SDL2/SDL.h"
#include <math.h>

void draw_circle(SDL_Renderer *renderer, int x, int y, int radius, Uint8 r, Uint8 g, Uint8 b) {
    // Dessine le cercle avec la couleur de bordure spécifiée
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx*dx + dy*dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void draw_arrow(SDL_Renderer* renderer, int start_x, int start_y, int end_x, int end_y, int arrow_width, int arrow_height, Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);

    // Calcule la longueur de la flèche
    double arrow_length = sqrt(pow(end_x - start_x, 2) + pow(end_y - start_y, 2));

    // Calcule l'angle de la flèche
    double arrow_angle = atan2(end_y - start_y, end_x - start_x);

    // Calcule la position du bout de la flèche
    int arrow_end_x = end_x - arrow_width * cos(arrow_angle);
    int arrow_end_y = end_y - arrow_width * sin(arrow_angle);

    // Dessine le corps de la flèche
    SDL_RenderDrawLine(renderer, start_x, start_y, end_x, end_y);

    // Dessine le bout de la flèche
    SDL_RenderDrawLine(renderer, end_x, end_y, arrow_end_x + arrow_height * cos(arrow_angle + M_PI/2), arrow_end_y + arrow_height * sin(arrow_angle + M_PI/2));
    SDL_RenderDrawLine(renderer, end_x, end_y, arrow_end_x + arrow_height * cos(arrow_angle - M_PI/2), arrow_end_y + arrow_height * sin(arrow_angle - M_PI/2));
}



int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    //int window_open = init(window, renderer);
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Failed to initialize the SDL2 library\n");
        return -1;
    }

    window = SDL_CreateWindow("Lapinou", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        680, 480, 
        SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);

    if(!window)
    {
        printf("Failed to create window\n");
        return -1;
    }

    if(!renderer)
    {
        printf("Failed to create renderer\n");
        return -1;
    }

    
    int window_open = 1;

    draw_circle(renderer, 100, 100, 50, 200, 0, 50);
    draw_circle(renderer, 300, 300, 20, 0, 50, 255);
    double c = cos(M_PI/4.0);
    draw_arrow(renderer, 100 + 50*c, 100 + 50*c, 300 - 20*c, 300 - 20*c, 3, 5, 255, 255, 255);

    SDL_RenderPresent(renderer);
    // Main loop
    SDL_Event e;
    while (window_open) {
        SDL_WaitEvent(&e);
        switch (e.type) {
            case SDL_QUIT:
                window_open = 0;
                break;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}