//Arkkhanirut Pandej 66070501062

#include<stdio.h>
#include<string.h>

struct dict{
	char value[100];
	char key[100];
};

void editdict(struct dict *dic, int size, char *edit_key, char *edit_value) {
    int change_made = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(dic[i].key, edit_key) == 0) {
            strcpy(dic[i].value, edit_value);
            change_made = 1;
            break;
        }
    }
    if (!change_made) {
        printf("No change\n");
    }
}

void printdict(struct dict *dic, int size) {
    for(int i = 0; i < size; i++) {
        printf("%s : %s\n", dic[i].key, dic[i].value);
    }
}

int main() {
    int size;
    scanf("%d", &size);
    struct dict dic[size];

    for (int i = 0; i < size; i++) {
        scanf("%s %s", dic[i].key, dic[i].value);
    }

    char edit_key[100], edit_value[100];
    scanf("%s %s", edit_key, edit_value);

    editdict(dic, size, edit_key, edit_value);

    printdict(dic, size);

    return 0;
}
