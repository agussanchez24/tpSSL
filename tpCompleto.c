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

enum tipoError           
{
    sinError,       
    cadenaNula,     
    cadenaInvalida,        
    overflow
} errores;

numeroAstronomico crearDesdeCadena(char *);
numeroAstronomico crearDesdeCifraSeguidaDeCeros(int, int);
numeroAstronomico crearAleatorio();
bool esSecuenciaNula(numeroAstronomico);
bool esSecuenciaInvalida(numeroAstronomico);
bool esOverflow(numeroAstronomico);
void getTipoDeError(numeroAstronomico);
bool esError(numeroAstronomico numeroAstronomicoAEvaluar);
numeroAstronomico suma(numeroAstronomico, numeroAstronomico);
bool esMenor(numeroAstronomico,numeroAstronomico);
bool sonIguales(numeroAstronomico,numeroAstronomico);
int leerArchivoTexto();
int leerArchivoBinario();
char* agregarCerosIzq(char *,int); //funcion auxiliar 

// OK
numeroAstronomico crearDesdeCadena(char *cadenaAImprimir){

    char *cadena;
    numeroAstronomico numeroADevolver;
    cadena = (char *) malloc(101 * sizeof(char));
    cadena = cadenaAImprimir;
    numeroADevolver.entero = cadena;
    numeroADevolver.longitudError = strlen(cadena);
    printf("El numero astronomico es (%s, %d)", cadena, numeroADevolver.longitudError);
    free(cadena);
    return numeroADevolver;
}

//OK
numeroAstronomico crearDesdeCifraSeguidaDeCeros(int num, int ceros){

    numeroAstronomico numeroADevolver;
    int i;
  
 	char str1[100];
    char str2[100]; 
    sprintf(str1,"%d", num);
    sprintf(str2,"%d", 0);

	for (i =0;  i < ceros ; i++){	
    	strcat(str1,str2);
	}
	numeroADevolver.entero = str1;
    numeroADevolver.longitudError = 1;
	printf("El numero astronomico es (%s, %d)", numeroADevolver.entero, numeroADevolver.longitudError);

    if(esOverflow(numeroADevolver)){
        numeroADevolver.entero  = "0";
        getTipoDeError(numeroADevolver);
    return numeroADevolver;
}

//OK
numeroAstronomico crearAleatorio() {
  
  numeroAstronomico numeroADevolver;
  int randomNum;
  int i, int1;
  char str1[98];
  char str2[98]; 
  
  srand(time(0));
  int1 = rand() % 99;
  sprintf(str1,"%d", int1);
  
  for (i = 1; i < 44; i++) {	
	randomNum = rand() % 99;
	sprintf(str2,"%d", randomNum);
	strcat(str1,str2);	
  }
  
  numeroADevolver.entero = str1;
  numeroADevolver.longitudError = 1;
  printf("El numero astronomico es (%s, %d)", numeroADevolver.entero, numeroADevolver.longitudError);
}

//OK
bool esSecuenciaNula(numeroAstronomico numeroAstronomicoAEvaluar){

    numeroAstronomico numAstronomico = numeroAstronomicoAEvaluar;
    if (strlen((char *) numAstronomico.entero) == 0){
        printf("La secuencia es nula");
    } else printf ("La secuencia no es nula");
    return strlen(numAstronomico.entero) == 0;
}

//OK
bool esSecuenciaInvalida(numeroAstronomico numeroAstronomicoAEvaluar){
    char *cadena;
    cadena = (char *) malloc(101 * sizeof(char));
    cadena = numeroAstronomicoAEvaluar.entero;
    int i = 0;
    bool flag = false;
    while (*cadena != '\0'){
        if (!(isdigit(*cadena))){
            flag = true;
            printf("La cadena es invalida");
            return flag;
        }
        cadena++;        
    }
    printf("La cadena es valida");
    return flag;
}

// ¿?
bool esOverflow(numeroAstronomico numeroAstronomicoAEvaluar){
    char *cadena;
    cadena = (char *) malloc(101 * sizeof(char));
    cadena = numeroAstronomicoAEvaluar.entero;
    return (strlen(cadena) > 100);
}

//REVISAR
bool esPunteroNulo(int* puntero){
	
	if (puntero == NULL)
		return true;
	else
		return false;
}

//REVISAR
void getTipoDeError(numeroAstronomico numeroAstronomicoAEvaluar){

    const char *error = "Ningun error";

    if(esSecuenciaInvalida(numeroAstronomicoAEvaluar)){
        error = "cadenaInvalida";
    } else if (esSecuenciaNula(numeroAstronomicoAEvaluar)){
        error = "cadenaNula";
    } else if (esOverflow(numeroAstronomicoAEvaluar)){
        error = "overflow";
    }
    printf("%s", error);
}

//OK
bool esError(numeroAstronomico numeroAstronomicoAEvaluar){
    return (esSecuenciaNula(numeroAstronomicoAEvaluar) || esSecuenciaInvalida(numeroAstronomicoAEvaluar) || esOverflow(numeroAstronomicoAEvaluar));
}

void mostrar(char *line, int cantidad)
{
	
	int i, x;
	int posicionactual = cantidad*3;
	int posicionpunto = 1;

  //imprimo tantos strings de 3 numeros como cantidad pase como parametro. 
  //cada 3 posiciones imprimo un punto, si es que no lleguC) a la cantidad max (para que no quede al final).

	
	for (i = 0; i < cantidad * 3; i++){
      printf ("%c", line[i]);
      if (posicionpunto == 3 && i < (cantidad * 3) - 1)	{
		printf (".");
		posicionpunto = 0;
	  }
    posicionpunto++;
    }
	printf ("\n");
	posicionpunto = 1;

  //mientras el numero astronomico exista, devuelvo strings de 3 numeros
  //siendo la cantidad 1 unidad menos a lo que pase por parametro en cada linea
  
  

    while (line[posicionactual] != '\0'){
      for (x = 0; x < (cantidad - 1) * 3; x++){
      	if(line[posicionactual] != '\0'){
	    printf ("%c", line[posicionactual]);
	    posicionactual++;
	    if (posicionpunto == 3 && x < ((cantidad - 1) * 3) - 1){
	        printf (".");
            posicionpunto = 0;
	    }
	    posicionpunto++;
    }
    }
    posicionpunto = 1;
    printf ("\n");
    }
}

numeroAstronomico suma(numeroAstronomico numeroAstronomicoUno, numeroAstronomico numeroAstronomicoDos){
    numeroAstronomico resultadoAstronomico;
    
    char *resultadoAstro;
    resultadoAstro = (char *) malloc(101 * sizeof(char));

    if(esError(numeroAstronomicoUno) || esError(numeroAstronomicoDos)){
        printf("%s", "Numero astronomico 1: ");
        getTipoDeError(numeroAstronomicoUno);
        printf("%s", "Numero astronomico 2: ");
        getTipoDeError(numeroAstronomicoDos);
        resultadoAstronomico.entero = "0"; //resultado de la suma es 0 e imprimer el error 
        return(resultadoAstronomico); 
    }

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
    if(esOverflow(resultadoAstronomico)){
        resultadoAstronomico.entero  = "0";
        getTipoDeError(resultadoAstronomico);
    }
    return(resultadoAstronomico);
}

bool esMenor(numeroAstronomico numeroAstronomicoUno, numeroAstronomico numeroAstronomicoDos){

    if(esError(numeroAstronomicoUno) || esError(numeroAstronomicoDos)){
        printf("%s", "Numero astronomico 1: ");
        getTipoDeError(numeroAstronomicoUno);
        printf("%s", "Numero astronomico 2: ");
        getTipoDeError(numeroAstronomicoDos);
        return(false); 
    }

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

    if(esError(numeroAstronomicoUno) || esError(numeroAstronomicoDos)){
        printf("%s", "Numero astronomico 1: ");
        getTipoDeError(numeroAstronomicoUno);
        printf("%s", "Numero astronomico 2: ");
        getTipoDeError(numeroAstronomicoDos);
        return(false); 

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


int leerArchivoTexto(){

	FILE *fp;

    fp = fopen("numeroAstronomico.txt","r");
    
    if	(fp == NULL){
	
	perror ("Error en la apertura del archivo");
	return 1;
	}
	char character;
	
	printf("\nLa cadena leida en el archivo es:\n");
	while (feof(fp) == 0) {
	
	character = fgetc(fp);
	
	if(character == 35) //este numero representa a # en ASCII
		break;
	else
	printf("%c", character);

}

}


int leerArchivoBinario(){

	FILE *fp;

    fp = fopen("numeroAstronomico.txt","rb");
    
    if	(fp == NULL){
	
	perror ("Error en la apertura del archivo");
	return 1;
	}
	char character;
	
	printf("\nLa cadena leida en el archivo es:\n");
	while (feof(fp) == 0) {
	
	character = fgetc(fp);
	
	if(character == 35)
		break;
	else
	printf("%c", character);

}

}



int main(){
//    numeroAstronomico astron;
//    astron.entero = "352asd35";
//    astron.longitudError = 2;
//   crearDesdeCifraSeguidaDeCeros(1234, 22);
//  mostrar("123456782345678912345678912312233456123456123456123", 4);
    return 0;
}