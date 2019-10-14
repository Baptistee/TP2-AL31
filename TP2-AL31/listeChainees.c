/************************************

		Listes simplement chainées !
		
implantation en C !

************************************/


/*
*	
*	
*	le but est de :
*	- implanter les listes chainées ;
*	- implanter l'insertion en tête et en queue ;
*	- implanter le tri de listes chainées (sélection et quicksort) ;
*	- implanter l'insertion après un successeur (en préservant le tri);
*	- implanter 
*	
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define SIZE 10
#define INFINITE 10000

#define MAX_VAL 50


/*
Structure de données liste chaînée.
*/

typedef struct cell_t
{
	struct cell_t* suivant;
	int val;

} cell_t;

typedef struct list_t
{
	struct cell_t* head;

} list_t;


/*
	fonctions d'affichage
*/

void affiche_cell(cell_t n)
{
	printf("\n AFFICHE CELL : %d \n", n.val);

}


void affiche_list(list_t l)
{
	if (l.head)
	{
		cell_t* ptr = NULL;
		ptr = l.head;

		printf("\n AFFICHE LISTE : \n");

		while (ptr)
		{
			affiche_cell(*ptr);
			ptr = ptr->suivant;
		}
	}

}


/*
	fonctions d'insertion
*/

list_t insert_in_head(int elt, list_t l)
{
	cell_t* prochain = NULL;

	prochain = l.head;

	cell_t* nouveau = (cell_t*)malloc(sizeof(cell_t));

	nouveau->val = elt;

	l.head = nouveau;

	nouveau->suivant = prochain;

	return l;
	
}

list_t insert_in_tail(int elt, list_t l)
{
	if (l.head != NULL)
	{
		cell_t* dernier = (cell_t*)malloc(sizeof(cell_t));
		dernier->val = elt;
		dernier->suivant = NULL;

		cell_t* ptr = NULL;

		ptr = l.head;

		while (ptr->suivant)
		{
			ptr = ptr->suivant;
		}

		ptr->suivant = dernier;

	}
	return l;

}

/*
	fonctions de suppression
*/

list_t delete_in_head(list_t l)
{
	if (l.head)
	{
		cell_t* ancien = l.head;

		l.head = l.head->suivant;

		free(ancien);
	}

	return l;

}

list_t delete_in_tail(list_t l)
{
	if (l.head)
	{
		cell_t* precedent = NULL;

		cell_t* dernier = NULL;
		dernier = l.head;

		while (dernier->suivant)
		{
			precedent = dernier;
			dernier = dernier->suivant;
		}

		precedent->suivant = NULL;

		free(dernier);

	}

	return l;

}


/*
	Création d'une liste de n d'éléments aléatoires
*/

list_t create_list(int n)
{
	int i = 0;
	list_t* liste = (list_t*)malloc(sizeof(list_t));
	liste->head = NULL;

	for (i; i < n; i++)
	{
		liste->head = insert_in_head(rand() % 50, *liste).head;
	}
	
	return *liste;
}





/*
	"free" d'une liste
*/

void free_list(list_t l)
{
	if (l.head)
	{

		while (l.head)
		{
			l = delete_in_head(l);
		}

	}
}



/*
	fonction d'échange
*/

list_t swap_with_head(cell_t * c, list_t l)
{

	/* mettre ici votre code */
	
}




/*
	tri !
*/

cell_t * min_of_list(list_t l)
{
	cell_t* ptr;
	cell_t* ptrmin = NULL;

	if (l.head)
	{
		int min = l.head->val;
		ptr = l.head;

		while (ptr)
		{
			if (ptr->val < min)
			{
				printf("\n TEST %d \n",ptr->val);
				min = ptr->val;
				ptrmin = ptr;
			}

			ptr = ptr->suivant;
		}
	}

	return ptrmin;
}

cell_t * max_of_list(list_t l)
{
	int max = 0;
	cell_t* ptr;
	cell_t* ptrmax = NULL;

	if (l.head)
	{
		ptr = l.head;

		while (ptr)
		{
			if (ptr->val > max)
			{
				max = ptr->val;
				ptrmax = ptr;
			}

			ptr = ptr->suivant;
		}
	}

	return ptrmax;
}

list_t selection_sort(list_t l)
{

	/* mettre ici votre code */
}

/********************

		MAIN !!

********************/

int main(){
	srand(time(NULL));

	///Phase 1 : Fonctionne
	/*
	list_t liste;

	cell_t c1; c1.val = 1;
	cell_t c2; c2.val = 2;
	cell_t c3; c3.val = 3;

	c1.suivant = &c2; c2.suivant = &c3; c3.suivant = NULL;

	liste.head = &c1;

	liste = insert_in_head(0, liste);

	liste = insert_in_tail(9, liste);

	liste = delete_in_head(liste);

	liste = delete_in_tail(liste);

	affiche_list(liste);
	*/

	///Phase 2 :
	list_t liste = create_list(5);

	cell_t* min = min_of_list(liste);
	cell_t* max = max_of_list(liste);

	affiche_list(liste);

	printf("\n MIN : %d \n MAX : %d \n", min->val, max->val);

	free_list(liste);
	liste.head = NULL; ///Mettre vers un pointeur NULL

	affiche_list(liste);

	printf("TERMINE - - - - -");

	return 0;
}










