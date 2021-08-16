/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:08:50 by nflan             #+#    #+#             */
/*   Updated: 2021/08/16 10:16:43 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	check_columns_lines(char table[6][6]); // appelle inutile de cette fonction, on ne s'en sert pas

int	absent_on_line(char k, char table[6][6], int x) // on verifie que la valeur k passee en parametre (1 a 4) n'est pas presente sur la ligne
{
	int	y;

	y = 1;
	while (y < 5)
	{
		if (table[x][y] == k - '0')
			return (0); // si elle est presente, retourne 0 et la fonction va etre rappelee avec une autre valeur de k
		y++;
	}
	return (1); // si elle est absente, retourne 1, la valeur sera ajoutee a la position donnee en parametre par la fonction is_valid
}

// meme principe que pour les lignes mais pour les colonnes
int	absent_on_column(char k, char table[6][6], int y)
{
	int	x;

	x = 1;
	while (x < 5)
	{
		if (table[x][y] == k - '0')
			return (0);
		x++;
	}
	return (1);
}

int	is_valid(char table[6][6], int position) // fonction qui ajoute les numeros de facon a ne pas avoir deux fois le meme sur la meme ligne ou colonne
{
	int		x; // compteur de ligne
	int		y; // compteur de position sur la ligne
	char	k; // valeur que l'on va ajouter

	k = '1'; // on commence a 1 puisque les valeurs vont de 1 a 4 et '' car c'est un char mais je pense que sans, je n'avais pas besoin de retirer l'ascii au moment de l'ajout de la valeur, plus bas
	x = 1 + position / 5; // on commence a 1 car le tableau fait 6x6 et on vise l'interieur puis on utilise le parametre position qui sera modifie plus tard lors des differents appels de la fonction. quand position sera un multiple de 5, on changera de ligne
	y = 1 + position % 5; // on commence a 1 car le tableau fait 6x6 et on vise l'interieur puis on utilise le parametre position qui sera modifie plus tard lors des differents appels de la fonction. quand position sera ne sera pas un multiple de 5, on changera de colonne
	if (x == 5 && y == 5) // si on est au bout du tableau, on retourne 1 car on a fini de la completer. Normalement sans faute mais on n'a pas reussi a coder ca
		return (1);
	if (table[x][y] != 0) // si la position ou on est est differente de 0, alors on passe a la case suivante (puisqu'on aura deja initialiser le tableau a 0 et ajoute les 4
		return (is_valid(table, position + 1)); // donc on rappelle la fonction en avancant d'une case
	while (k <= '4') // tant qu'on n est pas au dessus de la valeur max de k
	{	
		if (absent_on_line(k, table, x) && absent_on_column(k, table, y)) // si le chiffre teste est absent sur la ligne ET de la colonne
		{
			table[x][y] = k - '0'; // on l'implemente
			if (is_valid(table, position + 1)) // si a la position d'apres, on est au bout du tableau, on retourne 1
				return (1);
		}
		k = k + 1; // si la valeur ete deja sur la ligne ou la colonne, on teste avec la valeur suivante de k
	}
	table[x][y] = 0; // si on ne peut pas remplir la case, normalement on laisse a 0 et on retourne une erreur puis on return 0 mais on a pas reussi a faire ca.
	return (0);
}
