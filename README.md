# SodiumDIA
Логический анализатор интерфейсов физического уровня

### 3.2.1 Тактовые кнопки
<!-- ISSUE:2 start -->

### Issue #2: Модуль ввода [![Static Badge](https://img.shields.io/badge/-Todo-green)](https://github.com/IUTechSupp/SodiumDIA/issues/2) 


**Автор:** @SodAcetate 

 


<!-- ISSUE:2 end -->

### 3.2.3 Графический интерфейс
<!-- ISSUE:3 start -->

### Issue #3: Графический интерфейс [![Static Badge](https://img.shields.io/badge/-Todo-green)](https://github.com/IUTechSupp/SodiumDIA/issues/3) 


**Автор:** @SodAcetate 

 


<!-- ISSUE:3 end -->

<!-- ISSUE:6 start -->
---
<!-- ISSUE:6 end -->

Был отрисован шрифт размера 9х9 пикселей для кодировки CP866 (W. I. P.):
<img width="1440" height="1440" alt="image" src="https://github.com/user-attachments/assets/dbc19858-1d11-412b-b562-18034ae3ba28" />

При помощи python-скрипта шрифт кодируется в 1 бит на пиксель: 0 — фон, 1 — символ, и загружается во flash-память МК посредством хардкода массива байт (uint8_t).
<img width="855" height="139" alt="image" src="https://github.com/user-attachments/assets/9370d2e4-14fa-4e28-8ae9-e7c16925de73" />

В МК отрисовщик шрифта имеет буфер 9х9 бит. При отрисовке символа в этот буфер загружается соответствующий символ и отрисовывается по заданным координатам по правилу “фоновый цвет если 0, цвет символа если 1”.
Для работы с дисплеем используется модифицированная библиотека ST7735. 
<!-- ISSUE:4 start -->

<!-- ISSUE:4 end -->

<!-- ISSUE:5 start -->

<!-- ISSUE:5 end -->

<!-- ISSUE:6 start -->

<!-- ISSUE:6 end -->
