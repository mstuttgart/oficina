from django.conf.urls import url, include, patterns
from . import views

# app_name = 'library'

urlpatterns = [
    url(r'^$', views.index, name='index'),
    url(r'^save/$', views.save, name='book.save'),
    url(r'^edit/(?P<book_id>[0-9]+)/$', views.edit, name='book.edit'),
    url(r'^remove/(?P<book_id>[0-9]+)/$', views.remove, name='book.remove')
]
