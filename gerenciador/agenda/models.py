# -*- encoding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models
from django.contrib.auth.models import User

# Create your models here.
class ItemAgenda(models.Model):

    titulo = models.CharField(max_length=100)
    data = models.DateField()
    hora = models.TimeField()
    descricao = models.TextField()
    usuario = models.ForeignKey(User)

    def __unicode__(self):
        return '%s - %s %s' % (self.titulo, self.data, self.hora)
