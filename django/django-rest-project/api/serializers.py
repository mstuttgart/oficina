from django.contrib.auth.models import User
from rest_framework import serializers

from .models import Comic


class ComicSerializer(serializers.ModelSerializer):
    """Comic serializer to map the Model instance JSON format."""

    owner = serializers.ReadOnlyField(source='owner.username')

    class Meta:
        """Meta class to map serializers fields with the model fields."""
        model = Comic
        fields = ('id', 'name', 'owner', 'date_created', 'date_modified')
        read_only_fields = ('date_created', 'date_modified')


class UserSerializer(serializers.ModelSerializer):
    """User serializer class to map User model instance  to JSON format."""

    comic = serializers.PrimaryKeyRelatedField(many=True,
                                               queryset=Comic.objects.all())

    class Meta:
        model = User
        fields = ('id', 'username', 'snippets')
