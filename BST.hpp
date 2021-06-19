#include "Stiva.hpp"

class BST  
{ 
protected:
    Echipa echipa;
	BST *left, *right;
public: 
	BST *root;
    BST(); 
    BST(const BST &);
    BST& operator=(const BST &); 
    ~BST();
    BST(const Echipa &); 										// se connstruieste un obiect de tip BST cu echipa primita ca parametru
    BST* adauga_echipa(BST*, const Echipa &); 					// metoda de adaugare a unei echipe in arbore
    BST* creeaza_arbore(BST* , Stiva &);						// metoda ce extrage o echipa din stiva primita ca parametru, si o introduce in arbore prin intermediul metodei de mai sus
    void scrie_arbore_in_fisier(BST*, std::ofstream &); 		// metoda de scriere in fisier a continutului arborelui
    BST* getLeft() const;									
    BST* getRight() const;	
    Echipa getEchipa() const;							
    static BST* copiaza(BST *);									// metoda de copiere recursiva a tuturor elementelor din arborele primit ca parametru in arborele actual
}; 
  


