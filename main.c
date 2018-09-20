/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:46:44 by sbxaba            #+#    #+#             */
/*   Updated: 2018/08/31 08:46:25 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		i;
	t_env	e;
	t_dir	*tmp;

	i = 1;
	e.list = NULL;
	while (i < argc)
	{
		if (argv[i][0] != '-' && (tmp = (t_dir*)malloc(sizeof(t_dir))))
		{
			tmp->dir = argv[i];
			tmp->next = e.list;
			e.list = tmp;
			ft_putstr("ft_ls: ");
			ft_putstr(argv[i]);
			ft_putendl(": No such file or directory");
		}
		else if (add_args(&e, argv[i]) == 0)
			return (0);
		i++;
	}
	if (e.list == NULL)
		do_list(&e);
	ft_ls(&e);
}
