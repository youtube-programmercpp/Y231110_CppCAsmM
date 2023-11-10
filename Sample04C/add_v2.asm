; x64 用アセンブリ言語サンプルプログラム
; int add_v2(int a, int b, int c, int d, int e, int f);
;
; 《スタックフレーム》
; 0000  戻り先アドレス <--- RSP
; 0008  第１引数 a 用の領域
; 0010  第２引数 b 用の領域
; 0018  第３引数 c 用の領域
; 0020  第４引数 d 用の領域
; 0028  第５引数 e
; 0030  第６引数 f

PUBLIC add_v2
_TEXT  SEGMENT
add_v2 PROC
	   mov eax, ecx                  ; EAX←    第１引数 a
	   add eax, edx                  ; ECX←ECX+第２引数 b
	   add eax, r8d                  ; ECX←ECX+第３引数 c
	   add eax, r9d                  ; ECX←ECX+第４引数 d
	   add eax, dword ptr [rsp+28h]  ; EAX←EAX+第５引数 e
	   add eax, dword ptr [rsp+30h]  ; EAX←EAX+第６引数 f
	   ret                           ; 呼び出し元に戻る
add_v2 ENDP
_TEXT  ENDS
       END
