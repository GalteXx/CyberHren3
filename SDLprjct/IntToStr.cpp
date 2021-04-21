#include "All.h"

string int_to_str(int a)
{
	string final;
	int num = 0;
	int k = 10;
	for (int i = 0; i < num_len(a) - 2; i++)
	{
		k = k * 10;
	}

	for (int i = 0; i < num_len(a); i++)
	{
		num = a / k;
		final = final + char((num % 10) + 48);
		k = k / 10;
	}
	return(final);
}
