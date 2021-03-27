//CONTAR REGISTROS
//PEDIR MEMORIA PARA UN VECTOR DE STRUCT ARTICULOS
// DE IGUAL CANTIDAD DE REGISTROS QUE EL ARCHIVO
//COPIAR EL ARCHIVO EN EL VECTOR
//ORDENAR EL VECTOR POR EL CAMPO ELEGIDO
//MOSTRAR EL VECTOR ORDENADO
//LIBERAR LA MEMORIA PEDIDA


//Ejercicio:
//Autor:DEK
//Fecha:14/04/2011
//Comentario: Leer los registros del archivo de articulos, guardarlos en un vector
// y luego mostrar el vector, ordenarlo por descripción y volver a mostrarlo.
//No se sabe la cantidad de registros, asi que hay que
//asignar dinámicamente la memoria a un vector luego de contar la cantidad de registros
//También se muestra una función para ordenar directamente un archivo sin llevar los registros a la memoria
//Se incluye también la función qsort() que es de la librería cstdlib, y que
//ordena vectores de cualquier tipo. Para usarla se necesita hacer una función,
// para adecuar el tipo de datos del vector, y enviarla como parámetro

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct articulo
  {
  char cod[5];
  char desc[30];
  float pu;
  int stock;
  bool activo;
  };

long contarRegistros();
void mostrarVector(struct articulo *, long);
void copiarArchivoMemoria(struct articulo *, long);
void ordenarVector(struct articulo *, long);
void ordenar_archivo();

//FUNCION QUE SE ENVIA COMO PARAMETRO A qsort()

int comparacionDesc(const void *i, const void *j) {
    articulo *reg1=(articulo *)i;
    articulo *reg2=(articulo *)j;
    return strcmp(reg1->desc,reg2->desc)*(-1);
}
////////////////////////////////////////
int main()
{
  struct articulo *vec;
  long cant;
  cant=contarRegistros();//se calcula la cantidad de registros del archivo
  vec=(struct articulo *) malloc(cant*sizeof(struct articulo));// se asigna memoria para construir el vector
  if(vec==NULL) return 1;//Si el vector contiene NULL significa que no se pudo asignar memoria
  ////////////////////////
  copiarArchivoMemoria(vec,cant);//se copia el contenido completo del archivo en el vector
  cout<<"VECTOR SIN ORDENAR:"<<endl;
  mostrarVector(vec,cant);// se muestra el vector sin ordenar
//  cout<<endl<<endl;
  system("pause");
  system("cls");
  ordenarVector(vec,cant);// se ordena el vector
//  qsort(vec, cant, sizeof(articulo), comparacionDesc);
  cout<<"VECTOR ORDENADO POR DESCRIPCION:"<<endl;
  mostrarVector(vec,cant);// se muestra el vector ordenado
  free(vec);// se libera la memoria
  return 0;
}

void mostrarVector(struct articulo *v, long cant)
{
  int i;
  for(i=0;i<cant;i++)
  {
    cout<<"CODIGO: ";
    cout<<v[i].cod<<endl;
    cout<<"DESCRIPCION: ";
    cout<<v[i].desc<<endl;
    cout<<"PRECIO UNITARIO: ";
    cout<<v[i].pu<<endl;
    cout<<"STOCK: ";
    cout<<v[i].stock<<endl;
    system("pause");
    }
}

void copiarArchivoMemoria(struct articulo *v,long cant)
{
  FILE *part;
  part=fopen("articulo.dat","ab");
  if(part==NULL)
    {
      cout<<"Error de archivo";
      exit(1);
      }
  fread(v, sizeof(struct articulo),cant,part);
  fclose(part);
  }

long contarRegistros()
{
  FILE *part;
  long cantbyte;
  part=fopen("articulo.dat","rb");
  if(part==NULL)
    {
      cout<<"Error de archivo";
      exit(1);
      }
  fseek(part,0,2);
  cantbyte=ftell(part);
  fclose(part);
  return cantbyte/sizeof(struct articulo);
  }

/*Otra forma leyendo de a 1 registro)*/
/*void leer_archivo(struct articulo * v, long cant)
{
  FILE *part;
  int i;
  part=fopen("articulo.dat","rb");
  if(part==NULL)
    {
      cout<<"Error de archivo";
      exit(1);
      }
   for(i=0;i<cant;i++)
      fread(v+i, sizeof(struct articulo),1,part);// o &v[i]

  fclose(part);
}*/

void ordenarVector(struct articulo *v, long cant)
{
  int i, j, posmin;
  struct articulo aux;
  for(i=0;i<cant-1;i++)
    {
      posmin=i;
      for(j=i+1;j<cant;j++){
//        if(strcmp(v[posmin].desc,v[j].desc)>0)
        if(v[posmin].pu>v[j].pu)
                posmin=j;
      }
      aux=v[i];
      v[i]=v[posmin];
      v[posmin]=aux;
    }

  }

//USANDO EL MISMO ALGORTIMO DE ORDENAMIENTO SE ORDENA EL ARCHIVO
void ordenarArchivo()
{
  int i=0, j, posmin;
  long cant;
  struct articulo aux,reg1, reg2;
  FILE *p;
  cant=contarRegistros();
  p=fopen("articulo.dat","rb+");
  if(p==NULL) exit(1);

  for(i=0;i<cant-1;i++)
    {
      fseek(p,sizeof(struct articulo)*i,0);
      fread(&reg1, sizeof reg1, 1, p);
      posmin=i;
      for(j=i+1;j<cant;j++)
        {
        fseek(p,sizeof(struct articulo)*j,0);
        fread(&reg2, sizeof reg2, 1, p);
        if(strcmp(reg1.desc,reg2.desc)>0)
          {
          posmin=j;
          reg1=reg2;
          }
        }
      fseek(p,sizeof(struct articulo)*i,0);
      fread(&aux, sizeof reg1, 1, p);
      fseek(p,sizeof(struct articulo)*i,0);
      fwrite(&reg1,sizeof reg1, 1, p);
      fseek(p,sizeof(struct articulo)*posmin,0);
      fwrite(&aux,sizeof aux, 1, p);
    }
  fclose(p);
  }
