/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:18:31 by cpopolan          #+#    #+#             */
/*   Updated: 2023/01/19 14:05:43 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *stack, int *x)
{
	char	*line;
	int		i;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
		i++;
	line = line_before(stack, i);
	*x = i;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stack[4096];
	char		*buffer;
	char		*line;
	int			read_bytes;
	int			i;

	i = 0;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		buffer = calloc(sizeof(char), (BUFFER_SIZE + 1));
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd < 0)
		{
			free(buffer);
			return (NULL);
		}
		stack[fd] = join(stack[fd], buffer);
		free(buffer);
		if (ft_search(stack[fd]))
			break ;
	}
	line = ft_line(stack[fd], &i);
	stack[fd] = line_after(stack[fd], i);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	int		fd2;
	int		i;
	char	*str;
	char	*str2;

	i = 0;
	fd = open("testo.txt", O_RDONLY);
	fd2 = open("testo2.txt", O_RDONLY);
	while (i < 17)
	{
		str = get_next_line(fd);
		str2 = get_next_line(fd2);
		printf("%s", str);
		printf("%s", str2);
		free(str);
		free(str2);
		i++;
	}
	close(fd);
	close(fd2);
	return (0);
}*/
