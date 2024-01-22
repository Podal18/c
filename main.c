//Глава 13, номер 8
//Смоделировать диалог покупки произвольного товара в магазине.
//При этом у покупателя есть возможность расплатиться либо по карточке, либо по чеку. 
//Информацию о платеже хранить в объединении (union).

#include <stdio.h>
#include <string.h>

typedef struct Product {
    char productName[50];
    double price;
} Product;

typedef union Pay {
    char cardNumber[16];
    int checkNumber;
} Pay;

typedef struct Customer {
    char name[30];
    char city[20];
    Pay pay;
} Customer;

typedef struct Pokupka {
    int pokupkaId;
    Product product;
    Customer customer;
    char payMethod[20];
} Pokupka;

int main() {
    // считывание информации о товаре
    Product item;
    printf("Введите название товара: ");
    scanf("%s", item.productName);
    printf("Введите цену товара: ");
    scanf("%lf", &item.price);

    // Создаем покупателя + считывание
    Customer buyer;
    printf("Введите ФИО покупателя: ");
    scanf("%s", buyer.name);
    printf("Введите город покупателя: ");
    scanf("%s", buyer.city);

    // Создаем покупку
    Pokupka pokupka;
    pokupka.pokupkaId = 1;
    pokupka.product = item;
    pokupka.customer = buyer;

    // Выбор метода оплаты, считывание
    printf("Выберите метод оплаты (Card или Check): ");
    scanf("%s", pokupka.payMethod);

    getchar(); // Считываем символ новой строки из буфера

    // Вводим информацию о методе оплаты
    if (strcmp(pokupka.payMethod, "Card") == 0) {
        printf("Введите номер карты: ");
        scanf("%s", pokupka.customer.pay.cardNumber);
    } else if (strcmp(pokupka.payMethod, "Check") == 0) {
        printf("Введите номер чека: ");
        scanf("%d", &pokupka.customer.pay.checkNumber);
    } else {
        printf("Неподдерживаемый метод оплаты\n");
        return 0; 
    }

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
    }

    return 0;
}
