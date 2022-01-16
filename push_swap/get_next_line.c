/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:28:40 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/16 05:27:27 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*sr1;
	unsigned char	*sr2;

	i = 0;
	sr1 = (unsigned char *)s1;
	sr2 = (unsigned char *)s2;
	while (i < n && (sr1[i] || sr2[i]))
	{
		if (sr1[i] != sr2[i])
			return (sr1[i] - sr2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*dst;

	i = ft_strlen(s1);
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = (char)s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	char	save[999999];
	char	buff[1];
	char	*line;
	int		i;

	i = 0;
	if (fd < 0)
		return (NULL);
	save[i] = '\0';
	while (read(STDIN_FILENO, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (NULL);
	line = ft_strdup(save);
	return (line);
}
