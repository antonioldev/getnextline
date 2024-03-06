/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 07:22:50 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/10 07:28:05 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

int		check_for_n_line(char *temp, size_t len);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
void	ft_strcpy(char *dest, char *src);
void	ft_strcat(char *dest, char *src, size_t len_src);
void	ft_strncpy(char *dest, char *src, size_t j, size_t scr_len);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
#endif