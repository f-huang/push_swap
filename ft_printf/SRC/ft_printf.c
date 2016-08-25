/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 13:30:54 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/25 18:46:49 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_env		e;
	int			len;

	init_env(&e);
	va_start(e.ap, format);
	if ((read_str(&e, (char*)format)) == -1)
		return (-1);
	read_and_transform_arg(&e);
	len = print_entire_list(&e, 1);
	va_end(e.ap);
	destroy_env(&e);
	return (len);
}

int			ft_printf_fd(int fd, const char *format, ...)
{
	t_env		e;
	int			len;

	init_env(&e);
	va_start(e.ap, format);
	if ((read_str(&e, (char*)format)) == -1)
		return (-1);
	read_and_transform_arg(&e);
	len = print_entire_list(&e, fd);
	va_end(e.ap);
	destroy_env(&e);
	return (len);
}
