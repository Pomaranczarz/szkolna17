#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[40];
    char author[20];
};

void ReadStdinToBook(struct Book* book);
void SaveBookToFile(const char* filename, struct Book book);
void ReadFileToBook(const char* filename, struct Book* book);

int main(void) {
    size_t num_of_books;
    printf("Podaj liczbe ksiazek: \n");
    scanf("%llu", &num_of_books);

    struct Book* books = (struct Book*)malloc(num_of_books * sizeof(struct Book));

    for (int i = 0; i < num_of_books; i++)
        ReadStdinToBook(&books[i]);


    return 0;
}

void SaveBookToFile(const char* filename, struct Book book) {
    FILE* out = fopen(filename, "a");
    if (out == NULL) {
        perror("Nie udalo sie otworzyc pliku");
        return;
    }
}

void ReadFileToBook(const char* filename, struct Book* book) {

}

void ReadStdinToBook(struct Book* book) {
    printf("Podaj tytul (max 40 znakow): \n");
    scanf("%s", book->title);

    printf("Podaj autora (max 20 znakow): \n");
    scanf9("%s", book->author);
}
