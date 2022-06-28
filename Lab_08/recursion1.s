        .data

# TPS 2 #3 (input prompt to be displayed)
str: .asciiz "Please enter an integer: "

        .text
main:		addi $sp, $sp, -4
 		la $a0,str
		li $v0,4
		syscall
		li $v0,5
		syscall
		move $s0,$v0
		#add $v0, $0,$0
		move $a0,$s0
		sw $s0, 0($sp)
		jal recursion
		move $a0,$v0
		li $v0,1
		lw $s0, 0($sp)
		syscall
		j end

recursion:	addi $sp, $sp, -12
		#sw $t1, 4($sp)
		sw $ra, 8($sp)
		addi $t0, $a0, -10
		bne $t0, $zero, not_ten
		addi $v0, $zero,2
		j end_recur

not_ten:	addi $t0, $a0, -11
		bne $t0, $zero, not_eleven
		addi $v0, $zero,1
		j end_recur

not_eleven:	sw $a0, 4($sp)
		addi $a0,$a0,2
		jal recursion
		lw $a0, 4($sp)
		add $v0, $v0,$a0
		sw $v0, 0($sp)
		addi $a0,$a0,1
		jal recursion
		lw $t0, 0($sp)
		add $v0, $t0, $v0 
		j end_recur

end_recur:	#lw $t1, 4($sp)
		lw $ra, 8($sp)
		addi $sp, $sp, 12	
		jr $ra

end:		addi $sp, $sp 4	
		li $v0, 10 
		syscall
