#include <cmath>
#include "CubedAirf.h"
#include "Constantes.h"
#include <iostream>
using namespace std;


CubedAir::CubedAir(array<double,3> vent, double taux_humidite)
: vent(vent), taux_humidite(taux_humidite)
{}

string CubedAir::toString(vector<string> format, char sep) const {
	// Format v2 h T P P_eau P_rosee nuage (P8 Progmaph)
	std::string out("");
	for (auto f : format) {
		if (f == "v2") {
			out += to_string(v2());
		}
		if (f == "h") {
			out += to_string(h);
		}
		if (f == "T") {
			out += to_string(T);
		}
		if (f == "P") {
			out += to_string(P);
		//	out += std::to_string(P_eau);
		}
		if (f == "P_rosee") {
			out += to_string(P_rosee);
		}
		if (f == "P_eau") {
			out += to_string(P_eau);
		}
		if (f == "nuage") {
			out += to_string(nuage);
		}
		out += sep;
	}
	out.pop_back(); // Pour enlever le dernier sépérateur
	return out;
}

double CubedAir::get_humidite() const {
	return taux_humidite;
}

void CubedAir::set_humidite(double th) {
	taux_humidite = th;
}

array<double,3> CubedAir::getVent() const {
	return vent;
}

bool CubedAir::get_nuage() const {
	return nuage;
}

double CubedAir::v2() const {
	return vent[0] * vent[0] + vent[1] * vent[1] + vent[2] * vent[2];
}

// Voir complément mathématique partie 4
void CubedAir::calc_all(double cte, double z, double P_inf, double T_inf) {
	// L'ordre est important
	calc_h(cte, z);
	calc_T();
	calc_P(P_inf, T_inf);
	calc_P_eau();
	calc_P_rosee();
	calc_nuage();
}

void CubedAir::calc_h(double cte, double z) {
	h = cte - Physique::g * z - 0.5 * v2();
}

void CubedAir::calc_T() {
	T = 2 * Physique::M_airsec * h / (7.0 * Physique::R);
}	

void CubedAir::calc_P(double P_inf, double T_inf) {
	P = P_inf * std::pow(T_inf, -3.5) * std::pow(T, 3.5);
}

void CubedAir::calc_P_eau() {
	double rapport_masses(Physique::M_eau/Physique::M_airsec);
	P_eau = P * taux_humidite / (rapport_masses + taux_humidite);
}
void CubedAir::calc_P_rosee() {
	P_rosee = Physique::P_ref * exp(13.96 - 5208 / T);
}

void CubedAir::calc_nuage() {
	nuage = P_eau > P_rosee;
}
		
		
