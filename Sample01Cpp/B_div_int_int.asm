; x64 用アセンブリ言語サンプルプログラム
; セミコロン以降は行末までコメントとなる
; namespace B {
; 	int div(int a, int b)
; 	{
; 		return a / b;
; 	}
; }
_TEXT           SEGMENT             ; プログラムコード用セグメント開始(TEXTセグメント)
PUBLIC          ?div@B@@YAHHH@Z     ; ?div@B@@YAHHH@Z を public にする
?div@B@@YAHHH@Z PROC              ; ?div@B@@YAHHH@Z 手続きの記述開始
	            MOV  EAX, ECX       ; 転送 EAX             ←第1引数(ECX)
	            MOV  ECX, EDX       ; 転送 ECX             ←第2引数(EDX)
	            CDQ                 ; 変換 EDX:EAX         ←EAX(符号拡張付き)
	            IDIV ECX            ; 演算 EAX(商), EDX(余)←EDX:EAX÷ECX
	            RET                 ; 呼び出し元に戻る
?div@B@@YAHHH@Z ENDP              ; ?div@B@@YAHHH@Z 手続きの記述終了
_TEXT           ENDS                ; プログラムコード用セグメント終了
	            END                 ; プログラム記述終了
