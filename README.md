# Disparador de câmera - Arduino

Controle da câmera **NewLink - Sport Mini** via Arduino.

## Material

- 3x Transistor 2N3904
- Arduino
- Fios

![camera](assets/sport-mini-01.png)
![camera](assets/sport-mini-02.jpg)

## Montagem

- Abra a câmera, e solde um fio em cada lado dos _push buttons_ de cada função, ou seja, cada função terão dois fios soldados para fechar contato

![circuito 01](assets/20180318_032941.jpg)
![circuito 02](assets/20180318_033114.jpg)
![circuito 03](assets/20180318_033118.jpg)

- Em uma placa, o protoboard, ligue os três transístores, cada par de fios que você soldou no passo anterior, é ligado em um transistor, no emissor e no coletor - no caso, as pernas de cada lateral do transistor.

![circuito 04](assets/20180318_033137.jpg)
![circuito 05](assets/20180318_033202.jpg)

- O terminal do meio de cada transístor, é ligado em uma porta digital do arduino, neste caso, utilizei a porta 2, 3 e 4 (botão de disparo, botão de ligar/desligar e seleção de modo, respectivamente).

![circuito 06](assets/20180318_033232.jpg)

- Ao final você terá algo parecido com isso:

![circuito 07](assets/20180318_033247.jpg)

- Você pode ver funcionando no link abaixo:

[![arduino - camera](http://img.youtube.com/vi/O6URbU7rcL0/0.jpg)](https://www.youtube.com/watch?v=O6URbU7rcL0 "Arduino controlando camera")