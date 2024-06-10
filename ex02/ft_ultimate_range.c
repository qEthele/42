/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yua <yua@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:30:03 by yua               #+#    #+#             */
/*   Updated: 2024/06/09 17:58:15 by yua              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*dest;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	dest = (int *)malloc((max - min) * sizeof(int));
	if (dest == NULL)
		return (-1);
	while (i < (max - min))
	{
		dest[i] = min + i;
		i++;
	}
	*range = dest;
	return (i);
}

int	main(void)
{
	int	*range;
	int	min;
	int	max;
	int	size;
	int	i;

	min = 0;
	max = 5;
	size = ft_ultimate_range(&range, min, max);
	i = 0;
	if (size == -1)
		printf("malloc failed");
	if (size == 0)
		printf("min >= max");
	if (size > 0)
	{
		while (i < size)
		{
			printf("%d ", range[i]);
			i++;
		}
	}
}
