/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:25:06 by misikogl          #+#    #+#             */
/*   Updated: 2022/09/29 22:13:54 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*j;

	i = 0;
	j = (unsigned char *)b;
	while (i < len)
	{
		j[i] = c;
		i++;
	}
	return (j);
}

// int main()
// {
// 	char str[] = "ahmet";
// 	printf("%s",ft_memset(str, 'b', 2));
// }
