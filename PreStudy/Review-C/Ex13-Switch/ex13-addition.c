#include <stdio.h>

int main(int argc, char *argv[])
{
	int arg_cnt = 0;
	int i = 0;
	for(arg_cnt = 1; arg_cnt < argc; arg_cnt++)
	{
		char letter;
		printf("==== The NO.%d arg is %s\n", arg_cnt, argv[arg_cnt]);
		for(i = 0, letter = argv[arg_cnt][i]; argv[arg_cnt][i] != '\0'; i++)
		{
			letter = argv[arg_cnt][i];

			switch(letter)
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					printf("%d: %c\n", i, letter - 32);
					break;
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
					printf("%d: '%c'\n", i, letter);
					break;
				case 'y': letter -= 32;
    	        case 'Y':
    	        	if(i > 2)
					{
						// it's only sometimes Y
						printf("%d: '%c'\n", i, letter);
						break;
					}
    	        	//break;

				default:
					printf("%d: %c is not a vowel\n", i, letter);
			}
		}
	}

	return 0;
}


