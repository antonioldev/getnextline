/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 07:21:01 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/17 16:22:15 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_static_array(char *temp, char *s, int fz)
{
	int		j;
	size_t	len;
	size_t	len_temp;
	char	*ptr;

	ptr = 0;
	if (temp || fz > 0)
	{
		len_temp = ft_strlen(temp);
		j = check_for_n_line(temp, len_temp);
		len = len_temp - j;
		if (len > 0 && len_temp > 0)
		{
			ptr = (char *)malloc((len + 1));
			ft_strncpy(ptr, temp, j, len_temp);
		}
	}
	free(s);
	s = 0;
	if (ptr)
		return (ptr);
	return (0);
}

static int	fill_temp_array(char **temp, char *s, int fz)
{
	char	*temp2;
	size_t	len;
	size_t	len_src;

	if (*temp == 0 && fz != 0)
	{
		*temp = (char *)malloc((fz + 1));
		ft_strcpy(*temp, s);
		len_src = ft_strlen(*temp);
	}
	else if (fz != 0)
	{
		len_src = ft_strlen(*temp);
		len = len_src + fz + 1;
		temp2 = (char *)malloc(len);
		ft_strcpy(temp2, *temp);
		ft_strcat(temp2, s, len_src);
		free(*temp);
		*temp = (char *)malloc(len + 1);
		ft_strcpy(*temp, temp2);
		free(temp2);
	}
	if (fz < BUFFER_SIZE)
		return (0);
	return (check_for_n_line(*temp, len_src));
}

static char	*empty_static(char *static_arr, char *temp, size_t len)
{
	temp = (char *)malloc((len + 1));
	ft_strcpy(temp, static_arr);
	free(static_arr);
	static_arr = 0;
	return (temp);
}

static int	fill_s(char *s, int fd)
{
	int		fz;

	fz = read(fd, s, BUFFER_SIZE);
	if (fz < 0)
	{
		free (s);
		return (-1);
	}
	if (fz < BUFFER_SIZE)
		s[fz] = '\0';
	else
		s[BUFFER_SIZE] = '\0';
	return (fz);
}

char	*get_next_line(int fd)
{
	static char	*static_arr;
	char		*temp;
	char		*s;
	int			fz;
	int			check;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 4095)
		return (NULL);
	s = (char *)malloc(BUFFER_SIZE + 1);
	check = -1;
	temp = 0;
	if (static_arr != 0)
		temp = empty_static(static_arr, temp, ft_strlen(static_arr));
	while (check == -1)
	{
		fz = fill_s(s, fd);
		if (fz < 0)
			return (NULL);
		check = fill_temp_array(&temp, s, fz);
	}
	static_arr = fill_static_array(temp, s, fz);
	if (temp && ft_strlen(temp) > 0)
		return (temp);
	free(temp);
	return (NULL);
}
