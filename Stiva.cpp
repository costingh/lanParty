#include "Stiva.hpp"

Stiva::Stiva() : front(NULL) {}
	
Stiva::Stiva(const Stiva &stiva) : front(NULL) { *this = stiva; }

Stiva& Stiva::operator=(const Stiva &stiva) 
{ 	
	if(this != &stiva)
	{
		front = NULL;
		Echipa *aux = stiva.front;
		while(aux != NULL)
		{
			push(*aux);
			aux = aux->next_team;
		}
		delete aux;
	}
	return *this;
}	

Stiva::~Stiva()
{
	while(front != NULL)
		this->pop();
}

void Stiva::push(const Echipa &echipa)
{
	Echipa *temp = new Echipa();
	*temp = echipa;
	if(front == NULL)
		temp->next_team = NULL;
	else
		temp->next_team = front;
		
	front = temp;
}

void Stiva::pop()
{
	if(front == NULL)
		std::cout << "Stiva este goala !! \n";
	else
	{
		Echipa *temp = front;
		front = front->next_team;
		delete temp;
	}
}

void Stiva::display() const
{	
	Echipa *temp = new Echipa();
	temp = front;
	if(front == NULL)
		std::cout << "Stiva este goala !! \n";
	else
	{
		while(temp != NULL)
		{
			std::cout<< "Nume echipa: " << temp->getTeamName() << std::endl;
			temp = temp->next_team;
		}
	}
}

void Stiva::creeaza_stiva_castigatori(const Coada &coada)
{
	Meci *meci = new Meci();
	meci = coada.getFront();
	while(meci != NULL)
	{	
		this->push(meci->getWinner());
		meci = meci->next;
	}
	delete meci;
}

void Stiva::creeaza_stiva_pierzatori(const Coada &coada)
{
	Meci *meci = new Meci();
	meci = coada.getFront();
	while(meci != NULL)
	{		
		this->push(meci->getLoser());
		meci = meci->next;
	}
	delete meci;
}

Stiva Stiva::writeWinners(std::ofstream& winners_list, int nr)
{
	Stiva stiva;
	Echipa *echipa = this->top();	
	winners_list << '\n';
	winners_list << "WINNERS OF ROUND NO:" << nr << '\n';
	while (echipa != NULL)
	{	
		winners_list << *echipa;
		stiva.push(*echipa);
		this->pop();
		echipa = this->top();
	}
	delete echipa;
	return stiva;
}

void Stiva::goleste_stiva()
{
	while(front != NULL)
		this->pop();	
}

void Stiva::formeaza_meciuri(Coada *coada)
{	
	Echipa *echipa = front;
	if( coada->getNumarMeciuri()/2 != 0)
	{	
		for(int i = 0; i < coada->getNumarMeciuri()/2; i++)
		{
			Meci meci(*echipa, *echipa->next_team);
			coada->adauga_meci(meci);			
			echipa = echipa->next_team->next_team;
		}
		coada->setNumarMeciuri(coada->getNumarMeciuri()/2);	
	}
}

Echipa* Stiva::top() { return front; }

Stiva Stiva::adauga_puncte()
{
	Stiva stiva;
	Echipa *echipa = this->top();	
	while (echipa != NULL)
	{
		echipa->modificaMedie();
		stiva.push(*echipa);
		this->pop();
		echipa = this->top();
	}	
	delete echipa;
	return stiva;
}

Stiva Stiva::creeaza_si_scrie_in_fisier_coada(Lista lista, std::ofstream &rezultate)
{
	int nr_echipe_ramase = lista.getNrEchipe();								// se calculeaza numarul echipelor din lista primita 
	Coada coada(nr_echipe_ramase/2);										// in coada se vor stoca meciurile, ale caror numar este jumatate din numarul echipelor
	coada.creeaza_meciuri(lista);											// se populeaza coada cu meciuri (cate doua echipe consecutive formeaza un meci)
	coada.writeMatches(rezultate, 1);										// se scriu meciurile in fisier ( parametrul 1 face ca in fisier sa fie scrisa linia : --- ROUND NO:1
	Stiva castigatori, pierzatori, ultimele_opt_echipe;						// stive cu castigatorii si pierzatorii dintr-un meci, dar si cu cele 8 echipe ramase la finalul executiei functiei 
	int numar_runde = log2(nr_echipe_ramase);								// Numarul de runde este logaritm in baza 2 din numarul de echipe ramase in competitie(2^nr_runde = nr_echipe)

	for(int runda = 0; runda < numar_runde; runda++)						// pentru fiecare runda
	{
		castigatori.creeaza_stiva_castigatori(coada);						// din coada de meciuri, se extrag castigatorii in stiva de castigatori
		castigatori = castigatori.adauga_puncte();							// se adauga cate un punct de echipa (un punct la fiecare jucator) la fiecare echipa castigatoare
		pierzatori.creeaza_stiva_pierzatori(coada);							// din coada de meciuri, se extrag castigatorii in stiva de pierzatori
		castigatori = castigatori.writeWinners(rezultate, runda+1);			// se creeaza o copie a stivei de castigatori, iar din cea initiala se extrage cate o echipa, care este scrisa in fisier, pana cand stiva se goleste			
		if(numar_runde >= 3 && numar_runde - 1 - runda == 3)				// Daca pana la runda finala mai sunt 3 runde, inseamna ca in stiva castigatori 																	
			ultimele_opt_echipe = castigatori;								// avem  cele 8 echipe pe care trebuie sa le punem intr-un arbore binar de cautare ( 2^3=8 )
		pierzatori.goleste_stiva();											// se goleste stiva de pierzatori
		coada.golesteCoada();												// se goleste coada cu meciuri
		castigatori.formeaza_meciuri(&coada);								// din stiva de castigatori se vor crea din nou meciuri ( in coada care a fost golita )
		castigatori.goleste_stiva();										// se goleste stiva de castigatori
		coada.writeMatches(rezultate, runda+2);								// se scriu meciurile din coada in fisier 
	}
	return ultimele_opt_echipe;
}































