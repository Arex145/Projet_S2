#include <allegro.h>
#include "regles.h"

void regles() {
    BITMAP* regles;
    regles = load_bitmap("regles_du_jeux.bmp", NULL);
    blit(regles, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    readkey();
}