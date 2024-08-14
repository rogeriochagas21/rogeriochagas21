#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
/* Exemplo de Arquivo com busca sequencial e alteracao */

typedef struct {
	char nusp[10], nome[30];
	int idade;
	float nota;
} REG1;

typedef struct {
        char nusp[10];
        unsigned int pos;
}IND;

REG1 alunos;
IND indice;

FILE *fptr, *fptr1;

int grava_arq( )
{
	char conf;


	if ( ((fptr = fopen("alunos.arq", "ab+")) == NULL) || ((fptr1 = fopen("indice.arq", "ab+")) == NULL))
	{
		printf("Nao posso abrir o arquivo\n");
		getch();
		return(0);
	}
	fflush(stdin);

	printf(" \t\t Cadastro de Dados no Arquivo\n\n" );
	printf("Digite o numero USP do aluno ou <ENTER> para sair: ");
	gets(alunos.nusp);
	while(alunos.nusp[0] != '\0')
	{
		printf("Nome =  ");
    	gets(alunos.nome);
		printf("Idade =  ");
		scanf("%d", &alunos.idade);
		printf("Nota = ");
		scanf("%f", &alunos.nota);
		printf("Confirma informacoes (S/N)?");
		fflush(stdin);
		scanf("%c", &conf);
		if (conf == 's')
		{

		    printf("posicao antes de gravar em arq: %ld\n", ftell(fptr));
			getch();
			fwrite(&alunos, sizeof(alunos), 1, fptr);
		    printf("tamanho do registro: %d\n", sizeof(alunos));
			getch();

		    printf("posicao depois de gravar: %ld\n", ftell(fptr));
			getch();
			indice.pos = ftell(fptr) - sizeof(alunos);
		    printf("posicao para arq indice: %ld\n", indice.pos);
			getch();
			strcpy(indice.nusp, alunos.nusp);
			fwrite(&indice, sizeof(indice), 1, fptr1);
        }
		fflush(stdin);
		printf("Digite o numero USP do aluno ou <ENTER> para sair: ");
		gets(alunos.nusp);
	}
	fclose(fptr);
	fclose(fptr1);
	return(0);
}  /* fim funcao grava_arq */

int atualiza_arq()
{
	char numero[10], c, achou = 0;

	if ( ((fptr = fopen("alunos.arq", "rb+")) == NULL) || ((fptr1 = fopen("indice.arq", "rb")) == NULL))
	{
		printf("Arquivo nao existente...\n");
		getch();
		return(0);
	}
    printf ("\t\tAtualizando dados do Arquivo ...\n\n\n");
    fflush(stdin);
    printf("Entre com o numero USP:");
	gets(numero);
	fflush(stdin);

    while( (achou == 0)  && (fread(&indice, sizeof(indice),1,fptr1) == 1) )
	       if (strcmp(indice.nusp, numero) == 0)
	                               achou = 1;
	if (achou == 1)
    {
              fseek(fptr, indice.pos, 0);
              if(fread(&alunos, sizeof(alunos),1,fptr) == 1)
	          {
              	printf("posicao do ponteiro do arquivo: %ld\n", ftell(fptr));
                getch();
                printf("Nome  = %s\n",alunos.nome);
		        printf("Novo nome = ");
		        gets(alunos.nome);
          		printf("Idade = %d\n", alunos.idade);
            	printf("Nova idade = ");
            	scanf("%d", &alunos.idade);
             	printf("Nota  = %.2f\n\n", alunos.nota);
              	printf("Nova nota = ");
               	scanf("%f", &alunos.nota);
                printf("Confirma novos dados (s/n)?");
		        fflush(stdin);
		        scanf("%c", &c);
		        if (c == 's')
		        {
			          fseek(fptr, (ftell(fptr) - sizeof(alunos)), 0); /*posiciona novamente arq */
			          printf("posicao antes de gravar: %ld\n", ftell(fptr));
			          getch();
			          if (fwrite(&alunos, sizeof(alunos), 1, fptr) == 1)
			          {
				         printf("o arquivo foi atualizado com sucesso\n\n");
				         getch();
			          }
                }
             }
    }
	else
	{
		printf("nome nao encontrado no arquivo...");
		getch();
	}
	fclose(fptr);
	fclose(fptr1);
	return(0);
}  /* fim funcao atauliza_arq */

int ler_arq()
{
char numero[10], achou =0;
	if ( ((fptr = fopen("alunos.arq", "rb")) == NULL) || ((fptr1 = fopen("indice.arq", "rb")) == NULL))
	{
		printf("Arquivo nao existente...\n");
		getch();
		return(0);
	}
	fflush(stdin);
	printf ("\t\tConsulta Dados do Arquivo ...\n\n\n");
	printf("Entre com o numero USP a ser consultado:");
	gets(numero);
	fflush(stdin);

    while( (achou == 0)  && (fread(&indice, sizeof(indice),1,fptr1) == 1) )

	       if (strcmp(indice.nusp, numero) == 0)
	                               achou = 1;
	if (achou == 1)
    {
              fseek(fptr, indice.pos, 0);
              if(fread(&alunos, sizeof(alunos),1,fptr) == 1)
	          {
		            printf("Numero  = %s\n",alunos.nusp);
                    printf("Nome  = %s\n",alunos.nome);
		            printf("Idade = %d\n", alunos.idade);
              		printf("Nota  = %.2f\n\n", alunos.nota);
		            getch();
              }
              else
                  printf("registro nao encontrado em fptr!\n" );
    }
    else
    {
        printf("Numero USP nao cadastrado, tente novamente...\n\n");
        getch();
    }

	fclose(fptr);
	fclose(fptr1);
	return(0);
}  /* fim funcao ler_arq */

int  main()
{

	int op;
	do {

		printf("\t\t*****Programa Exemplo para Manipulacao de Arquivos****\n\n");
		printf("\t1 - Ler arquivo\n");
		printf("\t2 - Gravar arquivo\n");
		printf("\t3 - Atualiza dados \n");
		printf("\t4 - Sair do programa\n");
		scanf("%d", &op);
		switch (op) {
				case 1: ler_arq(); break;
				case 2: grava_arq(); break;
				case 3: atualiza_arq();break;
				case 4: exit(0); break;
				default: break;
			}
		} while (op != 4);

}

