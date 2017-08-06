# -*- encoding: utf-8 -*-

from django import forms


class LibraryForm(forms.Form):

    id = forms.IntegerField(widget=forms.HiddenInput(), required=False)

    title = forms.CharField(label=u'Título', max_length=100)

    description = forms.CharField(widget=forms.Textarea(attrs={'rows': '4'}),
                                  label=u'Descrição',
                                  max_length=500,
                                  required=False
                                  )

    status = forms.BooleanField(label='Emprestado', required=False)

    friend_name = forms.CharField(label='Amigo', max_length=100,
                                  required=False)

    friend_email = forms.EmailField(label='Email', max_length=50,
                                    required=False)
