# Goal Checker
## Iniciando o servidor Python com Flask
1. Primeiramente instale todas as dependencias que estão em [requirements.txt](IPSSI-server-flask/requirements.txt) com <br>
     `cd C:\caminho\para\seu\projeto`<br>`
    pip install -r requirements.txt
    `.
3. Inicie o servidor rodando o arquivo [main.py](IPSSI-server-flask/main.py) (Python 3.12.2).
4. Execute o comando `netsh advfirewall firewall add rule name="Allow Flask 5000" protocol=TCP dir=in localport=5000 action=allow` no seu PowerShell (admin) para permitir que essa porta 5000 seja aberta.


## Itens necessários:
- ESP32 DEVKETV1
- Sensor Ultrassônico HC-SR04
- ESP32-CAM
- FTDI232
- Alguns jumpers
- Duas protoboards

## Conexão ESP32 com o sensor Ultrassônico HC-SR04
![image](https://github.com/TheBrunno/ipssi-goal-checker-esp32/assets/68453992/c4e75d03-517f-4438-b7a5-596618d6adc0)
(Caso só esteja detectando 0CM de distância, conecte no pino `5v` ou `vin`).

## Conexão ESP32-CAM
![image](https://github.com/TheBrunno/ipssi-goal-checker-esp32/assets/68453992/3ad9d212-56b6-44d0-ac8c-cb1f8503c0a4)
(O jumper verde serve apenas para o bootloader do esp32-cam ser ativado, após o upload do código, você deve retirá-lo e pressionar o botão `RST`. Outra observação é que você deve selecionar o pino `5v` no `FTDI232`).
