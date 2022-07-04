/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:51:56 by amurcia-          #+#    #+#             */
/*   Updated: 2022/05/24 19:45:18 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while ((cont < n && s1[cont] != '\0')
		|| (cont < n && s2[cont] != '\0'))
	{
		if (s1[cont] != s2[cont])
			return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
		cont++;
	}
	if (n == 0)
		return (0);
	return (0);
}
