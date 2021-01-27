extends Area2D
signal hit

export var speed = 400 # How fast the player will move (pixels/sec).
var screen_size # Size of the game window.



# Called when the node enters the scene tree for the first time.
func _ready():
	screen_size = get_viewport_rect().size
	hide()


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	var velocity = Vector2() # the player1s movement vector

	if Input.is_action_pressed("ui_right"):
		velocity.x += 1

	if Input.is_action_pressed("ui_left"):
		velocity.x -= 1

	if Input.is_action_pressed("ui_down"):
		velocity.y += 1

	if Input.is_action_pressed("ui_up"):
		velocity.y -= 1

	if velocity.length() > 0:
		velocity = velocity.normalized() * speed

		# $ returns the node at the relative path from the current node
		$AnimatedSprite.play()
	else:
		$AnimatedSprite.stop()

	# delta: frame lenght - the amount of time tha the previous
	# frame took to complete
	position += velocity * delta

	# clamp:  restricting a value in to a given range
	position.x = clamp(position.x, 0, screen_size.x)
	position.y = clamp(position.y, 0, screen_size.y)

	if velocity.x != 0:
		$AnimatedSprite.animation = "walk"
		$AnimatedSprite.flip_v = false
		$AnimatedSprite.flip_h = velocity.x < 0

	elif velocity.y != 0:
		$AnimatedSprite.animation = "up"
		$AnimatedSprite.flip_h = false
		$AnimatedSprite.flip_v = velocity.y > 0


func _on_Player_body_entered(body):
	hide() # Player disappears after being hit.
	emit_signal("hit")

	# Disable collisionm after player hit
	$CollisionShape2D.set_deferred("disable", true)

func start(pos):
	position = pos
	show()
	$CollisionShape2D.disabled = false
