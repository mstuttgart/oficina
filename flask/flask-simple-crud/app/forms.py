from flask_wtf import FlaskForm
from wtforms import TextField, IntegerField, TextAreaField
from wtforms import validators, ValidationError


class BookForm(FlaskForm):
    title = TextField('Title', validators=[validators.DataRequired('Please, enter book title')])
    year = IntegerField('Year')
    description = TextAreaField('Description')
