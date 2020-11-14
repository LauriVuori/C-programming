#include <stdio.h>


#define MAXLEN 15
#define USER_QTY 3
#define FALSE 0
#define TRUE 1

struct user{
	char user_username[MAXLEN];
	char user_password[MAXLEN];
};

struct admin{
	char admin_username[MAXLEN];
	char admin_passwrod[MAXLEN];
};

void init_users(struct user _users[]);
void init_admin(struct admin* admin);
void admin_authenticate(struct admin* admin);

int main(void){
	struct user _users[USER_QTY];
	struct admin _admin = {{"admin"}, {"admin"}};
	// init_admin(&_admin);
	// init_users(_users);
	admin_authenticate(&_admin);
}

void init_users(struct user users[]){
	char s[10] = "test";
	for (int i = 0; s[i] != '\0'; i++){
		users[0].user_password[i] = s[i];
	}
	printf("%s\n", users[0].user_password);
	printf("%s\n", users[0].user_password);
}

void init_admin(struct admin* admin){
	char s[10] = "admin";
	for (int i = 0; s[i] != '\0'; i++){
		admin->admin_passwrod[i] = s[i];
	}
	printf("%s\n", admin->admin_passwrod);
}

void admin_authenticate(struct admin* admin){
	char temp[15];
	int authenticated = TRUE;
	printf("Give admin username:\n");
	scanf("%s", temp);
	for (int i = 0; admin->admin_username[i] != '\0'; i++){
		if (admin->admin_username[i] != temp[i]){
			authenticated = FALSE;
		}
	}
	if (authenticated == FALSE){
		printf("Wrong crenetials given");
	}
	else{
		printf("Give admin password:\n");
		scanf("%s", temp);
		for (int i = 0; admin->admin_passwrod[i] != '\0'; i++){
			if (admin->admin_passwrod[i] != temp[i]){
				authenticated = FALSE;
			}
		}
		if (authenticated == FALSE){
		printf("Wrong crenetials given");
		}
	}
	if (authenticated == TRUE){
		printf("Credentials correct!");
	}
}