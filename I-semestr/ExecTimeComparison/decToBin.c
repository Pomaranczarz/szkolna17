#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* strrev(char* str) {
	char *p1, *p2;

	if (!str || !*str)
		return str;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;
}

const char* decToBin(long long int decNumber) {
	char* result = (char*) calloc(40, sizeof(char));
	size_t result_index = 0;

	while (decNumber) {
		result[result_index++] = (decNumber % 2) + '0';
		decNumber /= 2;
	}

	return strrev(result);
}

time_t measure(long long count) {
	clock_t start = clock();

	for (unsigned long long i = 0; i < count; i++)
		free(decToBin(i));

	clock_t end = clock();

	return end - start;
}

int main(void) {
	long double measureSum = 0;
	long long int numOfCases = 5000;
	long count = 1;
	while (numOfCases < 200000) {
		for (size_t i = 0; i < 100; i++)
			measureSum += (float) measure(numOfCases) / CLOCKS_PER_SEC;

		printf("Average exec time for %lld cases: %Lf microseconds\n", numOfCases, (measureSum / 100) * 1000000);
		numOfCases += 5000 * count;
		measureSum = 0;
		count += 1;
	}
}