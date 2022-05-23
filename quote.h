#ifndef QUOTE_H
# define QUOTE_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_mini
{
	char	**env;
	int	exit_status;
} t_mini;


/* 1_quote_utils.c */
char    *get_envname(char *str);
char    *ft_getenv(char *name, char **env);

/* 2_translate_vars.c */
char    *ft_append(char *buffer, char c);
char    *ft_join(char *front, char *back);
char    *ft_append_env(char *buffer, char *command, int *index);
char    *translate_cmd(char *command);

extern t_mini g_mini;
#endif
