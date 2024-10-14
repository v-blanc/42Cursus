# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_libft.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 16:47:10 by vblanc            #+#    #+#              #
#    Updated: 2024/10/14 14:36:53 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m'

echo "=================== Testing libft ===================\n"

make fclean > /dev/null
make > /dev/null
rm -rf results/summary.txt > /dev/null
touch results/summary.txt > /dev/null

for file in bin/*; do
    basename_file=$(basename $file _exec)
    echo "> Testing $BLUE$basename_file$NC"
    output_user_file=${basename_file}_output.txt
    output_ref_file="${basename_file##ft_}_output.txt"
    result_file="res_${basename_file##ft_}"
    ./$file > output_user/$output_user_file
    diff -U 100 output_ref/$output_ref_file output_user/$output_user_file > results/$result_file
    if [ ! -s results/$result_file ]; then
        echo "$GREEN  Diff OK$NC"
    else
        echo "$RED  Diff KO$NC"
        echo "=================== $basename_file ===================\n" >> results/summary.txt
        cat results/$result_file >> results/summary.txt
        echo "\n" >> results/summary.txt
    fi
done
