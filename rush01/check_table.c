/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:21:55 by nflan             #+#    #+#             */
/*   Updated: 2021/08/16 10:06:50 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// malheureusement, on n'utilisera pas cette fonction mais on peut montrer qu'elle exite. si il demande a l eval, dites bien qu elle n est pas implementee dans le code

// allez checker la fonction commentee, c'est le meme principe pour chaque fonction sauf que les checks ne se font pas dans le meme sens (haut en bas, bas en haut, gauche a droite, droite a gauche)

int	check_up_column(char table[6][6]) //on verifie, de haut en bas que les valeurs correspondent au jeu
{
	int	y;
	int	count;
	int	valid;

	y = 1;
	valid = 0;
	while (y < 5)
	{
		count = 0;
		count++;
		if (table[2][y] > table[1][y])
			count++;
		if (table[3][y] > table[1][y] && table[3][y] > table[2][y])
			count++;
		if (table[4][y] == 4)
			count++;
		if (table[0][y] == count)
			valid++;
		y++;
	}
	if (valid == 4)
		return (1);
	return (0);
}

int	check_down_column(char table[6][6]) //on verifie, de bas en haut que les valeurs correspondent au jeu
{
	int	y;
	int	count;
	int	valid;

	y = 1;
	valid = 0;
	while (y < 5)
	{
		count = 0;
		count++;
		if (table[3][y] > table[4][y])
			count++;
		if (table[2][y] > table[4][y] && table[2][y] > table[3][y])
			count++;
		if (table[1][y] == 4)
			count++;
		if (table[5][y] == count)
			valid++;
		y++;
	}
	if (valid == 4)
		return (1);
	return (0);
}

int	check_left_row(char table[6][6])i //on verifie, de gauche a droite que les valeurs correspondent au jeu

{
	int	x;
	int	count; // compte le nombre de gratte ciel que l'on voit depuis la position
	int	valid; // confirme si la ligne est bonne

	x = 1; // tableau de 6x6 mais on verifie le 4x4 donc on commence a 1
	valid = 0;
	while (x < 5) // tant qu'on est pas a la derniere ligne
	{
		count = 0;
		count++; // on voit forcement la premiere valeur donc on ajoute 1 au count
		if (table[x][2] > table[x][1]) // si la valeur 2 est plus haute que la valeur 1, on ajoute 1 au count
			count++;
		if (table[x][3] > table[x][2] && table[x][3] > table[x][1]) // si la valeur 3 est superieur a la valeur 2 et a la valeur 1, on la voit donc on ajoute 1 au count
			count++;
		if (table[x][4] == 4) // si la derniere valeur est 4, on la voit donc on ajoute 1
			count++;
		if (table[x][0] == count) // si, a la fin de la ligne, count est egal a la valeur du parametre de la ligne que l'on verifie, on ajoute incremente valid
			valid++;
		x++; // on change de ligne a la fin de chaque ligne jusqu'a la derniere
	}
	if (valid == 4) // si toutes les lignes sont correct
		return (1); // on retourne 1
	return (0); // sinon on retourne 0
}

int	check_right_row(char table[6][6]) //on verifie, de droite a gauche que les valeurs correspondent au jeu
{
	int	x;
	int	count;
	int	valid;

	x = 1;
	valid = 0;
	while (x < 5)
	{
		count = 0;
		count++;
		if (table[x][3] > table[x][4])
			count++;
		if (table[x][2] > table[x][3] && table[x][2] > table[x][4])
			count++;
		if (table[x][1] == 4)
			count++;
		if (table[x][5] == count)
			valid++;
		x++;
	}
	if (valid == 4)
		return (1);
	return (0);
}

int	check_columns_lines(char table[6][6]) // on appelle les fonction et, si elles retournent tout 1, le tableau est correct, sinon, il ne l'est pas
{
	int	check;

	check = 0;
	if (check_up_column(table) == 1) // si les valeurs de haut en bas sont toutes bonnes, on ajoute 1 a check
		check++;
	if (check_down_column(table) == 1) // si les valeurs de bas en haut sont toutes bonnes, on ajoute 1 a check
		check++;
	if (check_left_row(table) == 1) // si les valeurs de gauche a droite sont toutes bonnes, on ajoute 1 a check
		check++;
	if (check_right_row(table) == 1) // si les valeurs de droite a gauche sont toutes bonnes, on ajoute 1 a check
		check++;
	if (check == 4) // si check = 4 c'est que toutes valeurs du tableau sont bonne donc on retour 1
		return (1);
	else // sinon, on retourne 0, le tableau est faux et on est suppose recommencer avec d'autres valeurs mais on n'a pas reussi
		return (0);
}
