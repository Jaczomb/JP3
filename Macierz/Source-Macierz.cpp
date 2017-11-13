#include <iostream>
#include "macierz.h"
//4 zasady
//1. operator =;
//2. konstruktor kopiuj¹cy
//3. konstruktor bezparametrowy
//4. destruktor
// + opisy
//zapytac czy to pelne zasady
//zapytac o usuwanie tablic dynamicznych
//using namespace std;

int main()
{
	//macierz A(3), B(3), C(3), D(3);		//MOJE
	Macierz A, B, C, D;
	A.set (0,0,1.0);			//(gdzie, co, jaka wartosc)
	A.set (0,1,2.0);
	A.set (1,0,3.0);
	A.set (1,1,4.0);
	B = A;
	B.set (0,0,5.0);
	//A.testprint('A');			//MOJE
	//B.testprint('B');			//MOJE
	//B.setsize(2);				//MOJE
	//B.testprint('B');			//MOJE
	//Macierz E = A;			//MOJE
	//Macierz F(A);				//MOJE
	//Macierz G = Macierz(A);	//MOJE
	//E.testprint('E');			//MOJE
	//F.testprint('F');			//MOJE
	//G.testprint('G');			//MOJE
	//E.set(0, 1, 22.0);		//MOJE
	//E.setsize(4);				//MOJE
	//E.testprint('E');			//MOJE
	//E.set(0, 3, 4.0);			//MOJE
	//E.testprint('E');			//MOJE
	//E.setsize(2);				//MOJE
	//E.testprint('E');			//MOJE
	//E.setsize(4);				//MOJE
	//E.testprint('E');			//MOJE
	////getchar();				//MOJE
	//C = A;					//MOJE
	//C.testprint('C');			//MOJE
	C=A*B;
	//C.testprint('C');			//MOJE
	//C.set(0, 1, 18.0);		//MOJE
	//C.set(1, 0, 15.0);		//MOJE
	//C.testprint('C');			//MOJE
	////getchar();				//MOJE
	D=B*A;
	//D.testprint('D');			//MOJE
	if (C == D)
		std::cout << "Macierze sa rowne";
	else
		std::cout << "Macierze sa nierowne";
	getchar();					//MOJE
	return 0;
}