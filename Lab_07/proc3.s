		.data
x:		.word 5
y:		.word 10
z:		.word 15

		.text
main:		la $t0, x
		lw $s0, 0($t0)
		la $t0, y
		lw $s1, 0($t0)
		la $t0, z
		lw $s2, 0($t0)
		#addi $sp, $sp -28
		addi $sp, $sp -12
		sw $s0, 0($sp)
		sw $s1, 4($sp)
		sw $s2, 8($sp)
		add $a0, $zero, $s0
		add $a1, $zero, $s1
		add $a2, $zero, $s2
		jal foo
		lw $s0, 0($sp)
		lw $s1, 4($sp)
		lw $s2, 8($sp)
		addi $sp, $sp 12
		add $s3, $s0,$s1
		add $s3, $s3,$s2
		add $a0, $s3,$v0
		li $v0, 1		 
		syscall
		j finish

foo:		add $t0, $a0, $a1
		add $t1, $a1, $a2
		add $t2, $a2, $a0
		addi $sp, $sp -24
		#sw $ra, 12($sp)
		#sw $a0, 16($sp)
		#sw $a1, 20($sp)
		#sw $a2, 24($sp)
		sw $ra, 0($sp)
		sw $a0, 4($sp)
		sw $a1, 8($sp)
		sw $a2, 12($sp)
		sw $s0, 16($sp)
		sw $s0, 20($sp)
		add $a0, $zero, $t0
		add $a1, $zero, $t1
		add $a2, $zero, $t2
		jal bar
		move $s0,$v0
		#lw $a0, 16($sp)
		#lw $a1, 20($sp)
		#lw $a2, 24($sp)
		lw $a0, 4($sp)
		lw $a1, 8($sp)
		lw $a2, 12($sp)
		
		sub $t0, $a0, $a2
		sub $t1, $a1, $a0
		add $t2, $a1, $a1
		add $a0, $zero, $t0
		add $a1, $zero, $t1
		add $a2, $zero, $t2
		jal bar
		move $s1,$v0
		add $v0, $s1, $s0
		#lw $ra, 12($sp)
		lw $ra, 0($sp)
		lw $s0, 16($sp)
		lw $s1, 20($sp)
		addi $sp, $sp 24
		jr $ra

bar:		sub $v0, $a2, $a0
		sllv $v0, $v0,$a1
		
		jr $ra
		

finish:	
