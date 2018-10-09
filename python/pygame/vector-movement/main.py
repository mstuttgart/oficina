# -*- coding: utf-8 -*-
import pygame
import math

class Vetor:

    def __init__(self, x=0.0, y=0.0):
        self.x = x
        self.y = y

    def calcula_vetor_unitario(self):
        norma = math.sqrt(math.pow(self.x, 2) + math.pow(self.y, 2))
        norma = float(norma)
        v_unit_x = self.x/norma
        v_unit_y = self.y/norma

        return Vetor(v_unit_x, v_unit_y)

    def add(self, vetor):
        self.x += vetor.x
        self.y += vetor.y

    def sub(self, vetor):
        x0 = vetor.x - self.x
        y0 = vetor.y - self.y

        v = Vetor(x0, y0)
        return v.calcula_vetor_unitario()

class Personagem:

    def __init__(self, position):
        self.position = position
        self.image = None

    def get_position(self):
        return (self.position.x, self.position.y)

if __name__ == '__main__':
    pygame.init()

    # Definimos as dimensoes da janela
    display_w = 800
    display_h = 640

    # Incializamos o display
    screen = pygame.display.set_mode((display_w, display_h))

    # Flag para controlar o fluxo de loop
    done = False

    # Clock utilizado para controlarmos os FPS
    clock = pygame.time.Clock()

    pers_1 = Personagem(Vetor(0, 0))
    pers_1.image = pygame.image.load('Attack (1).png')

    pers_2 = Personagem(Vetor(700, 500))
    pers_2.image = pygame.image.load('Attack (2).png')

    x, y = 0, 0

    while not done:

        # Verifamos se ocorreu algum evento (teclado, mouse)
        for event in pygame.event.get():

            # Caso a janela seja fechada, saimos do loop para encerrar o jogo
            # Se pressionarmos a tecla ESC, saimos do loop e encerramos o jogo
            if event.type == pygame.QUIT:
                done = True
        v_desloc = Vetor(0, 0)

        pressed = pygame.key.get_pressed()

        if pressed[pygame.K_LEFT]:
            v_desloc.x = -3

        if pressed[pygame.K_RIGHT]:
            v_desloc.x = 3

        if pressed[pygame.K_UP]:
            v_desloc.y = -3

        if pressed[pygame.K_DOWN]:
            v_desloc.y = 3

        # Criamos o vetor velocidade para o personagem 1
        pers_2.position.add(v_desloc)

        # Pintamos a tela de branco
        screen.fill((255, 255, 255))

        # Desenhamos a imagem da bola
        screen.blit(pers_1.image, pers_1.get_position())
        screen.blit(pers_2.image, pers_2.get_position())

        # Atualizamos oi display
        pygame.display.flip()

        # Calculamos nova posicao
        v_unit = pers_1.position.sub(pers_2.position)
        pers_1.position.add(v_unit)


        # Aguardamos passar 1/60 segundos para redesenharmos a tela
        # Cotrole de FPS
        clock.tick(60)
