#include "../../so_long.h"

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
