	THUMB
	AREA array, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY
__main  FUNCTION
	MOV R0, #0x20000000 ;memory location corresponding to the first array element
	
	MOV R1, #2 ;first array element
	MOV R2, #7 ;second array element
	MOV R3, #3 ;third array element
	MOV R4, #8 ;fourth array element
	MOV R5, #6 ;fifth array element
	
	MOV R6, #5 ;counter is equal to the size of the array, which is known beforehand

	STR R1, [R0]
	STR R2, [R0, #4]
	STR R3, [R0, #8]
	STR R4, [R0, #0xC]
	STR R5, [R0, #0x10]
	;array elements are stored in contiguous memory locations, successive memory location is 4 bytes away, since memory is byte-addressable
	
loop LDR R7, [R0]
	TST R7, #1 ;AND operation checks whether the number is odd or even, LSB is one if number is odd
	BNE here ;not incrementing counter if the number is odd
	ADD R8, R8, #1 ;incrementing counter
here ADD R0, R0, #4 ;pointing to the next array element
	SUB R6, R6, #1 ;decrementing counter
	CMP R6, #0
	BNE loop ;looping until every array element has been considered

	MOV R0, R8 ;the largest array element
	
	BL printMsg
stop B stop ;stop program
	ENDFUNC
	END 