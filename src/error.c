/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:24:36 by sheferna          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:04 by sheferna         ###   ########.fr       */
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
