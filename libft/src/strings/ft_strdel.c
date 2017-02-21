/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:39:50 by agaspard          #+#    #+#             */
/*   Updated: 2016/11/21 17:14:14 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** frees *as then set to NULL
*/

void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
