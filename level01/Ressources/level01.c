#include <stdio.h>
#include <string.h>

char a_user_name[256];

int	verify_user_name()
{
	puts("verifying username....\n");
	strncmp(a_user_name, "dat_wil", 7);
}

int	verify_user_pass(password)
{
	strncmp(password, "admin", 5);
}

int	main()
{
	int     verify;
	char	password[64];

	memset(password, '\0', 64);
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username:");
	fgets(a_user_name, 256, stdin);
	verify = verify_user_name();
	if (verify != 0)
	{
		puts("nope, incorrect username...\n");
		return (1);
	}
	puts("Enter Password: ");
    fgets(password, 100, stdin);
    check = verify_user_pass(password);
    if (verify == 0)
    {
        puts("nope, incorrect password...\n");
        return 1;
    }
    if (verify == 0)
    {
        return 0;
    }
    return 1;
}
