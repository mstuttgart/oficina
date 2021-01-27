extends KinematicBody2D

const UP = Vector2(0, -1)
const GRAVITY = 20
const ACCELERATION = 50
const MAX_SPEED = 200
const JUMP_HEIGHT = -500

var motion = Vector2()

func _physics_process(delta): 
	
	motion.y += GRAVITY
	
	var friction = false
	
	if Input.is_action_pressed("ui_right"):
		
		# Limite horizontal speed
		motion.x = min(motion.x + ACCELERATION, MAX_SPEED)

		$Sprite.flip_h = false
		$Sprite.play("Run")
		
	elif Input.is_action_pressed("ui_left"):

		motion.x = max(motion.x - ACCELERATION, -MAX_SPEED)

		$Sprite.flip_h = true
		$Sprite.play("Run")
	else:
		friction = true
		# Interpolacao para desascelerar personagem simulando fricçao
		motion.x = lerp(motion.x, 0, 0.2)
		$Sprite.play("Idle")
		
	if is_on_floor():
		
		if Input.is_action_just_pressed("ui_up"):
			motion.y = JUMP_HEIGHT
			
		if friction == true:
			motion.x = lerp(motion.x, 0, 0.2)

	else:
		if motion.y < 0:
			$Sprite.play("Rise")
		elif motion.y == 0:
			$Sprite.play("Jump")
		else:
			$Sprite.play("Fall")
		
		if friction == true:
			motion.x = lerp(motion.x, 0, 0.05)
		
	motion = move_and_slide(motion, UP)
