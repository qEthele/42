/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yua <yua@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:04:40 by yua               #+#    #+#             */
/*   Updated: 2024/06/10 01:35:57 by yua              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int check_str_twice(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 1 + i;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}	
	return (1);
}

int checkbase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9')))
		{
			return (0);
		}
		i++;
	}
	if (i >= 2)
		return (check_str_twice(str));
	return (0);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *dest;
	 if (!checkbase(base_from) || !checkbase(base_to))
	 	return (NULL);
	return (dest);
}

int main(void)
{
	char	*nbr;
	char	*base_from;
	char	*base_to;

	nbr = "10";
	base_from = "0123456789";
	base_to = "0123456789ABCDEF";
	printf("%s", ft_convert_base(nbr, base_from, base_to));
}