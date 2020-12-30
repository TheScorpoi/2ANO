#include <stdio.h>

#ifndef N
#define N 8
#endif

/* Programa que o stor fez no video de dynamic programming
testei com N = 40000, usa quase a RAM toda
*/

long solve(int x, int y){

	static long S[N][N];
	if(x < 0 || x >= N || y < 0 || y >= N || y > x ){
		return 0L;
	}
	if (x == N - 1 && y == N - 1){
		return 1L;
	}
	if (S[x][y] == 0L){
		S[x][y] = solve(x + 1, y) + solve(x, y + 1);
	}
	return S[x][y];
}

int main(void){
	printf("%ld\n", solve(0,0));	
	return 0;
}
