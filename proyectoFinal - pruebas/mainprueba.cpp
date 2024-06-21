#include<iostream>
#include<cstdlib>
#include<ctime>
#include"miniwin.hpp"
#include"bibRFJ.hpp"

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
    MiniWinImage felixjrreparaR("felixrepara.bmp", "felixreparamask.bmp");
    MiniWinImage felixjrreparaL("felixreparaleft.bmp", "felixreparaleftmask.bmp");

    Personaje Ralph;
    MiniWinImage ralphstand("ralphstand.bmp", "ralphstandmask.bmp");
    MiniWinImage ralphC1("ralphmove.bmp", "ralphmovemask.bmp");
    MiniWinImage ralphC2("ralphmove2.bmp", "ralphmove2mask.bmp");
    MiniWinImage ralphG1("ralphgolpea1.bmp", "ralphgolpea1mask.bmp");
    MiniWinImage ralphG2("ralphgolpea2.bmp", "ralphgolpea2mask.bmp");
    MiniWinImage ralphG3("ralphgolpea3.bmp", "ralphgolpea3mask.bmp");

    Personaje Inquilino;
    MiniWinImage vecino("inquilino.bmp", "inquilinomask.bmp");

    MiniWinImage edificio("EdificioRalph.bmp");
    MiniWinImage ventanaR("ventanas.bmp", "ventanasmask.bmp");
    MiniWinImage speech("felixdialogue.bmp", "felixdialoguemask.bmp");

    bool move = false;
    bool izq = false;
    bool der = false;
    bool secreto = false;
    bool condicion = true;

    int t;
    int inicio = 0, totvr = 0;
    bool on = false;
    bool i_presionada = false;
    bool d_presionada = false;
    bool ar_presionada = false;
    bool ab_presionada = false;
    bool repara = false;
    float x = 0, y = 0;
    float xv = 0, yv = 0;
    float xr = 0, yr = 0;
    bool vrotas[7][5];
    int band = 0, band2 = 0, posv1 = 0, posv2 = 0;
    bool ayuda1 = true;


    titulo("Repara Felix Jr.");
    ventana(escala * 739, escala * 376);
    color_fondo(Colores::NEGRO);

    /*-----------------------Tamaños de las fotos de personajes-----------------------------*/
    felixjrmove.alto(felixjrmove.alto() * escala);
    felixjrmove.ancho(felixjrmove.ancho() * escala);
    felixjr.alto(felixjr.alto() * escala);
    felixjr.ancho(felixjr.ancho() * escala);
    felixjrmoveleft.alto(felixjrmoveleft.alto() * escala);
    felixjrmoveleft.ancho(felixjrmoveleft.ancho() * escala);
    felixjrleft.alto(felixjrleft.alto() * escala);
    felixjrleft.ancho(felixjrleft.ancho() * escala);
    felixjrreparaR.alto(felixjrreparaR.alto() * escala);
    felixjrreparaR.ancho(felixjrreparaR.ancho() * escala);
    felixjrreparaL.alto(felixjrreparaL.alto() * escala);
    felixjrreparaL.ancho(felixjrreparaL.ancho() * escala);


    ralphstand.alto(ralphstand.alto() * escala);
    ralphstand.ancho(ralphstand.ancho() * escala);
    ralphC1.alto(ralphC1.alto() * escala);
    ralphC1.ancho(ralphC1.ancho() * escala);
    ralphC2.alto(ralphC2.alto() * escala);
    ralphC2.ancho(ralphC2.ancho() * escala);
    ralphG1.alto(ralphG1.alto() * escala);
    ralphG1.ancho(ralphG1.ancho() * escala);
    ralphG2.alto(ralphG2.alto() * escala);
    ralphG2.ancho(ralphG2.ancho() * escala);
    ralphG3.alto(ralphG3.alto() * escala);
    ralphG3.ancho(ralphG3.ancho() * escala);


    /*-----------------------Tamaños de foto de edificio-----------------------------*/
    edificio.alto(edificio.alto() * escala);
    edificio.ancho(edificio.ancho() * escala);
    ventanaR.alto(ventanaR.alto() * escala/2.5);
    ventanaR.ancho(5 + (ventanaR.ancho() * escala/2.5));

    /*-----------------------Extras-----------------------------*/
    speech.alto((speech.alto() / 1.5) * escala);
    speech.ancho((speech.ancho() / 1.5) * escala);

    y = valto() - felixjr.alto();

    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 5; j++){
            vrotas[i][j] = false;
        }
    }

    t = tecla();
    
    while( t != Teclas::ESCAPE){

        if(x < (escala*260 + felixjr.ancho()) && y > (valto() - felixjr.alto() - 0.1)) ar_presionada = false;
        if(x > (vancho() - escala*282) && y > (valto() - felixjr.alto() - 0.1)) ar_presionada = false;
        if (x + felixjr.ancho() > vancho()){
            x = vancho() - felixjr.ancho();}
        if (i_presionada){
            x -= v*escala*3.5;
            i_presionada = false;
            }
        if (x < 0){
            x = 0;}
        if (d_presionada){
            x += v*escala*3.5;
            d_presionada = false;
            }
        if (y + felixjr.alto() > valto()){
            y = valto() - felixjr.alto();}
        if (ar_presionada){
            y += -v*escala*5.3;
            ar_presionada = false;
            }
        if (y < 26*escala){
            y = 26*escala;}
        if (ab_presionada){
            y -= -v*escala*5.3;
            ab_presionada = false;
            }
            
        if((y + felixjr.alto()) < (valto() - felixjr.alto() - 0.1)){
            if (x < (v*escala*3.5*8)){
                x = (v*escala*3.5*8);
                }
            if((x + felixjr.ancho()) > (vancho() - v*escala*3.5*8)){
                x = (vancho() - v*escala*3.5*8 - felixjr.ancho());
            }
        }

        //borra();
        //color(NEGRO);

        /*-----------Posición de Felix---------------------------*/
        felixjr.posX(x);
        felixjr.posY(y);
        felixjrmove.posX(x);
        felixjrmove.posY(y);
        felixjrleft.posX(x);
        felixjrleft.posY(y);
        felixjrmoveleft.posX(x);
        felixjrmoveleft.posY(y);
        felixjrreparaR.posX(x);
        felixjrreparaR.posY(y);
        felixjrreparaL.posX(x-(13*escala));
        felixjrreparaL.posY(y);

        /*-----------Posición de Ralph---------------------------*/
        ralphstand.posX(xr);
        ralphstand.posY(yr);
        ralphC1.posX(xr);
        ralphC1.posY(yr);
        ralphC2.posX(xr);
        ralphC2.posY(yr);
        ralphG1.posX(xr);
        ralphG1.posY(yr);
        ralphG2.posX(xr);
        ralphG2.posY(yr);
        ralphG3.posX(xr);
        ralphG3.posY(yr);

        borra();

        // Mostrar Imagen
        muestraImagen(edificio);

        // Re-imprimir
        if(condicion == false){
            for (int i = 0; i < 5; i++){
                for (int j = 0; j < 7; j++){
                    if(vrotas[i][j]){
                        ventanaR.posX((i * 3.5 * v * escala) + (28.5 * escala * v) - escala*2.7);
                        ventanaR.posY((j * 5.3 * v * escala) + escala*5);
                        muestraImagen(ventanaR);
                        ralphstand.posX(xr);
                        ralphstand.posY(yr);
                        muestraImagen(ralphstand);
                        totvr++;
                    }
                }
            }
        }

        t = teclaDown();

        if(t == RETURN) {
            if(band % 2 == 0){
            on = !on;
            fullscreen(on);
            secreto = true;
            }
            else{
            on = !on;
            fullscreen(on);
            secreto = false;
            }
            band += 1;
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
            move = true;
        }
        if (t == ABAJO)
        {
            ab_presionada = true;
            move = true;
        }
        if (t == ESPACIO)
        {
            repara = true;
        }

        // -----------------------------------------------------

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
            move = false;
        }
        if (t == ABAJO)
        {
            ab_presionada = false;
            move = false;
        }
        if (t == ESPACIO)
        {
            repara = false;
        }

        if(move){
            if(izq){
                muestraImagen(felixjrmoveleft);
            }
            else{
                muestraImagen(felixjrmove);
            }
        }
        else {
            if(izq){
                if(repara == false) muestraImagen(felixjrleft);
            }
            else{
                if(repara == false && band2 != 0) muestraImagen(felixjr);
            }
        }
        if(move == false && repara){
            if(izq) muestraImagen(felixjrreparaL);
            else muestraImagen(felixjrreparaR);
            for (int i = 0; i < 5; i++){
                for (int j = 0; j < 7; j++){
                    if(vrotas[i][j]){
                        ventanaR.posX((i * 3.5 * v * escala) + (28.5 * escala * v) - escala*2.7);
                        ventanaR.posY((j * 5.3 * v * escala) + escala*5);
                        if((felixjrreparaR.posX()+escala) >= ventanaR.posX() && felixjrreparaR.posX() <= (ventanaR.posX()+38*escala)){
                            if(felixjrreparaR.posY() >= ventanaR.posY() && felixjrreparaR.posY() <= (ventanaR.posY()+63*escala)){
                                vrotas[i][j] = false;
                            }
                        }
                        if((felixjrreparaL.posX()+escala) >= ventanaR.posX() && felixjrreparaL.posX() <= (ventanaR.posX()+38*escala)){
                            if(felixjrreparaL.posY() >= ventanaR.posY() && felixjrreparaL.posY() <= (ventanaR.posY()+63*escala)){
                                vrotas[i][j] = false;
                            }
                        }
                    }
                }
            }
        }

        if (secreto){
            color(AMARILLO);
            rectangulo_lleno(vancho()-felixjr.ancho(),valto()-felixjr.alto(),vancho(),valto());
            if(x == (vancho()-felixjr.ancho())){
                mensaje("Encontraste un objeto oculto.","Felicidades!");
                x = vancho() - felixjr.ancho() - felixjr.ancho();
                }
        }

        // Animaciones

        if(condicion){
            refresca();
            
            espera(1000);
            xr -= 50;
            yr = (valto() - ralphstand.alto());
            for (int i = 0; i < (5 * escala); i++){
                borra();
                muestraImagen(edificio);
                xr += v;
                ralphC1.posX(xr);
                ralphC1.posY(yr);
                muestraImagen(ralphC1);
                refresca();
                espera(100);
                borra();

                muestraImagen(edificio);
                xr += v;
                ralphC2.posX(xr);
                ralphC2.posY(yr);
                muestraImagen(ralphC2);
                refresca();
                espera(100);
            }
            borra();
            muestraImagen(edificio);
            ralphstand.posX(xr);
            ralphstand.posY(yr);
            muestraImagen(ralphstand);
            refresca();
            espera(2000);
            for (int i = 0; i < (13 * escala); i++){
                borra();
                muestraImagen(edificio);
                xr += v;
                ralphC1.posX(xr);
                ralphC1.posY(yr);
                muestraImagen(ralphC1);
                refresca();
                espera(100);
                borra();

                muestraImagen(edificio);
                xr += v;
                ralphC2.posX(xr);
                ralphC2.posY(yr);
                muestraImagen(ralphC2);
                 
                refresca();
                espera(100);
            }
            borra();
            muestraImagen(edificio);
            ralphstand.posX(xr);
            ralphstand.posY(yr);
            muestraImagen(ralphstand);
            refresca();

            espera(2000);

            x -= 120;
            y = (valto() - felixjr.alto());

            srand(time(NULL));
            for (int i = 0; i < 12; i++){
                borra();
                muestraImagen(edificio);

                // Re-imprimir
                for (int i = 0; i < 5; i++){
                    for (int j = 0; j < 7; j++){
                        if(vrotas[i][j]){
                            ventanaR.posX((i * 3.5 * v * escala) + (28.5 * escala * v) - escala*2.7);
                            ventanaR.posY((j * 5.3 * v * escala) + escala*5);
                            muestraImagen(ventanaR);
                        }
                    }
                }

                posv1 = (rand() % 5);
                posv2 = (rand() % 7);
                if(posv1 == 2 && posv2 == 6) posv2 = 4;
                if(posv1 == 2 && posv2 == 5) posv2 = 4;
                vrotas[posv1][posv2] = true;               
                ventanaR.posX((posv1 * 3.5 * v * escala) + (28.5 * escala * v) - escala*2.7);
                ventanaR.posY((posv2 * 5.3 * v * escala) + escala*5);
                muestraImagen(ventanaR);
                ralphstand.posX(xr);
                ralphstand.posY(yr);
                muestraImagen(ralphstand);

                x += v;
                felixjrmove.posX(x);
                felixjrmove.posY(y);
                muestraImagen(felixjrmove);

                refresca();
                espera(250);
            }
            condicion = false;
        }

        if(band2 == 1){
            //color(BLANCO);
            refresca();
            espera(500);
            speech.posX(felixjr.posX()+5*escala);
            speech.posY(felixjr.posY()-16*escala);
            muestraImagen(speech);
            refresca();
            espera(2000);
            for (int i = 0; i < (28.5 * escala); i++){
                
                muestraImagen(edificio);
                x += v;
                felixjrmove.posX(x);
                felixjrmove.posY(y);
                muestraImagen(felixjrmove);
                
                // Re-imprimir
                for (int i = 0; i < 5; i++){
                    for (int j = 0; j < 7; j++){
                        if(vrotas[i][j] == true){
                            ventanaR.posX((i * 3.5 * v * escala) + (28.5 * escala * v) - escala*2.7);
                            ventanaR.posY((j * 5.3 * v * escala) + escala*5);
                            muestraImagen(ventanaR);
                            ralphstand.posX(xr);
                            ralphstand.posY(yr);
                            muestraImagen(ralphstand);
                        }
                    }
                }
                refresca();
                espera(1);
            }
        }
            
        
        band2 ++;
        if(band > 5) band = 3;
        if(band2 > 5) band2 = 3;
        totvr = 0;
        refresca();
        espera(1);
        borra();
    }
    cierra();

    return 0;
}
