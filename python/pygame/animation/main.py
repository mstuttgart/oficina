# -*- coding: utf-8 -*-
import pygame


class SpriteSheet:

    def __init__(self, filename, cols, rows):
        self.sheet = pygame.image.load(filename)

        self.rows = rows
        self.cols = cols
        self.total_cells = cols * rows

        self.rect = self.sheet.get_rect()

        w = self.cell_width = self.rect.width / cols
        h = self.cell_height = self.rect.height / rows

        self.cells = [(i % cols * w, i // cols * h, w, h) for i in range(self.total_cells)]

    def draw(self, surface, cell_index, x, y):
        surface.blit(self.sheet, (x, y), self.cells[cell_index])


if __name__ == '__main__':
    pygame.init()

    # Definimos as dimensoes da janela
    display_w = 400
    display_h = 300

    # Incializamos o display
    screen = pygame.display.set_mode((display_w, display_h))

    # Flag para controlar o fluxo de loop
    done = False

    # Clock utilizado para controlarmos os FPS
    clock = pygame.time.Clock()

    # Criamos o SpriteSheet
    sprite = SpriteSheet(filename='map.png', cols=5, rows=2)

    index = 0

    x = display_w/2 - sprite.cell_width/2
    y = display_h/2 - sprite.cell_height/2

    while not done:

        # Verifamos se ocorreu algum evento (teclado, mouse)
        for event in pygame.event.get():

            # Caso a janela seja fechada, saimos do loop para encerrar o jogo
            # Se pressionarmos a tecla ESC, saimos do loop e encerramos o jogo
            if event.type == pygame.QUIT:
                done = True

        index = (index + 1) if index < sprite.total_cells - 1 else 0

        # Pintamos a tela de branco
        screen.fill((255, 255, 255))

	# Desenha sprite
        sprite.draw(surface=screen, cell_index=index, x=x, y=y)

        # Atualizamos oi display
        pygame.display.flip()

        # Aguardamos passar 1/60 segundos para redesenharmos a tela
        # Cotrole de FPS
        clock.tick(25)
