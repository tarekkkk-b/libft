/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:07:56 by tabadawi          #+#    #+#             */
/*   Updated: 2023/11/28 14:23:05 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	t;

	i = 0;
	t = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == t)
			return ((char *)s + i);
		i++;
	}
	if (t == '\0')
		return ((char *)s + i);
	return (NULL);
}
