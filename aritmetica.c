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
bool esMenor(numeroAstronomico,numeroAstronomico);
bool sonIguales(numeroAstronomico,numeroAstronomico);
char* agregarCerosIzq(char *,int);

char* agregarCerosIzq(char *cadena,int cant){
    if(cant != 0){
        //char *numCeros;
        char *numCeros = (char *) malloc(101 * sizeof(char));
        //numCeros = "";
        for(int i=cant;i>0;i--){
        strcat(numCeros,"0");
        }
        strcat(numCeros,cadena);
        //printf("%s\n",numCeros);
        return(numCeros);
    }
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

    int carry = 0;
    int i = 0;
    int lenUno = strlen(numUno);
    int lenDos = strlen(numDos);
    int dif = abs(lenUno - lenDos);
    if(lenUno >= lenDos){  
        
        numDos = agregarCerosIzq(numDos,dif+1);
	    numUno = agregarCerosIzq(numUno,1);
    }else{
        
        numUno = agregarCerosIzq(numUno,dif+1);
        numDos = agregarCerosIzq(numDos,1);
        }
    i = strlen(numUno)-1;//ahora las dos longitudes son son iguales
    for(i;i>=0;i--){ 

        int num1 = numUno[i] - '0';
        int num2 = numDos[i] - '0';

        if(carry == 0){
            
            int res = (num1 + num2);
            char resultado[2];
            if(res >= 10){
                res = res%10;
                carry = (num1 + num2)/10;
            
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
            

            int res = (num1 + num2 + carry);
            char resultado[2];
            if(res >= 10){
                res = res%10;
                carry = (num1 + num2 + carry)/10;

            }else{
                carry = 0;
            }
           
            char *numInv;
            numInv = (char *) malloc(101 * sizeof(char));
            sprintf(resultado,"%d",res);
            strcpy(numInv,resultado);
            strcat(numInv,resultadoAstro);
            strcpy(resultadoAstro, numInv);
            free(numInv);

        }
       
    }
    resultadoAstronomico.entero = resultadoAstro;
    return(resultadoAstronomico);
    
    
}

bool esMenor(numeroAstronomico numeroAstronomicoUno, numeroAstronomico numeroAstronomicoDos){
    
    char *numUno;
    numUno = (char *) malloc(101 * sizeof(char));
    numUno = numeroAstronomicoUno.entero;

    char *numDos;
    numDos = (char *) malloc(101 * sizeof(char));
    numDos = numeroAstronomicoDos.entero;

    int lenUno = strlen(numUno);
    int lenDos = strlen(numDos);

    if(lenUno==lenDos){
        while(*numUno != '\0'){

            int num1 = *numUno - '0';
            int num2 = *numDos - '0';
            if(num1!=num2){
                return(num1<num2);
            }
            numDos++;
            numUno++;
        }
    }else{
        return(lenUno<lenDos);
    }
}

bool sonIguales(numeroAstronomico numeroAstronomicoUno, numeroAstronomico numeroAstronomicoDos){

char *numUno;
    numUno = (char *) malloc(101 * sizeof(char));
    numUno = numeroAstronomicoUno.entero;

    char *numDos;
    numDos = (char *) malloc(101 * sizeof(char));
    numDos = numeroAstronomicoDos.entero;

    int lenUno = strlen(numUno);
    int lenDos = strlen(numDos);

    if(lenUno==lenDos){
        while(*numUno != '\0'){

            if(*numUno != *numDos){
                return(false);
            }
            numDos++;
            numUno++;
        }return(true);
    }else{
        return(false);
    }
}


int main(){

    numeroAstronomico astroUno;
    numeroAstronomico astroDos;
    numeroAstronomico astroRes;
    astroUno.entero = "5";
    astroDos.entero = "3";
    bool res = esMenor(astroUno,astroDos); //OK
    bool sonIng = sonIguales(astroUno,astroDos); //Ok
    astroRes = suma(astroUno,astroDos); //Ok
    
    printf("%s\n", astroRes.entero);
    return(0);
}