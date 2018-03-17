//
// Created by Wikibooks community
//
#include "HeapSort.h"


void iswap(int &n1, int &n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}
int HeapSort(int a[], int n) {
    // ----------- Сортировка ------------
    // Сортирует по возрастанию. Чтобы получить сортировку по убыванию,
    // поменяйте знаки сравнения в строчках, помеченных /*(знак)*/
   unsigned  int sh = 0u; // Смещение
    bool b;
    int comparisons_iter=0;
    do {
        b = false;
        for (unsigned int i = 0u; i < n; ++i) {

            if (i * 2 + 2 + sh < n) {
                if ((a[i + sh] > /*<*/ a[i * 2 + 1 + sh]) || (a[i + sh] > /*<*/ a[i * 2 + 2 + sh])) {
                    comparisons_iter += 2;
                    if (a[i * 2 + 1 + sh] < /*>*/ a[i * 2 + 2 + sh]) {
                        comparisons_iter++;
                        iswap(a[i + sh], a[i * 2 + 1 + sh]);
                        b = true;
                    } else if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh]) {
                        comparisons_iter++;
                        iswap(a[i + sh], a[i * 2 + 2 + sh]);
                        b = true;
                    }
                }
                // Дополнительная проверка для последних двух элементов;
                // с её помощью можно отсортировать пирамиду
                // состоящую всего лишь из трёх элементов
                if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh]) {
                    comparisons_iter++;
                    iswap(a[i * 2 + 1 + sh], a[i * 2 + 2 + sh]);
                    b = true;
                }
            } else if (i * 2 + 1 + sh < n) {

                if (a[i + sh] > /*<*/ a[i * 2 + 1 + sh]) {
                    comparisons_iter++;
                    iswap(a[i + sh], a[i * 2 + 1 + sh]);
                    b = true;
                }
            }
        }
        if (!b)
            ++sh; // Смещение увеличивается, когда на текущем этапе сортировать больше нечего
    } while (sh + 2 < n); // Конец сортировки

    return comparisons_iter;

}
