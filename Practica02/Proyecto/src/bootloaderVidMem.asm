; Trabajando en 16 bits
bits 16
start:
; Mover el DS (Direction Segment) a la direccion 17c0
  mov ax, 07c0h
  mov ds, ax
; Se usa el ES (Extra Segment) a la direccion de video
  mov ax,0xb800
  mov es,ax
;Se declara el mensaje y se guarda la direccion del mismo en SI
  mov si, msg
;Movemos el DI a la direccion para la esquina superior izquierda
  mov di,0x0
; Comienza el ciclo
.loop
  mov al,[si]    ; se carga el byte del caracter
  mov ah,0x0f    ; se carga el byte de la configuracion
  mov [es:di],ax ; se carga el registro de al y ah (ax)a la direccion correspondiente
  inc si         ; siguiente caracter
  add di,2       ; se le suma 2 la direccion (1 por el caracter y otro por la configuracion)
  cmp al,0       ; Compara el contenido con un 0
  je done        ; Si es verdadero, se va a done:
  jmp .loop      ; Repite el ciclo

  ; Se declara la cadena con el 0 al final
msg:	db 'Directo a la memoria :)', 0
  ; Funcion cuando encuentra el fin de la cadena (linea 18)
done:
  ; Magic Numbers
  times 510 - ($ - $$) db 0
  dw 0xAA55
