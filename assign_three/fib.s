	THUMB
	AREA array, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY
__main  FUNCTION
	MOV R8, #10 ;'n' numbers of the Fibonacci series

	MOV R5, #0 ;first number in the Fibonacci series
	MOV R6, #1 ;second number in the Fibonacci series
	
loop MOV R0, R5
	BL printMsg
	ADD R7, R5, R6
	MOV R5, R6
	MOV R6, R7
	SUB R8, R8, #1 ;decrementing counter
	CMP R8, #0
	BNE loop ;looping until every array element has been considered
stop B stop ;stop program
	ENDFUNC
	END 