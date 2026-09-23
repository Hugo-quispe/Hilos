#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex;
void* hilo_funcion1(void* arg){
  printf("Hola desde el hilo %ld\n" , (long)arg);
  pthread_exit(NULL);
}

void* hilo_funcion_con_mutex(void* arg){
  pthread_mutex_lock(&mutex); //bloquear mutex
  printf("Hola desde el hilo %ld\n", (long)arg);
  pthread_mutex_unlock(&mutex); //Desbloquear mutex
  pthread_exit(NULL);
}

void* hilo_funcion2(void* arg){
  pthread_mutex_lock(&mutex); //bloquear mutex
  printf("Hola desde el hilo %ld\n" , (long)arg);
  pthread_mutex_unlock(&mutex); //Desbloquear mutex
  pthread_exit(NULL);
}

void ejecutar_con_hilos2(int num_hilos){
  pthread_t hilos[num_hilos];
  pthread_mutex_init(&mutex, NULL);//inciar mutex
  
  //medicion de tiempo
  clock_t start, end;
  start = clock();
  
  for (long i = 0; i < num_hilos; i++){
    pthread_create(&hilos[i], NULL, hilo_funcion2, (void*)i);
  }
  for (int i = 0; i < num_hilos; i++){
    pthread_join(
    hilos[i],NULL);
  }
  
  end = clock(); //fin del temporizador
  pthread_mutex_destroy(&mutex);//Destruir mutex
  double cpu_time_used =((double)(end - start))/CLOCKS_PER_SEC;
  printf ("tiempo total de ejecucion con %d hilos: %f segundo\n", num_hilos, cpu_time_used);
    
}

int main(){
  printf("ejecucion con 1 hilo...\n");
  ejecutar_con_hilos2(1);
  printf("ejecucion con 5 hilo...\n");
  ejecutar_con_hilos2(5);
  printf("ejecucion con 10 hilo...\n");
  ejecutar_con_hilos2(10);
  
  printf("Finalizo la ejecucion de programa principal\n");
  return 0;
  //ejecucion con tiempo
}
