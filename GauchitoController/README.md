Gauchito
========
API para controle de um R.M.R. pertencente a UEM/Maringá-PR

Doc:_https://github.com/rochapaulo/Gauchito/blob/master/RA60937.pdf

Montagem
======
As conexões do RMR podem ser feitas conforme a definida no arquivo "Gauchito.h"
https://github.com/rochapaulo/Gauchito/blob/master/GauchitoAPI/Gauchito/Gauchito.h

onde estão definidas as constantes:

- Driver de potência da interface direita
```C
#define RDIR 27
#define RPWM 45
#define RBRAKE 25
#define RCHA 19
#define RCHB 23
#define RINT 4
```

- Driver de potência da interface esquerda
```C
#define LDIR 26
#define LPWM 8
#define LBRAKE 24
#define LCHA 3
#define LCHB 22
#define LINT 1
```

- Ultrassom
```C
#define ULTRASONIC_PIN 7
```

- Infravermelho: 1,2,3,4,5,6
```C
#define IR01_PIN A10
#define IR02_PIN A11
#define IR03_PIN A12
#define IR04_PIN A13
#define IR05_PIN A14
#define IR06_PIN A15
```

- Bússola: Magnetometro;
Utiliza o protocolo de comunicação i2c, portanto não é necessário definir pinos específicos pra ele no construtor do objeto.

Fututos componentes podem ser adicionados neste arquivo. A ligação deve ser feita diretamente na placa

| Board         | SDA   | SCL  |
| ------------- |:-----:| ----:|
| Uno           | A4    | A5   |
| Mega2560      | 20    | 21   |
| Leonardo      | 2     | 3    |
| Due 20        | 20    | 21   |
http://arduino.cc/en/reference/wire


##instalação
```bash
$make install
GAUCHITO API - INSTALLER
=========================================
Arduino sketchbook library folder: user/arduino/sketchbook/library
```
