/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:55:41 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/28 15:22:44 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_cmd_type(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp)
	{
		if (tmp->pos == 0 && tmp->type == WORD)
			tmp->cmd_t = CMD;
		else if (tmp->type == WORD || tmp->type == STRING || tmp->type == HEREDOC)
			tmp->cmd_t = ARGS;
		tmp = tmp->next;
	}
	return (0);
}
