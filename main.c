#include <stdio.h>
#include "stdlib.h"
#include <ctype.h>
#include "locale.h"


void clone(FILE *arq_original, FILE *arq_destino);
void pre_processador(FILE *arq_destino);
void str_trim(char *trim_origem,char *trim_destino);
void comentarios(FILE *arq);

int main(){
    char conteudo, auxiliar[100], arq_original[100],arq_destino[100];
    FILE *origem,*destino;

    printf("Arquivo de origem\n> ");
    fgets(auxiliar,100,stdin);
    str_trim(auxiliar,arq_original);
    origem = fopen(arq_original,"r");

    if(origem == NULL)
        printf("Não existe arquivo de origem\n");
    else{
        printf("Arquivo de destino:\n> ");
        fgets(arq_destino,100,stdin);
        destino = fopen(arq_destino,"w");
        clone(origem,destino);
        fclose(origem);
        fclose(destino);
        destino = fopen(arq_destino,"a");
    }


    fclose(destino);
    return 0;
}

void clone(FILE *origem, FILE *destino){
    char conteudo;
    int linhas = 0, linha_atual = 0;
    while((conteudo = fgetc(origem))!=EOF)
        linhas++;

    rewind(origem);

    while((conteudo = fgetc(origem))!= EOF){
        fputc(conteudo, destino);
    }
    printf("\nArquivo copiado com sucesso\n\n");

}

void str_trim(char *trim_origem, char *trim_destino) {
    int flag = 0;


    while(*trim_origem){
        if(!isspace((unsigned char) *trim_origem) && flag == 0) {
            *trim_destino++ = *trim_origem;
            flag = 1;
    }


        trim_origem++;
        if(flag == 1)
            *trim_destino++ = *trim_origem;

    }


    while(1){
        trim_destino--;
        if(!isspace((unsigned char) *trim_destino) && flag == 0) {
            break;
        }
        flag = 0;
        *trim_destino = '\0';
    }
}

void comentarios(FILE *arq){
    char conteudo = fgetc(arq);
    if(conteudo == '/'){
        comentarios(arq);
        if(conteudo == '/'){
            while((conteudo = fgetc(arq))!= '\n'){

            }
        }
    }
    else
        comentarios(arq);
}


void pre_processador(FILE *arq_destino){
    comentarios(arq_destino);
    rewind(arq_destino);
}

