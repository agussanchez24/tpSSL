#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
int main(){

char *numUno;
numUno = (char *) malloc(101 * sizeof(char));
numUno = "123456";
// char *numDos;
// numDos = (char *) malloc(101 * sizeof(char));
// numDos = "22222";
// int cont = 0;
// while (*numDos != '\0' && *numUno != '\0' )
// {

//     int num1 = *numUno - '0'; //paso a entero
//     int num2 = *numDos - '0';

   
    
//     //printf("%d\n",num1);
   
//     cont = cont + num1;
//     numUno++;
//     numDos++;
    
// }
//printf("%d\n",cont);
    char *numCeros;
    numCeros = (char *) malloc(101 * sizeof(char));
    for(int i=4;i>0;i--){
    strcat(numCeros,"0");
    }
    strcat(numCeros,numUno);
    
   

printf("%s\n",numCeros);
// printf("%c\n",numUno[10]);
// printf("%c\n",numUno[strlen(numUno)-1]);
}

