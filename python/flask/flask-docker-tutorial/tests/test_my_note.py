import unittest

from flask import abort, url_for
from flask_testing import TestCase

from my_note import app


class BasicTest(unittest.TestCase):

    def setUp(self):

        # Criamos um client para teste
        self.app = app.test_client()

        # Para que as exceptions lancadas
        # sejam propagadas para o cliente de test
        self.app.testing = True

    def test_index_status_code(self):
        """Test the /index status code"""
        response = self.app.get('/')

        self.assertEqual(response.status_code, 200)

    def test_about_status_code(self):
        """Test status code from about page"""
        response = self.app.get('/about/')

        self.assertEqual(response.status_code, 200)
