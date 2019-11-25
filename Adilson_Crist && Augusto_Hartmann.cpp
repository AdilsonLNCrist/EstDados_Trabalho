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
       no *noauxiliar;
       no *anterior;
       no *final;
       no *support2;
       no *support3;
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
	
void excluir_ultimo_registro(){ /// Função 1
	system("cls");
     proximo = inicio;
       while (proximo->prox != NULL){
              penultimo=proximo; ///// Atravessa a lista
              proximo=proximo->prox;
        }

       printf("\nULTIMO REGISTRO DA LISTA EXCLUIDO");
       printf("\n\nUse qualquer tecla para continuar");
	   free(proximo); //// Limpa a posição;
       penultimo->prox = NULL;
	   getch();
}

void  excluir_primeiro_registro(){ /// Função 2
	
	noauxiliar = inicio;
	inicio=inicio->prox;
	  system("cls");
	  printf("\nPRIMEIRO REGISTRO DA LISTA EXCLUIDO");    
	  printf("\n\nUse qualquer tecla para continuar");
	  free(noauxiliar);
	  getch();
}

void excluir_determinado_registro(){ /// Função 3
	system("cls");
	noauxiliar = NULL;
	char* texto;
	printf("informe o nome completo registro que deseja excluir: ");
	scanf("%s", &nome);
	proximo = inicio;
	while(proximo->prox != NULL){
		if(strcmp(nome,proximo->nome)==0){
			if(noauxiliar != NULL){
				texto = "Registro excluido\n\n";
				noauxiliar->prox = proximo->prox;
				free(proximo);
			}
		    else {
				//strcpy(texto, "Registro nao encontrado\n");
				noauxiliar->prox = proximo->prox;
				free(proximo);
			}
	        break;
	   }
	   else{
	   		texto = "Registro nao encontrado\n\n";
       		noauxiliar = proximo;
       		proximo = proximo->prox;
	   }    
	}
	printf("%s", texto);
	system("pause");
	
}
void inserir_registro_inicio(){ /// Função 4
	system("cls");
	anterior = (no *)malloc(sizeof(no));

	printf("Informe os dados do registro para ser inserido no inicio da lista: ");
	printf("\nNOME: ");
	scanf("%s",&anterior->nome);
	printf("\nSEXO: ");
	scanf("%s",&anterior->sexo);
	printf("\nIDADE: ");
	scanf("%d",&anterior->idade);
    printf("\nREGISTRO INSERIDO NO INICIO DA LISTA\n\n");
	system("pause");
	anterior->prox = inicio;
	inicio = anterior;
}
void inserir_registro_final(){ /// Função 5
	system("cls");
	 final = (no *)malloc(sizeof(no));
	 proximo = inicio;
	 while(proximo->prox != NULL)
		  proximo = proximo->prox;
	
		  
	printf("Informe os dados do registro para ser inserido no final da lista:");
	printf("\nNOME: ");
	scanf("%s",&proximo->nome);
	printf("\nSEXO: ");
	scanf(" %c",&proximo->sexo);
    printf("\nIDADE: ");
	scanf("%d",&proximo->idade);
    printf("\nREGISTRO INSERIDO NO FINAL DA LISTA\n\n");
    system("pause");
	proximo->prox = final;
	final->prox = NULL;
	
}
void ordenar_idade_crescente(){ /// Função 6
	while(1){
		int trocano = 0; // variavel de verificação
		support2 = inicio; // variavel de suporte
		support3 = inicio; // variavel de suporte
		proximo = support3->prox; 
		while(proximo->prox != NULL){
			if(support3->idade > proximo->idade){ //Verifica se a idade do suporte é maior que a idade do proximo
				trocano = 1; // realiza mudanca de valor na variavel
				if(support3 == inicio){ //verifica se o nó do suporte3 é igual ao inicio
					inicio = proximo; // caso for, iguala o inicio ao proximo
				}else{
					support2->prox = proximo;
				}
				support3->prox = proximo->prox;
				proximo->prox = support3;
				
				support2 = proximo;
				proximo = support3->prox;
				}else{
					support2 = support3;
					support3 = proximo;
					proximo = support3->prox;
				}	
		} // * Fim * while(proximo->prox != NULL)
		if(!trocano){
			break;
		}
	} // * Fim * while (1)
	system("cls");
	printf("\n LISTA ORDENADA POR IDADE\n\n");
	system("pause");
} // ** Fim ** void ordenar_idade_crescente()

