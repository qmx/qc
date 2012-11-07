#include <stdio.h>
#include "crypto_box.h"

unsigned char pk[crypto_box_PUBLICKEYBYTES];
unsigned char sk[crypto_box_SECRETKEYBYTES];

int main(int argc, char *argv[])
{
	crypto_box_keypair(pk, sk);
	fprintf(stdout, pk);
	fprintf(stdout, "\nhello");
	return 0;
}
