from django.test import TestCase
from django.contrib.auth.models import User
from rest_framework.test import APIClient
from rest_framework import status

from .models import Comic


class ModelTestCase(TestCase):
    """This class defines the test suite for the comic model."""

    def setUp(self):
        """Define the test cliente and other variables"""
        user = User.objects.create(username='nerd')
        self.comic = Comic(name='Comic Test', owner=user)

    def test_model_can_create_a_comic(self):
        """Test the comic model can create a comic."""
        old_count = Comic.objects.count()
        self.comic.save()
        new_count = Comic.objects.count()
        self.assertNotEqual(old_count, new_count)


class TestComicListView(TestCase):
    """Test suite fot the comic list views. GET and POST requests."""

    def setUp(self):
        """Define the test client and other test variables."""

        # Create test user
        user = User.objects.create(username='nerd')

        # Initialize client and force it to use authentication
        self.client = APIClient()
        self.client.force_authenticate(user=user)

        self.comic_data = {
            'name': 'Lorem Ipsum',
            'owner': user.id,
        }

    def test_authorization_is_enforced(self):
        """Test that the api has user authorization."""
        new_cliet = APIClient()
        #res = new_cliet.get('/comics/', format='json')
        #self.assertEqual(res.status_code, status.HTTP_401_UNAUTHORIZED)

    def test_get(self):
        """Test GET request to Comic List"""
        comics = Comic.objects.all()
        response = self.client.get('/comics/',
                                   format='json')
        self.assertEqual(response.status_code, status.HTTP_200_OK)

        # Create a comic to test list comics
        self.client.post('/comics/', self.comic_data)

        # Made the GET request again
        comics = Comic.objects.all()
        response = self.client.get('/comics/')
        self.assertEqual(response.status_code, status.HTTP_200_OK)

        for comic in comics:
            self.assertContains(response, comic)

    def test_post(self):
        """Test the api has comic creation capability."""
        # Create a comic to test list comics
        response = self.client.post('/comics/', self.comic_data)
        self.assertEqual(response.status_code, status.HTTP_201_CREATED)

        # Bad Request test
        response = self.client.post('/comics/', {'nam': 2})
        self.assertEqual(response.status_code, status.HTTP_400_BAD_REQUEST)


class TestComicDetailView(TestCase):
    """Test case to Comic Detail View. GET, PUT and DELETE requests."""

    def setUp(self):
        """Define the test client and other test variables."""
        user = User.objects.create(username='nerd')

        # Initialize client and force it to use authentication
        self.client = APIClient()
        self.client.force_authenticate(user=user)

        self.comic_data = {
            'name': 'Lorem Ipsum',
            'owner': user.id,
        }
        self.response = self.client.post('/comics/',
                                         self.comic_data,
                                         format='json')

    def test_authorization_is_enforced(self):
        """Test that the api has user authorization."""
        new_cliet = APIClient()
        comic = Comic.objects.get()
        res = new_cliet.get('/comics/%d/' % comic.id, format='json')
        self.assertEqual(res.status_code, status.HTTP_401_UNAUTHORIZED)

    def test_get(self):
        """Test the api can get a comic."""
        comic = Comic.objects.get()
        self.response = self.client.get('/comics/%d/' % comic.id,
                                        format='json')

        self.assertEqual(self.response.status_code, status.HTTP_200_OK)
        self.assertContains(self.response, comic)

    def test_put(self):
        """Test the api can update a comic"""
        comic = Comic.objects.get()
        self.response = self.client.put('/comics/%d/' % comic.id,
                                        {'name': 'Ipsum Lorem'},
                                        format='json')

        self.assertEqual(self.response.status_code, status.HTTP_200_OK)

    def test_delete(self):
        """Test the api can delete a comic"""
        comic = Comic.objects.get()
        self.response = self.client.delete('/comics/%d/' % comic.id,
                                           format='json')
        self.assertEqual(self.response.status_code,
                         status.HTTP_204_NO_CONTENT)
