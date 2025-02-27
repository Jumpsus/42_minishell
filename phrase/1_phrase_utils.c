/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_phrase_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:55:27 by pratanac          #+#    #+#             */
/*   Updated: 2022/05/20 12:55:29 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_pipe_error(char *line)
{
	int	i;
	int	last;

	i = 0;
	last = 0;
	if (line[i] == '|')
		return (1);
	while (line[i])
	{
		if (line[i] == '|')
		{
			if (last)
				return(1);
			last = 1;
		}
		else
		{
			last = 0;
		}
		i++;
	}
	if (i > 0 && line[i - 1] == '|')
		return (2);
	return (0);
}
