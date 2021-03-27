#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(short x, short y){
COORD a;
a.X = x;
a.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
struct Punto{
int x,y;
};
int main(void){
Punto *triangulo;
Punto *cuadrado;
triangulo = new Punto[3];
cuadrado = (struct Punto *) malloc(sizeof(struct Punto) * 4);
triangulo[0].x = 40;
triangulo[0].y = 5;

triangulo[1].x = 34;
triangulo[1].y = 15;
triangulo[2].x = 46;
triangulo[2].y = 15;

cuadrado[0].x = 0;
cuadrado[0].y = 0;
cuadrado[1].x = 10;
cuadrado[1].y = 0;
cuadrado[2].x = 0;
cuadrado[2].y = 4;
cuadrado[3].x = 10;
cuadrado[3].y = 4;
for(int i = 0; i<3; i++){
gotoxy(triangulo[i].x, triangulo[i].y);
cout << "^";
}
for(int i = 0; i<4; i++){
gotoxy(cuadrado[i].x, cuadrado[i].y);
cout << "*";
}
gotoxy(0,20);
delete []triangulo;
free(cuadrado);
}
