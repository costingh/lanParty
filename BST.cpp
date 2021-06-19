#include "BST.hpp"

BST::BST() : left(NULL), right(NULL), root(NULL) {} 

BST* BST::copiaza(BST *t)
{
    if ( t != NULL )
    {
        BST* left = copiaza( t->left );
        BST* right = copiaza( t->right );
        BST *node;
        node->echipa = t->echipa;
        node->left = t->left;
        node->right = t->right;
        node->root = t->root;
        return node;
    }
    else
        return NULL;
}

BST& BST::operator=(const BST &bst) 
{ 	
	root = copiaza(bst.root);
	return *this;
}

  
BST::BST(const Echipa &ech) 
{ 
    echipa = ech;
    left = right = NULL; 
} 
  
BST* BST::adauga_echipa(BST* root, const Echipa &ech) 
{ 
    if (!root)  
        return new BST(ech); 																// returneaza un nou nod din bst
    if (ech.getMedie() > root->echipa.getMedie())   										// daca mediea echipei primita ca parametru este mai mare decat a celei din bst, aceasta va fi introdusa in dreapta acesteia
		root->right = adauga_echipa(root->right, ech);			 
    else if (ech.getMedie() < root->echipa.getMedie())													
		root->left = adauga_echipa(root->left, ech);   										// se introduce in stanga
	else if (ech.getMedie() == root->echipa.getMedie())										// daca mediile sunt egale, introducerea echipelor in arbore se face in ordine alfabetica
	{
		int x = compara_doua_stringuri(ech.getTeamName(), root->echipa.getTeamName());
		if (x >= 0)
			root->right = adauga_echipa(root->right, ech);
		else
			root->left = adauga_echipa(root->left, ech);
	}
	return root; 
} 

void BST::scrie_arbore_in_fisier(BST* root, std::ofstream& rezultate) 
{ 
    if (!root) 
        return; 
   
    scrie_arbore_in_fisier(root->right, rezultate); 
    rezultate << std::left << std::setw(34) << root->echipa.getTeamName() << "-  " ;
	rezultate << std::fixed << std::setprecision(2) << root->echipa.getMedie() << "\n";    
    scrie_arbore_in_fisier(root->left, rezultate);       
} 
 
BST* BST::creeaza_arbore(BST *root, Stiva &stiva_top_opt_echipe)							// metoda care creeaza un arbore binar de cautare dintr-o stiva data ( cu cele ultimele 8 echipe din competitie )
{
	Echipa *echipa = stiva_top_opt_echipe.top();
	while(echipa != NULL)
	{
		root = adauga_echipa(root, *echipa);
		stiva_top_opt_echipe.pop();
		echipa = stiva_top_opt_echipe.top();
	}
	delete echipa;
	return root;
}

BST::~BST() {
	delete left; 
    delete right; 
}  

BST* BST::getLeft() const { return left; }

BST* BST::getRight() const { return right; }

Echipa BST::getEchipa() const { return this->echipa; }









