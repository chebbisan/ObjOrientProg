
/*
Задание 2.7. Утомительное чтение. На вход программы идет три числа. Первое –
количество слов в строке, второе – количество строк на странице, третье –
число страниц в книге. Каждая третья страница содержит лишь половину строк,
а на каждой пятой на всю страницу распечатана картинка. Посчитать
количество слов в книге.
*/

#include <iostream>

int main() {
    int words, strings, pages, picture_pages = 0, half_page = 0;
    std::cout << "Enter word count: ";
    std::cin >> words;

    std::cout << "Enter string count: ";
    std::cin >> strings;

    std::cout << "Enter page count: ";
    std::cin >> pages;

    

    if (pages > 2) {
        half_page = pages / 3;
    }
    if (pages > 4) {
        picture_pages = pages / 5;
    }

    pages = pages - picture_pages - half_page;

    int all_words = words * strings * pages + words * strings / 2 * half_page;
    
    std::cout << "Summary of words: " << all_words <<'\n';
    
}