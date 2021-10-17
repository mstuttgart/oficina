# -*- encoding: utf-8 -*-
from django.shortcuts import render, get_object_or_404
from django.conf import settings
from django.contrib.auth.decorators import login_required
from models import ItemAgenda
from forms import FormItemAgenda

@login_required
def lista(request):
    # Recebe records da tabela ItemAgenda
    lista_itens = ItemAgenda.objects.filter(usuario=request.user)

    # Nome do template, dict com elementos que serao repassados ao template
    return render(request, 'lista.html', {
        'lista_itens': lista_itens,
        })

@login_required
def adiciona(request):

    if request.method == 'POST':
        form = FormItemAgenda(request.POST, request.FILES)

        if form.is_valid():
            item = form.save(commit=False)
            item.usuario = request.user
            item.save()
            return render(request, 'salvo.html', {'form': form})

    else:
        form = FormItemAgenda()
    return render(request, 'adiciona.html', {'form': form})

@login_required
def remove(request, id_item):
    # pk = primary key
    item = get_object_or_404(ItemAgenda, pk=id_item, usuario=request.user)
    if request.method == 'POST':
        item.delete()
        return render(request, 'removido.html', {})
    return render(request, 'remove.html', {'item': item})

@login_required
def item(request, id_item):
    # pk = primary key
    item = get_object_or_404(ItemAgenda, pk=id_item, usuario=request.user)
    if request.method == 'POST':
        form = FormItemAgenda(request.POST, request.FILES, instance=item)
        if form.is_valid():
            item = form.save(commit=False)
            item.usuario = request.user
            item.save()
            return render(request, 'salvo.html', {})
    else:
        form = FormItemAgenda(instance=item)
    return render(request, 'item.html', {'form': form})
