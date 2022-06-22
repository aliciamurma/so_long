/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:40:10 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/07 15:02:00 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	cont;
	size_t	len_s;

	cont = 0;
	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (len >= len_s - start && start < len_s)
		len = len_s - start;
	else if (start >= len_s)
		len = 0;
	else if (len > len_s)
		len = len_s;
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (0);
	while (cont < len)
		d[cont++] = s[start++];
	d[cont] = '\0';
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		cont;
	int		conts3;

	cont = -1;
	conts3 = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (0);
	while (s1[++cont])
		s3[cont] = s1[cont];
	while (s2[conts3])
		s3[cont++] = s2[conts3++];
	s3[cont] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	int	cont;

	cont = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)(s + cont));
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
			return ((char *)(s + cont));
		cont++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	cont;

	cont = 0;
	if (!str)
		return (0);
	while (str[cont])
		cont++;
	return (cont);
}

int	ft_strlen2(char *str)
{
	int	cont;

	cont = 0;
	if (!str)
		return (0);
	while (str[cont])
		cont++;
	return (cont);
}


char	*ft_strdup(char *s1)
{
	int		cont;
	char	*s2;
	int		len;

	cont = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (s1[cont] != '\0')
	{
		s2[cont] = *((char *)(s1 + cont));
		cont++;
	}
	s2[cont] = '\0';
	return (s2);
}
