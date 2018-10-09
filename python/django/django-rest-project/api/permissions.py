from rest_framework.permissions import BasePermission
from .models import Comic


class IsOwner(BasePermission):
    """Custom permission class to allow only comic owner to edit them."""

    def has_object_permission(self, request, view, obj):
        """Return True if permission is granted to the comic owner."""

        if isinstance(obj, Comic):
            return obj.owner == request.user
        else:
            return obj.owner == request.user
