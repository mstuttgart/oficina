#include <LiquidCrystal.h>
// Requer "DHT sensor library" da Adafruit e "Adafruit Unified Sensor".
#include <DHT.h>

// Pinos do Arduino conectados ao LCD (modo de 4 bits).
const int RS = 12;
const int EN = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;

// Pino digital ligado ao sensor DHT11.
const int DHTPIN = 7;
const int TEMPO = 1000;

// Cria o objeto do sensor DHT.
DHT dht(DHTPIN, DHT11);

// Cria o objeto do LCD usando os pinos definidos acima.
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup()
{
    // Inicializa o LCD 16x2.
    lcd.begin(16, 2);

    // Inicia a comunicação serial para enviar as leituras ao computador.
    Serial.begin(9600);

    dht.begin();
}

void loop()
{
    // Lê o conversor analógico-digital de 10 bits (0 a 1023).
    float leitura = dht.readTemperature();
    float umidade = dht.readHumidity();

    // A leitura do DHT11 já está em graus Celsius.
    float temperatura = leitura;

    // Exibe a temperatura na segunda linha do LCD.
    lcd.clear();
    lcd.setCursor(0, 0);

    if (!isnan(temperatura) && !isnan(umidade))
    {
        // Exibe a temperatura e umidade no LCD.
        lcd.print("Temp.: ");
        lcd.print(temperatura);
        lcd.print(" oC");

        lcd.setCursor(0, 1);
        lcd.print("Umidade: ");
        lcd.print(umidade);

        lcd.print(" %");
    }
    else
    {
        lcd.print("Erro na leitura");
        Serial.println("Erro na leitura do sensor DHT11");
        delay(TEMPO);
        return;
    }

    // lcd.print("Temperatura:");
    // lcd.setCursor(0, 1);
    // lcd.print(temperatura);
    // lcd.print(" oC");

    // lcd.setCursor(0, 1);
    // lcd.print("Umidade:");
    // lcd.print(umidade);
    // lcd.print(" %");

    // Envia a temperatura pela porta serial com uma casa decimal.
    Serial.print("Temperatura: ");
    Serial.print(temperatura, 1);
    Serial.println(" oC");
    Serial.print("Umidade: ");
    Serial.print(umidade, 1);
    Serial.println(" %");

    // Aguarda antes de realizar a próxima leitura.
    delay(TEMPO);
}
