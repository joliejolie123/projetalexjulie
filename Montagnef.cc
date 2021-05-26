#include "Montagnef.h"
#include <cmath>
#include <iostream>
using namespace std;

Montagne::Montagne(std::array<double,3> longueurs, std::array<int,3> n_cubes)
: Boite3D(longueurs, n_cubes)
{}

void Montagne::afficher(std::ostream& out) const {
	out << "Une montagne : " << std::endl;
}

void MontagneGaussienne::afficher(std::ostream& out) const {
	//Montagne::afficher();
	out << "Une montagne gausienne de parametres:" << endl;
	out << "x0 : " << x0 << endl;
	out << "y0 : " << y0 << endl;
	out << "h : " << h << endl;
	out << "Sx0 : " << sigmax << endl;
	out << "Sy0 : " << sigmay << endl;
}

MontagneGaussienne::MontagneGaussienne(int i0, int j0, double h_, int si, int sj, std::array<double,3> l, std::array<int,3> n)
:Montagne(l,n)
{
	for(int i(0); i < 3; ++i) {
		longueurs[i] = l[i];
		n_cubes[i] = n[i];
		lambdas[i] = longueurs[i] / (n_cubes[i] - 1);
}
	h = h_;
	x0 = i_to_x(i0);
	y0 = j_to_y(j0);
	sigmax = si * lambdas[0];
	sigmay = sj * lambdas[1];
}

double MontagneGaussienne::altitude(double x, double y) const {
	
	double alt(0.0);
	double un(0.5 * (x-x0) * (x-x0) / (sigmax * sigmax));
	double deux(0.5 * (y-y0) * (y-y0) / (sigmay * sigmay));
	alt = h * exp(-un - deux);
    if (alt < 0.5 * lambdas[2]){
		alt=0.0;
	}
    return alt;
	
}

void MontagneGaussienne::dessine_sur(SupportADessin& support) const {
	support.dessine(*this);
}

ChaineDeMontagnes::ChaineDeMontagnes(array<double,3> l, array<int,3> n_cubes)
: Montagne(l, n_cubes) 
{}

vector<Montagne*> ChaineDeMontagnes::getMontagnes() const {
	return montagnes;
}

void ChaineDeMontagnes::ajouterMontagne(Montagne* m) {
	montagnes.push_back(m);
}

double ChaineDeMontagnes::altitude(double x, double y) const {
	size_t t(montagnes.size());
	double max(0.0);
	for (size_t i(0); i < t; ++i) {
		if (montagnes[i]->altitude(x,y) > max) {
			max = montagnes[i]->altitude(x,y);
		}
	}
	return max;
}

void ChaineDeMontagnes::dessine_sur(SupportADessin& s) const {
	s.dessine(*this);
}

void ChaineDeMontagnes::afficher(std::ostream& out) const {
	size_t t(montagnes.size());
	for(size_t i(0); i < t; ++i) {
		montagnes[i]->afficher(out);
	}
}

/*
MontagneConique::MontagneConique(int i0, int j0, double h, double phi, array<double,3> l, array<int,3> n_cubes)
: Montagne(l, n_cubes)
{
	x0 = i_to_x(i0);
	y0 = j_to_y(j0);
}


double MontagneConique::altitude(double x, double y) const {
	double z((cos(theta) / sin(theta) * sqrt((x-x0) * (x-x0) + (y-y0) * (y-y0) * -1)));
	if(z + h < lambdas[2]) {
		return 0.0;
	}
	return z + h;
}

void MontagneConique::afficher() const {
	//Montagne::afficher();cout << "Une montagne gausienne de parametres:" << endl;
	cout << "Une montagne conique de parametres : " << endl;
	cout << "x0 : " << x0 << endl;
	cout << "y0 : " << y0 << endl;
	cout << "h : " << h << endl;
	cout << "theta : " << theta << endl;
}*/
	
	

