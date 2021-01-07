#include <stdio.h>

long long int fibonacciIterative (long long int n){
	long long int previousPreviousNumber = 0, previousNumber = 0, currentNumber = 1;
	for (long long x = 1; x < n; x++){
		previousPreviousNumber = previousNumber;
		previousNumber = currentNumber;
		currentNumber = previousNumber + previousPreviousNumber;
	}
	return currentNumber;
}


int main(){

	printf ("\nDigite o n-ésimo termo da sequência de Fibonacci que você quer calcular:\n");
	int n; scanf ("%d", &n);

	printf ("Resultado: %lld\n\n", fibonacciIterative(n));
}