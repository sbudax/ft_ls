/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:21:34 by sbxaba            #+#    #+#             */
/*   Updated: 2018/08/31 08:43:51 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		add_args(t_env *e, char *arg)
{
	int	i;

	i = 1;
	while (arg[i] != '\0')
	{
		if (arg[i] == 'l')
			e->l = 1;
		else if (arg[i] == 'a')
			e->a = 1;
		else if (arg[i] == 'r')
			e->r = 1;
		else if (arg[i] == 't')
			e->t = 1;
		else if (arg[i] == 'R')
			e->rr = 1;
		else
		{
			ft_putstr(arg);
			ft_putendl(": Invalid argument");
			return (0);
		}
		i++;
	}
	return (1);
}

int		compare_strings(t_dir d1, t_dir d2)
{
	return (ft_strcmp(d1.dir, d2.dir));
}

int		compare_time(t_dir d1, t_dir d2)
{
	if (d1.time < d2.time)
		return (1);
	else
		return (0);
}

void	sort_list(t_dir **head, int (*cmp)(t_dir, t_dir), int done)
{
	t_dir	**src;
	t_dir	*temp;
	t_dir	*next;

	while (!done && *head != NULL && (*head)->next != NULL)
	{
		src = head;
		temp = *head;
		next = (*head)->next;
		done = 1;
		while (next)
		{
			if (cmp(*temp, *next) > 0)
			{
				temp->next = next->next;
				next->next = temp;
				*src = next;
				done = 0;
			}
			src = &temp->next;
			temp = next;
			next = next->next;
		}
	}
}
