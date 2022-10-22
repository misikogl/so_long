/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhammed <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:33:31 by misikogl          #+#    #+#             */
/*   Updated: 2022/03/31 23:32:51 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			return (str + i);
		}
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (NULL);
}
/*
int main()
{
	char a[] = "irema";
	char *v;
	v = ft_strchr(a,'r');
	printf("%s\n",v);
}
*/
