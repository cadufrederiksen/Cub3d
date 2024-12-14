/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:30:08 by sheferna          #+#    #+#             */
/*   Updated: 2024/12/14 19:46:18 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/* 
La dirección inicial del jugador se divide en dos funciones:
set_north_south: Configura los valores de dirección y plano para el eje norte-sur.
set_east_west: Configura los valores para el eje este-oeste.
 */
static void	set_north_south(t_player *player, char spawn)
{
	// El jugador está mirando al norte (dir_y = -1.0).
	// El plano de cámara se extiende a lo largo del eje X (plane_x = 0.66), perpendicular a la dirección (hacia el norte).
	if (spawn == 'N')
	{
		player->dir_x = 0.0; // Mirando hacia arriba (norte)
		player->dir_y = -1.0;
		player->plane_x = 0.66; // Plano de cámara en el eje X
		player->plane_y = 0.0;
	}
	else if (spawn == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->plane_x = -0.66;
		player->plane_y = 0.0;
	}
}

static void	set_east_west(t_player *player, char spawn)
{	// El jugador está mirando al este (dir_x = 1.0)
	// El plano de cámara se extiende a lo largo del eje Y (plane_y = 0.66), perpendicular a la dirección (hacia el este)
	if (spawn == 'E')
	{
		player->dir_x = 1.0; // Mirando hacia la derecha (este)
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = 0.66; // Plano de cámara en el eje Y
	}
	else if (spawn == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = -0.66;
	}
}

/* 
El plano de cámara y la dirección se combinan para calcular los rayos que se proyectan en la pantalla. 
Cada rayo se calcula a partir de:
rayDirection=dir+plane×(posicion relativa en pantalla)
Donde:

dir es la dirección del jugador.
plane es el plano de cámara.
La posición relativa en pantalla varía de -1 (izquierda) a 1 (derecha).
El valor 0.66 asegura que la proyección sea adecuada para un FOV de 66 grados.
*/

// selecciona la función correcta (norte-sur u este-oeste) según el carácter (spawn)
void	set_player_direction(t_player *player, char spawn)
{
	if (spawn == 'N' || spawn == 'S')
		set_north_south(player, spawn);
	else if (spawn == 'E' || spawn == 'W')
		set_east_west(player, spawn);
}
// inicializa al jugador con las coordenadas y dirección provenientes de los datos del mapa
void	init_player_from_map(t_game *game)
{
	if (game->mapsets->spawn == 0)
		error_exit("Error: Player spawn not found\n", game);
	game->player->pos_x = (double)game->mapsets->p_x + 0.5; // + 0.5 para centrar en la celda
	game->player->pos_y = (double)game->mapsets->p_y + 0.5; // + 0.5 para centrar en la celda
	set_player_direction(game->player, game->mapsets->spawn);
}
/* 
Dirección (dir_x, dir_y):

Define hacia dónde está mirando el jugador:
N: (0, -1)
S: (0, 1)
E: (1, 0)
W: (-1, 0)
Plano de cámara (plane_x, plane_y):

Representa el plano perpendicular a la dirección del jugador, usado para calcular el campo de visión en la proyección 2D.
Norte-sur: Plano en el eje X.
Este-oeste: Plano en el eje Y.
Posición (pos_x, pos_y):

Se inicializa en el centro de la celda con +0.5 para evitar problemas de alineación.
 */

/* 
Plano de la camara:
En un juego como Cub3D, el plano de cámara es un vector que define el ancho del campo de visión del jugador en el mundo 3D. Este plano es perpendicular a la dirección en la que está mirando el jugador (dir_x y dir_y).

El vector de dirección del jugador (dir_x, dir_y) indica hacia dónde mira el jugador (el eje principal de visión).
El plano de cámara define un área visual que se proyectará en la pantalla. A partir de este plano, se lanzan rayos para calcular qué partes del mundo se ven.

El valor 0.66 representa la mitad del ancho del campo de visión horizontal del jugador en relación a su dirección.

Relación con el campo de visión (FOV):
En el sistema de raycasting usado por muchos motores como el de Wolfenstein 3D, el FOV por defecto suele ser de 66 grados.
El valor 0.66 es un número empírico que funciona bien para generar una proyección visual que simula un FOV de aproximadamente 66 grados.
Este valor controla cuán "ancha" o "estrecha" parece la visión del jugador.
 */
