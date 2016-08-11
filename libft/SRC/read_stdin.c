/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 22:08:09 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/11 20:57:24 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char			*read_stdin(void)
{
	int				ret;
	char			*tmp;
	char			*line;
	char			buf[BUFF_SIZE + 1];

	if (BUFF_SIZE <= 0)
		return (NULL);
	line = (char*)ft_strnew(1);
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ft_strchr(line, '\n') == 0) && (ret = read(0, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		if (!(line = ft_strjoin_free(line, buf)))
			return (NULL);
	}
	tmp = ft_strstr(line, "\n");
	if (tmp)
		ft_bzero(tmp, ft_strlen(tmp));
	if (ret == 0)
		line = NULL;
	return (line);
}
