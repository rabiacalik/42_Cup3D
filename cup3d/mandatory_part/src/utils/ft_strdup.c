#include "cub3d.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	index;
	size_t	len;

	len = ft_strlen(s) + 1;
	ret = malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	index = 0;
	while (index < len)
	{
		ret[index] = s[index];
		index++;
	}
	return (ret);
}