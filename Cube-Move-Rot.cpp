/**************************************
Nombre: Lucy Carmona Vieyra
Matrícula: 9496
Grupo: IECSA 05
**************************************/
#include <allegro.h>
#include <cmath>
using namespace std;
#define lado 100
#define PI 3.141592654
#define color_1 2
#define color_2 5
#define color_3 3
#define color_4 12
#define color_5 1
#define prof 35
#define ancho 700
#define alto 500

void cuadrado(float[], float[], float[], float[], BITMAP *buffer);
void cuadrado_borra(float[], float[], float[], float[], BITMAP *buffer, int);
void cubo(float[], float[], float[], float[], BITMAP *buffer, int color);
void cubo_borra(float[], float[], float[], float[], BITMAP *buffer, int color);

int main()
{
    allegro_init();
    set_color_depth(8);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, ancho, alto, 0, 0);
    install_timer();
    install_keyboard();
    BITMAP *buffer=create_bitmap(ancho, alto);
    rectfill (buffer, 0, 0, 700, 500, 15);
    int CENTRO_Y=SCREEN_H/2;
    int CENTRO_X=SCREEN_W/2;
    float dif=PI/2;
    float r=sqrt(lado*lado/2), angulo_b=PI/8;
    float cambio_ang=PI/45, cambio_lad=lado/10;
    // 0->x, 1->y
    float a[2], b[2], c[2], d[2];
    b[0]=CENTRO_X+(r*cos(angulo_b));
    b[1]=CENTRO_Y+(r*sin(angulo_b));
    a[0]=CENTRO_X+(r*cos(angulo_b+dif));
    a[1]=CENTRO_Y+(r*sin(angulo_b+dif));
    c[0]=CENTRO_X+(r*cos(angulo_b+2*dif));
    c[1]=CENTRO_Y+(r*sin(angulo_b+2*dif));
    d[0]=CENTRO_X+(r*cos(angulo_b+3*dif));
    d[1]=CENTRO_Y+(r*sin(angulo_b+3*dif));
    cuadrado(a, b, c, d, buffer);
    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
    do
    {
        if(key[KEY_RIGHT] || key[KEY_UP])
        {
            cuadrado_borra(a, b, c, d, buffer, 15);
            angulo_b+=cambio_ang;
            if(key[KEY_RIGHT]) CENTRO_X+=cambio_lad;
            else CENTRO_Y-=cambio_lad;
            b[0]=CENTRO_X+(r*cos(angulo_b));
            b[1]=CENTRO_Y+(r*sin(angulo_b));
            a[0]=CENTRO_X+(r*cos(angulo_b+dif));
            a[1]=CENTRO_Y+(r*sin(angulo_b+dif));
            c[0]=CENTRO_X+(r*cos(angulo_b+2*dif));
            c[1]=CENTRO_Y+(r*sin(angulo_b+2*dif));
            d[0]=CENTRO_X+(r*cos(angulo_b+3*dif));
            d[1]=CENTRO_Y+(r*sin(angulo_b+3*dif));
            cuadrado(a, b, c, d, buffer);
            blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
            rest(10);
        }
        if(key[KEY_LEFT] || key[KEY_DOWN])
        {
            cuadrado_borra(a, b, c, d, buffer, 15);
            angulo_b-=cambio_ang;
            if(key[KEY_LEFT]) CENTRO_X-=cambio_lad;
            else CENTRO_Y+=cambio_lad;
            b[0]=CENTRO_X+(r*cos(angulo_b));
            b[1]=CENTRO_Y+(r*sin(angulo_b));
            a[0]=CENTRO_X+(r*cos(angulo_b+dif));
            a[1]=CENTRO_Y+(r*sin(angulo_b+dif));
            c[0]=CENTRO_X+(r*cos(angulo_b+2*dif));
            c[1]=CENTRO_Y+(r*sin(angulo_b+2*dif));
            d[0]=CENTRO_X+(r*cos(angulo_b+3*dif));
            d[1]=CENTRO_Y+(r*sin(angulo_b+3*dif));
            cuadrado(a, b, c, d, buffer);
            blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
            rest(10);
        }
    }
    while(!key[KEY_ESC]);
    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}
END_OF_MAIN();

void cuadrado (float a[], float b[], float c[], float d[], BITMAP *buffer)
{
    line(buffer, b[0], b[1], a[0], a[1], color_1);
    line(buffer, a[0], a[1], c[0], c[1], color_2);
    line(buffer, c[0], c[1], d[0], d[1], color_3);
    line(buffer, d[0], d[1], b[0], b[1], color_4);
    line(buffer, b[0]+prof, b[1]+prof, a[0]+prof, a[1]+prof, color_1);
    line(buffer, a[0]+prof, a[1]+prof, c[0]+prof, c[1]+prof, color_2);
    line(buffer, c[0]+prof, c[1]+prof, d[0]+prof, d[1]+prof, color_3);
    line(buffer, d[0]+prof, d[1]+prof, b[0]+prof, b[1]+prof, color_4);
    cubo(a, b, c, d, buffer, color_5);
}

void cuadrado_borra (float a[], float b[], float c[], float d[], BITMAP *buffer, int color)
{
    line(buffer, b[0], b[1], a[0], a[1], color);
    line(buffer, a[0], a[1], c[0], c[1], color);
    line(buffer, c[0], c[1], d[0], d[1], color);
    line(buffer, d[0], d[1], b[0], b[1], color);
    line(buffer, b[0]+prof, b[1]+prof, a[0]+prof, a[1]+prof, color);
    line(buffer, a[0]+prof, a[1]+prof, c[0]+prof, c[1]+prof, color);
    line(buffer, c[0]+prof, c[1]+prof, d[0]+prof, d[1]+prof, color);
    line(buffer, d[0]+prof, d[1]+prof, b[0]+prof, b[1]+prof, color);
    cubo(a, b, c, d, buffer, color);
}

void cubo(float a[], float b[], float c[], float d[], BITMAP *buffer, int color)
{
    line(buffer, a[0], a[1], a[0]+prof, a[1]+prof, color);
    line(buffer, b[0], b[1], b[0]+prof, b[1]+prof, color);
    line(buffer, c[0], c[1], c[0]+prof, c[1]+prof, color);
    line(buffer, d[0], d[1], d[0]+prof, d[1]+prof, color);
}
