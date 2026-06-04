# SodiumDIA
Логический анализатор интерфейсов физического уровня

<!-- ISSUE:2 start -->

### Issue #2: Модуль ввода [![Static Badge](https://img.shields.io/badge/-Todo-green)](https://github.com/IUTechSupp/SodiumDIA/issues/2) 


**Автор:** @SodAcetate 

 


<!-- ISSUE:2 end -->

<!-- ISSUE:3 start -->

### Issue #3: Графический интерфейс [![Static Badge](https://img.shields.io/badge/-Todo-green)](https://github.com/IUTechSupp/SodiumDIA/issues/3) 


**Автор:** @SodAcetate 

 


<!-- ISSUE:3 end -->

<!-- ISSUE:4 start -->

### Issue #4: Вывод символа в ячее сетки [![Static Badge](https://img.shields.io/badge/-Todo-green)](https://github.com/IUTechSupp/SodiumDIA/issues/4) 


**Автор:** @SodAcetate 

 Размер шрифта позволяет использовать сетку 14х17 символов. Функция отрисовки символа в конкретной ячее сетки вычисляет начало этой ячеи и вызывает функцию отрисовки символа по этим координатам:

_offset_y = border_y + pos_y * FONT_HEIGHT

offset_x = border_x + pos_x * FONT_WIDTH_

Рамка (border) вокруг интерфейса нужна для центровки содержимого:

_border_x = ( 128 % FONT_WIDTH ) / 2 = 1

border_y = (160 % FONT_HEIGHT) / 2 = 3.5 ~ 3_




<!-- ISSUE:4 end -->

<!-- ISSUE:5 start -->

### Issue #5: Вывод слова, начиная с ячеи сетки [![Static Badge](https://img.shields.io/badge/-Todo-green)](https://github.com/IUTechSupp/SodiumDIA/issues/5) 


**Автор:** @SodAcetate 

 Функция вывода слова должна принимать x и y координаты начальной ячеи слова и отрисовывать N символов, начиная с этой ячеи, где:

_N ≤ 17 - pos_x_

В случае выхода за пределы экрана слово обрывается.




<!-- ISSUE:5 end -->
