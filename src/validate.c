/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:39 by sheferna          #+#    #+#             */
/*   Updated: 2024/12/03 20:02:51 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_texture_paths(t_mapsets *mapsets)
{
	if (!mapsets->no_path || !mapsets->so_path || 
		!mapsets->we_path || !mapsets->ea_path)
		return (error("Error: Missing texture paths"));
	if (access(mapsets->no_path, F_OK) != 0 ||
		access(mapsets->so_path, F_OK) != 0 ||
		access(mapsets->we_path, F_OK) != 0 ||
		access(mapsets->ea_path, F_OK) != 0)
		return (error("Error: Invalid texture file paths"));
	return (0);
}
