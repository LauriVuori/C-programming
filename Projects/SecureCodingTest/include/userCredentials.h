#define MAXLEN 50


struct admin {
    char admin_username[MAXLEN];
    char admin_password[MAXLEN];

    char admin_firstname[MAXLEN];
    char admin_lastname[MAXLEN];
};

struct user {
    char user_username[MAXLEN];
    char user_password[MAXLEN];

    char user_firstname[MAXLEN];
    char user_lastname[MAXLEN];
};