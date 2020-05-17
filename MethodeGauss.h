void permutation(int ligne_1, int ligne_2, int taille, double mat[taille][taille]);
void reduction(double facteur, int ligne_1, int ligne_2,int taille, double mat[taille][taille]);
int pivot(int ligne, int taille, double mat[taille][taille]);
double calc_determinant(int taille, double mat[taille][taille]);

#define P_ZERO 0.000001
