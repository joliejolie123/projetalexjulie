#include <iostream>
#include "Montagnef.h"
#include <vector>
#include <cmath>
using namespace std;

int main() {
	
	//MontagneGaussienne m(15, 15, 18, 5.0, 10.0);
	
	array<double,3> l({20.0,20.0,20.0});
	array<int,3> n_cubes({30,30,30});
	
	MontagneGaussienne m(15, 15, 18.0, 5, 10, l, n_cubes);
	
	/*int i(14);
	int j(15);
	double x(m.i_to_x(i));
	double y(m.j_to_y(j));
	double alt(0.0);
	double un(0.5 * (x-m.x0) * (x-m.x0) / (m.sigmax * m.sigmax));
	double deux(0.5 * (y-m.y0) * (y-m.y0) / (m.sigmay * m.sigmay));
	alt = m.h * exp(-un - deux);
	cout << m.altitude(x, y) << endl;
	cout << alt << endl;
	*/
	
	/*
	for (auto l : m.get_lambdas()) {
		cout << l << endl;
	}
	*/

	for (int i(0) ; i <= 29 ; ++i) {
			double xi(m.i_to_x(i));
			for (int j(0) ; j <= 29 ; ++j) {
				double yj(m.j_to_y(j));
					cout << i << ' ' << j << ' ' << m.altitude(xi,yj) << endl;
			}
			cout << endl;
		}

	
		
	/*	for (int i(0);i<30;++i){
			for (int j(0);j<30;++j){

			cout<<i<<" "<<j<<" "<<m.altitude(i,j)<<endl;
			}
		}
		
		
	
	MontagneGaussienne m(15, 15, 18, 5, 10);
	

	for (int i(0) ; i <= 29 ; ++i) {
		for (int j(0) ; j <= 29 ; ++j) {
			cout << i << ' ' << j << ' ' << m.altitude(i,j) << endl;
		}
		cout << endl;
	}*/
	
	return 0;
	

	
}
