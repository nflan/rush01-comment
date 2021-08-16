/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 14:40:33 by nflan             #+#    #+#             */
/*   Updated: 2021/08/16 09:54:45 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_four_row(char tab[6][6]) // on check s'il y a des 1 dans les lignes, si oui, on met des 4 dans la cellule au dessus ou en dessous
{
	int	i;

	i = 1; // on commence a 1 car tableau de 6x6
	while (i < 5) // on s'arrete a 4 car tableau de 6x6
	{
		if (tab[0][i] == 1) // si, sur la ligne 0 il y a un 1
			tab[1][i] = 4; // on met un 4 en dessous
		i++; // on avance sur la ligne
	}
	i = 1;
	while (i < 5)
	{
		if (tab[5][i] == 1) // sim sur la ligne 5 il y a un 1
			tab[4][i] = 4; // on met un 4 au dessus
		i++; // on avance sur la ligne
	}
	return (1);
}

int	check_four_column(char tab[6][6])// on check s'il y a des 1 dans les colonnes, si oui, on met des 4 dans la cellule a droite ou a gauche. pareil qu'avant mais avec les colonnes
{
	int	j;

	j = 1;
	while (j < 5)
	{
		if (tab[j][0] == 1)
			tab[j][1] = 4;
		j++;
	}
	j = 1;
	while (j < 5)
	{
		if (tab[j][5] == 1)
			tab[j][4] = 4;
		j++;
	}
	return (1);
}

int	check_four(char tab[6][6]) // on appelle les fonctions dans une fonction pour gagner de la place dans le main
{
	check_four_row(tab);
	check_four_column(tab);
	return (1);
}
// note : toutes les fonctions auraient pu etre des void et ne rien retourner.
