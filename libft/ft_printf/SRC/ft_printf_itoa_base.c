/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:16:47 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 15:18:50 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_n(unsigned int n, int base)
{
	int					ret;

	ret = 1;
	while (n / base)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

char		*ft_printf_itoa_base(int n, int base, bool is_uin)
{
	const char			pattern[17] = "0123456789abcdef";
	char				*ret;
	unsigned int		uin;
	int					len;
	bool				neg;

	neg = (base == 10 && n < 0) ? 1 : 0;
	neg && is_uin == false ? ABS(n) : 1;
	uin = (unsigned int)n;
	len = count_n(uin, base);
	if ((ret = ft_strnew(len)) == NULL)
		return (NULL);
	ret[len--] = 0;
	while (len >= 0)
	{
		ret[len] = pattern[uin % base];
		uin /= base;
		len--;
	}
	return (ret);
}
