/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:12:57 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/13 15:49:19 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_put_error(char *str, int error)
{
	(void)error;
	ft_putstr_fd(str, 2); // TODO: replace ft_putendl_fd by ftd_printf()
	return (1);
}
void	ft_free_data(t_data *data)
{
	(void)data;
}

void	ft_megafree(t_data *data)
{
	(void)data;
}
