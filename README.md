Код кодом, а доказывать работоспособность программы как-то нужно, а при отсутствии ключевых примеров это все превращается в интересное приключение!
Итак, что мы имеем в нашем режиме гаммирования:
Операция сложения, операция XOR и операцию Простой замены.
Будем считать, что в первых двух ошибиться достаточно сложно, поэтому проверим последнюю одним из немногих возможных для нас способом.
При наличии ключевых примеров для Простой замены из ГОСТ Р 34.13 - 2015, дадим нашей функции гаммирования ключ:

![alt text](https://sun9-66.userapi.com/impg/ZL4CXIb3GoF2koiMF1tLMlOx6I8-tDQQVi36ow/mnkB6w8izQs.jpg?size=545x56&quality=96&proxy=1&sign=1ef4e7a63b2dbcdfd6dc3466674f973f)

И вместо синхрон посылки открытый текст:

![alt text](https://sun9-6.userapi.com/impg/v7MBfBvRE59xVg-vRgAICJIBiUnNM7fI5erWHw/3ToezZhDMYE.jpg?size=399x51&quality=96&proxy=1&sign=a553ad0f95dc78739fce2681c418dfc4)

После чего, на первой итерации вызова функции для простой замены мы получим зашифрованный текст:

![alt text](https://sun9-26.userapi.com/impg/i2HHdJznVpRVKeRsycpmYovvPzvF9LB7ljN5Gg/px990sqz3eU.jpg?size=570x63&quality=96&proxy=1&sign=274998283de6942dad7a7d1a97ef04cc)

Проверим, что имеем мы:

![alt text](https://sun9-19.userapi.com/impg/9yzhfJnvf3SErdd503iJEl2GFmF52TJOXj6UzA/w54iiQB9ix4.jpg?size=929x112&quality=96&proxy=1&sign=7abf78e259bdb8c56f5891f659af66c4)

Все сошлось, а значит, мы можем сделать вывод, что для последующих итераций выробатки гаммы, она будет вырабатываться корректно.
