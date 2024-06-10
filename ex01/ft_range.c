/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yua <yua@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:01:39 by yua               #+#    #+#             */
/*   Updated: 2024/06/09 17:58:47 by yua              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	dest = (int *)malloc((max - min) * sizeof(int));
	while (i < (max - min))
	{
		dest[i] = min + i;
		i++;
	}
	return (dest);
}

int	main(void)
{
	int	*dest;
	int	i;
	int	min;
	int	max;

	min = 5;
	max = 5;
	dest = ft_range(min, max);
	i = 0;
	if (dest == NULL)
	{
		printf("min >= max");
	}
	else
	{
		while (i < (max - min))
		{
			printf("%d ", dest[i]);
			i++;
		}
	}
}
