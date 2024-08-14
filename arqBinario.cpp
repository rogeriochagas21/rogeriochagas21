#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// Programa que escreve um registro em arquivo

struct REG {
               int codigo;
               char nome[40];
               int idade;
               };

struct REG pessoa;

FILE *arq;

int grava()
{
  char op;
   arq = fopen("pessoa.dad", "ab+");

   if (arq== NULL)
   {
   	printf("Nao foi possivel criar o arquivo\n");
    return(0);
   }
   fflush(stdin);
   printf("\n\n ***** Cadastro de Pessoas *****\n\n");
   printf("Digite um codigo ou 0 para para encerrar...\n");
   scanf("%d", &pessoa.codigo);
   fflush(stdin);
   while (pessoa.codigo != 0 )
   {
         printf("Nome:");
         gets(pessoa.nome);
         fflush(stdin);
         printf("Idade:");
         scanf("%d", &pessoa.idade);
         fflush(stdin);
         printf("\nConfirma os dados (s/n)?");
         op=getche();
         fflush(stdin);
         if (op == 's' || op == 'S')
            fwrite(&pessoa, sizeof(pessoa), 1, arq);
          printf("\nDigite um codigo  ou 0 para para encerrar...\n");
          scanf("%d", &pessoa.codigo);
          fflush(stdin);

   }
   fclose(arq);
}

int le()
{
   char texto[80];

   arq = fopen("pessoa.dad", "rb");

   if (arq == NULL)
   {
   	printf("Arquivo nao pode ser aberto\n");
   	return(0);
   }

   printf("\n\n ***** Dados Cadastrados para os Livros *****\n\n");

   while (fread(&pessoa, sizeof(pessoa), 1, arq) > 0 )
   {
         printf("Codigo: %d\n", pessoa.codigo);
         printf("Nome  : %s\n", pessoa.nome);
         printf("Idade: %d\n", pessoa.idade);
         printf("-------------------------------------------\n");


   }
   printf("Tecle para continuar...\n");
   getch();
   fclose(arq);
}

int main()
{
  int op=0;

  while (op != 3)
  {
         printf("\n\n***** Programa com Arquivo Binario *****\n");
         printf("1 - Gravar dados no arquivo\n");
         printf("2 - Mostrar os dados do arquivo\n");
         printf("3 - Sair do programa\n");
         scanf("%d", &op);
         if (op == 1)
            grava();
         else if (op == 2)
             le();
  }

  system("PAUSE");
  return 0;
}
