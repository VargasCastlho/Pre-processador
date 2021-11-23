#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "locale.h"


void clone(FILE *arq_original, FILE *arq_destino);
void pre_processador(FILE *arq_original,FILE *arq_destino);
void comentarios(char *vet);
char *leitura(FILE *arq,char *vet);

int main(){
    FILE *origem,*destino;
    origem = fopen("arquivo_entrada.c","r");

    if(origem == NULL)
        printf("Não existe arquivo de origem\n");
    else{
        destino = fopen("arquivo_pre_processado.c","a");
        pre_processador(origem,destino);

    }


    fclose(destino);
    return 0;
}

void comentarios(char *vet){
    if((*vet) == '/'){
        if((*vet+1) == '/'){
            while(1){
                if(*vet!='\n'){
                    vet = '';
                }
                break;
            }
        }
        if((*vet+1) == '*'){
            while(1){
                if((*vet)!='*'&& (*vet+1) != '/'){
                    (*vet) = '';
                }
                else
                    if((*vet) == '*' && (*vet+1) != '/')
                        vet = '';
                break;
            }
        }
    }
    else
        comentarios(vet+1);

}

char *leitura(FILE *arq,char *vet){
    fseek(arq,0,SEEK_END);
    long dimensao = ftell(arq);
    fseek(arq,0,SEEK_SET);
    vet = (char*) malloc((dimensao+1)*sizeof(char));

    if(vet){
        fread(vet,1,dimensao,arq);
        vet[dimensao] ='\0';
    }
    return vet;
}



void pre_processador(FILE *arq_original,FILE *arq_destino){
    char conteudo,*vet;
    vet = leitura(arq_original,vet);
    fclose(arq_original);


}

