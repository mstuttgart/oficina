"""gerenciador URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/1.9/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  url(r'^$', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  url(r'^$', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.conf.urls import url, include
    2. Add a URL to urlpatterns:  url(r'^blog/', include('blog.urls'))
"""
from django.conf.urls import url
from django.contrib import admin
from django.conf import settings
from django.contrib.auth import views as django_views
from agenda import views as agenda_views


urlpatterns = [
    url(r'^admin/', admin.site.urls, name='index'),
    url(r'^$', agenda_views.lista, name='lista'),
    url(r'^adiciona/$', agenda_views.adiciona, name='adiciona'),
    url(r'^remove/(?P<id_item>\d+)/$', agenda_views.remove, name='remove'),
    url(r'^item/(?P<id_item>\d+)/$', agenda_views.item, name='item'),
    url(r'^login/$', django_views.login, {'template_name': "login.html"}),
    url(r'^logout/$', django_views.logout_then_login, {'login_url': '/login/'}),
]

# if settings.DEBUG:
#     urlpatterns += [
#         url(r'^media/(?P<path>.*)$', django.views.static.server,
#             {'document_root': settings.MEDIA_URL}),
#     ]
