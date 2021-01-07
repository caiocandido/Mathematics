
#include <stdio.h>

long long int fibonacciRecursive(long long int n){
	// Stopping criterion
	if (n == 0) return 0;
	if (n == 1) return 1;

	return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}


int main(){
	printf ("\n\n\n");
	printf ("Digite o n-ésimo termo da sequência de Fibonacci que você quer calcular:\n");
	long long int n; scanf ("%lld", &n);
	printf ("%lld\n", fibonacciRecursive(n));
	printf ("\n\n\n");
}