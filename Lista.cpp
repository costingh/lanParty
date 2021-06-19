#include "Lista.hpp"

Lista::Lista(): nr_echipe(0), start_echipe(NULL) {}

Lista::Lista(int nr): nr_echipe(nr), start_echipe(NULL) {}

Lista::Lista(const Lista &l): nr_echipe(l.nr_echipe), start_echipe(NULL) { *this = l; }

Lista& Lista::operator=(const Lista &l)  														// se copiaza elementele din lista primita ca parametru, in lista actuala
{ 																								// deep copy
	if(this != &l)
	{
		nr_echipe = l.nr_echipe;
		start_echipe = NULL;
		Echipa *aux = l.start_echipe;
		while(aux != NULL)
		{
			adauga_la_final(*aux);
			aux = aux->next_team;
		}
		delete aux;
	}
  	return *this;
}

void Lista::addTeam(const Echipa &e)															// se adauga o echipa, la inceputul listei
{	
    Echipa *aux = new Echipa();
    *aux = e;	
	if (start_echipe == NULL)
	{
		start_echipe = aux;
		aux->next_team = NULL;
		start_echipe->calcMedie();
	}
	else 
	{   
		aux->next_team = start_echipe;
		start_echipe = aux;
		start_echipe->calcMedie();
    }
}

Lista::~Lista() 																				// destrucotul parcurge fiecare element al listei pe care il sterge
{																								// in momentul executarii instructiunii delete current - se va apela destrucotul obiectului current de tip Echipa
	Echipa* current = start_echipe;
	while( current != NULL ) {
	    Echipa* next = current->next_team;
	    delete current;
	    current = next;
	}
	start_echipe = NULL;
}

std::ostream& operator<<(std::ostream &dev, const Lista &lista) 								// metoda ce parcurge lista si scrie numele fiecarei echipe pe o linie separata din fisier
{
	Echipa *aux = new Echipa();
	aux = lista.start_echipe;		
	while (aux!= NULL)
	{	
		dev << aux->getTeamName() << '\n';
		aux = aux->next_team;
	}
	return dev;
}

std::istream& operator>>(std::istream &dev, Lista &lista) 
{
	if (!dev.eof())
		dev >> lista.nr_echipe;
	for(int echipa = 0; echipa < lista.nr_echipe; echipa++)
	{	
		Echipa echipa_de_jucatori;
		dev >> echipa_de_jucatori;
		lista.addTeam(echipa_de_jucatori);
	}
	return dev;
}

void Lista::elimina_echipe()																	// metoda ce elimina echipele cu cel mai mic punctaj de echipa
{																								
	int echipe_ramase = 1;																		// initializam numarul echipelor ramase cu 1
	for(int echipa = 0; echipa < nr_echipe; echipa++)											
	{	
		echipe_ramase *= 2;																		// calculam numarul de echipe ce trebuie sa ramana in fisier, ca fiind putere a lui 2 ( 2^echipe_ramase )
		if ( echipe_ramase <= nr_echipe && echipe_ramase*2 > nr_echipe)							// daca numarul este mai mic decat numarul initial de echipe, dar 2^echipe_ramase + 1 este mai mare
		{	
			for(int i = 0; i < nr_echipe - echipe_ramase; i++)									// vom apela metoda ce gaseste si sterge minimul de n-ori, unde n este numarul de echipe ce trebuie sterse
				sterge_minim();																	// egal cu diferenta intre numarul de echipe initial, si cel de echipe ramase
			nr_echipe = echipe_ramase;															// acualizam numarul de echipe din lista
			return;																				
		}
	}
}

void Lista::sterge_minim()																		// se parcurge lista, se gaseste echipa cu punctajul minim, se salveaza pozitia acesteia din lista, iar la finalul functiei aceasta 
{																								// este stearsa din lista
	Echipa *aux, *min;
	aux = start_echipe->next_team;  																
	min = start_echipe;	
	float valoare_minima = aux->getMedie(); 
	while(aux->next_team != NULL)
	{	
		if (aux->next_team->getMedie() < valoare_minima)
		{
			valoare_minima = aux->next_team->getMedie();
			min = aux;
		}
		aux = aux->next_team;
	}
	if(start_echipe->getMedie() <=  valoare_minima)
	{
		aux = start_echipe;
		start_echipe = start_echipe->next_team;
		delete aux;
		return;
	}
	aux = min->next_team;
	min->next_team = aux->next_team;
	delete aux;
}

void Lista::adauga_la_final(const Echipa &echipa)
{
	Echipa *aux = new Echipa();
    *aux = echipa;
	aux->next_team = NULL;
	if (start_echipe == NULL)
		start_echipe = aux;
	else 
	{   	
		Echipa *temp = new Echipa();
		temp = start_echipe;
        while (temp->next_team != NULL) 
            temp = temp->next_team; 
        temp->next_team = aux;		
    }    
}

int Lista::getNrEchipe() const { return nr_echipe; }

Echipa* Lista::getStart() const { return start_echipe; }
