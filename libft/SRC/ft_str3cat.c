/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 15:22:48 by fhuang            #+#    #+#             */
/*   Updated: 2016/07/13 15:24:53 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str3cat(char *s1, char *s2, char *s3)
{
	char	*ret;

	ret = ft_strndup(s1, ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3));
	if (ret == NULL)
		return (NULL);
	if (s2 != NULL)
		ret = ft_strcat(ret, s2);
	if (s3 != NULL)
		ret = ft_strcat(ret, s3);
	return (ret);
}
