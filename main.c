#include "phrase.h"

/*
// Lexer TEST

int	main()
{
	char	**lex;
	int		i = 0;
	// test here
	lex = lexer("cat a.out|cat \"\'$VARS\'\"|||cat|echo hi ho     nooo    mooo");
	while (lex[i])
	{
		printf("%s address= %p\n", lex[i], &lex[i]);
		i++;
	}
}

*/

// Parser TEST
int	main()
{
	char	**lex;
    char    ***pars;
	// test here
	lex = lexer("cat a.out|cat \"\'$VARS\'\"|||cat|echo hi ho     nooo    mooo");
    pars = parser(lex);
    
    int j = 0;
    int k = 0;
    while (pars[j])
    {
        k = 0;
        while (pars[j][k])
        {
            printf("%s ",pars[j][k]);
            k++;
        }
        printf("\n");
        j++;
    }
}

