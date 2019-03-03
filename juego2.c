#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu (int *, int *);
void llenar (int **, int*, int*);
void imprimir (int **, int*, int*);
void modificar (int **, int*, int*);

int main (void)
{
	int ** princ;
	int TamFila, TamCol, i, j;
	int * ApTamFila = &TamFila;
	int * ApTamCol = &TamCol;
	menu(ApTamFila, ApTamCol);
	princ = (int**) malloc (sizeof(int*)*(*ApTamFila));
	for(i=0;i<(*ApTamCol);i++)
	{
		princ[i]=(int*)malloc(sizeof(int)*(*ApTamCol));
	}	
	llenar(princ, ApTamFila, ApTamCol);
	imprimir(princ, ApTamFila, ApTamCol);
	modificar(princ, ApTamFila, ApTamCol);
	imprimir(princ, ApTamFila, ApTamCol);
	modificar(princ, ApTamFila, ApTamCol);
	imprimir(princ, ApTamFila, ApTamCol);
	free(princ);
}

void menu (int * ApF, int * ApC)
{
	int i, j;
	printf("\t\t\t******JUEGO DE LA VIDA*****\n");	
	printf("\t\t\t\tEL TABLERO\n");
	//printf("\nLa dirección del puntero es: %p", ApF);
	printf("\nIngresa el número de filas de tu tablero: ");
	scanf("%d", ApF);
	//printf("\nEl valor del contenido es: %d", *ApF);
	printf("\nIngresa el número de columnas de tu tablero: ");
	scanf("%d", ApC);
}

void llenar (int** M, int *F, int *C)
{
	int i, j; 
	srand(time(NULL));     //Se elige la semilla
	for(i = 0; i<*F;i++)
	{
		for(j = 0; j<*C; j++)
		{
			M[i][j]=0+rand()%((2)-(0)); //SE GENERA UN NÚMERO ALEATORIO ENTRE 0 Y 1
		}                                     //SE CONSIDERARÁ 1=CÉLULA VIVA, 0=CÉLULA MUERTA
	}
}

void imprimir (int** M, int *F, int *C)
{
	printf("\n\n");
	int i, j; 
	for(i = 0; i<*F;i++)
	{
		printf("\n");
		for(j = 0; j<*C; j++)
		{
			//printf("%d", TAB[i][j]);
			if(M[i][j]==1)
				printf("@");
			else
				printf(".");
			printf("\t");
		}
	}
}

void modificar (int **TAB, int*TamFila, int*TamCol)
{
		if((TAB[0][1]+TAB[1][0]+TAB[1][1])<2)
			TAB[0][0]=0;
		else
			TAB[0][0]=1;
///	.	
		if((TAB[0][(*TamCol)-1]+TAB[1][(*TamCol)-1]+TAB[1][(*TamCol)])<2)
			TAB[0][(*TamCol)]=0;
		else
			TAB[0][(*TamCol)]=1;
///
		if((TAB[(*TamFila)-1][0]+TAB[(*TamFila)-1][1]+TAB[(*TamFila)][1])<2)
			TAB[(*TamFila)][0]=0;
		else
			TAB[(*TamFila)][0]=1;
///
		if((TAB[(*TamFila)-1][(*TamCol)]+TAB[(*TamFila)-1][(*TamCol)-1]+TAB[(*TamFila)][(*TamCol)-1])<2)
			TAB[(*TamFila)][(*TamCol)]=0;
		else
			TAB[(*TamFila)][(*TamCol)]=1;		
}



