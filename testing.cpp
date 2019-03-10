// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "config.h"
#include "library.h"


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stdout, "%s Version %d.%d\n", argv[0],
			Tutorial_VERSION_MAJOR,
			Tutorial_VERSION_MINOR);
		fprintf(stdout, "Usage: %s number\n", argv[0]);
		return 1;
	}

	int inputValue = atoi(argv[1]);


	printf("the %d + 9 = %d\n",
		inputValue, library::Add(inputValue, 9));
	return 0;
}
