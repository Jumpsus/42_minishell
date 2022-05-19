#include "phrase.h"

/* return 0 if pharase is in complete */
/* return 1 when phrase is complete */
int	able_to_phrase(char *str)
{
	int		i;
	int		flag;
	char	quote;
	
	i = 0;
	flag = 0;
	while (str[i])
	{
		if (!flag && (str[i] == '\'' || str[i] == '\"'))
		{
			flag = 1;
			quote = str[i];
		}
		else if (flag && str[i] == quote)
		{
			flag = 0;
		}
		i++;
	}
	if (flag)
		return (0);
	return (1);
}

/*
int	main()
{
	printf("%d\n",able_to_phrase("fsdfads\"afdsaffs"));
}
*/
