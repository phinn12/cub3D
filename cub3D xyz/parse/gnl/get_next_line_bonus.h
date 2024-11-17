/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:02:54 by ibkocak           #+#    #+#             */
/*   Updated: 2023/11/15 16:05:16 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

char	*get_next_line(int fd);
char	*ft_get_lef(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchar(char *str, char c);
int		ft_strlen(char *str);
char	*ft_reader(int fd, char *str);
#endif
