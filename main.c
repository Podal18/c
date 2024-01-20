//Глава 13, номер 8
//Смоделировать диалог покупки произвольного товара в магазине.
//При этом у покупателя есть возможность расплатиться либо по карточке, либо по чеку. 
//Информацию о платеже хранить в объединении (union).

#include <stdio.h>
#include <string.h>

// Структура для представления товара
typedef struct Product {
    char productName[50]; // Название товара
    double price;        // Цена товара
} Product;

// Объединение для представления информации о платеже
typedef union Pay {
    char cardNumber[16]; // Номер кредитной карты
    int checkNumber;     // Номер чека
} Pay;

// Структура для представления покупателя
typedef struct Customer {
    char name[30];       // ФИО покупателя
    char city[20];       // Город покупателя
    Pay pay; // Информация о платеже
} Customer;

// Структура для представления покупки
typedef struct Pokupka {
    int pokupkaId;       // ИД покупки
    Product product;      // Товар
    Customer customer;    // Покупатель
    char payMethod[20]; // Метод оплаты ("Card" или "Check")
} Pokupka;

int main() {
    // Создаем товар
    Product item;
    strcpy(item.productName, "Ноутбук");
    item.price = 45000.00;

    // Создаем покупателя
    Customer buyer;
    strcpy(buyer.name, "Подгорнова Александра Васильевна");
    strcpy(buyer.city, "Москва");

    // Создаем покупку
    Pokupka pokupka;
    pokupka.pokupkaId = 1;
    pokupka.product = item;
    pokupka.customer = buyer;

    // Выбираем метод оплаты
    strcpy(pokupka.payMethod, "Card"); // Можно выбрать "Check" для оплаты чеком

    // Выводим информацию о покупке
    printf("ID покупки №%d\n", pokupka.pokupkaId);
    printf("Товар: %s,\nЦена: %.2f\n", pokupka.product.productName, pokupka.product.price);
    printf("Покупатель: %s ,\nГород: %s\n", pokupka.customer.name, pokupka.customer.city);

    // Выводим информацию о методе оплаты
    if (strcmp(pokupka.payMethod, "Card") == 0) {
        printf("Метод оплаты: Карта\n");
        printf("Номер карты: %s\n", pokupka.customer.pay.cardNumber);
    } else if (strcmp(pokupka.payMethod, "Check") == 0) {
        printf("Метод оплаты: Чек\n");
        printf("Номер чека: %d\n", pokupka.customer.pay.checkNumber);
    } else {
        printf("Неподдерживаемый метод оплаты\n");
    }

    return 0;
}
