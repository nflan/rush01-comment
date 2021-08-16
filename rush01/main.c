/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:51:25 by nflan             #+#    #+#             */
/*   Updated: 2021/08/16 09:39:33 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
// ensemble des prototypes necessaires dans ce fichier.
void	ft_putchar(char c); 
int		init_table_column(char table[6][6], char *argv);
int		init_table_row(char table[6][6], char *argv);
int		init_table_0(char table[6][6], char *argv);
void	ft_print_tab(char table[6][6]);
int		is_valid(char table[6][6], int position);
int		check_four(char tab[6][6]);
int		check_columns_lines(char table[6][6]);

char	*ft_strcpy(char *dest, char *src) // on prend la chaine de caractere donnee en parametre pour la retourner sans les espaces.
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] >= '1' && src[i] <= '4')
		{
			dest[j] = src[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_strlen(char *str) // on recupere la taille de la chaine de caractere (ici pour la chaine sans les espaces) pour pouvoir la tester plus tard
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check(char *str, int nb) // fonction pour checker si la chaine passer en parametre est correcte
{
	int	i;
	int	s;

	i = 0;
	s = ft_strlen(str); // on recupere la taille de la chaine de caractere (sans les espaces)
	if (nb != 2 || s != 16) // si la chaine de caracteres ne contient pas 16 caracteres OU si le nombre de parametre est superieur ou inferieur a 2, retourne une erreur
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (str[i]) // on parcours la chaine de caractere pour verifier qu il n y a pas 2 caracteres egaux face a face a part 2 (sinon c'est faux)
	{
		if (str[i] == str[i + 4] && str[i] != '2')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (i % 4 == 0) // quand on arrive a la fin des 4 parametres (en haut), on avance de 4 pour comparer les lignes.
			i += 4;
		else // sinon, on avance 1 par 1 sur la ligne ou la colonne
			i++;
	}
	return (1); // si tout va bien, on retourne 1
}

int	main(int argc, char **argv) //on initialise main avec des arguments et un nombre d'arguments (sachant que ./a.out est l'argument [0] et compte comme 1 argument
{
	char	*av; // stockera notre argv[1] sans les espaces
	char	table[6][6]; // table de jeu
	int		i; // position dans le tableau

	i = 0;
	av = ft_strcpy(argv[1], argv[1]); // chaine de caractere entree en paramettre sans les espaces
	init_table_0(table, av); // on appelle la fonction d'un autre fichier (init_table.c). La fonction permet d'initialiser la table de jeu a 0 et les chiffres rentres en parametre sur les cotes.
	if (ft_check(av, argc) == 0) // on appelle la fonction test 
		return (0); // si c'est le parametre rentre n'est pas valide, on arrete le programme
	check_four(table); // on appelle la fonction d'un autre fichier (print_four.c) pour ajouter les 4 si on trouve un 1 en parametre
	if (is_valid(table, i) == 0) // on appelle la fonction is_valid d'un autre fichier pour ajouter les chiffres dans le tableau de maniere a ne pas avoir deux fois le meme chiffre sur la meme ligne ou la meme colonne
		write(1, "Error\n", 6); // si la fonction retourne 0, le tableau n'est pas possible et retourne une erreur
	ft_print_tab(table); // on appelle une fonction d'un autre fichier (print_table.c) pour afficher la table
	return (0); // la fonction est fini, on sort du programme
}
