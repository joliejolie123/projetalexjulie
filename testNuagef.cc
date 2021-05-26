#include <iostream>
#include "Cielf.h"
#include "Constantes.h"
//#include "Montagne.h"
//#include "ChampPotentielf.h"
#include "Vecteur2Df.h" 
using namespace std;

void affiche(int n_cubes, double longueur, double l, const Ciel& ciel, const Montagne& montagne) {
	// Format i j k V2 h T P P_eau P_rosee nuage
	cout.precision(15);
	for (int i(0); i < n_cubes; ++i) {
		for (int j(0); j < n_cubes; ++j) {
			for (int k(0); k < n_cubes; ++k) {
				if (k*l >= montagne.altitude(i*l, j*l - longueur/2) 
				and not ciel.bord(i,0) and not ciel.bord(j,1) and not ciel.bord(k,2)){
					
					CubedAir a(ciel.getCube(i,j,k));
					
					cout << i << "  " << j << "  " << k << "  " << a.toString({"v2", "h", "T", "P", "P_eau", "P_rosee", "nuage"}) << endl;
				}
			}
		}
	}
}

int main() {
	
	cout << "ok" << endl;
	int n_cubes(30);
	double longueur(20.0);
	double lambda(longueur / (n_cubes - 1));
	double v_inf(20.0);
	MontagneGaussienne m(15*lambda, 15*lambda - 20/2, 15*lambda, 5*lambda, 5*lambda);
	ChampPotentiel champ({longueur, longueur, longueur}, {n_cubes, n_cubes, n_cubes});
	champ.initialise(v_inf, m);
	champ.resolution(m, lambda*lambda*lambda*lambda*1e-04, 2000, false);
	double P_inf = Physique::P_ref;
	double T_inf = 284.5;
	double taux_humidite = 8e-3;
	double h_inf = 3.5 * Physique::R * T_inf / Physique::M_airsec;
	double cte = 0.5 * v_inf * v_inf + h_inf;
	
	
	Ciel c(champ, taux_humidite);
	c.calc_nuage(cte, P_inf, T_inf/*, taux_humidite*/); // arguments : cte, P_inf, T_inf, taux_humidite
	affiche(n_cubes, longueur, lambda, c, m);
	return 0;
	
}


/*
int main() {
	
	Montagne m(15.0*(20.0/29.0), 15.0*(20.0/29.0) - 20/2, 15.0*(20.0/29.0), 5.0*(20.0/29.0), 5.0*(20.0/29.0));
	
	Ciel c({20.0, 20.0, 20.0}, {30, 30, 30});
	
	
	c.affiche();
	
	
	
	cout << "ok" << endl;
	
	return 0;
}
*/

