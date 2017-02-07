/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:52:12 by fhuang            #+#    #+#             */
/*   Updated: 2016/07/09 18:52:16 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		arglst_add(t_print **lst, t_print *new)
{
	t_print		*link;

	if (*lst)
	{
		link = *lst;
		while (NEXT_ARG)
			link = NEXT_ARG;
		NEXT_ARG = new;
	}
	else
		*lst = new;
}

void			add_link(t_env *e, t_print *new, bool arg)
{
	t_print		*link;
	t_print		**lst;

	new->next = NULL;
	new->next_arg = NULL;
	lst = &e->full_lst;
	if (*lst)
	{
		link = *lst;
		while (NEXT)
			link = NEXT;
		NEXT = new;
	}
	else
		*lst = new;
	if (arg)
		arglst_add(&e->arg_lst, new);
}
