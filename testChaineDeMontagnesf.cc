#include <iostream>
#include "Montagnef.h"
#include <vector>
#include <cmath>
using namespace std;

int main() {
	
	array<double,3> l({20.0,20.0,20.0});
	array<int,3> n_cubes({30,30,30});
	
	
	ChaineDeMontagnes chaine(l, n_cubes);
	MontagneGaussienne m1(15, 15, 18.0, 5, 10, l, n_cubes);
	MontagneGaussienne m2(2, 22, 12.0, 12, 3, l, n_cubes);
	MontagneGaussienne m3(20, 2, 15.0, 8, 4, l, n_cubes);
	
	MontagneGaussienne *ptr_m1;
	MontagneGaussienne *ptr_m2;
	MontagneGaussienne *ptr_m3;
	
	ptr_m1 = &m1;
	ptr_m2 = &m2;
	ptr_m3 = &m3;
	
	chaine.ajouterMontagne(ptr_m1);
	chaine.ajouterMontagne(ptr_m2);
	chaine.ajouterMontagne(ptr_m3);
	

	
	
	for(int i(0) ; i <= 29 ; ++i) {
		double xi(chaine.i_to_x(i));
		for (int j(0) ; j <= 29 ; ++j) {
			double yj(chaine.j_to_y(j));
			cout << i << ' ' << j << ' ' << chaine.altitude(xi,yj) << endl;
		}
		cout << endl;
	}
	
	
	return 0;
	
}
