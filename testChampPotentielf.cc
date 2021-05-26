#include <iostream>
#include "ChampPotentielf.h"
#include <iostream>
#include "Vecteur2Df.h" 
using namespace std;

int main() {
	
	//MontagneGaussienne m(15.0*(20.0/29.0), 15.0*(20.0/29.0) - 20/2, 15.0*(20.0/29.0), 5.0*(20.0/29.0), 5.0*(20.0/29.0));
	
	MontagneGaussienne m(15, 15, 18.0, 10, 5);
	
	ChampPotentiel c({20.0, 20.0, 20.0}, {30, 30, 30});
	
	c.initialise(20.0, m);
	
	c.calcul_laplacien(m);
	
	c.affiche_laplacien();
		
	//c.affiche_potentiel();
	
	//c.affiche_laplacien();


	
	return 0;
}


