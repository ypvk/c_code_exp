IF "%2" == "" (
	gcc -o %1 "%1.c"
)
IF "%2" == "g" (
	gcc -o %1 "%1.c" -g
)
