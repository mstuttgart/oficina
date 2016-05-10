# -*- encoding: utf-8 -*-
from django.shortcuts import render_to_response, get_object_or_404
from django.template import RequestContext

from models import ItemAgenda
from forms import FormItemAgenda


def lista(request):
    # Recebe records da tabela ItemAgenda
    lista_itens = ItemAgenda.objects.all()

    # Nome do template, dict com elementos que serao repassados ao template
    return render_to_response('lista.html', {'lista_itens': lista_itens})


def adiciona(request):

    if request.method == 'POST':
        form = FormItemAgenda(request.POST, request.FILES)

        if form.is_valid():
            dados = form.cleaned_data
            item = ItemAgenda(titulo=dados['titulo'],
                              data=dados['data'],
                              hora=dados['hora'],
                              descricao=dados['descricao'])
            item.save()
            return render_to_response('salvo.html', {})

    else:
        form = FormItemAgenda()
    return render_to_response('adiciona.html', {'form': form},
                              context_instance=RequestContext(request))


def item(request, id_item):
    # pk = primary key
    item = get_object_or_404(ItemAgenda, pk=id_item)
    return render_to_response('item.html', {'item': item})
