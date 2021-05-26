#include <array>
#include <string>
#include "Boite3Df.h"
#include "ChampPotentielf.h"
#include "Potentielf.h"
#include "Montagnef.h"
#include "Vecteur2Df.h"
#include <iostream>
using namespace std;

ChampPotentiel::ChampPotentiel(std::array<double,3> l, std::array<int,3> n)
: Boite3D(l,n)
{}

Potentiel ChampPotentiel::get_potentiel(int i, int j, int k) const {
	return potentiels[i][j][k];
}

void ChampPotentiel::initialise(double v, const MontagneGaussienne& m) {
	for(int i(0); i < n_cubes[0]; ++i) {
		vector<vector<Potentiel> > tab2;
		double xi(i * lambdas[0]);
		
		for(int j(0); j < n_cubes[1]; ++j) {
			vector<Potentiel> tab1;
			double yj(j_to_y(j));
			
			for(int k(0); k < n_cubes[2]; ++k) {
				double zk(k * lambdas[2]);
				if (zk >= m.altitude(xi, yj)) {
					Vecteur2D A((-v * zk) / 2, (v * yj) / 2);
					Vecteur2D lapA;
					Potentiel p(A, lapA);
					tab1.push_back(p);
				} else {
					Vecteur2D A;
					Vecteur2D lapA;
					Potentiel p(A, lapA);
					tab1.push_back(p);
				}
			}
			tab2.push_back(tab1);
		}
		potentiels.push_back(tab2);
	}
}

void ChampPotentiel::affiche_laplacien() const {
	for(size_t  i(1); i < n_cubes[0] - 1; ++i) {
		for(size_t  j(1); j < n_cubes[1] - 1; ++j) {
			for(size_t k(1); k < n_cubes[2] - 1; ++k) {
				cout << i << " " << j << " " << k << " " << potentiels[i][j][k].getLaplacien() << endl;
			}
		}
	}
}

void ChampPotentiel::affiche_potentiel() const {
	for(size_t  i(0); i < n_cubes[0]; ++i) {
		for(size_t  j(0); j < n_cubes[1]; ++j) {
			for(size_t k(0); k < n_cubes[2]; ++k) {
				cout << i << " " << j << " " << k << " " << potentiels[i][j][k].getPotentiel() << endl;
			}
		}
	}
	
}


Vecteur2D ChampPotentiel::calcul_laplacien(int i, int j, int k) const {
	// Calcul du laplacien de la cube position i, j, k
	Vecteur2D v0 = (potentiels[i][j][k]).getPotentiel();
	Vecteur2D v1 = (potentiels[i-1][j][k]).getPotentiel();
	Vecteur2D v2 = (potentiels[i][j-1][k]).getPotentiel();
	Vecteur2D v3 = (potentiels[i][j][k-1]).getPotentiel();
	Vecteur2D v4 = (potentiels[i+1][j][k]).getPotentiel();
	Vecteur2D v5 = (potentiels[i][j+1][k]).getPotentiel();
	Vecteur2D v6 = (potentiels[i][j][k+1]).getPotentiel();
	return v1 + v2 + v3 - 6 * v0 + v4 + v5 + v6;
}



void ChampPotentiel::calcul_laplacien(MontagneGaussienne const& m) { 
	
	
	for(int i(1); i < n_cubes[0] - 1; ++i) {
		//cout << "ok" << endl;
		for(int j(1); j < n_cubes[1] - 1; ++j) {
			//cout << "ok" << endl;
			for(int k(1); k < n_cubes[2] - 1; ++k) {
				//cout << "ok" << endl;
				if(k*lambdas[2] >= m.altitude(i*lambdas[0], j_to_y(j))) {
					//cout << "DABBBBBBB" << endl;
					(potentiels[i][j][k]).setLaplacien(calcul_laplacien(i,j,k)); //ICI LE SEGFAULT!!!!!!!!!!!!!!!!!!!
				}
			}
		}
	}
}

	/*
	// Calcul du laplacien pour chaque cube du champ
	for(int i(1); i < n_cubes[0] - 1; ++i) {
		double xi(lambdas[0]*i);
		for(int j(1); j < n_cubes[1] - 1; ++j) {
			double yj(lambdas[1]*j - longueurs[1]/2);
			for(int k(1); k < n_cubes[2] - 1; ++k) {
				double zk(lambdas[2]*k);
				if (zk >= m.altitude(xi, yj)) {
					potentiels[i][j][k].setLaplacien(calcul_laplacien(i, j, k));
				}
			}
		}
	}
}
//
*/


double ChampPotentiel::erreur() const {
	double a(0.0);
	for(int i(0); i < n_cubes[0]; ++i) {
		for(int j(0); j < n_cubes[1]; ++j) {
			for(int k(0); k < n_cubes[2]; ++k) {
				Vecteur2D laplacien(potentiels[i][j][k].getLaplacien());
				a += laplacien.norme2();
			}
		}
	}
	return a;
}

void ChampPotentiel::iteration() {
	for(int i(1); i < n_cubes[0] - 1; ++i) {
		for(int j(1); j < n_cubes[1] - 1; ++j) {
			for(int k(1); k < n_cubes[2] - 1; ++k) {
				Vecteur2D p(potentiels[i][j][k].getPotentiel());
				Vecteur2D diff_p(potentiels[i][j][k].getLaplacien());
				Vecteur2D n(p + 0.1 * diff_p);
				potentiels[i][j][k].setPotentiel(n);
			}
		}
	}
}

void ChampPotentiel::resolution(MontagneGaussienne const& m, double seuil, int max, bool verbeuse) {
	int n(0);
	do {
		calcul_laplacien(m);
		iteration();
		if (verbeuse) {
			affiche_potentiel();
			std::cout << std::endl;
			affiche_laplacien();
		}
		++n;
	} while(erreur() > seuil and n < max);
}

array<double,3> ChampPotentiel::vitesse(int i, int j, int k, array<double,3> v_default) const {
	
	if(bord(i,0) or bord(j,0) or bord(k,2)) {
		return v_default;
	}
	
	Vecteur2D a = potentiels[i-1][j][k].getPotentiel();
	Vecteur2D b = potentiels[i][j-1][k].getPotentiel();
	Vecteur2D c = potentiels[i][j][k-1].getPotentiel();
	Vecteur2D d = potentiels[i+1][j][k].getPotentiel();
	Vecteur2D e = potentiels[i][j+1][k].getPotentiel();
	Vecteur2D f = potentiels[i][j][k+1].getPotentiel();
	
	return {
		(1.0 / (2*lambdas[0])) * (e.getY() - b.getY() - f.getX() + c.getX()),
		(1.0 / (2*lambdas[1])) * (-d.getY() + a.getY()),
		(1.0 / (2*lambdas[2])) * (d.getX() - a.getX())
	};
}

void ChampPotentiel::dessine_sur(SupportADessin& support) const {
	support.dessine(*this);
}

