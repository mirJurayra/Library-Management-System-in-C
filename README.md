Project Report: Library Management System in C

Description of the Project
This project is a Library Management System implemented in the C programming language. It simulates the operations of a library, allowing for the management of books, students, rentals, and purchases. The project utilizes C structures (`struct`) to represent books, students, and rental transactions, as well as arrays to store these structures. This system is designed to facilitate various library operations including adding books, removing books, renting books, returning books, purchasing books, reviewing books, and requesting new books.

Structures Used:
- Book: Represents a book in the library with attributes `id`, `title`, `author`, `quantity`, and `price`.
- Student: Represents a student with attributes `id`, `name`, and `student_id`.
- Rental: Represents a rental transaction with attributes `student_id`, `book_id`, `rental_days`, and `is_returned`.

Functionality:
- Add Book (`addBook`): Prompts the user to input book details and adds the book to the library inventory.
- Remove Book (`removeBook`): Removes a book from the inventory based on its ID.
- List Books (`listBooks`): Displays all books currently in the library, including their details.
- Add Student (`addStudent`): Registers a new student by prompting the user for student details.
- Rent Book (`rentBook`): Allows a student or general user to rent a book. Students can rent books for free for up to 5 days, while general users are charged 10 Taka per day.
- Return Book (`returnBook`): Processes the return of a rented book, updating the inventory and rental records.
- Buy Book (`buyBook`): Allows users to purchase books from the library's inventory. The quantity of the purchased books is deducted from the inventory.
- Review Book (`reviewBook`): Allows users to submit reviews for books.
- Request Book (`requestBook`): Allows users to request the library to acquire new books not currently in the collection.

The main function presents a menu to the user, allowing them to choose which operation to perform. Each operation is handled by its respective function, and the menu is displayed again after each operation until the user chooses to exit.
