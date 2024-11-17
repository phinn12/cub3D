/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:02:54 by ibkocak           #+#    #+#             */
/*   Updated: 2024/10/15 17:17:23 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_get_lef(char *str);
char	*ft_strchar(char *str, char c);
char    *ft_strjoin(const char *s1, const char *s2);
int     ft_strlenx(const char *str);
char	*ft_reader(int fd, char *str);
char	*get_next_line(int fd);
#endif
