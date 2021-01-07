
#include <stdio.h>

void recursion(long long int n){
	// Stopping criterion
	if (n == 0) return;

	recursion(n-1);

	printf ("%lld ", n);

}

int main(){
	printf ("\n\n\n\n\n");
	printf ("Digite até qual valor você gostaria de imprimir.\nOu seja, digite um valor para ’n’:\n");
	long long int n; scanf ("%lld", &n);
	recursion(n);
	printf ("\n\n\n\n\n");
}