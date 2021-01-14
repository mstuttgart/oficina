extends KinematicBody2D

const UP = Vector2(0, -1)
const GRAVITY = 20
const SPEED = 200
const JUMP_HEIGHT = -600

var motion = Vector2()
 
func _physics_process(delta): 
	
	motion.y += GRAVITY
	
	if Input.is_action_pressed("ui_right"):
		motion.x = SPEED
		$Sprite.flip_h = false
		$Sprite.play("Run")
		
	elif Input.is_action_pressed("ui_left"):
		motion.x = -SPEED
		$Sprite.flip_h = true
		$Sprite.play("Run")
	else:
		motion.x = 0
		$Sprite.play("Idle")
		 
	if is_on_floor():
		
		if Input.is_action_just_pressed("ui_up"):
			motion.y = JUMP_HEIGHT
			
	else:
		$Sprite.play("Jump")
		
	motion = move_and_slide(motion, UP)
