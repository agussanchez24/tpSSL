#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


typedef struct {
    char* entero;
    int longitudError;
} numeroAstronomico;

numeroAstronomico suma(numeroAstronomico, numeroAstronomico);
char agregarCerosIzq(char *,int);

char agregarCerosIzq(char *cadena,int cant){
    if(cant == 0){
        return(cadena);
    }
    char *numCeros;
    numCeros = (char *) malloc(101 * sizeof(char));
    for(int i=cant;i>0;i--){
    strcat(numCeros,"0");
    }
    strcat(numCeros,cadena);
    return(numCeros);
}


numeroAstronomico suma(numeroAstronomico numeroAstronomicoUno, numeroAstronomico numeroAstronomicoDos){
    numeroAstronomico resultadoAstronomico;

    char *resultadoAstro;
    resultadoAstro = (char *) malloc(101 * sizeof(char));

    char *numUno;
    numUno = (char *) malloc(101 * sizeof(char));
    numUno = numeroAstronomicoUno.entero;

    char *numDos;
    numDos = (char *) malloc(101 * sizeof(char));
    numDos = numeroAstronomicoDos.entero;

    char carry = '0';
    int i = 0;
    int lenUno = strlen(numUno);
    int lenDos = strlen(numDos);
    if(lenUno >= lenDos){  //aca falta arreglar. para que funcione bien los dos numeros tienen que quedar parejos (ej: 0923 y 0003) 
        i = lenUno-1;
        int dif = lenUno - lenDos;
        agregarCerosIzq(numDos,dif+1);
	    agregarCerosIzq(numUno,1);
    }else{
        i = lenDos-1;
        int dif = lenDos - lenUno;
        agregarCerosIzq(numUno,dif+1);
        agregarCerosIzq(numDos,1);
        }
        
    for(i;i>=0;i--){ 

        int num1 = numUno[i] - '0';
        int num2 = numDos[i] - '0';

        if(!isdigit(numUno[i])){
            num1 = 0;
        }
        if(!isdigit(numDos[i])){
            num2 = 0;
        }
    

        if(carry == '0'){
            
            int res = (num1 + num2);
            char carryTemp[1];
            char resultado[2];
            if(res >= 10){
                res = res/10;
                int carryNum = (num1 + num2)%10;
                carry = 48 + carryNum; 
            }
            
            char *numInv;
            numInv = (char *) malloc(101 * sizeof(char));
            sprintf(resultado,"%d",res);
            strcpy(numInv,resultado);
            strcat(numInv,resultadoAstro);
            strcpy(resultadoAstro, numInv);
            free(numInv);
            
            
        }else
        {
            
            int carryNum = carry - '0';
            int res = (num1 + num2 + carryNum);
            char carryTemp[1];
            char resultado[2];
            if(res >= 10){
                res = res/10;
                int carryNum = (num1 + num2)%10;
                carry = 48 + carryNum; 
                
            }else{
                carry = '0';
            }
            //printf("%d\n",res);
            char *numInv;
            numInv = (char *) malloc(101 * sizeof(char));
            sprintf(resultado,"%d",res);
            strcpy(numInv,resultado);
            strcat(numInv,resultadoAstro);
            strcpy(resultadoAstro, numInv);
            free(numInv);

        }
       
    }
    // resultadoAstronomico.entero = resultadoAstro;
    // return(resultadoAstronomico);
    printf("%s\n",resultadoAstro);
    
}


int main(){
    
    numeroAstronomico astroUno;
    numeroAstronomico astroDos;
    astroUno.entero = "020";
    astroDos.entero = "900";
    suma(astroUno,astroDos);
    return 0;
}
