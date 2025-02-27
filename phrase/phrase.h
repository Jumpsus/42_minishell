#ifndef PHRASE_H
# define PHRASE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

/* 1_phrase_utils.c*/
int     able_to_phrase(char *str);
int     is_pipe_error(char *line);

/* 2_lexer.c*/
int		skip_quote(char *line, int index);
char	**lexer(char *line);

/* 3_parser.c*/
char    ***parser(char **lex);

/* 4_free_pharse.c*/
void    free_lexer(char **lex);
void    free_parser(char ***par);

#endif
