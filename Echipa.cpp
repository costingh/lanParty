#include "Echipa.hpp"

Echipa::Echipa() : nr_players(0), sumaPuncte(0), media(0), start(NULL), next_team(NULL) {}

Echipa::Echipa(int nr, std::string nume) : nr_players(nr), nume_echipa(nume), sumaPuncte(0), media(0), start(NULL), next_team(NULL) {}

Echipa::Echipa(const Echipa &e) : nr_players(e.nr_players), nume_echipa(e.nume_echipa), sumaPuncte(e.sumaPuncte), media(e.media), next_team(NULL), start(NULL) { *this = e; }

Echipa& Echipa::operator=(const Echipa &e) 
{ 	
	if(this != &e)
	{
		nr_players = e.nr_players;											// se copiaza valorile atributelor din obiectul primit ca parametru in obiectul actual
		nume_echipa = e.nume_echipa;
		sumaPuncte = e.sumaPuncte;
		media = e.media;
		next_team = NULL;
		start = NULL;
		Player *aux = e.start;												// se parcurge lista cu playeri din obiectul primit ca parametru se se creeaza o poie a tuturor elementelor
		while(aux != NULL)
		{
			adauga_player_la_final(*aux);
			aux = aux->next_player;
		}
		delete aux;
	}
	return *this;
}

Echipa::~Echipa() 															
{
	Player* current = start;
	while( current != NULL ) {
	    Player* next = current->next_player;
	    delete current;
	    current = next;
	}
	start = NULL;
}

void Echipa::addPlayer(const Player &p)
{	 
	Player *aux = new Player();
    *aux = p;	
	if (start == NULL)
	{
		start = aux;
		aux->next_player = NULL;
	}
	else 
	{   
		aux->next_player = start;
		start = aux;
    }
}

void Echipa::adauga_player_la_final(const Player &p)	// Folosita in constructorul de copiere pentru a nu se crea o lista de playeri
{														// inversata de fiecare data cand va fi apelat acesta
	Player *aux = new Player();
    *aux = p;
	aux->next_player = NULL;
	if (start == NULL)
	{
		start = aux;
		sumaPuncte += start->getPoints();
	}
	else 
	{   	
		Player *temp = new Player();
		temp = start;
        while (temp->next_player != NULL) 
            temp = temp->next_player; 
		sumaPuncte += aux->getPoints();
        temp->next_player = aux;		
    } 
}

std::istream& operator>>(std::istream &dev, Echipa &echipa) 
{
	dev >> echipa.nr_players;
	getline(dev, echipa.nume_echipa);
	echipa.nume_echipa.erase(0,1);

	int pos = echipa.nume_echipa.find_last_not_of(" ");												// se verifica daca exista spatiu la sfarsitul numeului echipe, daca da, va fi sters
	if (pos != std::string::npos)
		echipa.nume_echipa.erase(pos+1);
	else
		echipa.nume_echipa.clear(); 

	for(int player = 0; player < echipa.nr_players; player++)
	{
		Player jucator;
		dev >> jucator;
		echipa.addPlayer(jucator);
	}
	return dev;
}

std::ostream& operator<<(std::ostream &dev, const Echipa &echipa) 
{
	dev << std::left << std::setw(34) << echipa.nume_echipa << "-  " ;
    dev << std::fixed << std::setprecision(2) << echipa.media << "\n"; 
	return dev;
}

std::string Echipa::getTeamName() const { return nume_echipa; }

void Echipa::calcMedie() { media = (float)sumaPuncte/nr_players; }

float Echipa::getMedie() const { return (float)media; }

void Echipa::modificaMedie() { media += 1; }														// se adauga cate un punct de echipa
