# sergey_sokolvyak
RUS:

Array

Обеспечивает мгновенный доступ по индексу.
Фиксированный размер.
Подходит для хранения известного кол-ва значений с возможным обновлением.
Vector

Динамический массив.
Мгновенный доступ по индексу.
Быстро производит вставку и удаление элементов в конце вектора.
Не подходит для вставки/удаления элементов из середины вектора.
Stack

Быстрая вставка данных по принципу LIFO.
Доступ возможен только к последнему элементу.
Может использоваться для временного хранения данных с последовательным доступом.
Queue

Быстрая вставка данных по принципу FIFO.
Доступ возможен только к первому элементу.
Может использоваться для временного хранения данных с последовательным доступом.
Priority_queue

Автоматическая сортировка элементов очереди - сверху всегда самый большой элемент.
Доступ возможен только к самому большому элементу.
Может использоваться для временного хранения отсортированных данных с последовательным доступом.
Deque

Очередь с двусторонним доступом.
Быстрая вставка и удаление данных из начала или конца контейнера.
Имеет доступ по индексу.
Не подходит для вставки/удаления элементов из середины очереди.
List

Очередь с двусторонним доступом.
Очень быстро производит вставку или удаление элементов для любого места в листе.
Нет произвольного доступа. Возможны только итерации с начала или конца листа - доступ по индексу имеет линейную сложность O(N).
Forward_list

Очередь. Возможно итерировать только вперед.
Доступ по индексу немного быстрей чем в List.
Set

Бинарное дерево.
Храняться только уникальные значения.
Хранит эллементы с автоматической сортировкой по возрастанию.
Multiset

Допускает одинаковые значения.
Unordered_set и Unordered_multiset

Хеш-таблицы, порядок сортировки задается хеш-функцией.
Мгновенный доступ по ключу.
Map

Аналогичен контейнеру Set, хранит значение в виде std::pair.
Ключем выступает pair.first, а значением pair.second.
Поддерживает прямой доступ к значению по ключу - at() and [].
Полезен, когда чисто цифровой ключ не подходит, а нужен к примеру, строковый или вообще другой объектный.
Multimap

Аналогичен контейнеру Multiset, не поддерживает прямой доступ к значению по ключу.
Unordered_map and Unordered_multimap
Аналогичны контейнерам Unordered_set и Unordered_multiset
