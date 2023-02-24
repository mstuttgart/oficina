from __future__ import unicode_literals

from django.db import models
from django.utils.encoding import python_2_unicode_compatible


# Create your models here.
class Library(models.Model):

    title = models.CharField(max_length=100)
    description = models.TextField(blank=True, default='')
    status = models.BooleanField(default=False)
    friend_name = models.CharField(max_length=100, blank=True, default='')
    friend_email = models.EmailField(max_length=50, blank=True, default='')
    create_at = models.DateTimeField(auto_now_add=True)

    class Meta:
        verbose_name = 'Livro'
        verbose_name_plural = 'Livros'

    def __str__(self):
        return self.title

    def __unicode__(self):
        return self.title
