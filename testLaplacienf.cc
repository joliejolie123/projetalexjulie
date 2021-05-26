#include <iostream>
#include "ChampPotentielf.h"
using namespace std;

void affiche(int n_cubes, double l, double v_inf, const ChampPotentiel& champ, const MontagneGaussienne& m) {
	for (int i(0); i < n_cubes; ++i) {
		for (int j(0); j < n_cubes; ++j) {
			for (int k(0); k < n_cubes; ++k) {
				
				Potentiel p(champ.get_potentiel(i,j,k));
				array<double,3> v(champ.vitesse(i,j,k, {v_inf, 0,0}));
				
				cout << i << " " << j << " " << k << " " << p.getPotentiel().getX() << " " << p.getPotentiel().getY() << " " << v[0] <<  " " << v[1] << " " << v[2] << " " << v[0]*v[0] + v[1]*v[1] + v[2]*v[2] << endl;
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main() {
	
	array<int,3> n_cubes({30,30,30});
	array<double,3> l({20,20,20});
	double lambda(l[0] / (n_cubes[0] - 1));
	
	double v_inf(20);
	
	MontagneGaussienne m(15, 15, 15 * lambda, 5, 5, l, n_cubes);
	ChampPotentiel champ(l, n_cubes);
	
	champ.initialise(v_inf, m);
	champ.calcul_laplacien(m);
	//champ.resolution(m, lambda*lambda*lambda*lambda*1e-4, 2000, false);
	
	cout << champ.erreur();
	
	return 0; 
	
}
	
/*
int main() {
	array<int,3> n_cubes({30,30,30});
	array<double,3> longueurs({20,20,20});
	double lambda(longueurs[0] / (n_cubes[0] - 1));
	
	double v_inf(20);
	
	MontagneGaussienne m(15, 15, 15 * lambda, 5, 5, longueurs, n_cubes);
	ChampPotentiel champ(longueurs, n_cubes);
	
	champ.initialise(v_inf, m);
	champ.resolution(m, lambda*lambda*lambda*lambda*1e-4, 2000, false);
	
	affiche(n_cubes[0], longueurs[0], v_inf, champ, m);
	
	return 0;
	
}*/
