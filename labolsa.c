#include <stdio.h>
#include <stdlib.h>
#include "help.h"
#include "user.h"
#include "stock.h"

int main(int argn, char**argv){
  User *user;
  Stock *stock;
  char code[8];
  int i,N,M;

  //printf("%i\n", argn);
  if (argn > 2){
    sscanf(argv[1], "%i", &N); //función para transformar strings a otro que tu le asignes
    sscanf(argv[2], "%i", &M); 

    user = malloc(sizeof(User)*N);
    stock = malloc(sizeof(Stock)*M);
    printf("La bolsa simulator versión 28082024-1056\n");
    printf("Generating %i users...",N);

    for(i=0; i<N; i++){
      user[i] = newUser(i,1000.00);
    }
    printf("Ready!\n");
    printf("Memory used: %lu Bytes\n",sizeof(user[0])*N);
    printf("Memory used: %lu Kb\n",sizeof(user[0])*N/1000);
    printf("Generating stock...");

    for(i=0; i<M; i++){
      sprintf(code, "MEX%i",i);
      stock[i] = newStock(code,1000.00);
    }
    printf("Ready\n");
    printf("%s:%f\n",stock[0].code, stock[0].price);
  }
  else{
    print_help();

  }
  free(user);
  free(stock);
  return 0;
}

