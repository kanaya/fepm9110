/* ... */
int E[3] = { 18, 26, 37 }, P[3], C[3], N = 3;
#include <stdio.h>
void put(int, int);
void perm(void)
{
	int i;
	for (i = 0; i < N; i++)
		C[i] = 0;
	for (i = 0; i < N; i++)
		{ printf("\033[31m[i=%d]\033[0m\n", i); put(0, i); }
}
void put(int pos, int idx)
{
	int j;
	P[pos] = E[idx];
	if (pos == N - 1) {
		for (j = 0; j < N; j++)
			printf("\033[31m[j=%d]\033[0m %d ", j, P[j]);
		printf("\n");
	} else {
		C[idx] = 1;
		for (j = 0; j < N; j++) {
			if (C[j] == 0)
				put(pos + 1, j);
		}
		C[idx] = 0;
	}
}
int main(void)
{
	perm();
	return 0;
}