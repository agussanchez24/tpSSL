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
int leerArchivoTexto();
int leerArchivoBinario();


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
  
 	char str1[98];
    char str2[98]; 
    sprintf(str1,"%d", num);
    sprintf(str2,"%d", 0);

	for (i =0;  i < ceros ; i++){	
    	strcat(str1,str2);
	}
	numeroADevolver.entero = str1;
    numeroADevolver.longitudError = 1;
	printf("El numero astronomico es (%s, %d)", numeroADevolver.entero, numeroADevolver.longitudError);
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
    return true;
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
