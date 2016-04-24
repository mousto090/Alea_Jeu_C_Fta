#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#define N 50

int tailValDejaT = 0;

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

void initialiserGrille(int Grille[N][N], int taille)
{
	int i,j;
	for(i=0; i < taille; i++)
	{
		for(j=0; j < taille; j++)
		{
			Grille[i][j] = -1 ;
		}
	}
}

/**Generer les valeurs de la grille c'est-à-dire la moitié des valeurs
	qui seront ensuite dupliqué
*/
int genererValeursGrille(int tabValGenerer[], int nbValeurs) {
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

void afficherMatrice(int M[N][N], int taille)
{
	int i,j;
	printf("\t    ");
	for(i=0; i< taille; i++)
	{
		printf("%5d", i+1);
	}
	printf("\n\t%4c ",' ');
	for(i=0; i< (5*taille+2); i++)
	{
		printf("%c",'=');
	}
	
	printf("\n\t%3c||",' ');
	for(i=0; i< (5*taille); i++)
	{
		printf("%c",' ');
	}
	printf("  ||\n");
	
	for(i=0; i<taille; i++)
	{
		printf("\t%2d ||", i+1);
		for(j=0; j<taille; j++) 
		{
			if(M[i][j] == -1)
			{
				printf("%5c",'#');
			}
			else
			{
				printf("%5d",M[i][j]);
			}
		}
		printf("  || %d\n\t%3c||", i+1, ' ');
		for(j=0; j<taille; j++) 
		{
			printf("%5c",' ');
		}
		printf("  ||\n");
	}
	
	
	printf("\t%4c ",' ');
	for(i=0; i< (5*taille+2); i++)
	{
		printf("%c",'=');
	}
	printf("\n\t    ");
	for(i=0; i< taille; i++)
	{
		printf("%5d", i+1);
	}
	printf("\n");
	
}


void comparerCase(int GrilJeu[N][N], int l1, int c1, int l2, int c2, int valDejaTrouv[N])
{
	
	if(l1 != l2 || c1 !=c2)
	{
		if(GrilJeu[l1][c1] == GrilJeu[l2][c2])
		{
			if((nombreExistDansTab(valDejaTrouv, GrilJeu[l1][c1], tailValDejaT) == 0))
				valDejaTrouv[tailValDejaT++] = GrilJeu[l1][c1];
		}	
	}
	//printf("\n\n compariaison");
	//afficherTableau(valDejaTrouv, tailValDejaT);
	//printf("\n");
	
	if((GrilJeu[l1][c1] != GrilJeu[l2][c2]))
	{
		if((nombreExistDansTab(valDejaTrouv, GrilJeu[l1][c1], tailValDejaT) == 0))
		{
			GrilJeu[l1][c1] = -1;
		}
		
		if((nombreExistDansTab(valDejaTrouv, GrilJeu[l2][c2], tailValDejaT) == 0))
		{
			GrilJeu[l2][c2] = -1;
		}
	}
	
}
void verifier(int Gril[N][N], int GrilJeu[N][N], int taille, int l , int c)
{
	int i,j;
	printf("\t    ");
	for(i=0; i< taille; i++)
	{
		printf("%5d", i+1);
	}
	printf("\n\t%4c ",' ');
	for(i=0; i< (5*taille+2); i++)
	{
		printf("%c",'=');
	}
	
	printf("\n\t%3c||",' ');
	for(i=0; i< (5*taille); i++)
	{
		printf("%c",' ');
	}
	printf("  ||\n");
	
	GrilJeu[l][c] = Gril[l][c];
	for(i=0; i<taille; i++)
	{
		printf("\t%2d ||", i+1);
		
		
		
			for(j=0; j<taille; j++) 
			{
				if(GrilJeu[i][j] != -1)
				{
					printf("%5d",GrilJeu[i][j]);
				}
				else
				{
					printf("%5c", '#');
				}
				
			}
		
		
		printf("  || %d\n\t%3c||", i+1, ' ');
		for(j=0; j<taille; j++) 
		{
			printf("%5c",' ');
		}
		printf("  ||\n");
		
	}
	
	
	printf("\t%4c ",' ');
	for(i=0; i< (5*taille+2); i++)
	{
		printf("%c",'=');
	}
	printf("\n\t    ");
	for(i=0; i< taille; i++)
	{
		printf("%5d", i+1);
	}
	printf("\n");
	
}


void afficherGrille(int M[N][N], int taille) {
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

/**
	Melanger les valeurs de la grille 
**/
void melangerValeurGrille(int *valeursGrille, int taille)
{
	int i,j, tmp;
	int trie = 0;
	while(trie == 0)
	{
		trie = 1;
		for(i = 0; i < taille - 1; i++)	
		{
			if(valeursGrille[i] > valeursGrille[i+1])
			{
				tmp = valeursGrille[i];
				valeursGrille[i] = valeursGrille[i+1];
				valeursGrille[i+1] = tmp;
				trie = 0;
			}
		}
	}
}

/**
	Generer la grille finale pour le jeu !
**/
void genererGrille(int grille[N][N], int indicesGenererParLigne[N][N], int valeursGrille[], int nbLigneCol,  int tailValGril)
{
	int ligneG, colG;
	int k;
	int indTabIndice, indValGril, indCourant;
	
	//Remplir la moitié des cases de la grille
	k=0;
	for(colG=0;colG<nbLigneCol;colG++)
	{
		for(ligneG=0;ligneG<nbLigneCol/2;ligneG++) //la moitié de la ligne
		{
			indCourant = indicesGenererParLigne[colG][ligneG];
			//prendre les indices de la ligne dans le tableau indicesGenererParLigne
			grille[colG][indCourant] = valeursGrille[k++];
				
		}
	}
	/*	l'afficher ic avant d'appler la foncion melanger
	printf("\n===Tableau des Valeurs de la grille a dupliquer===\n\n");
	afficherTableau(valeursGrille, tailValGril);*/
	//Remplir l'autre moitié, il faut melanger les valeurs d'abord
	melangerValeurGrille(valeursGrille, tailValGril);
	//k=0;
	for(colG=0;colG<nbLigneCol;colG++)
	{
		for(ligneG=0;ligneG<nbLigneCol;ligneG++) 
		{
			if(grille[colG][ligneG] == -1 )
			{
				grille[colG][ligneG] = valeursGrille[--k];
			}
		}
	}
	/*printf("\n===Matrice des Indices générés===\n\n");
	afficherMatrice(indicesGenererParLigne, nbLigneCol);*/	
	/*printf("\n===Tableau des Valeurs de la grille trier===\n\n");
	afficherTableau(valeursGrille, tailValGril);*/	
	printf("\n\n===Grille finale===\n\n");
	printf("\n\n");
	afficherMatrice(grille, nbLigneCol);
	
	
}

int  menu()
{
	int choix;
	printf("\n\t=============\n");
	printf("\n\t1- Niveau Tres facile\n");
	printf("\n\t2- Niveau Facile\n");
	printf("\n\t3- Moyen\n");
	printf("\n\t4- Niveau Difficile\n");
	printf("\n\t5- Niveau Très difficile\n");
	printf("\n\t6- Niveau Expert\n\n");
	printf("veuiller choisir le niveau : ");
	scanf("%d",&choix);
	return choix;
}

int saisirIndice(int tailleGrille)
{
	int indice;	
	do
	{
		printf("\nDonner un indice (1 - %d) : ", tailleGrille);
		scanf("%d", &indice);
		indice--;
		if(indice<0 || indice >= tailleGrille)
		{
			printf("\nIndice non valide\n ");
		}
		
	}while(indice < 0 || indice >= tailleGrille);
	return indice;
}

int  gagner(int Gril[N][N], int GrilJeu[N][N], int taille)
{
	int i,j;
	for(i=0; i<taille; i++)
	{
		for(j=0; j<taille; j++)
		{
			if(Gril[i][j] != GrilJeu[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}
int jouer()
{
	int choix, nbLigneColGrille, nbValGrille;
	int tabValGrilGenerer[N*N];
	int tabIndicesGrilGenerer[N][N];
	int grille[N][N];
	int grilleJeu[N][N];
	int valDejaTrouve[N] = {0};
	int l1,l2,c1,c2;
	
	choix = menu();
	
	switch(choix)
	{
		case 1 :
			nbLigneColGrille=2;
			break;
		case 2 :
			nbLigneColGrille=4;
			break;
		case 3 :
			nbLigneColGrille=6;
			break;
		case 4 :
			nbLigneColGrille=8;
			break;
		case 5 :
			nbLigneColGrille=10;
			break;
		case 6 :
			nbLigneColGrille=12;
			break;
		
	}
	if(nbLigneColGrille == 2 || nbLigneColGrille == 4 || nbLigneColGrille == 6 || nbLigneColGrille == 8 ||
		nbLigneColGrille == 10 || nbLigneColGrille == 12 )
	{
		system("cls");
		initialiserGrille(grille, nbLigneColGrille);
		initialiserGrille(grilleJeu, nbLigneColGrille);
		nbValGrille = nbLigneColGrille*nbLigneColGrille/2;
		genererValeursGrille(tabValGrilGenerer,nbValGrille);
		generIndiceGrille(tabIndicesGrilGenerer, nbLigneColGrille);
		genererGrille(grille, tabIndicesGrilGenerer, tabValGrilGenerer, nbLigneColGrille, nbValGrille);
		while(1)
		{
			printf("\nChoix du 1er nombre\n");
			printf("Donner numero de la ligne ");
			l1 = saisirIndice(nbLigneColGrille);	
			printf("Donner numero de la colonne ");
			c1 = saisirIndice(nbLigneColGrille);
			
			verifier(grille,grilleJeu, nbLigneColGrille, l1, c1);
			printf("\nChoix du 2er nombre\n");
			printf("Donner numero de la ligne ");
			l2 = saisirIndice(nbLigneColGrille);
			printf("Donner numero de la colonne ");
			c2 = saisirIndice(nbLigneColGrille);
			verifier(grille,grilleJeu, nbLigneColGrille, l2, c2);
			printf("Tapez sur une touche pour continuer...\n\n");
			getch();
			
			comparerCase(grilleJeu, l1,c1,l2,c2, valDejaTrouve);
			
			if(gagner(grille,grilleJeu, nbLigneColGrille)==1)
			{
				printf("\n\n\t\tFelicitation vous avez gagner !!\n\n");
				exit(0);
			}
			else
			{
				afficherMatrice(grilleJeu, nbLigneColGrille);
			}
			
			
		}
	
	}
	
}
int main() {
	int i,j,x,nbValGrille;
	int grille[N][N];
	int T [N];
	int nbLigneColGrille;
	int tabValGrilGenerer[N*N];
	int tabIndicesGrilGenerer[N][N];
	
	
	
	/*nbLigneColGrille=4;
	initialiserGrille(grille, nbLigneColGrille);
	nbValGrille = nbLigneColGrille*nbLigneColGrille/2;
	genererValeursGrille(tabValGrilGenerer,nbValGrille);
	generIndiceGrille(tabIndicesGrilGenerer, nbLigneColGrille);
	genererGrille(grille, tabIndicesGrilGenerer, tabValGrilGenerer, nbLigneColGrille, nbValGrille);*/
	
	jouer();	

	 
	
	
	
getch();
}



