	THUMB
	AREA largest, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY
__main  FUNCTION
	MOV R0, #0x20000000 ;memory location corresponding to the first number
	
	MOV R1, #0x00000001 ;first number
	MOV R2, #0x00000007 ;second number
	MOV R3, #0x00000002 ;third number
	
	STR R1, [R0]
	STR R2, [R0, #0x00000004]
	STR R3, [R0, #0x00000008]

	;successive memory location 4 bytes away, since memory is byte-addressable

	LDR R4, [R0]
	LDR R5, [R0, #0x00000004]
	LDR R6, [R0, #0x00000008]
	
	CMP R4, R5
	ITE GE
	MOVGE R7, R4 ;if the first number is greater than the second number, the largest number so far will be the first number
	MOVLT R7, R5 ;if the first number is lesser than or equal to the second number, the largest number so far will be the second number
	
	CMP R7, R6
	ITE GE
	MOVGE R8, R7 ;if the largest number so far is greater than the third number, the largest number so far will be the largest of the three numbers 
	MOVLT R8, R6 ;if the largest number so far is lesser than or equal to the third number, the third number will be the largest of the three numbers 
	
	MOV R0, R8 ;the largest of the three numbers
	
	BL printMsg
stop B stop ;stop program
	ENDFUNC
	END 