ARG="1 2 3"; ./push_swap $ARG | ./checker_linux $ARG | tr '\n' ' ' 
ARG="1 2 3"; ./push_swap $ARG | wc -l  
echo "$ARG\n"

ARG="1 3 2"; ./push_swap $ARG | ./checker_linux $ARG | tr '\n' ' ' 
ARG="1 3 2"; ./push_swap $ARG | wc -l  
echo "$ARG\n"

ARG="2 1 3"; ./push_swap $ARG | ./checker_linux $ARG | tr '\n' ' ' 
ARG="2 1 3"; ./push_swap $ARG | wc -l  
echo "$ARG\n"

ARG="2 3 1"; ./push_swap $ARG | ./checker_linux $ARG | tr '\n' ' ' 
ARG="2 3 1"; ./push_swap $ARG | wc -l  
echo "$ARG\n"

ARG="3 1 2"; ./push_swap $ARG | ./checker_linux $ARG | tr '\n' ' ' 
ARG="3 1 2"; ./push_swap $ARG | wc -l  
echo "$ARG\n"

ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG | tr '\n' ' ' 
ARG="3 2 1"; ./push_swap $ARG | wc -l  
echo "$ARG\n"







