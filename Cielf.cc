#include <iostream>
#include <array>
#include "Cielf.h"
#include "CubedAirf.h"
#include <iostream>
#include <cmath>
using namespace std;
// Constructeurs

Ciel::Ciel(array<double, 3> l, array<int, 3> n, double taux_humidite, double v1, double v2, double v3)
: Boite3D(l, n)
{
	for(int i(0); i < n_cubes[0]; ++i) {
		vector<vector<CubedAir> > tab2;
		
		for(int j(0); j < n_cubes[1]; ++j) {
			vector<CubedAir> tab1;
			
			for(int k(0); k < n_cubes[2]; ++k) {
				CubedAir c(array<double, 3>({v1, v2, v3}), taux_humidite);
				tab1.push_back(c);
			}
			tab2.push_back(tab1);
		}
		air.push_back(tab2);
	}
}
Ciel::Ciel(const ChampPotentiel& champ, double taux_humidite, std::array<double,3> v_default)
: Boite3D(champ.get_longueurs(), champ.get_n_cubes())
{
	for(int i(0); i < n_cubes[0]; ++i) {
		vector<vector<CubedAir> > tab2;
		
		for(int j(0); j < n_cubes[1]; ++j) {
			vector<CubedAir> tab1;
			
			for(int k(0); k < n_cubes[2]; ++k) {
				tab1.push_back(CubedAir(champ.vitesse(i,j,k, v_default), taux_humidite));
				//auto v = champ.vitesse(i,j,k);
				//std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;
			}
			tab2.push_back(tab1);
		}
		air.push_back(tab2);
	}
}

// Méthodes
CubedAir Ciel::getCube(int i, int j, int k) const {
	return air[i][j][k];
}


void Ciel::calc_nuage(double cte, double P_inf, double T_inf) {
	for(int i(0); i < n_cubes[0]; ++i) {
		for(int j(0); j < n_cubes[1]; ++j) {
			for(int k(0); k < n_cubes[2]; ++k) {
				// std::cout << i << " " << j << " " << k << std::endl;
				air[i][j][k].calc_all(cte, k*lambdas[2], P_inf, T_inf);
			}
		}
	}
}

array<int,3> Ciel::previous(double dt, int i, int j, int k) const {
	array<double,3> vent(air[i][j][k].getVent());
	int a1, a2, a3;
	a1 = trunc(-dt * vent[0] / lambdas[0]);
	a2 = trunc(-dt * vent[1] / lambdas[1]);
	a3 = trunc(-dt * vent[2] / lambdas[2]);
	array<int,3> deplacement( {a1,a2,a3});
	return {(i + deplacement[0]), (j + deplacement[1]), (k + deplacement[2])};
	// !!!!!!!!!!!!!!!! Fixer les int et les doubles !!!!!!!!!!!!!!!!!!!!!!!
}
		
void Ciel::afficher(std::ostream& out, Montagne& montagne, std::vector<std::string> format) const {
	for(int i(1); i < n_cubes[0] - 1; ++i) {
		for(int j(1); j < n_cubes[1] - 1; ++j) {
			for(int k(1); k < n_cubes[2] - 1; ++k) {
				if(montagne.k_to_z(k) >= montagne.altitude(montagne.i_to_x(i), montagne.j_to_y(j))) {
					out << i << " " << j << " " << k << " " << air[i][j][k].toString(format) << std::endl;
				}
			}
		}
	}
}

/*std::ostream& operator <<(std::ostream& out, Ciel const& ciel) {
	out<<"un ciel : "<<endl;
	for(int i(0); i<ciel.get_n_cubes()[0]-1; ++i)
	{
		for(int j(0); j<ciel.get_n_cubes()[1]-1; ++j)
		{
			for(int k(0); k<ciel.get_n_cubes()[2]-1; ++k)
			{
				out<<i<<" "<<j<<" "<<k<<" "<<ciel.getCube(i,j,k).v2()<<" "<<ciel.getCube(i,j,k).get_humidite()<<" "<<ciel.getCube(i,j,k).get_T()<<" "<<ciel.getCube(i,j,k).get_P()<<" "<<ciel.getCube(i,j,k).get_P_eau()<<" "<<ciel.getCube(i,j,k).get_P_rosee()<<" "<<ciel.getCube(i,j,k).get_nuage()<< endl;
			}
		}
	
	}
	return out;
}*/


/*void Ciel::affiche_ciel()
{
	cout<<"un ciel : "<<endl;
	for(int i(1); i<get_n_cubes()[0]; ++i)
	{
		for(int j(1); j<get_n_cubes()[1]; ++j)
		{
			for(int k(1); k<get_n_cubes()[2]; ++k)
			{
				cout<<i<<" "<<j<<" "<<k<<" "<<getCube(i,j,k).v2()<<" "<<getCube(i,j,k).get_humidite()<<" "<<getCube(i,j,k).get_T()<<" "<<getCube(i,j,k).get_P()<<" "<<getCube(i,j,k).get_P_eau()<<" "<<getCube(i,j,k).get_P_rosee()<<" "<<getCube(i,j,k).get_nuage()<< endl;
			}
		}
	
	}
	
}*/
void Ciel::dessine_sur(SupportADessin& support) const {
	support.dessine(*this);
}


void Ciel::afficher(std::ostream& out) const {
	out << "Affichage d'un ciel " << endl;
}


void Ciel::set_humidite(int i, int j, int k, double taux) {
	air[i][j][k].set_humidite(taux);
}
