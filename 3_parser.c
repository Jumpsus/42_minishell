#include "phrase.h"

static int  count_row(char **lex)
{
    int     i;
    int     count;

    i = 0;
    if (ft_strncmp(lex[0], "|", 2))
        count = 1;
    else
        count = 0;
    while (lex[i])
    {
        if (!ft_strncmp(lex[i], "|", 2))
            count++;
        i++;
    }
    if (ft_strncmp(lex[i - 1], "|", 2))
        count--;
    return (count);
}

static int  count_col(char **lex, int index)
{
    int     i;

    i = 0;
    while (lex[index + i] && ft_strncmp(lex[index + i], "|", 2))
    {
        i++;
    }
    return (i);
}

static char **put_row(char **lex, int i_lex)
{
    char    **put;
    int     i;

    put = (char **)malloc(sizeof(char *) * (count_col(lex, i_lex) + 1));
    if (!put)
        return (NULL);
    i = 0;
    while (i < count_col(lex, i_lex))
    {
        put[i] = lex[i_lex + i];
        i++;
    }
    put[i] = '\0';
    return (put);
}

char    ***parser(char **lex)
{
    int     i;
    int     j;
    char    ***pars;

    i = 0;
    j = 0;
    pars = (char ***)malloc(sizeof(char **) * (count_row(lex) + 1));
    if (!pars)
        return (NULL);
    while (lex[i])
    {
        pars[j++] = put_row(lex, i);
        i += count_col(lex, i);
        if (lex[i])
            i++;
    }
    pars[j] = '\0';
    free(lex);
    return (pars);
}
