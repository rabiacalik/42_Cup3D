/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:21:01 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/14 20:31:46 by rcalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_isspace_a(const char *chr, int *index)
{
	*index = 0;
	while ((chr[*index] >= 9 && chr[*index] <= 13) || chr[*index] == ' ')
		(*index)++;
}

static int	ft_sign(char c, int *index)
{
	int	sign;

	sign = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			sign *= -1;
		*index += 1;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int	ret_val;
	int	index;
	int	sign;

	ret_val = 0;
	if (*nptr == '\0')
		return (0);
	ft_isspace_a(nptr, &index);
	sign = ft_sign(nptr[index], &index);
	while (nptr[index] == '0')
		index++;
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		ret_val = (ret_val * 10) + (nptr[index++] - '0');
		if (ret_val <= 0)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
	}
	return (ret_val * sign);
}
