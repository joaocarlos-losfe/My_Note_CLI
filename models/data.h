#include <stdio.h>
#include <stdlib.h>

int nmr_murais_criados = 0;


typedef struct
{
	char nota_titulo[30];
	char nota_texto[100];
	int nota_id;

}Nota;

typedef struct
{
	char mural_titulo[30];
	int mural_id;
	int mural_nmr_notas;
	
	Nota notas[100];

}Mural;
