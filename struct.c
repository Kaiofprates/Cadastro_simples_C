#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define blue "\x1b[34m" 
#define red "\x1b[31m"
#define cyan "\x1b[36m"
#define cls   "\x1b[0m"
#define magenta "\x1b[35m"
#define gren "\x1b[32m" 


#define arquivo "dados.txt"

int main()
{
	struct dados{char nome[20];char idade[3];char mercadoria[30];};struct dados cadastro;struct dados pesquisa;

	FILE *PA;
	PA = fopen(arquivo,"rb+");if(PA == NULL){fopen(arquivo,"wb+");}
	fclose(PA);


	void cad(){printf("\nnome.....: ");fflush(stdin);scanf("%s%*c", cadastro.nome);
	printf("\nidade...: ");fflush(stdin);scanf("%s%*c", cadastro.idade);
	printf("\nmercadoria...:");fflush(stdin);scanf("%s%*c", cadastro.mercadoria);

	PA = fopen(arquivo,"rw+");fseek(PA,0,SEEK_END);fwrite(&cadastro,sizeof(cadastro)*1,1,PA);fclose(PA);}


	void pesq(){
		char busca[10];printf("nome....:");fflush(stdin);scanf("%s%*c",busca);
		PA = fopen(arquivo,"rb+");rewind(PA);

		while(!feof(PA)){fread(&pesquisa,sizeof(cadastro),1,PA);
			if(!strcmp(pesquisa.nome,busca)){printf("idade: %s\n",pesquisa.idade);printf("mercadoria: %s\n",pesquisa.mercadoria);break;}
		}
		fclose(PA);
	}
	int n;
	printf(magenta "*****************************************************" cls);
	printf(cyan  "\n*____________________BANCO_DE_DADOS_________________*" cls);
	printf(magenta"\n*****************************************************" cls);
	printf(cyan   "\n****** 1-para novo cadastro. 2-para pesquisa. *******\n" cls);
	printf(gren ">>>>  " cls);
	scanf("%d",&n);

	switch(n){
		case 1:
		cad();
		break;
		case 2:
		pesq();
		break;
	}

	return 0;
}