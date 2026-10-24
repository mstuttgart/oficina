#include <LiquidCrystal.h>

// Pinos do Arduino conectados ao LCD (modo de 4 bits).
const int RS = 12;
const int EN = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;

// Entrada analógica ligada à saída do sensor LM35.
const int PORTA = A0;
const int TEMPO = 1000;

// Cria o objeto do LCD usando os pinos definidos acima.
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup()
{
    // Inicializa o LCD 16x2.
    lcd.begin(16, 2);

    // Inicia a comunicação serial para enviar as leituras ao computador.
    Serial.begin(9600);

    // Configura a entrada do sensor.
    pinMode(PORTA, INPUT);
}

void loop()
{
    // Lê o conversor analógico-digital de 10 bits (0 a 1023).
    int leitura = analogRead(PORTA);

    // Converte a leitura em graus Celsius.
    // Considera referência analógica de 5 V e sensibilidade do LM35 de 10 mV/°C.
    float temperatura = float(leitura) * 100 * 5.0 / 1023.0;

    // Exibe a temperatura na segunda linha do LCD.
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura:");
    lcd.setCursor(0, 1);
    lcd.print(temperatura);
    lcd.print(" oC");

    // Envia a temperatura pela porta serial com uma casa decimal.
    Serial.print("Temperatura: ");
    Serial.print(temperatura, 1);
    Serial.println(" oC");

    // Aguarda antes de realizar a próxima leitura.
    delay(TEMPO);
}
