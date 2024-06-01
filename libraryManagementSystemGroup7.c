#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_STUDENTS 50
#define RENTAL_PERIOD 5
#define RENTAL_PRICE 10

typedef struct {
    int id;
    char title[50];
    char author[50];
    int quantity;
    double price;
} Book;

typedef struct {
    int id;
    char name[50];
    char student_id[20];
} Student;

typedef struct {
    int student_id;
    int book_id;
    int rental_days;
    int is_returned;
} Rental;

Book books[MAX_BOOKS];
Student students[MAX_STUDENTS];
Rental rentals[MAX_BOOKS];
int book_count = 0;
int student_count = 0;
int rental_count = 0;

void addBook() {
    printf("Enter book id: ");
    scanf("%d", &books[book_count].id);
    printf("Enter book title: ");
    scanf(" %[^\n]", books[book_count].title);
    printf("Enter book author: ");
    scanf(" %[^\n]", books[book_count].author);
    printf("Enter quantity: ");
    scanf("%d", &books[book_count].quantity);
    printf("Enter price: ");
    scanf("%lf", &books[book_count].price);
    book_count++;
    printf("Book added successfully!\n");
}

void removeBook() {
    int id, i, found = 0;
    printf("Enter book id to remove: ");
    scanf("%d", &id);
    for (i = 0; i < book_count; i++) {
        if (books[i].id == id) {
            for (int j = i; j < book_count - 1; j++) {
                books[j] = books[j + 1];
            }
            book_count--;
            found = 1;
            printf("Book removed successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Book not found!\n");
    }
}

void listBooks() {
    printf("Book List:\n");
    for (int i = 0; i < book_count; i++) {
        printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n",
               books[i].id, books[i].title, books[i].author, books[i].quantity, books[i].price);
    }
}

void addStudent() {
    printf("Enter student id: ");
    scanf("%d", &students[student_count].id);
    printf("Enter student name: ");
    scanf(" %[^\n]", students[student_count].name);
    printf("Enter student card id: ");
    scanf(" %[^\n]", students[student_count].student_id);
    student_count++;
    printf("Student added successfully!\n");
}

int findStudentById(int id) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

int findBookById(int id) {
    for (int i = 0; i < book_count; i++) {
        if (books[i].id == id) {
            return i;
        }
    }
    return -1;
}

void rentBook() {
    int book_id, student_id, days, is_student;
    printf("Enter book id to rent: ");
    scanf("%d", &book_id);
    printf("Are you a student? (1 for Yes, 0 for No): ");
    scanf("%d", &is_student);

    if (is_student) {
        printf("Enter student id: ");
        scanf("%d", &student_id);
        int student_index = findStudentById(student_id);
        if (student_index == -1) {
            printf("Student not found!\n");
            return;
        }
        printf("Enter number of days (Max %d days): ", RENTAL_PERIOD);
        scanf("%d", &days);
        if (days > RENTAL_PERIOD) {
            printf("Rental period exceeds the allowed limit of %d days for students!\n", RENTAL_PERIOD);
            return;
        }
    } else {
        printf("Enter number of days: ");
        scanf("%d", &days);
    }

    int book_index = findBookById(book_id);
    if (book_index == -1 || books[book_index].quantity == 0) {
        printf("Book not available for rent!\n");
        return;
    }

    books[book_index].quantity--;
    rentals[rental_count].student_id = is_student ? student_id : -1;
    rentals[rental_count].book_id = book_id;
    rentals[rental_count].rental_days = days;
    rentals[rental_count].is_returned = 0;
    rental_count++;

    printf("Book rented successfully!\n");
}

void returnBook() {
    int book_id, student_id, is_student;
    printf("Enter book id to return: ");
    scanf("%d", &book_id);
    printf("Are you a student? (1 for Yes, 0 for No): ");
    scanf("%d", &is_student);

    if (is_student) {
        printf("Enter student id: ");
        scanf("%d", &student_id);
    }

    int book_index = findBookById(book_id);
    if (book_index == -1) {
        printf("Book not found in the system!\n");
        return;
    }

    for (int i = 0; i < rental_count; i++) {
        if (rentals[i].book_id == book_id &&
            rentals[i].student_id == (is_student ? student_id : -1) &&
            rentals[i].is_returned == 0) {
            rentals[i].is_returned = 1;
            books[book_index].quantity++;
            printf("Book returned successfully!\n");
            return;
        }
    }
    printf("Rental record not found!\n");
}

void buyBook() {
    int book_id, quantity;
    printf("Enter book id to buy: ");
    scanf("%d", &book_id);
    printf("Enter quantity to buy: ");
    scanf("%d", &quantity);

    int book_index = findBookById(book_id);
    if (book_index == -1 || books[book_index].quantity < quantity) {
        printf("Book not available in the required quantity!\n");
        return;
    }

    books[book_index].quantity -= quantity;
    double total_price = books[book_index].price * quantity;
    printf("Book purchased successfully! Total price: %.2f\n", total_price);
}

void reviewBook() {
    int book_id;
    char review[256];
    printf("Enter book id to review: ");
    scanf("%d", &book_id);
    printf("Enter your review: ");
    scanf(" %[^\n]", review);

    printf("Review submitted for book ID %d: %s\n", book_id, review);
}

void requestBook() {
    char requested_book[50];
    printf("Enter the book title you want to request: ");
    scanf(" %[^\n]", requested_book);

    printf("Request submitted for the book: %s\n", requested_book);
}

void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Remove Book\n");
    printf("3. List Books\n");
    printf("4. Add Student\n");
    printf("5. Rent Book\n");
    printf("6. Return Book\n");
    printf("7. Buy Book\n");
    printf("8. Review Book\n");
    printf("9. Request Book\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3:
                listBooks();
                break;
            case 4:
                addStudent();
                break;
            case 5:
                rentBook();
                break;
            case 6:
                returnBook();
                break;
            case 7:
                buyBook();
                break;
            case 8:
                reviewBook();
                break;
            case 9:
                requestBook();
                break;
            case 10:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 10);
    return 0;
}

