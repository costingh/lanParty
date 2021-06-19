#include "AVL.hpp"

AVL::AVL() : left(NULL), right(NULL), height(1), root(NULL) {} 

AVL::AVL(const AVL &avl) { root = copiaza(avl.root); }
	
AVL* AVL::copiaza(AVL *t)
{
    if ( t != NULL )
    {
        AVL* left = copiaza( t->left );
        AVL* right = copiaza( t->right );
        AVL *node;
        node->echipa = t->echipa;
        node->left = t->left;
        node->right = t->right;
        node->height = t->height;
        node->root = t->root;
        return node;
    }
    else
        return NULL;
}

AVL& AVL::operator=(const AVL &avl) 
{ 	
	root = copiaza(avl.root);
	return *this;
}

AVL::AVL(const Echipa &ech) 
{ 
    echipa = ech;    
    left = right = NULL; 
    height = 1;
} 

AVL* AVL::echipa_noua(const Echipa &ech)  
{    
    AVL* avl = new AVL(ech); 
    return avl;  
}    
    												
AVL* AVL::rightRotate(AVL *y)						/*         y                               x		*/
{  							 						/*        / \       rightRotate           /  \ 		*/
    AVL *x = y->left;  								/*       x   T3   - - - - - - - >        T1   y 	*/
    AVL *T2 = x->right;  							/*		/ \       < - - - - - - -            / \ 	*/
	x->right = y;  									/*	  T1  T2         leftRotate            T2  T3	*/
    y->left = T2;  					
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;			
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;                   
    return x;  
}  

AVL* AVL::leftRotate(AVL *x)  
{  
    AVL *y = x->right;  
    AVL *T2 = y->left;  
    y->left = x;  
    x->right = T2;  
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;                 
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;                 
    return y;  
}  
 
AVL* AVL::adauga(AVL* root, const Echipa &ech)  								// metoda ce adauga o echipa in subarborele cu radacina root
{  																				// si care returneaza radacina subarborelui
	if (!root)  
       return(echipa_noua(ech));  
       
	if (ech.getMedie() > root->echipa.getMedie())   							
		root->right = adauga(root->right, ech);			 
    else if (ech.getMedie() < root->echipa.getMedie())													
		root->left = adauga(root->left, ech);   	
	else if (ech.getMedie() == root->echipa.getMedie())	
	{
		int x = compara_doua_stringuri(ech.getTeamName(), root->echipa.getTeamName());
		if (x >= 0)
			root->right = adauga(root->right, ech);
		else
			root->left = adauga(root->left, ech);
	}
	
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));  	// se acualizeaza inaltimea
    int balance = getBalance(root);  											// se calculeaza factorul de echilibru pentru a se vedea daca nodul nu mai este echilibrat
		
    if (balance > 1 && ech.getMedie() <= root->left->echipa.getMedie())  		// daca factorul de echilibru > 1 , inseamna ca AVL nu este echilibrat la acest nod
        return rightRotate(root);  												// inaltimea pe partea stanga este mai mare decat cea pe partea dreapta      				
    if (balance < -1 && ech.getMedie() > root->right->echipa.getMedie())  		
        return leftRotate(root);    
    if (balance > 1 && ech.getMedie() > root->left->echipa.getMedie())  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
    if (balance < -1 && ech.getMedie() < root->right->echipa.getMedie())  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
    return root;  
}  
AVL* AVL::creeaza_avl(AVL* root, BST* bst)										// metoda care, creeaza o stiva cu elementele din BST si extrage pe rand cate o echipa pe care o adauga in AVL
{
	Stiva stiva_cu_elemente_din_BST;
	creeaza_stiva(bst, stiva_cu_elemente_din_BST);
	Echipa *echipa_din_stiva = stiva_cu_elemente_din_BST.top();
	
	while(echipa_din_stiva)
	{
		root = adauga(root, *echipa_din_stiva);
		stiva_cu_elemente_din_BST.pop();
		echipa_din_stiva = stiva_cu_elemente_din_BST.top();
	}
	return root;
}

void AVL::creeaza_stiva(BST *root, Stiva &stiva)								// se populeaza cu elemente stiva primita ca parametru
{
	if (!root)
		return;	
	creeaza_stiva(root->getLeft(), stiva);
	stiva.push(root->getEchipa());
	creeaza_stiva(root->getRight(), stiva);	
}
  
void AVL::scrie_echipele_pe_nivel(AVL* root, int level, std::ofstream &rezultate) 
{ 																			 	// metoda care se apeleaza recursiv, pana cand se ajunge la nivelul dorit, dipa care numele echipelor din acele noduri sunt scrise si in fisier
    if (root == NULL) 
        return;          
    if (level == 1) 
   		rezultate << root->echipa.getTeamName() << std::endl; 
    else if (level > 1) 
    {  
        scrie_echipele_pe_nivel(root->right, level-1, rezultate); 
        scrie_echipele_pe_nivel(root->left, level-1, rezultate);
    } 
} 

AVL::~AVL() 
{
	delete left; 
    delete right; 
}

int AVL::max(int a, int b) const { return (a > b)? a : b; }

int AVL::getHeight(AVL *avl) const
{  
    if (avl != NULL)  
		return avl->height; 
	return 0;   
} 

int AVL::getBalance(AVL *avl)  
{  
    if (avl != NULL)  
		return (getHeight(avl->left) - getHeight(avl->right));  
	return 0;  
}  



