/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:20:39 by amurcia-          #+#    #+#             */
/*   Updated: 2022/05/20 15:25:53 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	cont_h;
	size_t	cont_n;

	cont_h = 0;
	cont_n = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	else if (haystack[0] == '\0')
		return (0);
	while (haystack[cont_h] != '\0')
	{
		cont_n = 0;
		while ((haystack[cont_h + cont_n] == needle[cont_n])
			&& ((cont_h + cont_n) < len))
		{
			if (needle[cont_n + 1] == '\0')
				return ((char *)(haystack + cont_h));
			cont_n++;
		}
		cont_h++;
	}
	return (0);
}
