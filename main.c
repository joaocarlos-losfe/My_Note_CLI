#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "models/data.h"


void Adicionar_Mural(Mural *mural, int *nmr_murais_criados);
void Meus_murais(Mural *mural, int *nmr_murais_criados);
void Adicionar_nota_ao_mural(Mural *mural, int selected_mural);


int selected = 0; int confirmed = 0;

int main()
{
	system("cls"); Mural mural[100]; printf("Bild ok...\n"); 

	while (1)
	{
		system("cls");

		printf("\n0 - Meus murais\n1 - Novo mural\n\\> "); scanf("%d", &selected);
		
		switch (selected)
		{
		case 1:
			Adicionar_Mural(mural, &nmr_murais_criados);
			break;
		
		case 0:
			Meus_murais(mural, &nmr_murais_criados);
			break;

		default:
			printf("\nOpção invalida..");
			getchar();
			getchar();

			break;
		}
	}

	return 0;
}

void Meus_murais(Mural *mural, int *nmr_murais_criados)
{
	system("cls");

	int selected_mural = 0;

	int i = 0;
	if (*nmr_murais_criados > 0)
	{	
		printf("\nSeus murais: \n");

		for (i = 0; i <*nmr_murais_criados; i++)
		{
			printf("\n[%d] %s {%d}", mural[i].mural_id , mural[i].mural_titulo,  mural[i].mural_nmr_notas);
		}
		printf("\n");

		printf("\nSelecione um mural\n \n\\> "); scanf("%d", &selected_mural);
		Adicionar_nota_ao_mural(mural, selected_mural);

	}
	else
	{
		printf("Ainda não possui murais");
	}

	getchar();
	getchar();

	return;
	
}

void Adicionar_Mural(Mural *mural, int *nmr_murais_criados)
{
	system("cls");
	char tmp_mural_titulo[30];
	
	printf("\nNovo mural\n");

	printf("\nTitulo: "); scanf(" %[^\n]s", tmp_mural_titulo);

	printf("\nDeseja salvar ? 1 - sim.  0 - não\n"); scanf("%d", &confirmed);

	if (confirmed)
	{
		
		mural[*nmr_murais_criados].mural_id = *nmr_murais_criados;
		mural[*nmr_murais_criados].mural_nmr_notas = 0;
		
		strcpy(mural[*nmr_murais_criados].mural_titulo, tmp_mural_titulo);
		*nmr_murais_criados += 1;
		printf("\nSalvo com sucesso\n");
	}
	else
	{
		printf("\ndescartado...\n");
	}

	getchar();
	getchar();
	
	return;
}

void Adicionar_nota_ao_mural(Mural *mural, int selected_mural)
{
	system("cls");
	char tmp_nota_titulo[30];
	char tmp_nota_texto[100];
	int i = 0;

	if( mural[selected_mural].mural_nmr_notas > 0 )
	{
		printf("\n%s\n", mural[selected_mural].mural_titulo);
		for(i=0; i<mural[selected_mural].mural_nmr_notas; i++)
		{
			printf("\nTitulo %s", mural[selected_mural].notas[i].nota_titulo);
			printf("\nNota: %s", mural[selected_mural].notas[i].nota_texto);

			printf("\n");
		}
	}
	else
	{
		printf("\nSem notas...\n");
	}

	printf("\n\n1 - Nova nota...\n "); scanf("%d", &confirmed);
	
	if(confirmed)
	{
		printf("\nTitulo: "); scanf(" %[^\n]s", tmp_nota_titulo);
		printf("\nNota: "); scanf(" %[^\n]s", tmp_nota_texto);

		// pergutar pra salvar aqui
		printf("\nSalvando nota");

		mural[selected_mural].notas[mural[selected_mural].mural_nmr_notas].nota_id = mural[selected_mural].mural_nmr_notas;
		strcpy(mural[selected_mural].notas[mural[selected_mural].mural_nmr_notas].nota_texto, tmp_nota_texto);
		strcpy(mural[selected_mural].notas[mural[selected_mural].mural_nmr_notas].nota_titulo, tmp_nota_titulo);
		mural[selected_mural].mural_nmr_notas+=1;		

	}else
	{
		return;
	}
	
	getchar();
	
	return;
}