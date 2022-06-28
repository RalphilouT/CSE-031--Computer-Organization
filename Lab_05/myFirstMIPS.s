	.data 
n:      .word 100
	.text
main: 	#la      $s0, n
		#lw      $s0, 0($s0)
		addi	$t0, $s0, 0
		subi    $t1, $t0, 1
		subi    $t2, $t1, 2
		subi    $t3, $t2, 3
		subi    $t4, $t3, 4
		subi    $t5, $t4, 5
		subi    $t6, $t5, 6
		subi    $t7, $t6, 7
		j       finish
finish:	addi    $a0, $t7, 0
		li      $v0, 1
		syscall	
		li      $v0, 10	
		syscall	
