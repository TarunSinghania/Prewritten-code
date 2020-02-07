Group 1 precedence, no associativity
Scope resolution	::

Group 2 precedence, left to right associativity
Member selection (object or pointer)	. or –>
Array subscript	[ ]
Function call	( )
Postfix increment	++
Postfix decrement	––
Type name	typeid( )
Constant type conversion	const_cast
Dynamic type conversion	dynamic_cast
Reinterpreted type conversion	reinterpret_cast
Static type conversion	static_cast

Group 3 precedence, right to left associativity
Size of object or type	sizeof
Prefix increment	++
Prefix decrement	––
One's complement	~
Logical not	!
Unary negation	-
Unary plus	+
Address-of	&
Indirection	*
Create object	new
Destroy object	delete
Cast	Cast: ()

Group 4 precedence, left to right associativity
Pointer-to-member (objects or pointers)	.* or –>*

Group 5 precedence, left to right associativity
Multiplication	*
Division	/
Modulus	%
Group 6 precedence, left to right associativity
Addition	+
Subtraction	–
Group 7 precedence, left to right associativity
Left shift	<<
Right shift	>>
Group 8 precedence, left to right associativity
Less than	<
Greater than	>
Less than or equal to	<=
Greater than or equal to	>=
Group 9 precedence, left to right associativity
Equality	==
Inequality	!=
Group 10 precedence left to right associativity
Bitwise AND	&
Group 11 precedence, left to right associativity
Bitwise exclusive OR	^
Group 12 precedence, left to right associativity
Bitwise inclusive OR	&#124;
Group 13 precedence, left to right associativity
Logical AND	&&
Group 14 precedence, left to right associativity
Logical OR	&#124;&#124;
Group 15 precedence, right to left associativity
Conditional	? :
Group 16 precedence, right to left associativity
Assignment	=
Multiplication assignment	*=
Division assignment	/=
Modulus assignment	%=
Addition assignment	+=
Subtraction assignment	–=
Left-shift assignment	<<=
Right-shift assignment	>>=
Bitwise AND assignment	&=
Bitwise inclusive OR assignment	&#124;=
Bitwise exclusive OR assignment	^=
Group 17 precedence, right to left associativity
throw expression	throw
Group 18 precedence, left to right associativity
Comma	,