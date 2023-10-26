#include "cub3d.h"
size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(const char *s, int c)
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

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		s3[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
	{
		s3[i + j] = s2[j];
	}
	s3[i + j] = 0;
	free(s1);
	return (s3);
}

char	*ft_get_line(char *kalan)
{
	int		i;
	char	*str;

	i = 0;
	if (!kalan[i])
		return (NULL);
	while (kalan[i] && kalan[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (kalan[i] && kalan[i] != '\n')
	{
		str[i] = kalan[i];
		i++;
	}
	if (kalan[i] == '\n')
	{
		str[i] = kalan[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *kalan)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (kalan[i] && kalan[i] != '\n')
		i++;
	if (!kalan[i])
	{
		free(kalan);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_gnl_strlen(kalan) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (kalan[i])
		str[j++] = kalan[i++];
	str[j] = '\0';
	free(kalan);
	return (str);
}

char	*ft_read_to_left_str(int fd, char *kalan)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_gnl_strchr(kalan, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		kalan = ft_gnl_strjoin(kalan, buff);
	}
	free(buff);
	return (kalan);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*kalan;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	kalan = ft_read_to_left_str(fd, kalan);
	if (!kalan)
		return (NULL);
	str = ft_get_line(kalan);
	kalan = ft_new_left_str(kalan);
	return (str);
}
