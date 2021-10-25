# gnl

Fonction qui lit ligne par ligne un fichier

| Prototype | int get_next_line(int fd, char **line); |
| --- | --- |
| Parametres | File Descriptor à lire \| la ligne à remplir |
| Valeur retour | 1 : ligne lue |
| | 0 : fin du fichier |
| | -1 : erreur |

Pour une utilisation simplifié un main a été rajouté et include dans le Makefile
