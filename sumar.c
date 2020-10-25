#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *sumar(char *num_uno,char *num_dos){
    char result[102];
    char carry = num_uno[0];
    
    for(int i = 4;i!=1;i--){
        
        if(carry == '0'){
            int num1 = num_uno[i] - '0';
            int num2 = num_dos[i] - '0';
            int res = (num1 + num2);
            char carryTemp[1];
            char resultado[2];
            if(res >= 10){
                res = res/10;
                int carryNum = (num1 + num2)%10;
                carry = 48 + carryNum; 
            }
            //const char resultado = 48 + res; //48 es '0'
            sprintf(resultado,"%d",res);
            strcat(result,resultado);
            //printf("%c\n",resultado);
            
        }else
        {
            int num1 = num_uno[i] - '0';
            int num2 = num_dos[i] - '0';
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
            //char resultado = 48 + res; //48 es '0'
            //strcat(result,resultado);
            sprintf(resultado,"%d",res);
            strcat(result,resultado);
            //printf("%c\n",resultado);

        }
        
    }
    printf("%s\n",result);
    //return(result);
}


int main(){
    char num_uno[] = "00123";
    char num_dos[] = "00018";
    sumar(num_uno,num_dos);
    
return 0;
}