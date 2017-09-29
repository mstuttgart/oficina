from flask_wtf import FlaskForm
from wtforms import StringField, IntegerField, TextAreaField, FileField
from wtforms import validators, ValidationError
from wtforms.ext.sqlalchemy.fields import QuerySelectField

from app import models


class BookForm(FlaskForm):
    title = StringField('Title', validators=[validators.DataRequired(
        'Please, enter book title')])
    author = QuerySelectField(query_factory=lambda: models.Author.query.all(),
                              allow_blank=True,
                              get_pk=lambda a: a.id,
                              blank_text='',
                              get_label=lambda a: a.name,
                              validators=[validators.DataRequired(
                                  'Please, select the book author')])
    year = IntegerField('Year')
    description = TextAreaField('Description')
    cover = FileField()
    cover_path = StringField()


class AuthorForm(FlaskForm):
    name = StringField('Name', validators=[
        validators.DataRequired('Please, enter author name')])
