#include <allegro.h>
#include "deplacement_James.h"

void deplacement_James(t_perso *James){
    if (key[KEY_UP]&&James->y>0) James->y -= 4;
    if (key[KEY_DOWN]&&James->y<600) James->y += 4;
    if (key[KEY_LEFT]&&James->x>0) James->x -= 4;
    if (key[KEY_RIGHT]&&James->x<800) James->x += 4;
}