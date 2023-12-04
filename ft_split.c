/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:19:13 by tabadawi          #+#    #+#             */
/*   Updated: 2023/12/04 14:32:05 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(const char *s, char c)
{
	int		wordcount;

	wordcount = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			s++;
			if (*s == c || *s == '\0')
				wordcount++;
		}
	}
	return (wordcount);
}

static char	*wordsize(const char *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;
	int		wordcount;

	i = 0;
	if (!s)
		return (NULL);
	wordcount = words(s, c);
	split = malloc(sizeof(char *) * (wordcount + 1));
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			split[i] = wordsize(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	split[i] = (NULL);
	return (split);
}
