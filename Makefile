CC = $(CXX)
CXXFLAGS = -g -std=c++11 -pedantic -Wall

all : testVecteur2Df testMontagnef testBoite3D testChampPotentielf testLaplacienf testNuagef testChaineDeMontagnesf testSystemef

Vecteur2Df.o: Vecteur2Df.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o Vecteur2Df.o Vecteur2Df.cc

Montagnef.o: Montagnef.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o Montagnef.o Montagnef.cc
	
Boite3Df.o: Boite3Df.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o Boite3Df.o Boite3Df.cc
	
Potentielf.o: Potentielf.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o Potentielf.o Potentielf.cc
	
ChampPotentielf.o: ChampPotentielf.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o ChampPotentielf.o ChampPotentielf.cc
	
CubedAirf.o: CubedAirf.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o CubedAirf.o CubedAirf.cc
	
Cielf.o: Cielf.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o Cielf.o Cielf.cc
	
Dessinablef.o: Dessinablef.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o Dessinablef.o Dessinablef.cc

Systemef.o: Systemef.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o Systemef.o Systemef.cc
	
TextViewerf.o: TextViewerf.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o TextViewerf.o TextViewerf.cc
	
testVecteur2Df.o: testVecteur2Df.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o testVecteur2Df.o testVecteur2Df.cc
	
testMontagnef.o: testMontagnef.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o testMontagnef.o testMontagnef.cc

testBoite3D.o: testBoite3D.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o testBoite3D.o testBoite3D.cc
	
testChampPotentielf.o: testChampPotentielf.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o testChampPotentielf.o testChampPotentielf.cc
	
testLaplacienf.o: testLaplacienf.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o testLaplacienf.o testLaplacienf.cc	
	
testNuagef.o: testNuagef.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o testNuagef.o testNuagef.cc
	
testChaineDeMontagnesf.o: testChaineDeMontagnesf.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o testChaineDeMontagnesf.o testChaineDeMontagnesf.cc
	
testSystemef.o: testSystemef.cc
	g++ -std=c++11 -g -pedantic -Wall  -c -o testSystemef.o testSystemef.cc
	
testVecteur2Df: testVecteur2Df.o Vecteur2Df.o
		g++ testVecteur2Df.o Vecteur2Df.o -o  testVecteur2Df
		
testMontagnef: testMontagnef.o Montagnef.o Vecteur2Df.o Boite3Df.o
		g++ testMontagnef.o Vecteur2Df.o Montagnef.o Boite3Df.o -o  testMontagnef
		
testBoite3D: testBoite3D.o 
		g++ testBoite3D.o Boite3Df.o -o testBoite3D
		
testChampPotentielf: testChampPotentielf.o Vecteur2Df.o Montagnef.o Boite3Df.o Potentielf.o ChampPotentielf.o
		g++ testChampPotentielf.o Vecteur2Df.o Montagnef.o Boite3Df.o Potentielf.o ChampPotentielf.o -o  testChampPotentielf
		
testNuagef: testNuagef.o Vecteur2Df.o Montagnef.o Boite3Df.o Potentielf.o ChampPotentielf.o CubedAirf.o Cielf.o
		g++ testNuagef.o Vecteur2Df.o Montagnef.o Boite3Df.o Potentielf.o ChampPotentielf.o CubedAirf.o Cielf.o -o  testNuagef
		
testLaplacienf: testLaplacienf.o Vecteur2Df.o Montagnef.o Boite3Df.o Potentielf.o ChampPotentielf.o
		g++ testLaplacienf.o Vecteur2Df.o Montagnef.o Boite3Df.o Potentielf.o ChampPotentielf.o -o  testLaplacienf

testChaineDeMontagnesf: testChaineDeMontagnesf.o Montagnef.o Vecteur2Df.o Boite3Df.o 
		g++ testChaineDeMontagnesf.o Vecteur2Df.o Montagnef.o Boite3Df.o -o  testChaineDeMontagnesf
		
testSystemef: testSystemef.o Vecteur2Df.o Montagnef.o Boite3Df.o Potentielf.o ChampPotentielf.o CubedAirf.o Cielf.o Systemef.o Dessinablef.o TextViewerf.o
		g++ testSystemef.o Vecteur2Df.o Montagnef.o Boite3Df.o Potentielf.o ChampPotentielf.o CubedAirf.o Cielf.o Systemef.o Dessinablef.o TextViewerf.o -o  testSystemef
	
.PHONY: clean

clean:	
	rm -f *.o
	rm -f testVecteur2Df
	rm -f testChampPotentielf
	rm -f testNuagef
	rm -f testLaplacienf
	rm -f testSystemef

		
