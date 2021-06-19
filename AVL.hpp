#include "BST.hpp"

class AVL
{  
private:  
	Echipa echipa;													
    AVL *left, *right; 												
    int height;  
public:
	AVL *root;													
	AVL(); 
    AVL(const AVL &);
    AVL& operator=(const AVL &);    
	~AVL(); 
    AVL(const Echipa &);
    AVL* adauga(AVL* , const Echipa &); 							// metoda care adauga o echipa in AVL
    AVL* echipa_noua(const Echipa &);  								// metoda care creeaza un obiect de tipul avl, cu echipa primita ca parametru
    AVL* rightRotate(AVL *);   										// metoda folosita petru echilibrarea arborelui
    AVL* leftRotate(AVL *);  
    int getBalance(AVL *); 											// metoda care calculeaza factorul de echilibru
    int max(int , int ) const;  									
    int getHeight(AVL *) const;	 
    void scrie_echipele_pe_nivel(AVL* , int , std::ofstream &); 	// se scriu in fisier echipele, de pe nivelul arborelui primit ca parametru
    void creeaza_stiva(BST *, Stiva &);								// se creeaza stiva cu elementele din bst, primit ca parametru, in mod descrescator (exact ca in clasament cu cele 8 echipe )
    AVL* creeaza_avl(AVL* , BST *);									// se introduc echipele din stiva, in avl
    static AVL* copiaza(AVL *);										// metoda ce copiaza recursiv elementele unui arbore (folosita la impelmetarea constructorului de copiere, si a operatorului= )
};  







