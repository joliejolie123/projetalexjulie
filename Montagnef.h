#pragma once
#include <array>
#include "Boite3Df.h"
#include <iostream>
#include "Dessinablef.h"
#include <vector>

class Montagne : public Boite3D, public Dessinable {
	
	public:
		Montagne(std::array<double,3>, std::array<int,3>);
		virtual double altitude(double,double) const = 0;
		virtual void afficher(std::ostream&) const;
		//virtual void dessine_sur(SupportADessin&) const override ;
};

class MontagneGaussienne : public Montagne {
	
	public:
	
		// Constructeur
		MontagneGaussienne(int x0 = 0, int y0 = 0, double h = 0, int si = 0, int sj = 0, std::array<double,3> = {0.0,0.0,0.0}, std::array<int,3> = {0,0,0});
		
		// Méthodes
		/* Ajouté le mot virtual*/ virtual double altitude(double, double) const override; // Retourne l'altitude z au point de coordonnées (x,y)
		virtual void afficher(std::ostream&) const override; // Affiche les caractéristiques de la montagne
		virtual void dessine_sur(SupportADessin&) const override;
		
	private:
	
		double x0;
		double y0;
		double h;
		double sigmax;
		double sigmay;
		
};
	
class ChaineDeMontagnes : public Montagne {
	
	public:
		// Constructeur
		ChaineDeMontagnes(std::array<double,3>, std::array<int,3>);
		
		// Méthodes
		std::vector<Montagne*> getMontagnes() const; // Retourne la chaine de montagnes
		void ajouterMontagne(Montagne*); // Ajouter une montagne à la chaine de montagnes
		virtual double altitude(double,double) const override; // Retourne l'altitude de la chaine de montagnes (maximum de tous les montagnes)
		virtual void dessine_sur(SupportADessin&) const override;
		virtual void afficher(std::ostream&) const override; // Affiche les caracteristiques de chaque montagne dans la chaine de montagnes
	
	private:
		std::vector<Montagne*> montagnes;
};

/*
class MontagneConique : public Montagne {
	
	public:
		MontagneConique(int i0 = 0, int j0 = 0, double h = 0, double theta = 0, std::array<double,3> = {0.0,0.0,0.0}, std::array<int,3> = {0,0,0});
		double altitude(double, double) const override;
		virtual void dessine_sur(SupportADessin&) const;
		virtual void afficher() const override;
	
	private:
		double x0;
		double y0;
		double h;
		double theta;
};*/
	
