	THUMB
	AREA factorial, CODE, READONLY
	EXPORT __main
	ENTRY 
__main FUNCTION
	MOV r1, #5 ;load n into r1
	MOV r2, #1 ;if n = 0, at least n! = 1
loop CMP r1, #0
	MULGT r2, r1, r2
	SUBGT r1, r1, #1 ;decrement n
	BGT loop ;do another mul if counter != 0
stop B stop ;stop program
	ENDFUNC
	END 