#include "utils.h"

void creaza_lista(char *argv[])													// TODO: Cerinta 1
{																				// Creare lista cu echipe
	std::ifstream date_echipe(argv[2]);
	std::ofstream rezultate(argv[3]);
		
	Lista lista;																// Creeam obiectul lista, apeland constructorul fara parametri
	date_echipe >> lista;														// Populam obiectul cu datele din fisierul de intrare
	rezultate << lista;															// scriem numele echipelor continute in lista in fisierul de iesire
	
	rezultate.close();
    date_echipe.close();
}

void elimina(char *argv[])														// TODO: Cerinta 2
{																				// Creare lista cu echipe
	std::ifstream date_echipe(argv[2]);											// Eliminare echipe din lista astfel incat sa ramana n echipe, unde n-maxim si n putere a lui 2
	std::ofstream rezultate(argv[3]);
	
	Lista lista;
	date_echipe >> lista;
	lista.elimina_echipe();
	rezultate << lista;															// Eliminam din lista, echipele cu media minima, astfel incat, in lista sa ramana 2^n echipe, unde n este maxim
	
	rezultate.close();
    date_echipe.close();
}

void creeaza_coada(char *argv[])												// TODO: Cerinta 3
{																				// Creare lista cu echipe
	std::ifstream date_echipe(argv[2]);											// Eliminare echipe din lista astfel incat sa ramana n echipe, unde n-maxim si n putere a lui 2
	std::ofstream rezultate(argv[3]);											// Creare coada cu meciuri, stiva cu castigatori, stiva cu pierzatori

	Lista lista;
	date_echipe >> lista;
	lista.elimina_echipe();
	rezultate << lista;	
	Stiva stiva;																// apelam o metoda din clasa stiva, care primeste ca parametru lista, creeaza o coada cu meciurile, dar si stive cu castigatori si pierzatori
	stiva.creeaza_si_scrie_in_fisier_coada(lista, rezultate);					// pasii se repeta, pana in coada mai ramane o sigura echipa, stiva cu pierzatori este mereu golita, iar cea cu castigatorii este scrisa in fisier
																	
	rezultate.close();
    date_echipe.close();
}

void creeaza_BST(char *argv[])													// TODO: Cerinta 5
{																				// Creare lista cu echipe
	std::ifstream date_echipe(argv[2]);											// Eliminare echipe din lista astfel incat sa ramana n echipe, unde n-maxim si n putere a lui 2
	std::ofstream rezultate(argv[3]);											// Creare coada cu meciuri, stiva cu castigatori, stiva cu pierzatori
																				
	Lista lista;																// Crearea unui BST cu ultimele 8 echipe din competitie
	date_echipe >> lista;
	lista.elimina_echipe();
	rezultate << lista;

	Stiva opt_echipe;
	opt_echipe = opt_echipe.creeaza_si_scrie_in_fisier_coada(lista, rezultate); //metoda, returneaza stiva cu ultimele echipe care raman in competitie, pentru a fi folosita la construirea arborelui de cautare 

	rezultate << "\nTOP 8 TEAMS:\n";
	BST bst;																	
	bst.root = bst.root->creeaza_arbore(bst.root, opt_echipe);					// se extrage cate o echipa din stiva, si se introduce in arbore
	bst.root->scrie_arbore_in_fisier(bst.root, rezultate);						// este scris clasamentul cu cele 8 echipe in fisier
	delete bst.root;															// se elibereaza memoria ocupata de arbore, prin apelul recursiv al destructorului
	
	rezultate.close();
    date_echipe.close();
}

void creeaza_AVL(char *argv[])													// TODO: Cerinta 5
{																				// Creare lista cu echipe
	std::ifstream date_echipe(argv[2]);											// Eliminare echipe din lista astfel incat sa ramana n echipe, unde n-maxim si n putere a lui 2
	std::ofstream rezultate(argv[3]);											// Creare coada cu meciuri, stiva cu castigatori, stiva cu pierzatori
																												
	Lista lista;																// Crearea unui BST cu ultimele 8 echipe din competitie
	date_echipe >> lista;														// Crearea unui AVL cu echipele din BST
	lista.elimina_echipe();
	rezultate << lista;

	Stiva ultimele_opt_echipe;
 	ultimele_opt_echipe = ultimele_opt_echipe.creeaza_si_scrie_in_fisier_coada(lista, rezultate);
	 	
	rezultate << "\nTOP 8 TEAMS:\n";
	BST bst;																	// Vom crea un arbore binar de cautare ce conltine ultimele 8 echipe ramase in concurs
	bst.root = bst.root->creeaza_arbore(bst.root, ultimele_opt_echipe);
	bst.root->scrie_arbore_in_fisier(bst.root, rezultate);
	
	rezultate << "\nTHE LEVEL 2 TEAMS ARE: \n";
	AVL avl;  
	avl.root = avl.root->creeaza_avl(avl.root, bst.root);						// aceasta metoda, primeste ca parametru arborele binar, pe care il parcurge petru a extrage echipele, in ordine descrescatoare, si le introduce intr-o stiva
	avl.root->scrie_echipele_pe_nivel(avl.root, 3, rezultate);					// di aceasta stiva, se extrtage pe rand cate o echipa, urmand ca aceasta sa fie introdusa mai apoi in avl
	
	delete bst.root; 															// se elibereaza memoria ocupata de arbore, prin apelul recursiv al destructorului
	delete avl.root; 															// se elibereaza memoria ocupata de avl
	
	rezultate.close();
    date_echipe.close();
}



























