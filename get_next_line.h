/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:01:48 by wluedara          #+#    #+#             */
/*   Updated: 2022/10/29 16:06:31 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*get_read(int fd, char *str);
char	*get_str(char *str, int len);
char	*my_strchr(char *str, int c, int mode);
char	*my_strdup(char *s1, int len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		find_ch(char *str, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);


#endif