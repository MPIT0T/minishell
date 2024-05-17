/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_here_doc_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:06:32 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/17 19:38:25 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_lines(char *s1, char *s2, t_data *data)
{
	char	*res;

	if (ft_strcmp(s1, "") == 0)
	{
		res = ft_strdup(s2);
		if (!res)
			exit_error(ERROR_MALLOC, NULL, data);
	}
	else
	{
		res = ft_strjoin_free(s1, s2, 2);
		if (!res)
			exit_error(ERROR_MALLOC, NULL, data);
	}
	res = ft_strjoin_free(res, "\n", 1);
	if (!res)
		exit_error(ERROR_MALLOC, NULL, data);
	return (free(s1), res);
}

void	ft_heredoc_pipe(t_data *data, t_redir *redir, char *line)
{
	int	fd[2];

	if (pipe(fd) == -1)
		exit_error(ERROR_PIPE, NULL, data);
	ft_printf_fd(fd[1], "%s", line);
	close(fd[1]);
	redir->fd = fd[0];
}

void	heredoc_calc_expan_size(char *line, t_data *data,
	size_t *size, size_t *i)
{
	size_t	start;
	size_t	end;
	char	*tmp;

	if (line[*i + 1] == '?')
	{
		*size += ft_count(data, ft_itoa(g_error), 0);
		*i += 1;
	}
	else if (ft_iscaracter_env(line[*i + 1], 0) == 1
		&& line[*i + 1] != '\0')
	{
		*i += 1;
		start = *i;
		while (line[*i] && ft_iscaracter_env(line[*i], 1) == 1)
			*i += 1;
		if (ft_isdigit(line[*i]) == 1)
			*i += 1;
		end = *i;
		tmp = ft_strdup_size(&line[start], end - start);
		*size += ft_count(data, ft_envfind_data(data->env, tmp), 1);
		free(tmp);
		*i -= 1;
	}
	else if (ft_check_is_incote(line, i) == 1
		|| line[*i + 1] == '\0'
		|| ft_iscaracter_env(line[*i + 1], 0) == 0)
		*size += 1;
}
