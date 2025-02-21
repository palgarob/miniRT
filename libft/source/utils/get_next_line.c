/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:12:09 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/12 19:10:13 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	prepare_block(char **block)
{
	char	*nl;
	char	*new_block;
	int		len;

	nl = ft_strchr(*block, 10);
	if (!nl)
	{
		*block = 0;
		return ;
	}
	len = (nl - *block) + 1;
	if (!(*block)[len])
	{
		free(*block);
		*block = 0;
		return ;
	}
	new_block = ft_substr(*block, nl - *block + 1, ft_strlen(nl + 1));
	free(*block);
	*block = new_block;
}

static char	*stract_line(char *block)
{
	char	*nl;
	char	*line;

	nl = ft_strchr(block, 10);
	if (!nl)
		return (block);
	line = ft_substr(block, 0, (nl - block) + 1);
	return (line);
}

static char	*expand_block(char **block, int fd)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && (!*block || !ft_strchr(*block, 10)))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buf[bytes_read] = 0;
			*block = ft_strjoin_gnl(*block, buf);
			if (!*block)
				break ;
		}
	}
	free(buf);
	if (bytes_read < 0)
	{
		free(*block);
		*block = 0;
	}
	return (*block);
}

char	*get_next_line(int fd)
{
	static char	*block = 0;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!expand_block(&block, fd))
		return (NULL);
	line = stract_line(block);
	prepare_block(&block);
	return (line);
}
