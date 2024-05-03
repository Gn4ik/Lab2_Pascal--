# Lab2_Pascal--

# Состав группы Одинцов Михаил, Ермилова Дарья, Гнитиенко Кирилл
В рамках данного технического задания предлагается разработать интегрированнцю среду разработки, для написания программ на Pascal--.

# Цель проекта: 

Разработать интегрированную среду разработки для программ на языке Pascal--. Среда должна обеспечивать возможность написания и выполнения программ.

# Основные задачи системы:
- Должен выполняться синтаксический контроль корректности текста программы.
- Условные операторы м.б. вложенными.
- Текст программы должен храниться в виде иерархического списка.
- Переменные и константы должны храниться в таблице - на выбор: упорядоченная, дерево поиска, хеш-таблица.
- Вычисление арифметических и условных выражений должно выполняться с помощью постфиксной формы.


# Предлагаемый план реализации:

- Реализация чтения кода Pascal-- из файла и проверка его на корректность
- Файл состоит из 3 частей:
  - Название программы
  - Объявление переменных и констант
  - Код программы
- Создание иерархического списка для хранения кода
- Создание таблицы для хранения констант и переменных
- Реализация операторов Pascal--
  - операторы чтения/записи (Write,Read)
  - операторы сравнения (<> <= < > >= mod)
  - операторы if-else
  - оператор присваивания (:=)


# Ожидаемые результаты проекта:
- Разработка системы синтаксического контроля.
- Реализация операторов для Pascal--
- Реализация вспомогательных структур (иерархический список, таблица)
- Программа по окончанию работы должна выводить результат работы программы, написанной на Pascal--


# Общая структура проекта:
тут будут директории

# Используемые инструменты:
- Программа будет написана на языке С++ с использованием Visual Studio
- Система контроля версий Git.
- Фреймворк для написания автоматических тестов Google Tests.
  
# Модель

## Объекты:

 Синтаксис контроль
 - Берет текст программы и проверяет на наличие ошибок
 Компилятор
 - Переводит текст кода Pascal-- в код языка С++ и выполняет его

## Вспомагательные объекты

 Линейная неупорядоченная таблица
 - В ней будут храниться локальные и глобальные переменные
   
 Иерархический список
  - В ней будут храниться код языка Pascal--

## Алгоритмы:

1 Получение кода пользователя
  - Пользователь указывает путь к текстовому файлу, в котором храниться код на Pascal--
  - Программа считывает его и заполняет таблицу переменными и иерархический список операций
2 Проверка кода пользователя
  - Синтаксический контроль проходит по иерархическому списку и проверяет каждую операцию.
  - Если встречается незнакомая операция, то выдает ошибку.
3 Выполнения кода
  - Компилятор проходит по иерархическому списку и берет операции.
  - Каждую операцию переводит на язык С++ и выполняет.


