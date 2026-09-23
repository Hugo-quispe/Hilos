#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void* hilo_funcion(void* arg){
  printf("Hola desde el hilo %ld\n" , (long)arg);
  pthread_exit(NULL);
}
pthread_mutex_ mutex;
void* hilo_funcion_con_mutex(void* arg){
  pthread_mutex_lock(&mutex); //bloquear mutex
  printf("Hola desde el hilo %ld\n", (long)arg);
  pthread_mutex_unlock(&mutex); //Desbloquear mutex
  pthread_exit(NULL);
}
int main(){
  pthread_t hilo1, hilo2;
  
  pthread_mutex_init(&mutex, NULL);//inciar mutex
  pthread_create(&hilo1, NULL, hilo_funcion, (void*) 1);
  pthread_create(&hilo2, NULL, hilo_funcion, (void*) 2);
  
  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);
  pthread_mutex_destroy(&mutex);//Destruir mutex
  
  printf("Finalizo la ejecucion del programa principal\n");
  return 0;
  //ejecucion con tiempo
}
