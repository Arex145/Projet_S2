#include <allegro.h>
#include "menu.h"

void initialise_allegro(){
    allegro_init();
    install_keyboard();
    install_mouse();
    show_mouse(screen);
    set_color_depth(desktop_color_depth());
    if ((set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0)) != 0) {
        allegro_message("Pb de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

int main() {
    initialise_allegro();
    menu();
    allegro_exit();
    return 0;
}
END_OF_MAIN();
