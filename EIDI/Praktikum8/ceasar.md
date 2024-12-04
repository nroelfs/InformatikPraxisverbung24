# Chiffre einfach

```
; Caesar Chiffre
JMP start

offset:     DB 4
plaintext:  DB "Hello World!"
            DB 0 ; String terminator
ciphertext: DB 0 ; Platz für das verschlüsselte Ergebnis

start:
	MOV C, plaintext    ; Point to var
	MOV D, 232	; Point to output
	CALL print
        HLT             ; Stop execution

print:			; print(C:*from, D:*to)
	PUSH A
	PUSH B
	MOV B, 0
.loop:
	MOV A, [C]	; Get char from var
	ADD A, [offset]	;
	MOV [D], A	; Write to output
	INC C
	INC D
	CMP B, [C]	; Check if end
	JNZ .loop	; jump if not

	POP B
	POP A
	RET

```


# Chiffre Anders

```
; Caesar Chiffre
start:
	MOV C, plaintext    ; Point to var
	MOV D, 232	; Point to output
	CALL print
        HLT             ; Stop execution

print:			; print(C:*from, D:*to)
	PUSH A
	PUSH B
	MOV B, 0
.loop:
	MOV A, [C]	; Get char from var
	ADD A, [offset]	;
	CMP A, 90
	JA .CAP;
	CMP A, 122;
	JA .CAP2;
.out:
	MOV [D], A	; Write to output
	INC C
	INC D
	CMP B, [C]	; Check if end
	JNZ .loop	; jump if not

	POP B
	POP A
	RET

.CAP: 
	CMP A, 97
	JB .CAP2;
	JMP .out

.CAP2:
	SUB A, [res]
	JMP .out

offset: DB 4
res: 	DB 25
plaintext:  DB "Hello World!"
            DB 0 
ciphertext: DB 0 
```
