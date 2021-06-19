#include "Meci.hpp"

class Coada
{
private:
	int nr_meciuri;
    Meci *front, *rear;
public: 
	Coada();
	Coada(int nr);
	Coada(const Coada &);
	Coada& operator=(const Coada &);
	~Coada();
	void adauga_meci(const Meci& );
	void creeaza_meciuri(const Lista& );
	void writeMatches(std::ofstream &, int ) const;
	void golesteCoada();
	Meci* getFront() const;
	int getNumarMeciuri() const;
	void setNumarMeciuri(int nr);
};


