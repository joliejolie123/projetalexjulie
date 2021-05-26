#include <array>
#include <string>
#include "Boite3Df.h"
#include <vector>
#include "Potentielf.h"
#include "Montagnef.h"

class ChampPotentiel : public Boite3D {
	
	public:
		// Constructeur
		ChampPotentiel(std::array<double,3>, std::array<int,3>);
		
		// Méthodes
		void initialise(double, const MontagneGaussienne&); // Prend en argument un double (vitesse du vent au loin) est une montagne, initialise le potentiel vecteur en tout point comme indiqué dans la section 3.2 du complément mathématique 
		void affiche_potentiel() const; // Affiche les potentiels
		void affiche_laplacien() const; // Affiche les laplaciens
		void calcul_laplacien(const MontagneGaussienne&); // Calcule le Laplacien en tout point intérieur
		Vecteur2D calcul_laplacien(int, int, int) const; // Calcule le Laplacien en le point (i,j,k)
		Potentiel get_potentiel(int,int,int) const; // Retourne le potentiel en le point (i,j,k)
		double erreur() const; // Renvoie la somme des carrés la somme des carrés des normes des vecteurs laplacien
		void iteration(); // Applique l'équation (6) du complément mathématique en tout point
		void resolution(MontagneGaussienne const& m, double seuil, int max, bool verbeuse = false); // Répète l'itération tant que l'erreur est plus grand qu'un seuil donné et le nombre d'itérations plus petit qu'un maximum donné
		// resolution recoit 3 paramètres : le seuil d'erreur, le nombre maximum d'itérations, booléen indiquant si la méthode est "verbeuse" qui est false par défaut
		std::array<double,3> vitesse(int, int, int, std::array<double,3> = {0.0,0.0,0.0}) const; // Retourne un tableau de 3 doubles qui sont les coordonnées de la vitesse du vent en (i,j,k) suivant la formule (7) du complément mathématique
		void dessine_sur(SupportADessin& support) const;
		
	private:
		std::vector<std::vector<std::vector<Potentiel> > > potentiels;
		
};
