
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MethodeLaplace.h"




void cofacteur(double mat[N][N], double tmp[N][N], int p, int q, int n){

	int i = 0, j = 0;


	for (int ligne = 0; ligne < n;++ligne)
	{
		for (int col = 0; col < n;++col)
		{

			if (ligne != p && col != q)
			{
				tmp[i][j++] = mat[ligne][col];


				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}



double determinant(double mat[N][N], int N){

	double det = 0;


	if (N == 1)
		return mat[0][0];

	double tmp[N][N];

	int signe = 1;


	for (int f = 0; f < N; f++)
	{

		cofacteur(mat, tmp, 0, f, N);

		det += signe * mat[0][f] * determinant(tmp, N - 1);


		signe = -signe;
	}

	return det;
}


int main()
{


	srand(time(NULL));
	int scan_tmp;
	clock_t begin,end;

	printf("Saisir la taille N de la matrice (format N * N ):  ");
	while (scanf("%d", &scan_tmp) != 1) {

			printf("Saisir la taille N de la matrice (format N *N ): ");
	}

	N = scan_tmp;




	double matrice[N][N];

	for (int i = 0;i < N;++i){
		printf("\n");
		for(int j = 0;j < N;++j){
			matrice[i][j] = rand() % 100;
			//matrice[i][j] = rand()
			printf("Valeur [%d][%d] = %f\n",i,j,matrice[i][j]);
		}
	}


	begin = clock();
	printf("Determinant de la matrice : %f\n",
	determinant(matrice, N));
	end = clock();
	double temps = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Temps = %f\n",temps);
	return 0;
}
