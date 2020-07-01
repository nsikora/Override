Pour trouver cette faille, nous allons regarder rapidement les instructions assembleur du programme avec GDB, plus particulierement dans le main.

"gdb ./level00" nous permet d'ouvrir le programme dans GDB.
"disas main" nous permet de lire les instructions assembleur.

En balayant rapidement les instructions du regard, on peut voir que la ligne:

"0x080484e7 <+83>:	cmp    $0x149c,%eax"
compare notre entree a un resultat attendu, plus precisement, un chiffre.
C'est paar ailleurs la seule instruction de comparaison par rapport a une valeur predefinie.

Il suffit alors de rentrer en argument la valeur decimale de ce chiffre en hexadecimal afin de pouvoir s'authentifier.
