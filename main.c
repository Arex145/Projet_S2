#include <allegro.h>
#include "deplacement_James.h"
#include "deplacement_Jacob.h"

void initialise_allegro(){
        allegro_init();
        install_keyboard();
        install_mouse();
        set_color_depth(desktop_color_depth());
        if ((set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0)) != 0) {
            allegro_message("Pb de mode graphique");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
}

int main() {
initialise_allegro();
    t_perso Jacob;
    Jacob.x = 50;
    Jacob.y = 50;
    t_perso James;
    James.x = 100;
    James.y = 50;
    BITMAP *buffer = create_bitmap(800, 600);
    BITMAP *terrain1;
    BITMAP *terrain2;
    clear_bitmap(buffer);
    if (buffer == NULL){
        allegro_message("erreur");
    }
    BITMAP *JacobD;
    JacobD = load_bitmap("JacobD.bmp", NULL);
    if(JacobD==NULL) {
        allegro_message("erreur");
    }
    BITMAP *JamesD;
    JamesD = load_bitmap("James.bmp", NULL);
    if(JamesD==NULL) {
        allegro_message("erreur");
    }
    terrain1 = load_bitmap("fond_sable.bmp", NULL);
    if(terrain1==NULL) {
        allegro_message("erreur");
    }
    terrain2 = load_bitmap("fond_sable2.bmp", NULL);
    if(terrain2==NULL) {
        allegro_message("erreur");
    }

    BITMAP *terrainActuel = terrain1;

    while (!key[KEY_ESC]) {
        clear_to_color(buffer, makecol(0, 0, 0));
        deplacement_James(&James);
        deplacement_Jacob(&Jacob);
        if (Jacob.y < 0 || James.y < 0) {
            if (terrainActuel == terrain1) {
                terrainActuel = terrain2;
                Jacob.x = 50;
                Jacob.y = 50;
                James.x = 100;
                James.y = 50;
            } else {
                terrainActuel = terrain1;
                Jacob.x = 50;
                Jacob.y = 50;
                James.x = 100;
                James.y = 50;
            }
        }
        blit(terrainActuel, buffer, 0, 0, 0, 0, terrainActuel->w, terrainActuel->h);
        masked_stretch_blit(JacobD, buffer, 0, 0, JacobD->w, JacobD->h, Jacob.x, Jacob.y, 80, 70);
        masked_stretch_blit(JamesD, buffer, 0, 0, JamesD->w, JamesD->h, James.x, James.y, 80, 70);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        vsync();
    }

    allegro_exit();
    return 0;
}
END_OF_MAIN();