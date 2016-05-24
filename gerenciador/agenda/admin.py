from django.contrib import admin

from agenda.models import ItemAgenda

class ItemAgendaAdmin(admin.ModelAdmin):
    fields = ('titulo', 'data', 'hora', 'descricao')
    list_display = ('titulo', 'data', 'hora')

    def save_model(self, request, obj, form, change):
        obj.usuario = request.user
        obj.save()

    def queryset(self, request):
        qs = super(ItemAgendaAdmin, self).queryset(request)
        return qs.filter(usuario=request.user)

# Register your models here.
admin.site.register(ItemAgenda, ItemAgendaAdmin)
