#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pino do Sensor Touch
const int PINO_TOUCH = 2;
const int PINO_BUZZER = 8;

// Parâmetros dos olhos estilo EMO
const int EYE_W = 28;
const int EYE_H = 34;
const int EYE_R = 7;
const int EYE_SPACING = 16;
const int EYE_X = 28;
const int EYE_Y = 15;

// Estados do Robô
enum EstadoRobo
{
    ACORDADO,
    CARINHO,
    DORMINDO
};

EstadoRobo estadoAtual = ACORDADO;

// Temporizadores (millis)
unsigned long ultimoToque = 0;
unsigned long proximaPiscada = 0;
unsigned long proximoOlhar = 0;
bool piscando = false;
unsigned long inicioPiscada = 0;

int offsetX = 0;
int offsetY = 0;

// Configuração de tempos (ajuste como preferir)
// Para testar agora, configurei 15 segundos sem toque para ele dormir!
// Depois você pode mudar para 60000 (1 minuto) ou 120000 (2 minutos).
const unsigned long TEMPO_PARA_DORMIR = 15000;
const unsigned long DURACAO_CARINHO = 1500; // Fica 1.5s feliz após soltar o dedo

// --- EFEITOS SONOROS CHIPTUNE (Sem bibliotecas pesadas) ---

// Som curto e agudo de alegria ao receber carinho
void somCarinho()
{
    tone(PINO_BUZZER, 1318, 50); // E6
    delay(60);
    tone(PINO_BUZZER, 1568, 50); // G6
    delay(60);
    tone(PINO_BUZZER, 2093, 80); // C7
}

// Som decrescente simulando bocejo / sono
void somDormir()
{
    for (int freq = 1200; freq >= 400; freq -= 100)
    {
        tone(PINO_BUZZER, freq, 40);
        delay(45);
    }
    noTone(PINO_BUZZER);
}

// Bipe duplo rápido e alegre ao acordar
void somAcordar()
{
    tone(PINO_BUZZER, 1046, 60); // C6
    delay(80);
    tone(PINO_BUZZER, 1568, 100); // G6
}

// --- FUNÇÕES GRÁFICAS DE DESENHO ---

void desenharOlhosAbertos(int dx, int dy, int h, int r)
{
    display.clearDisplay();
    int yCentral = EYE_Y + dy + ((EYE_H - h) / 2);

    // Olho Esquerdo
    display.fillRoundRect(EYE_X + dx, yCentral, EYE_W, h, r, SSD1306_WHITE);
    // Olho Direito
    display.fillRoundRect(EYE_X + dx + EYE_W + EYE_SPACING, yCentral, EYE_W, h, r, SSD1306_WHITE);

    display.display();
}

// Olhos em arco curvado (^ ^) simulando sorriso/carinho
void desenharOlhosCarinho()
{
    display.clearDisplay();

    // Esquerdo
    display.fillRoundRect(EYE_X, EYE_Y + 8, EYE_W, 14, 5, SSD1306_WHITE);
    display.fillRoundRect(EYE_X + 3, EYE_Y + 14, EYE_W - 6, 12, 4, SSD1306_BLACK);

    // Direito
    display.fillRoundRect(EYE_X + EYE_W + EYE_SPACING, EYE_Y + 8, EYE_W, 14, 5, SSD1306_WHITE);
    display.fillRoundRect(EYE_X + EYE_W + EYE_SPACING + 3, EYE_Y + 14, EYE_W - 6, 12, 4, SSD1306_BLACK);

    display.display();
}

// Olhos fechados dormindo (- -)
void desenharOlhosDormindo()
{
    display.clearDisplay();
    int yLinha = EYE_Y + (EYE_H / 2);

    // Traço fino horizontal
    display.fillRoundRect(EYE_X, yLinha, EYE_W, 3, 1, SSD1306_WHITE);
    display.fillRoundRect(EYE_X + EYE_W + EYE_SPACING, yLinha, EYE_W, 3, 1, SSD1306_WHITE);

    display.display();
}

void setup()
{
    Serial.begin(115200);
    pinMode(PINO_TOUCH, INPUT);
    pinMode(PINO_BUZZER, OUTPUT);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        while (true)
            ;
    }

    display.clearDisplay();
    somAcordar(); // Som de inicialização do robô

    ultimoToque = millis();
    proximaPiscada = millis() + 3000;
    proximoOlhar = millis() + 5000;
}

void loop()
{

    unsigned long agora = millis();
    bool tocando = (digitalRead(PINO_TOUCH) == HIGH);

    // 1. GERENCIAMENTO DE ESTADOS E TRANSIÇÕES
    if (tocando)
    {
        ultimoToque = agora;
        somAcordar();
        estadoAtual = CARINHO;
    }
    else
    {
        if (estadoAtual == CARINHO && (agora - ultimoToque > DURACAO_CARINHO))
        {
            estadoAtual = ACORDADO;
            offsetX = 0;
            offsetY = 0; // Centraliza o olhar ao voltar
            proximaPiscada = agora + random(2000, 4000);
        }
        else if (estadoAtual == ACORDADO && (agora - ultimoToque > TEMPO_PARA_DORMIR))
        {
            estadoAtual = DORMINDO;
            somDormir();
        }
    }

    // 2. RENDERIZAÇÃO CONFORME O ESTADO
    switch (estadoAtual)
    {
    case CARINHO:
        desenharOlhosCarinho();
        break;

    case DORMINDO:
        desenharOlhosDormindo();
        break;

    case ACORDADO:
        // Controle do movimento do olhar
        if (agora >= proximoOlhar && !piscando)
        {
            int dir = random(0, 4);
            if (dir == 0)
            {
                offsetX = 0;
                offsetY = 0;
            } // Centro
            else if (dir == 1)
            {
                offsetX = -10;
                offsetY = 0;
            } // Esquerda
            else if (dir == 2)
            {
                offsetX = 10;
                offsetY = 0;
            } // Direita
            else if (dir == 3)
            {
                offsetX = 0;
                offsetY = -5;
            } // Cima

            proximoOlhar = agora + random(3000, 6000);
        }

        // Controle da piscada (sem delay longo)
        if (!piscando && agora >= proximaPiscada)
        {
            piscando = true;
            inicioPiscada = agora;
            desenharOlhosAbertos(offsetX, offsetY, 4, 1); // Olhos quase fechados
        }
        else if (piscando && (agora - inicioPiscada >= 120))
        {
            piscando = false;
            proximaPiscada = agora + random(3000, 6000);
            desenharOlhosAbertos(offsetX, offsetY, EYE_H, EYE_R);
        }
        else if (!piscando)
        {
            desenharOlhosAbertos(offsetX, offsetY, EYE_H, EYE_R);
        }
        break;
    }

    delay(20);
}