# SodiumDIA
Логический анализатор интерфейсов физического уровня

### 3.2.1 Тактовые кнопки
<!-- ISSUE:2 start -->

**Issue #2:** [![Static Badge](https://img.shields.io/badge/%D0%9C%D0%BE%D0%B4%D1%83%D0%BB%D1%8C%20%D0%B2%D0%B2%D0%BE%D0%B4%D0%B0-Todo-green)](https://github.com/IUTechSupp/SodiumDIA/issues/2)



---

<!-- ISSUE:2 end -->

### 3.2.3 Графический интерфейс
<!-- ISSUE:3 start -->

**Issue #3:** [![Static Badge](https://img.shields.io/badge/%D0%93%D1%80%D0%B0%D1%84%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B8%D0%B9%20%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D1%84%D0%B5%D0%B9%D1%81-Todo-green)](https://github.com/IUTechSupp/SodiumDIA/issues/3)



---

<!-- ISSUE:3 end -->

#### 3.2.3.1 Шрифт
<!-- ISSUE:6 start -->

**Issue #6:** [![Static Badge](https://img.shields.io/badge/%D0%A8%D1%80%D0%B8%D1%84%D1%82-Done-blue)](https://github.com/IUTechSupp/SodiumDIA/issues/6)



---

<!-- ISSUE:6 end -->

Был отрисован шрифт размера 9х9 пикселей для кодировки CP866 (W. I. P.):
<img width="1440" height="1440" alt="image" src="https://github.com/user-attachments/assets/dbc19858-1d11-412b-b562-18034ae3ba28" />

При помощи python-скрипта шрифт кодируется в 1 бит на пиксель: 0 — фон, 1 — символ, и загружается во flash-память МК посредством хардкода массива байт (uint8_t).
<img width="855" height="139" alt="image" src="https://github.com/user-attachments/assets/9370d2e4-14fa-4e28-8ae9-e7c16925de73" />

В МК отрисовщик шрифта имеет буфер 9х9 бит. При отрисовке символа в этот буфер загружается соответствующий символ и отрисовывается по заданным координатам по правилу “фоновый цвет если 0, цвет символа если 1”.
Для работы с дисплеем используется модифицированная библиотека ST7735. 


#### 3.2.3.1 Вывод символа в ячее сетки
<!-- ISSUE:4 start -->

**Issue #4:** [![Static Badge](https://img.shields.io/badge/%D0%92%D1%8B%D0%B2%D0%BE%D0%B4%20%D1%81%D0%B8%D0%BC%D0%B2%D0%BE%D0%BB%D0%B0%20%D0%B2%20%D1%8F%D1%87%D0%B5%D0%B5%20%D1%81%D0%B5%D1%82%D0%BA%D0%B8-Todo-green)](https://github.com/IUTechSupp/SodiumDIA/issues/4)

Размер шрифта позволяет использовать сетку 14х17 символов. Функция отрисовки символа в конкретной ячее сетки вычисляет начало этой ячеи и вызывает функцию отрисовки символа по этим координатам:

_offset_y = border_y + pos_y * FONT_HEIGHT_

_offset_x = border_x + pos_x * FONT_WIDTH_

Рамка (border) вокруг интерфейса нужна для центровки содержимого:

_border_x = ( 128 % FONT_WIDTH ) / 2 = 1_

_border_y = (160 % FONT_HEIGHT) / 2 = 3.5 ~ 3_

---

<!-- ISSUE:4 end -->

### 3.4.3.3 Вывод слова
<!-- ISSUE:5 start -->

**Issue #5:** [![Static Badge](https://img.shields.io/badge/%D0%92%D1%8B%D0%B2%D0%BE%D0%B4%20%D1%81%D0%BB%D0%BE%D0%B2%D0%B0%2C%20%D0%BD%D0%B0%D1%87%D0%B8%D0%BD%D0%B0%D1%8F%20%D1%81%20%D1%8F%D1%87%D0%B5%D0%B8%20%D1%81%D0%B5%D1%82%D0%BA%D0%B8-Todo-green)](https://github.com/IUTechSupp/SodiumDIA/issues/5)

Функция вывода слова должна принимать x и y координаты начальной ячеи слова и отрисовывать N символов, начиная с этой ячеи, где:

_N ≤ 17 - pos_x_

В случае выхода за пределы экрана слово обрывается.



---

<!-- ISSUE:5 end -->



### 3.4.3.4 Рендер строк
<!-- ISSUE:6 start -->

**Issue #6:** [![Static Badge](https://img.shields.io/badge/%D0%A8%D1%80%D0%B8%D1%84%D1%82-Done-blue)](https://github.com/IUTechSupp/SodiumDIA/issues/6)



---

<!-- ISSUE:6 end -->
