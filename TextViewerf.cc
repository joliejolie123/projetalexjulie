#include <iostream>
#include "TextViewerf.h"
#include "Systemef.h"
using namespace std;

TextViewer::TextViewer(std::ostream& flot)
: flot(flot)
{}

void TextViewer::dessine(Systeme const& s) {
	s.getMontagne()->dessine_sur(*this);
	flot << std::endl;
	dessine(*s.getChamp());
	flot << std::endl;
	dessine(*s.getCiel());
	s.afficher(cout);
	flot << std::endl;
	s.getChamp()->dessine_sur(*this);
	flot << std::endl;
	s.getCiel()->dessine_sur(*this);

}

void TextViewer::dessine(MontagneGaussienne const& m) {
	array<int,3> c(m.get_n_cubes());
	array<double,3> l(m.get_lambdas());
	for(int i(0); i < c[0]; ++i) {
		double xi(l[0] * i);
		for(int j(0); j < c[1]; ++j) {
			double yj(m.j_to_y(j));
			flot << i << " " << j << " " << m.altitude(xi,yj) << endl;
		}
	}
}

void TextViewer::dessine(Ciel const& ciel) {
	ciel;//?????????????????????????????????????? Quelle fonction afficher() ??????????????????????????????????
}

void TextViewer::dessine(ChampPotentiel const& champ) {
	champ.affiche_potentiel(); //affiche mais quoi ?????????????????
}

void TextViewer::dessine(ChaineDeMontagnes const& chaine) {
	cout << " Ceci est une chaine de montagnes " << endl;
}
	
