//Programa estruturado para o trabalho final do semestre, que le dados de um arquivo
//e coloca em uma lista encadeada para ser incrementado com as funcionalidades solicitadas
//no enunciado do arquivo da avaliação N2.

#include<stdio.h >
#include<stdlib.h>
#include<conio.h >
#include<ctype.h >
#include<string.h>

typedef struct cad {
        char   nome[40];
        int    idade;
        char   sexo;
        struct cad *prox;
} no;

       FILE *arquivo_cadastro = fopen("cadastro.txt", "r");
       char nome[40], sexo;
       int idade, opcao=1;
       no *inicio;
       no *proximo;
       no *penultimo;
       no *segundo;
       no *primeiro;
       no *ultimo;

       void listar();
       void excluir_ultimo_registro();
       void excluir_primeiro_registro();

main(){
       printf("\n CURSO: SUPERIOR DE TECNOLOGIA EM ANALISE E DESENVOLVIMENTO DE SISTEMAS");
       printf("\n COMPONENTE CURRICULAR: ESTRUTURAS DE DADOS");
       printf("\n PROFESSOR: FRANCK JOY");
       printf("\n ATIVIDADE FINAL DO SEMESTRE - N2 - PESO 6,0 NA NOTA DO SEMESTRE"); 
       printf("\n\n\n ESTE  PROGRAMA  EFETUA  LEITURA DOS  DADOS DE  UM ARQUIVO, ARMAZENANDO\n ESTES DADOS EM UMA LISTA ENCADEADA.");
       printf("\n O CODIGO ESTA  ESTRUTURADO PARA  SER INCREMENTADO  COM AS  RESPECTIVAS\n FUNCOES QUE IMPLEMENTEM AS FUNCIONALIDADES SOLICITADAS NO ENUNCIADO DO\n TRABALHO  FINAL DO SEMESTRE - N2");
       printf("\n\n Use qualquer tecla para iniciar");
       getch();
       inicio = (no *)malloc(sizeof(no));
       ultimo = (no *)malloc(sizeof(no));
       primeiro = (no *)malloc(sizeof(no));
       if (inicio == NULL)
                     exit(1);
       proximo = inicio;              
       if (arquivo_cadastro != NULL){
          while(fscanf(arquivo_cadastro, "%d %c %[^\n]s", &idade, &sexo, nome) != EOF){
                strcpy(proximo->nome, nome);
                proximo->idade = idade;
                proximo->sexo  = sexo;
                proximo->prox = (no *)malloc(sizeof(no));
                proximo = proximo->prox;                
          }
          proximo->prox = NULL;        
          system("cls");
          printf("\n\n\n OS DADOS FORAM LIDOS DO ARQUIVO E ENCADEADOS NA LISTA");
          printf("\n\n LISTAGEM DOS DADOS ENCADEADOS NA LISTA NA SEQUENCIA QUE FORAM LIDOS\n");
          listar();
          printf("\n\nUse qualquer tecla para continuar");
          getch();
          while (opcao != 0) { 
             system("cls");
             printf("\nMENU");
             printf("\n0-Finalizar programa");
             printf("\n1-Excluir   ultimo      registro da lista");
             printf("\n2-Excluir   primeiro    registro da lista");
             printf("\n3-Excluir  determinado  registro da lista");
             printf("\n4-Inserir  registro  no  inicio  da lista");
             printf("\n5-Inserir  registro  no  final  da  lista");
             printf("\n6-Ordenar lista ordem crescente por idade");
             printf("\n7-Listar   dados   encadeados   na  lista");            
             printf("\n\nOpcao: "); scanf("%d", &opcao);
             switch(opcao){
                    case 0:
                         
                    break;
                    case 1:
                         excluir_ultimo_registro();
                    break;
                    case 2:
                         excluir_primeiro_registro();
                    break;
                    case 3:
                         //excluir_determinado_registro();
                    break;
                    case 4:
                         //inserir_registro_inicio();
                    break;
                    case 5:
                         //inserir_registro_final();
                    break;
                    case 6:
                         //ordenar_idade_crescente();
                    break;
                    case 7:
                         listar();
                    break;
                    default:
                            printf("Comando invalido\n\n");
                    }
             }
          }                        
       else
          printf("\n\n PROBLEMA NA ABERTURA DO ARQUIVO\n O PROGRAMA SERA ENCERRADO");
       getch();
       fclose(arquivo_cadastro);
}

//Função para apresentar a lista
void listar(){//Case 7
     printf("\n ESTADO ATUAL DA LISTA\n");
     proximo = inicio;      
     while (proximo->prox != NULL){
           printf("\n **************************\n Nome: %s \n Idade: %2d  \n Sexo: %c", proximo->nome, proximo->idade, proximo->sexo); 
           proximo = proximo->prox;
     }
     getch();
}
void excluir_ultimo_registro(){//Case 1
	proximo = inicio;
	while(proximo->prox != NULL){
		penultimo = proximo;
		proximo = proximo->prox;
	}
	penultimo->prox = NULL;
	proximo = penultimo;
	free(penultimo);
	system("cls");
	printf("\nULTIMO REGISTRO DA LISTA EXCLUIDO ");
	printf("\n\nUse qualquer tecla para iniciar");
    getch();
}
void excluir_primeiro_registro(){//Case 2
	segundo = inicio->prox;
	free(inicio);
	inicio = segundo;
	system("cls");
	printf("\nPRIMEIRO REGISTRO DA LISTA EXCLUIDO ");
	printf("\n\nUse qualquer tecla para iniciar");
    getch();
}
