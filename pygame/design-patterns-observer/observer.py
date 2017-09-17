# -*- coding:utf-8 -*-


class Observer:

    def notify(self, x, y):
        pass

class Sombra(Observer):

    def __init__(x, y):
        self.x = x
        self.y = y

    def notify(self, x, y):
        self.x = x
        self.y = y
