//Ejercicio:
//Autor:DEK
//Fecha:
//Comentario:

# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
#include <windows.h>
#include <ctime>
#include <conio.h>

using namespace std;


///DEFINICIONES DE CONSTANTES Y FUNCIONES QUE SON UTILIZADAS POR LA CLASE PUNTO
enum Color{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};
/// Se definen una serie de constantes que asumen el valor que se le asignó.
/// Es más fácil usar cBLANCO para setear el color a blanco, que acordarse el número 15

void ocultarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void mostrarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 10;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(short x, short y){ ///UBICA EL CURSOR EN LA POSICIÓN x,y DE LA PANTALLA
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
///ASIGNA COLORES AL TEXTO Y AL FONDO DEL TEXTO
void textcolor(int colorTexto=15, int colorFondo=0){
    int color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

///**FIN FUNCIONES


 ///CLASE PANTALL
 class Pantalla{
private:
    int tamanioX;
    int tamanioY;
public:
    Pantalla(){
        CONSOLE_SCREEN_BUFFER_INFO c;
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(consoleHandle, &c);
        tamanioX=c.dwMaximumWindowSize.X;
        tamanioY=c.dwMaximumWindowSize.Y-1;
    }

    int getTamanioX(){return tamanioX;}
    int getTamanioY(){return tamanioY;}
 };

///CLASE PUNTO
///setXaleatorio() q asigne un valor aleatorio para el punt el eje X;
///setYaleatorio() q asigne un valor aleatorio para el punt el eje Y;
class Punto {
    private:
        int x;
        int y;
        int color;
    public:
        Punto(int a=0, int b=0, int nuevoColor=cNEGRO){
            x=a;
            y=b;
            color=15;
        }
        void Mostrar(){
            textcolor(color, 0);
            gotoxy(x,y);
            cout<<".";
        }
        void MostrarValores();
        void Ocultar(){gotoxy(x,y);cout<<" ";}
        void setXaleatorio(){
            Pantalla aux;
             x=rand()%aux.getTamanioX();
         }
        void setYaleatorio(){
           Pantalla aux;
            y=rand()%aux.getTamanioY();
         }
         void setColorAleatorio(){
            color=rand()%14;
         }
        void setX(int valor){if(valor>=0 && valor<=80)  x=valor;  }
        void setY(int valor){if(valor>=0)  y=valor;}
        void setColor(int nuevo){if(nuevo>0 && nuevo<=15)color=nuevo;}
        int getX(){return x;}
        int getY(){return y;}
        int getColor(){return color;}

        ~Punto(){///DESTRUCTOR: se ejecuta cuando el objeto cae fuera de su alcance.
            textcolor(0,15);
            }
};

void Punto::MostrarValores(){
        cout<<x<<endl;
        cout<<y<<endl;
        cout<<color<<endl;
    }
void probarHorizontal(){
            Punto a;
            int i;
            for(i=0;i<60;i++){
                a.setX(i);
                a.Mostrar();
            }
        }
void aleatorio(Punto *vec, int tam){
    srand(time(NULL));
    for(int i=0;i<tam;i++){
       vec[i].setXaleatorio();
       vec[i].setYaleatorio();
      }
}
void punto1(){

    int h=0, v=0;
    Punto obj;
    cout<<"ingrese los valores para x e y :";
    cin>>h;
    cout<<"\n ahora el vertical :";
    cin>>v;
    obj.setX(h);
    obj.setY(v);
    obj.Mostrar();
}
void punto2(){

    int h=0;
    Punto obj;
    cout<<"Difina la posicion del eje y :";
    cin>>h;
    obj.setY(h);
    for(int i=0; i< 50; i++){
        obj.setX(i);
        obj.Mostrar();
    }
}
void punto3(){
    int  v=0;
    Punto obj;
    cout<<"Difina la posicion del eje x :";
    cin>>v;
    obj.setX(v);
    for(int i=0; i< 50; i++){
        obj.setY(i);
        obj.Mostrar();
    }
}
void punto4(){
    int  h=10;
    Punto obj;
    obj.setY(h);
    for(int i=0; i< 50; i++){
        obj.setX(i);
        if(i%2==0){
            obj.setColor(cAMARILLO);
        }else{
            obj.setColor(cAZUL);
        }
        obj.Mostrar();
    }
}
void punto5(){
    int v=15;
    Punto obj;
    obj.setX(v);
    for(int i=0; i< 50; i++){
        obj.setY(i);
        if(i%2==0){
            obj.setColor(cAMARILLO);
        }else{
            obj.setColor(cROJO);
        }
        obj.Mostrar();
    }
}
void punto6(){

    Punto obj;
    obj.setY(1);
    for(int i=0; i< 40; i++){
        obj.setX(i);
             obj.setColor(cAMARILLO);

        obj.Mostrar();

    }
obj.setX(80);
    for(int i=80; i>40; i--){
        obj.setX(i);
        obj.setColor(cAZUL);
        obj.Mostrar();
    }

}
void punto7(){}
void punto8(){}
void punto9(){}
void punto10(){}
void punto11(){}
void punto12(){
    Punto vec[20];
    int i, j;
    aleatorio(vec, 20);
    for(i=0; i<100;i++){
        for(j=0;j<10; j++){
            vec[j].Mostrar();
        }
    }
}
void punto12b(){
    Punto a;
    for(int i=0;i<1000;i++){
        a.setXaleatorio();
        a.setYaleatorio();
        a.Mostrar();

    }
}
void punto13(){
      Punto a;

    while(!kbhit()){
        a.setColorAleatorio();
        a.setXaleatorio();
        a.setYaleatorio();
        a.Mostrar();
    }
}

int main() {
//    probarHorizontal();
//    return 0;
    int opc;
    while(true){
        system("cls");
        cout<<"----------MENU------------"<<endl;
        cout<<"1. DIBUJAR UN PUNTO"<<endl;
        cout<<"2. DIBUJAR UNA LINEA HORIZONTAL"<<endl;
        cout<<"3. DIBUJAR UNA LINEA DE PUNTOS VERTICAL"<<endl;
        cout<<"4. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL QUE ALTERNE 2 COLORES"<<endl;
        cout<<"5. DIBUJAR UNA LINEA DE PUNTOS VERTICAL QUE ALTERNE 2 COLORES"<<endl;
        cout<<"6.   PUNTO 6 hecho "<<endl;
        cout<<"7.   PUNTO 7 "<<endl;
        cout<<"8.   PUNTO 8 "<<endl;
        cout<<"9.   PUNTO 9 "<<endl;
        cout<<"10. PUNTO 10 "<<endl;
        cout<<"11. PUNTO 11"<<endl;
        cout<<"12. PUNTO 12 hecho"<<endl;
        cout<<"13. PUNTO 13 hecho"<<endl;
        cout<<"14. aleatorio "<<endl;
        cout<<" 0. FIN DEL PROGRAMA"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        ocultarCursor();
        switch(opc){
            case 1:punto1();break;
            case 2:punto2(); break;
            case 3: punto3();break;
            case 4: punto4();break;
            case 5:punto5(); break;
            case 6:punto6(); cout<<endl<<endl; break;
            case 7:punto7(); cout<<endl<<endl; break;
            case 8:punto8(); cout<<endl<<endl; break;
            case 9:punto9(); cout<<endl<<endl; break;
            case 10:punto10(); cout<<endl<<endl; break;
            case 11:punto11(); cout<<endl<<endl; break;
            case 12:punto12(); cout<<endl<<endl; break;
            case 13:punto13(); cout<<endl<<endl; break;
            case 0: return 0;
        }
        system("pause");
        mostrarCursor();
    }
    return 0;
}


