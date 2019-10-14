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

#define false 0
#define true 1


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
	if (l.head)
	{
		int tranfer = c->val;
		c->val = l.head->val;
		l.head->val = tranfer;

		return l;
	}

	return l;
}

list_t swap_with_tail(cell_t* c, list_t l)
{
	if (l.head)
	{
		cell_t* ptr = l.head;

		while (ptr->suivant)
		{
			ptr = ptr->suivant;
		}

		int tranfer = c->val;
		c->val = ptr->val;
		ptr->val = tranfer;

		return l;
	}

	return l;
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
		ptrmin = l.head;
		ptr = l.head;

		while (ptr)
		{
			if (ptr->val < min)
			{
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
	if (l.head)
	{
		list_t buffer;
		buffer.head = min_of_list(l);

		cell_t* ptr = l.head;

		while (ptr)
		{
			swap_with_head(min_of_list(l), l);

			l.head = ptr->suivant;

			ptr = ptr->suivant;
			
		}

		return buffer;
	}
}

list_t quick_sort(list_t l)
{
	if (l.head)
	{
		int taille = 0;
		cell_t* ptr = l.head;

		while (ptr)
		{
			ptr = ptr->suivant;
			taille++;
		}

		int pivot = rand() % (taille);
		ptr = l.head;

		printf("\n VAL PIVOT : %d : \n", pivot);
	}
}

/*
	Bataille
*/

cell_t* recup_index(int rand, list_t l)
{
	cell_t* ptr = NULL;

	ptr = l.head;

	for (int i = 0; i < rand; i++)
	{
		ptr = ptr->suivant;
	}

	return ptr;
}

list_t generer_paquet()
{
	int i = 51;
	list_t* liste = (list_t*)malloc(sizeof(list_t));
	liste->head = NULL;

	for (i; i >= 0; i--)
	{
		liste->head = insert_in_head(i, *liste).head;
	}

	return *liste;
}

list_t melanger_paquet(list_t l)
{
	cell_t* ptr = l.head;

	while (ptr)
	{
		l = swap_with_head(recup_index(rand() % 52, l), l);
		
		ptr = ptr->suivant;
	}

	return l;
}

list_t couper_paquet(list_t l)
{;
	list_t l2;

	cell_t* ptr = NULL;

	l2.head = recup_index(25, l);

	ptr = recup_index(24, l);

	ptr->suivant = NULL;

	return l2;
}

void jouer_coups(list_t l1, list_t l2)
{
	cell_t* ptr1 = l1.head;
	cell_t* ptr2 = l2.head;

	if ((ptr1->val % 13) < (ptr2->val % 13))
	{
		printf(" \n JOUEUR 2 GAGNE LE COUP AVEC %d CONTRE %d \n", (ptr2->val % 13), (ptr1->val % 13));
		insert_in_tail(l1.head, l2);
		insert_in_tail(l2.head, l2);
	}

	else if ((ptr1->val % 13) > (ptr2->val % 13))
	{
		printf(" \n JOUEUR 1 GAGNE LE COUP AVEC %d CONTRE %d \n", (ptr1->val % 13), (ptr2->val % 13));
		insert_in_tail(l1.head, l1);
		insert_in_tail(l2.head, l1);
	}

	else
	{
		printf("BATAILLE !");
	}
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

	
	///Phase 2 : Fonctionne
	/*
	list_t liste = create_list(10);

	cell_t* min = min_of_list(liste);
	cell_t* max = max_of_list(liste);

	affiche_list(liste);

	//printf("\n MIN : %d \n MAX : %d \n", min->val, max->val);

	//liste = swap_with_head(min, liste);
	//liste = swap_with_tail(max, liste);

	selection_sort(liste);

	affiche_list(liste);

	free_list(liste);
	liste.head = NULL; ///Mettre vers un pointeur NULL

	affiche_list(liste);
	*/

	///Phase 3 : Bataille ! (Non termine)
	/**/
	list_t paquet = generer_paquet();

	paquet = melanger_paquet(paquet);

	list_t paquet2 = couper_paquet(paquet);

	affiche_list(paquet);

	affiche_list(paquet2);

	jouer_coups(paquet, paquet2);

	printf("TERMINE - - - - -");

	return 0;
}










