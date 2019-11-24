#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <mpi.h>


void comunicacion(int pid,int estadoActual,MPI_Comm celula, MPI_Status stat ){
int estadoActual;
int vecinos=0;
fuente=pid-7;
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







int main(int argc, char **argv){
  int i,j,np,pid,iteraciones;
  int **matriz;
  int buffer[49];
  printf("Juego de la vida:\n");
  MPI_Status stat;
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&pid);
  MPI_Comm_size(MPI_COMM_WORLD,&np);

//iniciando tablero
if(np<=1){
 printf("Ño\n");

}
else
{
printf("Ingresa las iteraciones que quieres realizar:");
scanf("%d",&iteraciones);
for(k=0;k<=iteraciones;k++){
  //SCATTER
  comunicacion(pid,buffer[pid],MPI_COM_WORLD , MPI_Status stat);


}



}


MPI_finalize();
return 0;

}
