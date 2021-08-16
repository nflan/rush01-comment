/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:52:19 by nflan             #+#    #+#             */
/*   Updated: 2021/08/16 09:48:11 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	init_table_column(char table[6][6], char *argv) // on ajoute les parametres dans les colonnes
{
	int	x;
	int	y;
	int	k;

	x = 0;
	y = 1; // on commence a 1 puisque notre tableau fait 6x6 et que l'on ne veut pas ecrire dans la cellule [0][0]
	k = 0;
	while (y < 5) // temps que l'on n'est pas au bout du tableau
	{
		table[x][y] = argv[k] - '0'; // on ajoute a la cellule ou on se trouve, la valeur du parametre
		y++; // on avance dans les colonnes
		k++; // on prend le parametre suivant
		if (y == 5 && x != 5) // si on est au bout de la colonne ET pas sur la derniere colonne
		{
			y = 1; // on retourne au debut de la colonne
			x = 5; // on passe a la derniere colonne
		}
	}
	return (1); // quand tout est fait, on retourne 1 (on aurait pu faire la fonction en void et sans return
}

int	init_table_row(char table[6][6], char *argv) // on fait pareil que pour les colonnes mais pour les lignes
{
	int	x;
	int	y;
	int	k;

	x = 1;
	y = 0;
	k = 8;
	while (x < 5)
	{
		table[x][y] = argv[k] - '0';
		x++;
		k++;
		if (x == 5 && y != 5)
		{
			x = 1;
			y = 5;
		}
	}
	return (1);
}

int	init_table_0(char table[6][6], char *argv) // on ajoute les 0 dans les cellules du centre du tableau (4x4)
{
	int	x;
	int	y;

	x = 1; // on ne touche pas a la premiere ligne
	y = 1; // on ne touche pas a la premiere colonne
	while (y < 5 && x < 5) // on ne touche pas a la 5eme ligne ET colonne
	{
		table[x][y] = 0; // on met un 0 dans la cellule ou on est
		y++; // on avance de colonne
		if (y == 5 && x != 4) // si on est sur la derniere case de la colonne ET pas sur la derniere ligne
		{
			x++; // on avance de ligne
			y = 1; // on retourne a la premiere case de la colonne
		}
	}
	init_table_column(table, argv); // on appelle la fonction pour ajouter les colonnes
	init_table_row(table, argv); // on appelle la fonction pour ajouter les lignes
	return (1); // on retourne 1 mais on aurait pu passer la fonction en void et ne rien retourner
}
