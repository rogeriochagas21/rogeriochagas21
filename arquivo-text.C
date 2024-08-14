#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Programa que escreve uma cadeia de caracteres em um arquivo

int grava(FILE *arq)
{
   char texto[80];

   arq = fopen("arquivoDaEletrica.txt", "a");

   if (arq== NULL)
   {
   	printf("Nao foi possivel abrir o arquivo\n");
    return(0);
   }
   fflush(stdin);
   printf("\n\n ***** Funcao que grava em um arquivo texto *****\n\n");
   printf("Digite um texto ou <ENTER> para encerrar...\n");
   gets(texto);
   fflush(stdin);
   while (strlen(texto) > 0 )
   {
  	     fputs(texto, arq);
         fputs("\n", arq);
         gets(texto);
         fflush(stdin);
   }
   fclose(arq);
}

int le(FILE *arq)
{
   char texto[80];

   arq = fopen("arquivoDaEletrica.cuesta", "r");

   if (arq == NULL)
   {
   	printf("Arquivo nao pode ser aberto\n");
   	return(0);
   }

   printf("\n\n ***** Funcao que mostra dados de um arquivo texto *****\n\n");

   while (fgets(texto, 80, arq) != NULL )
	printf("%s", texto);


   fclose(arq);
}

int main(int argc, char *argv[])
{
  FILE *arq;
  int op=0;

  while (op != 3)
  {
         printf("\n\n***** Programa com Arquivo Texto *****\n");
         printf("1 - Gravar dados no arquivo\n");
         printf("2 - Mostrar os dados do arquivo\n");
         printf("3 - Sair do programa\n");
         scanf("%d", &op);
         if (op == 1)
            grava(arq);
         else if (op == 2)
             le(arq);
  }

  system("PAUSE");
  return 0;
}
