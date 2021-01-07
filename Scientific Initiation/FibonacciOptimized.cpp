#include <bits/stdc++.h>
using namespace std;

map<long long int, long long int>dynamicProgramming;

long long int fibonacciOptimized(long long int n){
	if (dynamicProgramming.count(n)) return dynamicProgramming[n];

	if (n == 0) return 0;
	if (n == 1) return 1;

	dynamicProgramming[n] = fibonacciOptimized(n-1) + fibonacciOptimized(n-2);

	return dynamicProgramming[n];
}



int main(){
	printf ("\nDigite o n-ésimo termo da sequência de Fibonacci que você quer calcular:\n");
	long long int n; scanf ("%lld", &n);
	printf ("Resultado: %lld\n\n", fibonacciOptimized(n));
}