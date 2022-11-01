/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:26:42 by wluedara          #+#    #+#             */
/*   Updated: 2022/11/01 00:26:49 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		len;
	int		i;
	int		x;

	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2[x] != '\0')
		new[i++] = s2[x++];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*my_strdup(char *s1, int len)
{
	char	*dest;
	int		i;

	dest = malloc(len + 1);
	if (!dest)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!s)
		return (0);
	j = ft_strlen((char *)s);
	if (start > j || len <= 0)
		sub = (char *)malloc(sizeof(char) * 1);
	else if (len >= j)
		sub = (char *)malloc(sizeof(char) * (j - start + 1));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
	{
		free(s);
		s = NULL;
		return (0);
	}
	i = 0;
	while (i < len && start < j)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
