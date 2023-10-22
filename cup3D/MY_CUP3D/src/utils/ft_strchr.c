#include "cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	int	s_len;

	if (!s)
		return (0);
	s_len = ft_gnl_strlen(s);
	while (s_len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		s_len--;
	}
	return (NULL);
}