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
       int ind,extremo2=0;
       bool flag;
       no *inicio;
       no *proximo;
       no *penultimo;
       no *aux;
       no *anterior;
       no *final;
       void listar();
       void excluir_ultimo_registro();
       void excluir_primeiro_registro();
       void excluir_determinado_registro();
       void inserir_registro_inicio();
       void inserir_registro_final();
       void ordenar_idade_crescente();

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
                         exit(1);
                    break;
                    case 1:
                         excluir_ultimo_registro();
                    break;
                    case 2:
                         excluir_primeiro_registro();
                    break;
                    case 3:
                         excluir_determinado_registro();
                    break;
                    case 4:
                         inserir_registro_inicio();
                    break;
                    case 5:
                         inserir_registro_final();
                    break;
                    case 6:
                         ordenar_idade_crescente();
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
void listar(){
     printf("\n ESTADO ATUAL DA LISTA\n");
     proximo = inicio;      
     while (proximo->prox != NULL){
           printf("\n **************************\n Nome: %s \n Idade: %2d  \n Sexo: %c", proximo->nome, proximo->idade, proximo->sexo); 
           proximo = proximo->prox;
     }
     getch();
}
	
void excluir_ultimo_registro(){

     proximo = inicio;
       while (proximo->prox != NULL){
              penultimo=proximo;
              proximo=proximo->prox;
              }

       printf("\n\n O ULTIMO VALOR DA LISTA FOI EXCLUIDO");
       printf("\n O VALOR EXCLUIDO FOI: \n ******************\n Nome: %s \n", penultimo->nome);
       
	   free(proximo);
       penultimo->prox = NULL;
       
	   getch();
}

void  excluir_primeiro_registro(){
	
	aux = inicio;
	inicio=inicio->prox;
	  
	  printf("\n\n O PRIMEIRO NOME FOI EXCLUIDO DA LISTA");    
      printf("\n O VALOR EXCLUIDO FOI: \n **************\n Nome: %s \n", aux->nome); 

	  free(aux);
	  
	  getch();
}

void excluir_determinado_registro(){
	aux = NULL;
	printf("\n INSIRA O NOME A SER EXCLUIDO: ");
	scanf("%s", &nome);
	proximo = inicio;
	while(proximo->prox != NULL){
		
		if(strcmp(nome,proximo->nome)==0){
			if(aux == NULL){
				printf("\n Nome: %s \n Idade: %2d  \n Sexo: %c",proximo->nome,proximo->idade,proximo->sexo);
				getch();
				inicio = proximo->prox;
				free(proximo);
			}
		    else {
				printf("O REGISTRO  %s  ", proximo->nome);
				printf("  FOI EXCLUIDO");
				getch();
				aux->prox = proximo->prox;
				free(proximo);
			}
	        break;
	   }
	   else{
       		aux = proximo;
       		proximo = proximo->prox;
	   }    
	}
	
}
void inserir_registro_inicio(){

	anterior = (no *)malloc(sizeof(no));

	printf("\n INFORME OS DADOS DE REGISTRO A SEREM INSERIDOS NO INICIO DA LISTA:  \n********************** ");
	printf("\n NOME: ");
	scanf("%s",&anterior->nome);
	printf("\n IDADE: ");
	scanf("%d",&anterior->idade);
	printf("\n SEXO: ");
	scanf("%s",&anterior->sexo);
    printf("\n O REGISTRO  INSERIDO NO INICIO DA LISTA FOI: %s", anterior->nome);
	
	anterior->prox = inicio;
	inicio = anterior;
    
    getch();
}
void inserir_registro_final(){
	 final = (no *)malloc(sizeof(no));
	 proximo = inicio;
	 while(proximo->prox != NULL)
		  proximo = proximo->prox;
	
		  
	printf("\n INFORME OS DADOS DE REGISTRO A SEREM INSERIDOS NO FINAL DA LISTA:  \n********************** ");
	printf("\n NOME: ");
	scanf("%s",&proximo->nome);
    printf("\n IDADE: ");
	scanf("%d",&proximo->idade);
	printf("\n SEXO: ");
	scanf(" %c",&proximo->sexo);
    printf("\n O REGISTRO  INSERIDO NO FINAL DA LISTA FOI: %s", proximo->nome);
	proximo->prox = final;
	final->prox = NULL;
	getch();
}

void ordenar_idade_crescente(){
	proximo = inicio;
       while (proximo->prox != NULL){
       		}
    printf("LISTA ORDENADA");
}

