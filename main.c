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

////stepik. Работа с массивами на С, 5.1, шаг 7
//Допишите программу, которая считает две точки  и выводит имя точки, ближайшей к началу координат

#include <stdio.h>
struct point_t{
    char name;
    int x, y;
};

main(){
    struct point_t a;
    struct point_t b;
    scanf("%c %d %d ", &a.name, &a.x, &a.y);
    scanf("%c %d %d ", &b.name, &b.x, &b.y);
    
    float A = sqrt(a.x * a.x + a.y * a.y);
    float B = sqrt(b.x * b.x + b.y * b.y);
    
    char bliz;
if (A < B) {
    bliz = a.name;
} else {
    bliz = b.name;
}
     printf("%c", bliz);

}
//stepik. Работа с массивами на С, 5.1, шаг 10
//Напишите функцию для определения четверти к которой относится заданная точка
int qurt(point_t z) {
if (z.x > 0 && z.y > 0) {
        // Точка находится в первой четверти
        return 1;
    } else if (z.x < 0 && z.y > 0) {
        // Точка находится во второй четверти
        return 2;
    } else if (z.x < 0 && z.y < 0) {
        // Точка находится в третьей четверти
        return 3;
    } else if (z.x > 0 && z.y < 0) {
        // Точка находится в четвёртой четверти
        return 4;
    } else {
        // Точка лежит на одной из координатных осей
        return 0;
    }
	return 0;
}

