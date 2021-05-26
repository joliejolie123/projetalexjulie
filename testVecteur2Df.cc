#include <iostream>
#include "Vecteur2Df.h"
using namespace std;

int main() {
	
	
	Vecteur2D vecteur1(1.0, 2.0);
	Vecteur2D vecteur2(2.0, 4.0);
	Vecteur2D vecteur3;
	
	cout << "Vecteur 1 : " << vecteur1 << endl;
	cout << "Vecteur 2 : " << vecteur2 << endl;
	
	vecteur3 = vecteur1;
	
	cout << "Vecteur1 : ";
	cout << vecteur1;
	cout << endl;
	
	cout << "Vecteur2 : ";
	cout << vecteur2;
	cout << endl;
	
	cout << "Le vecteur 1 est ";
	if (vecteur1 == vecteur2) {
		cout << "egal au";
	} else {
		cout << "different du";
	}
	cout << " vecteur 2." << endl;
	
	cout << "Le vecteur 1 est ";
	if (vecteur1 == vecteur3) {
		cout << "egal au";
	} else {
		cout << "different du";
	}
	cout << " vecteur 3." << endl;
	
	Vecteur2D a(1.0, 2.0);
	Vecteur2D b(2.0, 4.0);
	Vecteur2D c;
	
	
	c = a.addition(b);
	cout << c;
	cout << endl;
	
	c = a.oppose();
	cout << c;
	cout << endl;
	

	c = a.mult(10);
	cout << c;
	cout << endl;
	
	
	c = a + b;
	cout << c << endl;
	
	c = -a;

	c = 4.0 * a;

	
	/* test produit scalaire */
	double w;
	w = a.prod_scal(b);
	cout << w << endl;
	cout << endl;
	
	/* test norme */
	cout << b.norme() << endl;
	cout << b.norme2() << endl;
	
	/* unitaire */
	Vecteur2D i;
	i = c.unitaire();
	cout << i;
	
	/* test unitaire */
	cout << i.norme() << endl;
	
	
	return 0;

	
}


