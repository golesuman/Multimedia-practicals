echo "Enter the name of the executable file"
read file_name
gcc -o  $file_name $1 -lSDL_bgi -lSDL2  
./$file_name