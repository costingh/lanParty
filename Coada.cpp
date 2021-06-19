#include "Stiva.hpp"

Coada::Coada() : front(NULL), rear(NULL) {}
   
Coada::Coada(int nr) : nr_meciuri(nr), front(NULL), rear(NULL) {}

Coada::Coada(const Coada &coada) : nr_meciuri(coada.nr_meciuri), front(NULL), rear(NULL) { *this = coada; }

Coada& Coada::operator=(const Coada &coada) 
{ 	
	if(this != &coada)
	{
		nr_meciuri = coada.nr_meciuri;
		front = NULL;
		rear = NULL;
		Meci *aux = coada.front;
		while(aux != NULL)
		{
			adauga_meci(*aux);
			aux = aux->next;
		}
		delete aux;
	}
	return *this;
}

Coada::~Coada()
{	
	Meci * temp;
    while(front != NULL){
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;;	
}

void Coada::adauga_meci(const Meci &m)
{
	Meci *meci = new Meci(); 
	*meci = m;
    if (rear == NULL) { 
        front = rear = meci; 
        return; 
    } 
    rear->next = meci; 
    rear = meci; 
}

void Coada::creeaza_meciuri(const Lista &l) 										// se iau cate doua echipe consecutive din lista, se creeaza un meci cu acestea, iar apoi medciul este adaugat in coada
{
	Echipa *echipa = new Echipa();
	echipa = l.getStart();

	for(int i = 0; i < nr_meciuri; i++)
	{
		Meci meci(*echipa, *echipa->next_team);
		adauga_meci(meci);			
		echipa = echipa->next_team->next_team;
	}
	delete echipa;
}

void Coada::golesteCoada()															
{
	if (front == NULL) 
        return; 
    else
    {
    	while(front != NULL)
		{
			Meci* temp = front; 
	    	front = front->next;
			 
	    	delete temp;
		}
		rear = NULL; 	
	}
}

void Coada::writeMatches(std::ofstream& matches_list, int nr) const
{
	Meci *meci = new Meci();
	meci = front;		
	if(meci != NULL)
	{
		matches_list << '\n';
		matches_list << "--- ROUND NO:" << nr << '\n';
		while (meci != NULL)
		{	
			matches_list << *meci;
			meci = meci->next;
		}
		delete meci;
	}
}

Meci* Coada::getFront() const { return front; }

int Coada::getNumarMeciuri() const { return nr_meciuri; }

void Coada::setNumarMeciuri(int nr) { nr_meciuri = nr; }
