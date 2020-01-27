extends Panel

func _ready():
	# Conecta o sinal 'pressed' do botao a 
	# a função '_ready'
	get_node("Button").connect("pressed", self, "_on_Button_pressed")
	
	
func _on_Button_pressed():
	# Get node pega o filho imediato
	# se o nó Label fosse filho de 'Button'
	# ao invés de 'Panel' o código seria:
	# get_node("Button/Label") 
	get_node("Label").text = "Hello!"
	

