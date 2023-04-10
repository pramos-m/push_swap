/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:21:56 by pramos-m          #+#    #+#             */
/*   Updated: 2022/09/30 15:05:55 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
	{
		if (!s1)
			return ((char *)s2);
		if (!s2)
			return ((char *)s1);
	}
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = -1;
	j = -1;
	while (++i < ft_strlen(s1))
		str[i] = ((char *)s1)[i];
	while (++j <= ft_strlen(s2))
	{
		str[i] = ((char *)s2)[j];
		i++;
	}
	return (str);
}
