#include "Coada.hpp"

class Stiva
{
private:
	Echipa *front; 
public:
	Stiva();
	Stiva(const Stiva &);
	Stiva& operator=(const Stiva &);
	~Stiva();
	void push(const Echipa& );
	void pop();
	void display() const;	
	Echipa* top();
	void creeaza_stiva_castigatori(const Coada &);
	void creeaza_stiva_pierzatori(const Coada &);
	void writeMatches(std::ofstream &) const;
	Stiva writeWinners(std::ofstream &, int );
	void goleste_stiva();
	void formeaza_meciuri(Coada *coada);
	Stiva adauga_puncte();
	Stiva creeaza_si_scrie_in_fisier_coada(Lista , std::ofstream &);
};
