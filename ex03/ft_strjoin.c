/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yua <yua@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:01:54 by yua               #+#    #+#             */
/*   Updated: 2024/06/09 20:18:45 by yua              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_join(int size, char *dest, char *sep, char **strs)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			dest[index++] = strs[i][j++];
		j = 0;
		while (sep[j] && i != size - 1)
			dest[index++] = sep[j++];
		i++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*dest;
	int		i;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += ft_strlen(sep) * (size - 1);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_join(size, dest, sep, strs);
	return (dest);
}

int	main(void)
{
	char	*strs[4];
	char	*sep;
	int		size;
	char	*dest;

	strs[0] = "cat";
	strs[1] = "dog";
	strs[2] = "bird";
	strs[3] = "fish";
	sep = ", ";
	size = 3;
	dest = ft_strjoin(size, strs, sep);
	printf("%s", dest);
}
