#include "holberton.h"

/**
 * main - Entry point: multiplies two positive numbers
 * @argc: number of arguments passed
 * @argv: arguments passed (integers)
 */
int main(int argc, char** argv) {
	char *er = "Error\n";

	if (argc != 3) {
		while(*er) {
			_putchar(*er);
			*er += 1;
		}
		exit(98);
	}
	(void) argv;
	return (1);
}
