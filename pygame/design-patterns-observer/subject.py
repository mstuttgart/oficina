# -*- coding:utf-8 -*-

class Subject:

    def __init__(self):
        self._observers = []

    def register_observer(self, observer):
        self._observers.append(observer)

    def notify_observers(self):

        for observer in self._observers:
            observer.notify()
