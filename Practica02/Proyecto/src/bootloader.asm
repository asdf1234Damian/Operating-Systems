; Trabajando en 16 bits
bits 16
start:
; Mover el DS (Direction Segment) a la direccion 17c0
  mov ax, 07c0h
  mov ds, ax
; cld limpia la vandera de direccion (DF=0)
	cld
; Entra en modo TYY
  mov ah, 0Eh
; Aqui y en la linea 24 se declara el mensaje
	mov si, msg
; Comienza el ciclo, lodsb es para sacar uno por uno los caracteres de SI  a AL
.loop	lodsb
; Compara el contenido en al con un 0
	cmp al, 0
; Si el resultado es verdadero, va a done:
	je done
; Interrupcion para escribir el caracter
	int 10h
; Regresa a loop
	jmp .loop
; Se declara la cadena con el 0 al final
msg:	db 'Este no es mi primer ni ultimo hola mundo', 0
; Funcion cuando encuentra el fin de la cadena (linea 18)
done:
; Magic Numbers
times 510 - ($ - $$) db 0
dw 0xAA55
