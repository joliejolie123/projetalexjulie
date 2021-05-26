#pragma once
#include <iostream>
#include <array>
#include <string>
#include <vector>

class CubedAir {
	
	public:
		
		// Constructeur
		CubedAir(std::array<double,3>, double taux_humidite);
		
		// Méthodes
		std::array<double,3> getVent() const; // Renvoie le vent (tableau de 3 doubles)
		double get_humidite() const;
		void set_humidite(double th);
		bool get_nuage() const;
		double v2() const; // Renvoie le vent au carré
		std::string toString(std::vector<std::string> format={"v2", "h", "T", "P", "P_eau", "P_rosee", "nuage"}, char sep=' ') const;
		void calc_all(double, double, double, double); // Prend comme paramètres : cte, z, P_inf, T_inf, taux_humidité
		
		double get_T() const {
			return T;
		}
		
		double get_P_rosee() const {
			return P_rosee;
		}
		
		double get_P_eau() const {
			return P_eau;
		}
		double get_P() const {
			return P;
		}
		
		double get_h() const {
			return h;
		}
		double get_taux_humidite() const {
			return taux_humidite;
		}
		
		
		
	private:
		void calc_nuage(); 
		void calc_P_rosee();
		void calc_P_eau();
		void calc_P(double, double);
		void calc_T();
		void calc_h(double,double);
		std::array<double,3> vent;
		bool nuage;
		double P_rosee;
		double P_eau;
		double P;
		double T;
		double h;
		double taux_humidite;
};
		
