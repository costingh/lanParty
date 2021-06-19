#include "Echipa.hpp"

class Lista
{
private:
	int nr_echipe;
    Echipa *start_echipe;
public: 
	Lista();
	~Lista();
	Lista(int nr);
	Lista(const Lista &);
	Lista& operator=(const Lista &);
	int getNrEchipe() const;
	Echipa* getStart() const;
	void sterge_minim();
	void elimina_echipe();
	void addTeam(const Echipa &);
	void scrie(std::ofstream &) const;
	void adauga_la_final(const Echipa &);
	friend std::istream& operator>>(std::istream &, Lista &);
	friend std::ostream& operator<<(std::ostream &, const Lista &);
};


