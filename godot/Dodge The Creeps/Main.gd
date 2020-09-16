extends Node

# Para definir o tipo de 'Mob'
export (PackedScene) var Mob
var score

# Called when the node enters the scene tree for the first time.
func _ready():
	randomize()

func game_over():
	$ScoreTimer.stop()
	$MobTimer.stop()
	$Hud.show_game_over()
	
	# Deleta todos os mobs do grupo, de modo
	# a limpar a tela
	get_tree().call_group("MobGroup", "queue_free")
	
	$Music.stop()
	$DeathSound.play()
	
func new_game():
	score = 0
	$Music.play()
	$Player.start($StartPosition.position)
	$StartTimer.start()
	$Hud.update_score(score)
	$Hud.show_message("Get Ready")


func _on_MobTimer_timeout():
	# Choose a random location on Path2D
	$MobPath/MobSpawnLocation.offset = randi()
	
	# Create a mob instance and add it to the scene
	var mob = Mob.instance()
	add_child(mob)
	
	# Set the mob direction perpendicular to the path direction
	var direction = $MobPath/MobSpawnLocation.rotation + PI / 2
	
	# Set the mob position to a random location
	mob.position = $MobPath/MobSpawnLocation.position
	
	# Add some randomness to the direction
	direction += rand_range(-PI / 4, PI / 4)
	mob.rotation = direction
	
	# Set the velocity (speed and direction)
	mob.linear_velocity = Vector2(rand_range(mob.min_speed, mob.max_speed), 0)
	mob.linear_velocity = mob.linear_velocity.rotated(direction)


func _on_ScoreTimer_timeout():
	score += 1
	$Hud.update_score(score)


func _on_StartTimer_timeout():
	$MobTimer.start()
	$ScoreTimer.start()
