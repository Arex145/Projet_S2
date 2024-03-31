#include <allegro.h>
#include "deplacement_Jacob.h"

void deplacement_Jacob(t_perso *Jacob){
    if (key[KEY_W]&&Jacob->y>0) Jacob->y -= 4;
    if (key[KEY_S]&&Jacob->y<600) Jacob->y += 4;
    if (key[KEY_A]&&Jacob->x>0) Jacob->x -= 4;
    if (key[KEY_D]&&Jacob->x<800) Jacob->x += 4;
}
