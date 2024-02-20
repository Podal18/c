/*Stepik 4.6*/

/*Задача 1.
Продолжите программу. Объявите указатель ptr_a на переменную a и указатель ptr_b на переменную b. 
Поменяйте адреса указателей ptr_a и ptr_b между собой, используя третий вспомогательный указатель с обобщенным типом void*. 
Выведите в консоль в одну строчку через пробел целочисленные значения, на которые ссылаются указатели ptr_a и ptr_b именно в таком порядке:
<значение для ptr_a> <значение для ptr_b>*/

#include <stdio.h>

int main(void)
{
    short a, b;
    short *ptr_a = &a, *ptr_b = &b;
    void * ptr_help;
    
    scanf("%hd, %hd", &a, &b);
    
    ptr_help = ptr_a; //ptr_help = 0,  ptr_a = -5 --> ptr_help = -5
    ptr_a = ptr_b; //ptr_a = -5, ptr_b = 10, --> ptr_a = 10, ptr_help = -5
    ptr_b = ptr_help; //ptr_b = 10, ptr_help = -5 --> ptr_a = 10, ptr_b = -5
    printf("%d %d", *ptr_a, *ptr_b);

    __ASSERT_TESTS__ 
    return 0;
}


/* Задача 2.
Объявите указатель с именем ptr_var на переменную var. 
После этого объявите еще один указатель с именем ptr_ch для типа char и присвойте ему адрес, хранимый указателем ptr_var. (Не забудьте прописать операцию приведения типов.) 
Выведите в консоль целочисленное значение, на которое ссылается указатель ptr_ch.*/

#include <stdio.h>

int main(void)
{
    int var;
    int *ptr_var = &var;
    char *ptr_ch;

    scanf("%d", &var);

    ptr_ch = (char *) ptr_var;
    
    printf("%d", *ptr_var);

    __ASSERT_TESTS__ 
    return 0;
}


/*Задача 3
Продолжите программу. Объявите указатель с именем ptr_var на переменную var. 
После этого объявите еще один указатель с именем ptr_ch для типа char и присвойте ему адрес, хранимый указателем ptr_var. (Не забудьте прописать операцию приведения типов.) 
Запишите в ячейку памяти, на которую ссылается указатель ptr_ch, целочисленное значение 2. Выведите в консоль значение переменной var в виде одного целого числа.*/

#include <stdio.h>

int main(void)
{
    short var;
    short *ptr_var = &var;
    char hlp;
    char *ptr_ch = &hlp;
    
    scanf("%hd", &var);
    
    ptr_ch = (char *) ptr_var;
    *ptr_ch = 2;
    
    printf("%d", var);
    
    __ASSERT_TESTS__ 
    return 0;
}

/*Задача 4
Продолжите программу. По указателю global_ptr типа int необходимо выполнить запись целочисленного значения 10 в том случае, если global_ptr ссылается на выделенную область памяти.
Указатель global_ptr в программе не отображается, но он объявлен и существует.
P. S. В консоль ничего выводить не нужно.*/

#include <stdio.h>

int main(void)
{  
   int a = 2;
    
   if (global_ptr != NULL)
       *global_ptr = 10;
       
    return 0;
}
