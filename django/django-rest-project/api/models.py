from django.db import models


class Comic(models.Model):
    """This class represents the comic model."""

    name = models.CharField(max_length=255, blank=False, unique=True)
    owner = models.ForeignKey('auth.User',
                              related_name='comics',
                              on_delete=models.CASCADE)
    date_created = models.DateTimeField(auto_now_add=True)
    date_modified = models.DateTimeField(auto_now=True)

    def __str__(self):
        """Return a human readable representatio of the model instance"""
        return "{}".format(self.name)

