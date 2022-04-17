#include <iostream>
#include <string> 
#include <bitset>



int main() {
	// n = ancho de la cadena de bits 
	const int n = 8 ;
	std::string dividendo = " ";
	std::string divisor = " ";
	
	std::cout << "ingrese la cadena de bits del Dividendo: " << "\n";
	std::cin >> dividendo;
	std::cout << "ingrese la cadena de bits del Divisor" << "\n";
	std::cin >> divisor;
	std::bitset<n> Q (dividendo);
	std::bitset<n> M (divisor);
	std::bitset<n> N (~M);
	std::bitset<n> A ;
	
	//complement a 2 de M
	for (int dat = 0; dat < n - 1; dat++) {
		if (dat == 0) {
			if (N[dat] == 0) {
				N[dat] = 1;
				break;
			}
			else
				N[dat] = 0;
		}
		else {
			if (N[dat] == 0)
				N[dat] = 1;
			else
				N[dat] = 0;
		}
	}
	

	int count = n;

	while (count != 0) {
		A <<= 1;
		A[0] = Q[3];//n-1//;
		Q<<=1;	
		
		//Resta A - M
		A = A.to_ulong() + N.to_ulong();
		

		if (A[n-1] == 1) {
			Q[0] = 0;
			A = A.to_ulong() - N.to_ulong();	
		}
		else {
			Q[0] = 1;	
		}				
		count--;	
	}

	std::cout << "Residuo = " << A << "\n";
	std::cout << "Cosiente = " << Q << "\n";
	return 0;
}

