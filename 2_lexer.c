#include "phrase.h"

/*need to handle when pipe on first and last character*/
static int	skip_quote(char *line, int index)
{
	char	quote;
	int		i;

	i = 1;
	quote = line[index];
	while (line[index + i] && line[index + i] != quote)
	{
		i++;
	}
	return (i);
}

/*ugly code TT*/
static int	count_comp(char *line)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 1;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '|')
		{
			flag = 1;
			if (line[i] == '|')
				count++;
		}
		else
		{
			if (flag && ++count)
				flag = 0;
			if (line[i] == '\'' || line[i] == '\"')
				i += skip_quote(line, i);
		}
		i++;
	}
	return (count);
}

static int	count_w(char *line, int index)
{
	int		i;
	int		flag;
	char	quote;

	i = 0;
	flag = 0;
	if (line[index + i] == '|')
		return (1);
	while (line[index + i] && (flag || (line[index + i] != ' ' && line[index + i] != '|')))
	{
		if (!flag && (line[i] == '\'' || line[i] == '\"'))
		{
			flag = 1;
			quote = line[i];
		}
		else if (flag && line[i] == quote)
		{
			flag = 0;
		}
		i++;
	}
	return (i);
}

static char	*dup_w(char *line, int index, int word_len)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	while (i < word_len)
	{
		word[i] = line[index + i];
		i++;
	}
	word[i] = '\0';
	return (word);	
}

char	**lexer(char *line)
{
	char	**split;
	int		index;
	int		i;

	split = (char **)malloc(sizeof(char *) * (count_comp(line) + 1));
	if (!split)
		return (NULL);
	i = 0;
	index = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			split[index++] = dup_w(line, i, count_w(line, i));
			i += count_w(line, i);
			continue;
		}
		i++;
	}
	split[index] = '\0';
	return (split);
}

int	main()
{
	char	**lex;
	int		i = 0;
	// test here
	lex = lexer("cat a.out|echo hi");
	while (lex[i])
	{
		printf("%s\n", lex[i]);
		i++;
	}

	//printf("%d \n", count_comp(" cat a.out | echo | \"omg this is shit\"  "));
}