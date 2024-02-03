/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:04:01 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/02 20:04:28 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_current_line(char *s)
{
	int		i;
	char	*current;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	current = (char *)ft_calloc(sizeof (char), i + 2);
	if (!current)
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != '\n')
		current[i] = s[i];
	if (s[i] == '\n')
		current[i] = s[i];
	if (s[i] == '\n')
		i++;
	current[i] = '\0';
	return (current);
}

char	*get_read_line(int fd, char *readline)
{
	char		*buffer;
	int			flag;

	flag = 1;
	buffer = ft_calloc(sizeof (char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && flag > 0)
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[flag] = '\0';
		readline = ft_strjoin(readline, buffer);
	}
	free(buffer);
	return (readline);
}

char	*update_line(char *line)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	result = (char *)ft_calloc(sizeof(char), ft_strlen(line) - i + 1);
	if (!result)
		return (NULL);
	i++;
	j = 0;
	while (line[i + j])
	{
		result[j] = line[i + j];
		j++;
	}
	free(line);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_next[256];

	line = NULL;
	if (fd < 0 || fd > 256)
		return (NULL);
	line_next[fd] = get_read_line(fd, line_next[fd]);
	if (!line_next[fd])
	{
		return (NULL);
	}
	line = get_current_line(line_next[fd]);
	line_next[fd] = update_line(line_next[fd]);
	return (line);
}
