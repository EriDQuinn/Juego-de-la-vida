#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <mpi.h>


void comunicacion(int pid,int estadoActual,MPI_Comm celula, MPI_Status stat ){
//int estadoActual;
int vecinos=0;
int fuente=pid-7;
//Empieza recibir
MPI_Recv(&estadoAd,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD,&stat);
   printf("P %d recibe de P%d estado: %c\n",pid,fuente,estadoAd);
  if (estadoAd==1){
    vecinos++;
  }
  //Empieza a enviar su estado actual
  MPI_Send(&estadoActual,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD);
   printf("P %d recibe de P%d estado: %c\n",pid,fuente,estadoAd);
   printf("P %d envia a P%d estado: %c\n",pid,fuente,estadoActual);
   
  fuente=pid-6;
  MPI_Recv(&estadoAd,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD,&stat);
   printf("P %d recibe de P%d estado: %c\n",pid,fuente,estadoAd);
    if (estadoAd==1){
    vecinos++;
  }
   MPI_Send(&estadoActual,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD);
   printf("P %d envia a P%d estado: %c\n",pid,fuente,estadoActual);
   
fuente=pid-5;
  MPI_Recv(&estadoAd,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD,&stat);
   printf("P %d recibe de P%d estado: %c\n",pid,fuente,estadoAd);
    if (estadoAd==1){
    vecinos++;
  }
  MPI_Send(&estadoActual,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD);
   printf("P %d envia a P%d estado: %c\n",pid,fuente,estadoActual);
   
fuente=pid-1;
  MPI_Recv(&estadoAd,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD,&stat);
   printf("P %d recibe de P%d estado: %c\n",pid,fuente,estadoAd);
    if (estadoAd==1){
    vecinos++;
  }
  MPI_Send(&estadoActual,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD);
   printf("P %d envia a P%d estado: %c\n",pid,fuente,estadoActual);
   
fuente=pid+1;
  MPI_Recv(&estadoAd,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD,&stat);
   printf("P %d recibe de P%d estado: %c\n",pid,fuente,estadoAd);
    if (estadoAd==1){
    vecinos++;
  }
  MPI_Send(&estadoActual,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD);
   printf("P %d envia a P%d estado: %c\n",pid,fuente,estadoActual);
   
fuente=pid+5;
  MPI_Recv(&estadoAd,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD,&stat);
   printf("P %d recibe de P%d estado: %c\n",pid,fuente,estadoAd);
    if (estadoAd==1){
    vecinos++;
  }
  MPI_Send(&estadoActual,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD);
   printf("P %d envia a P%d estado: %c\n",pid,fuente,estadoActual);
   
fuente=pid+6;
  MPI_Recv(&estadoAd,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD,&stat);
   printf("P %d recibe de P%d estado: %c\n",pid,fuente,estadoAd);
    if (estadoAd==1){
    vecinos++;
  }
  MPI_Send(&estadoActual,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD);
   printf("P %d envia a P%d estado: %c\n",pid,fuente,estadoActual);
   
fuente=pid+7;
  MPI_Recv(&estadoAd,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD,&stat);
   printf("P %d recibe de P%d estado: %c\n",pid,fuente,estadoAd);
    if (estadoAd==1){
    vecinos++;
  }
  MPI_Send(&estadoActual,1, MPI_INT,fuente,&etiqueta,MPI_COMM_WORLD);
   printf("P %d envia a P%d estado: %c\n",pid,fuente,estadoActual);
   






}//end comunicacion

void imprimir_tablero(){
   int i,j;
   for(i=0;i<7;i++){
         for(j=0;j<7;j++){
            printf("\t %i",matriz[i][j]);
         }
      printf("\n");
       }

 }





int main(int argc, char **argv){
  int i,j,np,pid,iteraciones;
  int **matriz,**matrizAct;
  int buffer[36];
  double Ti,Tf;
  printf("Juego de la vida:\n");
  MPI_Status stat;
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&pid);
  MPI_Comm_size(MPI_COMM_WORLD,&np);

//iniciando tablero
if(np<=1){
 printf("Ño\n");
 printf("Ño\n");
}
else
{
   printf("Ingresa las iteraciones que quieres realizar:");
   scanf("%d",&iteraciones);
   //Creando tablero
      matriz=(int**)malloc(6*sizeof(int *));
      for(i=0;i<7;++){
         *(matriz+i)=(int *)malloc(6*sizeof(int));
      }
      matrizAct=(int**)malloc(6*sizeof(int *));
      for(i=0;i<7;++){
          *(matrizAct+i)=(int *)malloc(6*sizeof(int));
      }
    //llenando tablero
       for(i=0;i<7;i++){
         for(j=0;j<7;j++){
            matriz[i][j]=rand()%2;
         }
       }
      imprimir_tablero(matriz);
      Ti=MPI_Wtime();
      for(k=0;k<=iteraciones;k++){
        //SCATTER
        printf("P0--> Enviando datos a P%i:"pid); 
        MPI_Scatter(matriz,36,MPI_INT,&buffer1[pid],36,MPI_INIT,0,MPI_COMM_WORLD);//podria el buffer ir sin &


        imprimir_tablero();
        comunicacion(pid,buffer[pid],MPI_COM_WORLD , MPI_Status stat);
        //actualiza_tablero();
    }//fin iteraciones
    Tf=MPI_Wtime();
   
}//fin else

printf("Tiempo de ejecucion: %f",Ti-Tf);
MPI_Finalize();
return 0;

}
