/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:03:41 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/02 20:01:22 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include"get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	i;
	size_t	len;

	i = 0;
	len = size * nmemb;
	mem = malloc(len + 1);
	if (!mem)
		return (NULL);
	while (i < len)
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	lo;
	size_t	lr;
	size_t	maxlo;
	char	*sr;

	lo = start;
	maxlo = ft_strlen(s);
	lr = 0;
	if (!s || maxlo <= lo)
		return (NULL);
	if (len >= maxlo)
		len = maxlo;
	sr = ft_calloc(sizeof(char), (len + 1));
	if (!sr)
		return (NULL);
	while (lr < len && lo < maxlo)
		sr[lr++] = s[lo++];
	return (sr);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		l1;
	int		l2;
	char	*sr;

	l1 = -1;
	l2 = -1;
	if (!s1)
	{
		s1 = ft_calloc(sizeof (char), 2);
		s1[0] = '\0';
	}
	sr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sr)
		return (0);
	while (s1[++l1])
		sr[l1] = s1[l1];
	while (s2[++l2])
		sr[l1 + l2] = s2[l2];
	sr[l1 + l2] = '\0';
	free(s1);
	return (sr);
}
