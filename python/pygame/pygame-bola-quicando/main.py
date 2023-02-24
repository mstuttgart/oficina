# -*- encode: utf-8 -*-

import pygame

# Iniciamos o pygame
pygame.init()

# Definimos as dimensoes da janela
display_w = 400
display_h = 300

# Incializamos o display
screen = pygame.display.set_mode((display_w, display_h))

# Flag para controlar o fluxo de loop
done = False

# Carregamos a imagem da bola
ball = pygame.image.load('ball.png')

effect = pygame.mixer.Sound('jump.wav')

# Clock utilizado para controlarmos os FPS
clock = pygame.time.Clock()

# Coordenadas da bola
x = 20
y = 30

# Vetor direcao do movimento da bola
direction_x = 1
direction_y = 1

sound_on = False

while not done:

    # Verifamos se ocorreu algum evento (teclado, mouse)
    for event in pygame.event.get():

        # Caso a janela seja fechada, saimos do loop para encerrar o jogo
        # Se pressionarmos a tecla ESC, saimos do loop e encerramos o jogo
        if event.type == pygame.QUIT:
            done = True

        if event.type == pygame.KEYDOWN:

            if event.key == pygame.K_ESCAPE:
                done = True

            elif event.key == pygame.K_SPACE:
                sound_on = not sound_on

    # Verificamos os limites da tela na horizontal
    # e alteramos o sentido do vetor de movimento
    if x + ball.get_width() > display_w:
        direction_x = -1

        if sound_on:
            effect.play()

    elif x < 0:
        direction_x = 1
        if sound_on:
            effect.play()

    if y + ball.get_height() > display_h:
        direction_y = -1
        if sound_on:
            effect.play()

    elif y < 0:
        direction_y = 1
        if sound_on:
            effect.play()

    # Incrementamos ou decrementamos a posicao da bola
    x += 3 * direction_x
    y += 3 * direction_y

    # Pintamos a tela de branco
    screen.fill((255, 255, 255))

    # Desenhamos a imagem da bola
    screen.blit(ball, (x, y))

    # Atualizamos oi display
    pygame.display.flip()

    # Aguardamos passar 1/60 segundos para redesenharmos a tela
    # Cotrole de FPS
    clock.tick(60)

