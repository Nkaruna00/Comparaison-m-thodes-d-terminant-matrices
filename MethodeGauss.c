
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "MethodeGauss.h"




void permutation(int ligne_1, int ligne_2, int taille, double mat[taille][taille]){

    double tmp;

    for (int j = 0; j < taille; ++j) {
        tmp = mat[ligne_1][j];
        mat[ligne_1][j] = mat[ligne_2][j];
        mat[ligne_2][j] = tmp;
    }
}


void reduction(double facteur, int ligne_1, int ligne_2,int taille, double mat[taille][taille]){

    for (int j = 0; j < taille; ++j) {
        mat[ligne_2][j] += (facteur * mat[ligne_1][j]);
    }
}

int pivot(int ligne, int taille, double mat[taille][taille]){

    int j = 0;

    while (j < taille && fabs(mat[ligne][j]) < P_ZERO) {
        ++j;
    }

    return j;
}

double calc_determinant(int taille, double mat[taille][taille]){

    int pivot1, pivot2;
    int ligne;
    double facteur;
    int fin = 0;
    double determinant = 1.0;

    while (!fin) {
        fin = 1;
        ligne = 1;
        while (ligne < taille) {

            if ((pivot1 = pivot(ligne - 1, taille, mat)) == taille ||
                (pivot2 = pivot(ligne, taille, mat)) == taille) {
                return 0.0;
            }
            if (pivot1 == pivot2) {
                facteur = -mat[ligne][pivot1] / mat[ligne - 1][pivot1];
                reduction(facteur, ligne - 1, ligne, taille, mat);
                fin = 0;
            } else if (pivot2 < pivot1) {
                permutation(ligne - 1, ligne, taille, mat);
                determinant = -determinant;
                fin = 0;
            }
            ++ligne;
        }
    }

    for (int j = 0; j < taille; ++j) {
        determinant *= mat[j][j];
	}

    return determinant;
}



int main(){

    int taille;
    int scan_tmp;
    clock_t begin,end;


    printf("Saisir la taille N de la matrice (format N * N ):  ");
    while (scanf("%d", &scan_tmp) != 1) {

        printf("Saisir la taille N de la matrice (format N *N ): ");
    }

    taille = scan_tmp;

    double matrice[taille][taille];
    srand(time(NULL));

    for (int i = 0; i < taille; i++) {
            printf("\n");
        for (int j = 0; j < taille; j++) {
            //matrice[i][j] = rand();
            matrice[i][j] = rand() % 100;
            printf("Valeur [%d][%d] = %f\n",i,j,matrice[i][j]);
        }
    }


    begin = clock();
    double determinant = calc_determinant(taille, matrice);
    end = clock();
    double temps = (double)(end - begin) / CLOCKS_PER_SEC;


    printf("Temps = %f\n",temps);
    printf("Determinant: %f\n", determinant);


}
