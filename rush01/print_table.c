/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 19:04:36 by nflan             #+#    #+#             */
/*   Updated: 2021/08/16 09:56:43 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_tab(char table[6][6]) // affichage de la table
{
	int	x;
	int	y;

	y = 1; // on commence a 1 car tableau de 6x6 et on ne veut afficher que le milieu
	while (y < 5) // pareil qu'avant
	{
		x = 1;
		while (x < 5)
		{
			ft_putchar(table[y][x] + '0'); // on affiche les caracteres 1 a 1 dans le tableau de 4x4 au milieu. comme c'est des caracteres, on ajoute l'ascii avec +'0'
			if (++x < 5)
				ft_putchar(' ');
		}
		ft_putchar('\n'); // a la fin de chaque ligne, on retourne a la ligne
		y++; // a la fin de chaque ligne, on passe a la colonne d'apres
	}
}
