/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:56:59 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/17 11:31:36 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	check_for_n_line(char *temp, size_t len)
{
	size_t	i;

	i = 0;
	while (i <= len)
	{
		if (temp[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	ft_strncpy(char *dest, char *src, size_t j, size_t src_len)
{
	size_t	i;

	i = 0;
	while (j < src_len)
	{
		dest[i] = src[j];
		src[j] = '\0';
		i++;
		j++;
	}
	dest[i] = '\0';
}

void	ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_strcat(char *dest, char *src, size_t len_src)
{
	size_t	i;

	i = 0;
	if (dest || src)
	{
		while (src[i] != '\0')
		{
			dest[len_src] = src[i];
			len_src++;
			i++;
		}
		dest[len_src] = '\0';
	}
}
