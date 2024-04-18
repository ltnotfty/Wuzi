#! /bin/bash

count_file() {
# usage: ./count_file file_list tb_name
    if [ $# -ne 2 ]; then
	    echo "args: $# not equal 2"
	    return 

    fi 
flist=$1
tname=$2


printf "$tname\n" > $tname

printf "%-20s %-10s %-10s %-10s %-10s\n" "file" "chars" "words" "lines" "bytes" >> $tname 


for s_file in $flist
do
    wc -m -w -l -c $s_file | awk '{printf "%-20s %-10s %-10s %-10s %-10s\n",$5,$3,$2,$1,$4 }' >> $tname 
done


printf "%-20s" "${tname}" >>  $tname

awk 'NR > 1 && $2 != "" { c2 += $2;c3 += $3;c4 += $4;c5 += $5;} 
END {printf "%-10s %-10s %-10d %-10d\n",c2,c3,c4,c5}' $tname  >> $tname 

}



#SRC_FILES=`ls -lR | awk '$9 ~ /.+\.(c|cpp)$/ {print $9}'`
SRC_FILES=`find ./ -regextype egrep -regex ".*\.(c|cpp)$"`
#HEADER_FILES=`ls -lR | awk '$9 ~ /.+\.h$/ {print $9}'`
HEADER_FILES=`find ./ -regextype egrep -regex ".*\.h"`


src_name="src_stat"
hrd_name="hrd_stat"
tot_name="tot_stat"

tmp_file=()
tmp_file+=($src_name)
tmp_file+=($hrd_name)
tmp_file+=($tot_name)

count_file "${SRC_FILES}"  $src_name
count_file "${HEADER_FILES}" $hrd_name


#printf "%-20s %-10s %-10s %-10s %-10s\n" "file" "chars" "words" "lines" "bytes" >> $tot_name
sed -n '2p' $src_name > $tot_name

sed -n '$p' $src_name >> $tot_name
sed -n '$p' $hrd_name >> $tot_name
printf "%-20s" "$tot_name" >> $tot_name

awk 'NR > 1 {c2 += $2;c3 += $3; c4 += $4; c5 += $5;} 
END {printf "%-10d %-10d %-10d %-10d\n",c2,c3,c4,c5}' $tot_name  >> $tot_name 


cat $tot_name


rm ${tmp_file[@]}

