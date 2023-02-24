from django.urls import path
from rest_framework.urlpatterns import format_suffix_patterns

from .views import ComicListView, ComicDetailView
from .views import UserList, UserDetail

urlpatterns = [
    path('comics/', ComicListView.as_view()),
    path('comics/<int:pk>/', ComicDetailView.as_view()),
    path('users/', UserList.as_view()),
    path('users/<int:pk>/', UserDetail.as_view()),
]


urlpatterns = format_suffix_patterns(urlpatterns)
