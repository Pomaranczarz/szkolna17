#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TITLE_LEN 40
#define MAX_AUTHOR_LEN 20

struct Book {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
};

void ReadStdinToBook(struct Book* book);
void SaveBookToFile(const char* filename, struct Book book);
void ReadFileToBooks(const char* filename, struct Book* books, size_t num_of_books);
void PrintBookToStdin(struct Book book);
void PrintBookIf(struct Book* books, size_t num_of_books, bool(*predicate)(struct Book));
bool IsAuthorNowak(struct Book book) { return strcmp(book.author, "Nowak") == 0; }

int main(void) {
    size_t num_of_books;
    printf("Podaj liczbe ksiazek: \n");
    scanf("%llu", &num_of_books);

    struct Book* books = (struct Book*)malloc(num_of_books * sizeof(struct Book));

    for (int i = 0; i < num_of_books; i++) {
        ReadStdinToBook(&books[i]);
        SaveBookToFile("ksiazki.txt", books[i]);
    }

    free(books);
    books = (struct Book*)malloc(num_of_books * sizeof(struct Book));

    ReadFileToBooks("ksiazki.txt", books, num_of_books);

    for (int i = 0; i < num_of_books; i++)
        PrintBookToStdin(books[i]);

    free(books);
    return 0;
}

void SaveBookToFile(const char* filename, struct Book book) {
    FILE* out = fopen(filename, "a");
    if (out == NULL) {
        perror("Nie udalo sie otworzyc pliku");
        return;
    }

    fprintf(out, "%s %s\n", book.title, book.author);

    fclose(out);
}

void ReadFileToBooks(const char* filename, struct Book* books, size_t num_of_books) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        perror("Nie udalo sie otworzyc pliku");
        return;
    }
    
    for (int i = 0; i < num_of_books; i++)
        fscanf(in, "%s %s\n", books[i].title, books[i].author);

    fclose(in);
}

void ReadStdinToBook(struct Book* book) {
    printf("Podaj tytul (max %d znakow): \n", MAX_TITLE_LEN);
    scanf("%s", book->title);

    printf("Podaj autora (max %d znakow): \n", MAX_AUTHOR_LEN);
    scanf("%s", book->author);
}

void PrintBookToStdin(struct Book book) {
    printf("Tytul: %s\tAutor: %s\n", book.title, book.author);
}

void PrintBookIf(struct Book* books, size_t num_of_books, bool(*predicate)(struct Book)) {
    for (int i = 0; i < num_of_books; i++)
        if (predicate(books[i]))
            PrintBookToStdin(books[i]);
}