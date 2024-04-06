#include <allegro.h>
#include <stdio.h>
#include "menu.h"
#include "niveau1.h"
#include "regles.h"

void menu() {
    BITMAP *menu;
    menu = load_bitmap("accueil.bmp", NULL);
    BITMAP *jouer;
    BITMAP *charger;
    BITMAP *classement;
    BITMAP *regle_du_jeu;
    BITMAP *credits;
    BITMAP *quitter;
    jouer = load_bitmap("jouer.bmp", NULL);
    if(jouer==NULL) allegro_message("erreur jouer");
    //charger = load_bitmap("charger.bmp", NULL);
    //classement = load_bitmap("classement.bmp", NULL);
    regle_du_jeu = load_bitmap("regles.bmp", NULL);
    if(regle_du_jeu==NULL){
        printf("erreur regles");
    }
    //credits = load_bitmap("credits.bmp", NULL);
    //quitter = load_bitmap("quitter.bmp", NULL);
    show_mouse(screen);
    while (!key[KEY_ESC]) {
        blit(menu, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        if (mouse_y < 337 && mouse_y > 268 && mouse_x > 55 && mouse_x < 390) {
            do{
            blit(jouer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            if (mouse_b & 1) {
                niveau1();
            }
            }while (mouse_y < 337 && mouse_y > 268 && mouse_x > 55 && mouse_x < 390);
        }else if (mouse_y < 337 && mouse_y > 268 && mouse_x > 425 && mouse_x < 760) {
            do {
                blit(regle_du_jeu, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                if (mouse_b & 1) {
                    regles();
                }
                vsync();
            } while (mouse_x > 425 && mouse_x < 760);
        }
        vsync();
    }
}