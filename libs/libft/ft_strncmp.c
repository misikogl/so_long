/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhammed <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:09:49 by misikogl          #+#    #+#             */
/*   Updated: 2022/03/31 23:26:41 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char		*i;
	unsigned char		*j;
	size_t				k;

	k = 0;
	i = (unsigned char *) s1;
	j = (unsigned char *) s2;
	while (k < n && (i[k] || j[k]))
	{
		if (i[k] != j[k])
			return (i[k] - j[k]);
		k++;
	}	
	return (0);
}
/*
int main(void)
{
	char s1[] = "ahmet";
	char s2[] = "mumu";
	int z;

	z = ft_strncmp(s1, s2, 3);

	printf("%d\n", z);
}
*/
