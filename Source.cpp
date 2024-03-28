#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
private:
    string title;
    string author;
    double price;
    int quantity;

public:
    Book(string title, string author, double price, int quantity) : title(title), author(author), price(price), quantity(quantity) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    void decreaseQuantity(int amount) {
        quantity -= amount;
    }

    void increaseQuantity(int amount) {
        quantity += amount;
    }
};

class ShoppingCart {
private:
    vector<Book*> cart;

public:
    void addBookToCart(Book* book) {
        cart.push_back(book);
    }

    void viewCartContents() {
        cout << "Your Shopping Cart:" << endl;
        for (auto book : cart) {
            cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor() << ", Price: $" << book->getPrice() << endl;
        }
    }

    double calculateTotalPrice() {
        double total = 0.0;
        for (auto book : cart) {
            total += book->getPrice();
        }
        return total;
    }

    void checkout() {
        cout << "Total Price: $" << calculateTotalPrice() << endl;
        cart.clear();
        cout << "Thank you for shopping with us!" << endl;
    }
};

int main() {
    Book book1("101 Arabian Nights", "Unknown", 17.99, 5);
    Book book2("The Boy in the striped Pyjamas", "George Orwell", 15.49, 8);
    Book book3("The Animal Farm", "George Orwell", 10.49, 3);
    Book book4("Harry Potter : Chamber of Secrets", "J.K Rowling", 8.99, 15);
    Book book5("Harry Potter : The Goblet of fire", "J.K Rowling", 6.56, 16);
    Book book6("Harry Potter : The Deathly Hollows (part 1)", "J.K Rowling", 8.99, 15);
    Book book7("Harry Potter : The Deathly Hollows (part 2)", "J.K Rowling", 7.99, 14);

    ShoppingCart cart;

    int choice;
    do {
        cout << "--------------------MAIN MENU--------------------\n\n";
        cout << "1. Add to Cart\n";
        cout << "2. View Cart\n";
        cout << "3. Checkout\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int bookChoice;
            cout << "\nChoose a book to add to your cart:" << endl;
            cout << "1. " << book1.getTitle() << endl;
            cout << "2. " << book2.getTitle() << endl;
            cout << "3. " << book3.getTitle() << endl;
            cout << "4. " << book4.getTitle() << endl;
            cout << "5. " << book5.getTitle() << endl;
            cout << "6. " << book6.getTitle() << endl;
            cout << "7. " << book7.getTitle() << endl;
            cout << "Enter your choice: ";
            cin >> bookChoice;

            Book* selectedBook;
            switch (bookChoice) {
            case 1:
                selectedBook = &book1;
                break;
            case 2:
                selectedBook = &book2;
                break;
            case 3:
                selectedBook = &book3;
                break;
            case 4:
                selectedBook = &book4;
                break;
            case 5:
                selectedBook = &book5;
                break;
            case 6:
                selectedBook = &book6;
                break;
            case 7:
                selectedBook = &book7;
                break;
            default:
                cout << "Invalid choice!" << endl;
                continue;
            }
            cart.addBookToCart(selectedBook);
            cout << "Book added to cart." << endl;
            break;
        case 2:
            cart.viewCartContents();
            break;
        case 3:
            cart.checkout();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}