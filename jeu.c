#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#define N 50



//Chercher une valeur dans un tableau
int nombreExistDansTab(int T[], int valeur, int taille) {
	int i=0;
	for(i=0; i<taille; i++) {
		if(T[i] == valeur) {
			//printf("%d = %d existe \n",i,T[i]);
			return 1;
		}
	}
	return 0;
}

/**Generer les valeurs de la grille c'est-à-dire la moitié des valeurs
	qui seront ensuite dupliqué
*/
int genererValeursGril(int tabValGenerer[], int nbValeurs) {
	int i=0;
	int nombre;
	srand(time(NULL));
	while(i<nbValeurs) {
		
		nombre = rand()%(100+i+10);
		if(nombreExistDansTab(tabValGenerer, nombre,i) == 0)
		{
			tabValGenerer[i] = nombre;
			i++;
		}
		
	}
}

void afficherTableau(int T[], int taille) {
	int i=0;
	for(i=0; i<taille; i++) {
		printf("%5d",T[i]);
	}
}
void afficherMatrice(int M[N][N], int taille) {
	int i,j;
	for(i=0; i<taille; i++) {
		for(j=0; j<taille; j++) {
			printf("%5d",M[i][j]);
		}
		printf("\n");
	}
}
/*	
	Verifie si une valeur existe dans un interval donné
*/
int valeurExistDansInterval(int T[], int debut, int fin, int val)
{
	int i;
	for(i=debut;i<=fin;i++)
	{
		if(T[i] == val)
		{
			return 1;
		}
	}
	return 0;
}
/**
	Générer des indices aleatoire sur chaque ligne
	c'est-à-dire sur chaque ligne on générer (LongueurLigne/2) indices
	
**/
/*void generIndiceGrille(int tabIndice[][], int nbLignCol)
{
	int i,j,k,l;
	int nombre;
	int indiceLigne[nbLignCol/2];
	k=0;
	srand(time(NULL));
	for(i=0;i<nbLignCol;i++)
	{
		for(l=0;l<nbLignCol/2;l++)
		{
			indiceLigne[l] = -1;//mettre toutes les cases -1 pour une future comparaison
		}
		j=0;
		while(j<nbLignCol/2) 
		{
			nombre = rand()%nbLignCol;
			if(nombreExistDansTab(indiceLigne, nombre,j) == 0)
			{
				indiceLigne[j] = nombre;
				j++;
			}
		}
		//copy des indices de la ligne i
		for(l=0;l<nbLignCol/2;l++)
		{
			tabIndice[k++]=indiceLigne[l];
		}
		/*afficherTableau(indiceLigne,j);
		printf("fin\n");*/
/*	}
}*/

void generIndiceGrille(int indiceGenParLign[N][N], int nbLignCol)
{
	int nombre, ligne, col;	
	srand(time(NULL));
	for(col=0;col<nbLignCol;col++)
	{
		ligne = 0;
		while(ligne < nbLignCol/2) 
		{
			nombre = rand()%nbLignCol;
			if(nombreExistDansTab(indiceGenParLign[col], nombre,ligne) == 0)
			{
				indiceGenParLign[col][ligne] = nombre;
				ligne++;
			}
		}
	}
}

void genererGrille(int Grille[N][N], int valeursGrille[], int indicesGenererParLigne[], int nbLigneCol,  int taille)
{
	int i,j;
	int k=0;//indice du tableau valeurs[]
	for(i=0;i<nbLigneCol;i++)
	{
		for(j=0;j<nbLigneCol;j++)
		{
			if(valeurExistDansInterval(valeursGrille,k,k+4,j) == 1)
			{
				printf("%d existe \n",j);
			}
				
		}
	}
	
}
int main() {
	int i,j,x,nbValGrille;
	int Grille[N][N];
	int T [N];
	int nbLigneColGrille;
	int tabValGrilGenerer[N*N];
	int tabIndicesGrilGenerer[N][N];
	
	nbLigneColGrille=8;
	nbValGrille = nbLigneColGrille*nbLigneColGrille/2;
	/*genererValeursGril(tabValGrilGenerer,nbValGrille);
	afficherTableau(tabValGrilGenerer,nbValGrille);*/
	generIndiceGrille(tabIndicesGrilGenerer, nbLigneColGrille);
	afficherMatrice(tabIndicesGrilGenerer, nbLigneColGrille);
	//printf("\n\nIndices===\n\n");
	
	//afficherTableau(T,n*(n/2));
	//genererGrille(Grille,n,nbValGenerer,T,n*(n/2));
	
	
	
getch();
}



