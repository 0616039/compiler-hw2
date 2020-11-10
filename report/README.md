# 作業2 報告

學生 : 陸顗文  
學號 : 0616039 

+ HW2 是要寫出一個P語言的LALR(1)的parser   

+ 先宣告從lex return 回來的token   
首先寫出program 架構
> identifier; 
   
+ program body  
> <zero or more variable and constant declaration>
>  <zero or more function declaration>
>  <one compound statement>    
>  end identifier

+ data  
1. variable    
> var identifier_list: scalar_type;    
>  var identifier_list: array integer_constant to integer_constant of type;  
2. constant  
> var identifier_list: literal_constant;  

+ function  
>  identifier (<zero or more formal arguments>): scalar_type;
> <one compound statement>  
> end identifier   
 + arguments  
 >  identifier_list: type  
 + ideenterfier_list
 > identifier, identifier, ..., identifier
+ statement  
+ compound  
> begin  
> <zero or more variable and constant declaration>  
> <zero or more statements>  
> end  
+  simple  
> 1.variable_reference := expression;  
> 2.print variable_reference; or print expression;  
> 3.read variable_reference;
+ condition  
> 1. if expression then  
> <zero or more statements>  
> else  
> <zero or more statements>  
> end if  
> 2. if exprression then <zero or more statements> end if    
+ while  
> while expression do  
> <zero or more statements>  
> end do  
+ for  
>  for identifier := integer_constant to integer_constant do  
> <zero or more statements>  
> end do   
+ return  
> return expression ;  
+ function invocation  
> identifier (<expressions separated by zero or more comma>) ;  

+ expressions

|| Operator |  
|---|---|  
| negative | **`-`** |  
| addition | **`+`** |  
| subtraction | **`-`** |  
| multiplication | **`*`** |  
| division | **`/`**, **`mod`** |  
| relational | **`<`**, **`<=`**, **`<>`**, **`>=`**, **`>`**, **`=`** |  
| logical | **`and`**, **`or`**, **`not`** |    

  
+  先使用 yacc -d parser.y 就可以產生 y.tab.c，可以放在lex中做使用  
