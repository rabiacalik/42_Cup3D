#include "cub3d.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*ret;
	size_t	index;

	if (ft_strlen(str) < n)
		n = ft_strlen(str);
	ret = malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	index = 0;
	while (index < n)
	{
		ret[index] = str[index];
		index++;
	}
	ret[index] = 0;
	return (ret);
}