/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 12:10:39 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/08 12:37:06 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#ifndef GOOD
# define GOOD 1
#endif

#ifndef ERROR
# define ERROR 0
#endif

#ifndef ERROR_STRING
# define ERROR_STRING "Error\n"
#endif

int		check_parameters(char **av);

#endif
