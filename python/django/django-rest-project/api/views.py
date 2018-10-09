from django.http import Http404
from django.contrib.auth.models import User
from rest_framework import status
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import generics
from rest_framework import permissions

from .serializers import ComicSerializer, UserSerializer
from .models import Comic
from .permissions import IsOwner


class ComicListView(APIView):
    """This class handles the http GET (all) and POST request to comics."""

    permission_classes = (permissions.IsAuthenticated, IsOwner)

    def permorm_create(self, serializer):
        serializer.save(owner=self.request.user)

    def get(self, request, format='json'):
        """List all Comics"""
        comics = Comic.objects.all()
        serializer = ComicSerializer(comics, many=True)
        return Response(serializer.data)

    def post(self, request, format='json'):
        """Create a new Comic"""
        serializer = ComicSerializer(data=request.data)

        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        else:
            return Response(serializer.errors,
                            status=status.HTTP_400_BAD_REQUEST)


class ComicDetailView(APIView):
    """This class handles the http GET, PUT and DELETE requests to comic."""

    permission_classes = (permissions.IsAuthenticated, IsOwner)

    def get_comic(self, pk):
        """Get comic object from id"""
        try:
            return Comic.objects.get(pk=pk)
        except Comic.DoesNotExist:
            raise Http404

    def get(self, request, pk, format='json'):
        """Return Comic from ID"""
        comic = self.get_comic(pk=pk)
        serializer = ComicSerializer(comic)
        return Response(serializer.data)

    def put(self, request, pk, format='json'):
        """Update Comic from ID"""
        comic = self.get_comic(pk=pk)
        serializer = ComicSerializer(comic, data=request.data)

        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        else:
            return Response(serializer.errors,
                            status=status.HTTP_400_BAD_REQUEST)

    def delete(self, request, pk, format='json'):
        """Delete Comic"""
        comic = self.get_comic(pk=pk)
        comic.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)


class UserList(generics.ListAPIView):
    queryset = User.objects.all()
    serializer_class = UserSerializer


class UserDetail(generics.RetrieveAPIView):
    queryset = User.objects.all()
    serializer_class = UserSerializer
