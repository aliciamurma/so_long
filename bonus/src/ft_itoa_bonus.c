/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:25:27 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/01 19:21:35 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_min(int n, char *str)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
	}
	return (str);
}

static char	*ft_negatives(int n, char *str, int len)
{
	if (n == -2147483648)
	{
		ft_min(n, str);
		return (str);
	}
	if (n < 0)
		str[0] = '-';
	while (len > 1 && n <= -10)
	{
		str[len - 1] = (((n * -1) % 10) + '0');
		n = (n / 10);
		len--;
	}
	if (n > -10 && n <= 0 && len <= 2)
		str[len - 1] = (n + '0');
	if (n > -10 && n <= 0 && len <= 2)
		str[len - 1] = ((n * -1) + '0');
	if (n == 0)
		str[len - 1] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (len > 0 && n > 9)
	{
		str[len - 1] = ((n % 10) + '0');
		n = (n / 10);
		len--;
	}
	if (n >= 0 && n < 10)
		str[len - 1] = (n + '0');
	str = ft_negatives(n, str, len);
	return (str);
}
