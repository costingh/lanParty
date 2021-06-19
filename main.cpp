#include "utils.h"

int main(int argc, char *argv[]) {
	std::ifstream cerinte(argv[1]);
	
	for (int i = 0; i < 5; i++) {
		int task;
		cerinte >> task;
		switch (i) {
			case 0: {
				if (task == 1)
					creaza_lista(argv);
				break;
			}
			case 1: {
				if (task == 1)
					elimina(argv);
				break;
			}
			case 2: {
				if (task == 1)
					creeaza_coada(argv);
				break;
			}
			case 3: {
				if (task == 1)
					creeaza_BST(argv);
				break;
			}
			case 4: {
				if (task == 1)
					creeaza_AVL(argv);
				break;
			}
			default: {
				std::cout << "Error! " << std::endl;
				break;
			}
		}
	}
	cerinte.close();
	return 0;
}

