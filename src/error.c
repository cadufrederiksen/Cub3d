/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:24:36 by sheferna          #+#    #+#             */
/*   Updated: 2025/01/21 19:54:44 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error(char *message)
{
	ft_fprintf(2, message);
	return (1);
}

void	error_exit(char *message, t_game *game)
{
	ft_fprintf(2, message);
	if (game)
		free_game(game);
	exit(1);
}
