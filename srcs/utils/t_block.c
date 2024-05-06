/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_block.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:17:38 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/06 13:25:58 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_block	*ft_block_new(t_data *data)
{
	t_block	*block;

	block = malloc(sizeof(t_block));
	if (!block)
		exit_error(ERROR_MALLOC, NULL, data);
	block->args = NULL;
	block->redir = NULL;
	block->next = NULL;
	block->heredoc_exp = -1;
	block->cmd = NULL;
	if (data->block == NULL)
		data->block = block;
	else
	{
		while (data->block->next)
			data->block = data->block->next;
		data->block->next = block;
	}
	return (block);
}

void	ft_arg_print(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		ft_printf("%s ", args[i]);
		i++;
	}
	ft_printf("\n");
}

void	ft_block_print(t_block *block)
{
	t_block	*tmp;

	tmp = block;
	printf("\n\nblock\n");
	while (tmp)
	{
		ft_printf("cmd: %s\n", tmp->cmd);
		ft_printf("heredoc_exp: %d\n", tmp->heredoc_exp);
		ft_redir_print(tmp->redir);
		ft_printf("args: ");
		ft_arg_print(tmp->args);
		ft_printf("\n");
		tmp = tmp->next;
	}
}

void	ft_block_clear(t_block **block)
{
	t_block	*tmp;
	t_block	*next;

	tmp = *block;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->cmd)
			free(tmp->cmd);
		if (tmp->args)
			ft_free_tab(tmp->args);
		// if (tmp->redir)
		// 	ft_redir_clear(&tmp->redir);
		free(tmp);
		tmp = next;
	}
	*block = NULL;
}
