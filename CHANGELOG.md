Added folder calculator
	--> calculator.l
	--> calculator.y (specified the grammar according to what was discussed in class and declared a symbol table)
	--> Makefile
	--> negative values were identified added in the syntax
	--> expressions inside () was identified and added in the syntax
	

In the assignment2 : 
		Have created an abstract syntax tree, with the program as its root node and the other statements and declarations come as the extra nodes (similar to linked list)
		the ast only considers as of now :
			the declaration statements
			the assignment statements
			the write statements
		after every assign statements --> the symbol table would be printed like : 
			
		/*	printing symbol table values
			a = 10
			b = 20
			c = 190
		*/

		after every write statement --> the output for the particular write statement would be printed like : 

		/*
		console output : 
		20
		*/

		at the end of the interpretation : 

		the abstract syntax tree would be printed like : 


|-- program
|-- decl
  |-- integer
  |-- a [Var: a, value : 10]
  |-- b [Var: b, value : 20]
  |-- c [Var: c, value : 1]
|-- assign
  |-- a [Var: a, value : 10]
  |-- number
|-- write
|-- parameter
  |-- var_expr
    |-- a [Var: a, value : 10]
|-- assign
  |-- b [Var: b, value : 20]
  |-- number
|-- write
|-- parameter
  |-- var_expr
    |-- b [Var: b, value : 20]
|-- assign
  |-- c [Var: c, value : 1]
  |-- subtract
    |-- add
      |-- var_expr
        |-- a [Var: a, value : 10]
      |-- multiply
        |-- var_expr
          |-- b [Var: b, value : 20]
        |-- var_expr
          |-- a [Var: a, value : 10]
    |-- var_expr
      |-- b [Var: b, value : 20]
|-- write
|-- parameter
  |-- var_expr
    |-- c [Var: c, value : 1]
|-- parameter
  |-- var_expr
    |-- b [Var: b, value : 20]
|-- assign
  |-- c [Var: c, value : 1]
  |-- number
|-- write
|-- parameter
  |-- add
    |-- var_expr
      |-- c [Var: c, value : 1]
    |-- var_expr
      |-- b [Var: b, value : 20]

you can redirect the input file like : 
bin/compiler < 'file_path'

In the assignment 3 :
  added array (integer type)
  trying to write evaluate functions for the statements
  should integrate the functions with the .y file

  Added if-then and if-then-else
  started working with for loop (infinite loop issues should resolve them)

  resolved the infinite loop issues caused due to incorrect evaluate_assign 

  for loop corrected, with and without step and initial condition

  break statements included

  out of bound access error detected -- solved

  continue statements included

  





