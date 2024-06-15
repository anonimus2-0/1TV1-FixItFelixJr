#include <iostream>
#include "miniwin.hpp"
#include "bibRFJ.hpp"

using namespace std;
using namespace miniwin;
using namespace voyADemolerlo;

int main(){

    #define v 10
    #define escala 1.8

    Personaje felix;
    MiniWinImage felixjr("felixstand.bmp", "felixstandmask.bmp");
    MiniWinImage felixjrleft("felixstandleft.bmp", "felixstandleftmask.bmp");
    MiniWinImage felixjrmove("felixmove.bmp", "felixmovemask.bmp");
    MiniWinImage felixjrmoveleft("felixmoveleft.bmp", "felixmoveleftmask.bmp");
    MiniWinImage edificio("EdificioRalph.bmp");

    bool move = false;
    bool izq = false;
    bool der = false;

    int t;
    bool on = false;
    bool i_presionada = false;
    bool d_presionada = false;
    bool ar_presionada = false;
    bool ab_presionada = false;
    bool repara = false;
    float x = 0, y = 0;


    titulo("Reparalo Felix Jr.");
    // 52, 37
    ventana(escala * 739, escala * 376);
    color_fondo(Colores::NEGRO);

    /*-----------------------Tamaños de foto de felix-----------------------------*/
    felixjrmove.alto(felixjrmove.alto() * escala);
    felixjrmove.ancho(felixjrmove.ancho() * escala);
    felixjr.alto(felixjr.alto() * escala);
    felixjr.ancho(felixjr.ancho() * escala);
    felixjrmoveleft.alto(felixjrmoveleft.alto() * escala);
    felixjrmoveleft.ancho(felixjrmoveleft.ancho() * escala);
    felixjrleft.alto(felixjrleft.alto() * escala);
    felixjrleft.ancho(felixjrleft.ancho() * escala);

    y = valto() - felixjr.alto();


    /*-----------------------Tamaños de foto de edificio-----------------------------*/
    edificio.alto(edificio.alto() * escala);
    edificio.ancho(edificio.ancho() * escala);
        

    t = tecla();
    while( t != Teclas::ESCAPE){

        /*
        felixjr.posX(0);
        felixjr.posY(valto());
        felixjrmove.posX(0);
        felixjrmove.posY(valto());
        felixjrleft.posX(0);
        felixjrleft.posY(valto());
        felixjrmoveleft.posX(0);
        felixjrmoveleft.posY(valto());
        */

        if (x + felixjr.ancho() > vancho())
            x = vancho() - felixjr.ancho();
        if (i_presionada)
            x -= v;
        if (x < 0)
            x = 0;
        if (d_presionada)
            x += v;
        if (y + felixjr.alto() > valto())
            y = valto() - felixjr.alto();
        if (ar_presionada)
            y += -v;
        if (y < 0)
            y = 0;
        if (ab_presionada)
            y -= -v;

        borra();
        color(NEGRO);

        // rectangulo_lleno(x,y,x+50,y+50);

        /*-----------Posición de felix---------------------------*/
        felixjr.posX(x);
        felixjr.posY(y);
        felixjrmove.posX(x);
        felixjrmove.posY(y);
        felixjrleft.posX(x);
        felixjrleft.posY(y);
        felixjrmoveleft.posX(x);
        felixjrmoveleft.posY(y);
        /*-----------Posición de felix---------------------------*/

        // Imagen TEST
        muestraImagen(edificio);


        t = teclaDown();

        if(t == RETURN) {
            on = !on;
            fullscreen(on);
        }

        if (t == IZQUIERDA)
        {
            i_presionada = true;
            move = true;
            der = false;
            izq = true;
        }
        if (t == DERECHA)
        {
            d_presionada = true;
            move = true;
            izq = false;
            der = true;
        }
        if (t == ARRIBA)
        {
            ar_presionada = true;
        }
        if (t == ABAJO)
        {
            ab_presionada = true;
        }
        if (t == ESPACIO)
        {
            repara = true;
        }

        t = teclaUp();
        if (t == IZQUIERDA)
        {
            i_presionada = false;
            izq = true;
            der = false;
            move = false;
        }
        if (t == DERECHA)
        {
            d_presionada = false;
            der = true;
            izq = false;
            move = false;
        }
        if (t == ARRIBA)
        {
            ar_presionada = false;
        }
        if (t == ABAJO)
        {
            ab_presionada = false;
        }

        if(move){
            if(izq){
                muestraImagen(felixjrmoveleft);
            } else {
                muestraImagen(felixjrmove);
            }
        } else {
            if(izq){
                muestraImagen(felixjrleft);
            } else {
                muestraImagen(felixjr);
            }
        }

        refresca();
        espera(1);
    }
    
    cierra();

    return 0;
}
