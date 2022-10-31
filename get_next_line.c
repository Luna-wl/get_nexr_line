/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:07:15 by wluedara          #+#    #+#             */
/*   Updated: 2022/10/31 14:40:29 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_ch(char *str, char c)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str) + 1;
	if (!str)
		return (0);
	while (i < len)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_read(int fd, char *str)
{
	char	*buf;
	int		byte;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	byte = read(fd, buf, BUFFER_SIZE);
	if (byte <= 0)
	{
		free (buf);
		if (str[0] != '\0')
			return (str);
		free(str);
		return (NULL);
	}
	while (byte > 0)
	{
		buf[byte] = '\0';
		str = ft_strjoin(str, buf);
		if (find_ch(str, '\n') != -1)
			break ;
		byte = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (str);
}

char	*get_str(char *str, int len)
{
	char	*s;
	int		len_str;

	if (len < 1)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	len_str = ft_strlen(str) - len;
	s = ft_substr(str, len, len_str);
	free(str);
	str = NULL;
	return (s);
}

char	*get_new(char *str, int len)
{
	char	*new;

	if (len < 1)
	{
		new = ft_substr(str, 0, ft_strlen(str));
		return (new);
	}
	new = my_strdup(str, len);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	int			len;
	char		*new;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!str)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	str = get_read(fd, str);
	if (!str)
		return (NULL);
	len = find_ch(str, '\n') + 1;
	new = get_new(str, len);
	str = get_str(str, len);
	return (new);
}
