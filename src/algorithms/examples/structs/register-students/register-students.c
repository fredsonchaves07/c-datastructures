# include "stdio.h"
# include "stdlib.h"
# include "string.h"

typedef struct _book {
    char title[100];
    unsigned int num_pages;
    float price;
} Book;

typedef struct _student {
    char name[100];
    int age;
    Book* favorite_book;
} Student;

Book *create_book(const char *title, unsigned num_pages, float price) {
    Book *book = calloc(1, sizeof(Book));
    strcpy(book->title, title);
    book->num_pages = num_pages;
    book->price = price;
    return book;
}

Book *copy_book(const Book *book) {
    return create_book(book->title, book->num_pages, book->price);
}

void print_book(const Book *book) {
    printf("Title: %s\n", book->title);
    printf("Pages: %d\n", book->num_pages);
    printf("Price: R$ %.2f\n", book->price);
}

void clear(Book **book_ref) {
    Book *book = *book_ref;
    free(book);
    *book_ref = NULL;
}

Student *create_student(const char *name, int age, const Book *book) {
    Student *student = calloc(1, sizeof(Student));
    strcpy(student->name, name);
    student->age = age;
    student->favorite_book = copy_book(book);
    return student;
}

void print_student(const Student *student) {
    printf("Title: %s\n", student->name);
    printf("Idade: %d\n", student->age);
    printf("Livro favorito: %s\n", student->favorite_book->title);
}

void clear_student(Student **pStudent) {
    Student *student = *pStudent;
    free(student->favorite_book);
    free(student);
    *pStudent = NULL;
}

int main() {
    Book *book = create_book("Harry Potter 1", 200, 25);
    print_book(book);
    puts("");
    Student *student = create_student("Ted", 20, book);
    print_student(student);
    clear(&book);
    clear_student(&student);
    return 0;
}