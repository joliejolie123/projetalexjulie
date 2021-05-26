#include <iostream>
#include "TextViewerf.h"
#include "Constantes.h"
#include "Montagnef.h"
//#include "ChampPotentielf.h"
#include "Cielf.h"
#include "Systemef.h"
#include <array>
#include <vector>

using namespace std;

void testDeplacement(Systeme& s, int p) {
	for(int i(0); i < p ; ++i) {
		s.evolue(0.031);
	}
	std::vector<std::string> format({"v2", "h", "T", "P", "P_eau", "P_rosee", "nuage"});
	s.afficher_ciel(cout, format); // ???????????????????????????????????????
}

int main() {
	TextViewer textviewer(cout); 
	
	array<int,3> n_cubes({30,30,30});
	array<double,3> longueurs({20,20,20});
	
	double lambda(longueurs[0] / (n_cubes[0] - 1));
	double v_inf(20);
	
	MontagneGaussienne m(15, 15, 15 * lambda, 5, 5, longueurs, n_cubes); // ERROR : Variable type 'MontagneGaussienne' is an abstract class
	ChampPotentiel champ(longueurs, n_cubes);
	
	double P_inf = Physique::P_ref;
	double T_inf = 284.5;
	double taux_humidite = 8e-3;
	
	double h_inf = 3.5 * Physique::R * T_inf / Physique::M_airsec;
	double cte = 0.5 * v_inf * v_inf * h_inf;
	//Ciel(const ChampPotentiel& champ, double taux_humidite, std::array<double,3> v_default = {0.0, 0.0, 0.0});
	//Ciel c(champ,taux_humidite);
	
	
	Systeme s(&champ, &m, v_inf, cte, P_inf, T_inf, taux_humidite);
	s.demarre(textviewer); // ??????????????????????????????????????? On met quel support à dessin ????????????????????
	
	s.dessine_sur(textviewer);
	
	//testDeplacement(s, 9);
	
	return 0;
}
