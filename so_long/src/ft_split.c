/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:47:32 by amurcia-          #+#    #+#             */
/*   Updated: 2022/05/26 20:07:36 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t	ft_count_words(char *s, char c)
{
	size_t	cont;
	size_t	word;

	cont = 0;
	word = 0;
	while (s[cont])
	{
		if (s[cont] != c && (s[cont + 1] == c || s[cont + 1] == '\0'))
			word++;
		cont++;
	}
	return (word);
}

static void	ft_free(char **d, size_t cont_d)
{
	while (cont_d > 0)
	{
		cont_d--;
		free(d[cont_d]);
	}
	free(d);
}

static char	**ft_refile(char *s, char c, char **d)
{
	size_t	cont;
	size_t	start;
	size_t	cont_d;

	cont = 0;
	start = 0;
	cont_d = 0;
	while (s[cont])
	{
		if (s[cont] == c && s[cont + 1] != c)
			start = cont + 1;
		if (s[cont] != c && (s[cont + 1] == c || s[cont + 1] == '\0'))
		{	
			d[cont_d] = ft_substr(s, start, cont - start + 1);
			if (!d[cont_d])
			{
				ft_free(d, cont_d);
				return (NULL);
			}
			cont_d++;
		}
		cont++;
	}
	d[cont_d] = NULL;
	return (d);
}

char	**ft_split(char *s, char c)
{
	char	**d;
	size_t	words;

	words = ft_count_words(s, c);
	d = malloc(sizeof(char *) * (words + 1));
	if (!d || !s)
		return (NULL);
	d = ft_refile(s, c, d);
	return (d);
}
