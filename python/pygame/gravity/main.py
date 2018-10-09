# -*- coding: utf-8 -*-
import pygame
import math

class Vector2D:

    def __init__(self, x=0.0, y=0.0):
        self.x = x
        self.y = y

    def add(self, vetor):
        self.x += vetor.x
        self.y += vetor.y

class SpriteSheet:

    def __init__(self, filename, cols, rows):
        self.sheet = pygame.image.load(filename)

        self.rows = rows
        self.cols = cols
        self.total_cells = cols * rows

        self.rect = self.sheet.get_rect()

        w = self.cell_width = self.rect.width / cols
        h = self.cell_height = self.rect.height / rows


        self.cells = [(i % cols * w, i /cols * h, w, h) for i in range(self.total_cells)]

    def draw(self, surface, cell_index, x, y):
        surface.blit(self.sheet, (x, y), self.cells[cell_index])


if __name__ == '__main__':
    pygame.init()

    # Definimos as dimensoes da janela
    display_w = 640
    display_h = 480

    # Incializamos o display
    screen = pygame.display.set_mode((display_w, display_h))

    # Flag para controlar o fluxo de loop
    done = False

    # Clock utilizado para controlarmos os FPS
    clock = pygame.time.Clock()

    # Criamos o SpriteSheet
    sprite = SpriteSheet(filename='map.png', cols=5, rows=2)

    index = 0

    pulando = False

    position = Vector2D(0, display_h - sprite.cell_height)
    gravity = Vector2D(0, 2)
    velocidade = Vector2D(0, 0)

    while not done:

        # Verifamos se ocorreu algum evento (teclado, mouse)
        for event in pygame.event.get():

            # Caso a janela seja fechada, saimos do loop para encerrar o jogo
            # Se pressionarmos a tecla ESC, saimos do loop e encerramos o jogo
            if event.type == pygame.QUIT:
                done = True

        pressed = pygame.key.get_pressed()

        if pressed[pygame.K_LEFT]:
            velocidade.x = -5

        if pressed[pygame.K_RIGHT]:
            velocidade.x = 5

        # Acionamos a gravidade e o estado de pulo
        if pressed[pygame.K_SPACE] and not pulando:
            velocidade.y = -20
            pulando = True

        if pulando:
            # Adicionamos gravidade ao vetor velocidade
            # Isso faz com que a velocidade de subida do personagem diminua ate
            # que ele para emseguida comecar o movimento de queda
            velocidade.add(gravity)

        # Somamos o vetor velocidade ao vetor deslocamento
        position.add(velocidade)

        # Se o ultimo frame do spritesheet foi desenhado, voltamos para o primeiro
        index = (index + 1) if index < sprite.total_cells - 1 else 0

        # Pintamos a tela de branco
        screen.fill((255, 255, 255))

        # Desenhamos o sprite na tela
        sprite.draw(surface=screen, cell_index=index, x=position.x, y=position.y)

        # Atualizamos oi display
        pygame.display.flip()

        # Se os pes do personame alcancarem o fim da tela, consiramos que
        # ele chegou ao chao, logo o pulo foi finalizado
        if position.y > (display_h - sprite.cell_height):
            pulando = False

            # Zeramos a velocidade em y para que o personame nao continue descencendo
            velocidade.y = 0

        # Zeramos a velocidade em x para que o personagem nao continue se deslocando
        velocidade.x = 0

        # Aguardamos passar 1/25 segundos para redesenharmos a tela
        # Cotrole de FPS
        clock.tick(25)
