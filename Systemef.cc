#include <iostream>
#include "Systemef.h"
using namespace std;
// MontagneGaussienne -> Montagne ????????????????????????????
Systeme::Systeme(ChampPotentiel* champ, MontagneGaussienne* montagne, double v_inf, double cte, double P, double T, double taux)
: champ(champ), montagne(montagne) {
	champ->initialise(v_inf, *montagne);
}

Montagne* Systeme::getMontagne() const {
	return montagne;
}

ChampPotentiel* Systeme::getChamp() const {
	return champ;
}

Ciel* Systeme::getCiel() const {
	return ciel;
}

void Systeme::deplacerNuages(double dt) {
	array<int,3> n_cubes(ciel->get_n_cubes());
	for(int i(0); i < n_cubes[0]; ++i) {
		for(int j(0); j < n_cubes[1]; ++j) {
			for(int k(0); k < n_cubes[2]; ++j) {
				CubedAir cube(ciel->getCube(i,j,k));
				double t(cube.get_humidite());
				
				array<int,3> previous_cube(ciel->previous(dt,i,j,k));
				int pi(previous_cube[0]);
				int pj(previous_cube[1]);
				int pk(previous_cube[2]);
				
				if(pi != i or pj != j or pk != j) { // Si le cube précédent est différent du cube actuel
					if(cube.get_nuage() and (not ciel->in_boite(pi,pj,pk) or not ciel->getCube(pi,pj,pk).get_nuage())) { // ????????????????????????? Dans boite ca marche comment ???????????????????
						double nouveau_taux(t * (1 - 0.017));
						ciel->set_humidite(i,j,k, nouveau_taux); // ???????????
					} else if (not cube.get_nuage() and ciel->in_boite(pi,pj,pk) and ciel->getCube(pi,pj,pk).get_nuage()) { // ????????????????????????? Dans boite ca  marche comment ??????????????????
						double nouveau_taux(t * (1 + 0.05));
						ciel->set_humidite(i,j,k, nouveau_taux);
					}
				}
			}
		}
	}
}
						
				

void Systeme::dessine_sur(SupportADessin& support) const {
	support.dessine(*this);
}

void Systeme::afficher(std::ostream& sortie) const {
	sortie << "Le système est constitué de : " << std::endl << std::endl;
	montagne->afficher(cout);
	champ->affiche_potentiel();
}

void Systeme::evolue(double dt) {
	deplacerNuages(dt);
	ciel->calc_nuage(cte, P_inf, T_inf);
}

void Systeme::demarre(SupportADessin& support) {
	champ->resolution(*montagne, 1e-04, 3000, false);
	ciel = new Ciel(*champ, taux_humidite_initial, {v_inf, 0, 0});
	ciel->calc_nuage(cte, P_inf, T_inf);
}

void Systeme::afficher_ciel(std::ostream& out, std::vector<std::string> , char sep) const { // ???????????????????????????????????
	std::vector<std::string> format({"v2", "h", "T", "P", "P_eau", "P_rosee", "nuage"});
	ciel->afficher(out, *montagne, format);
	// Demander afficher() dans ciel (différents paramètres)
}

