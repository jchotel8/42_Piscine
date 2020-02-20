cat /etc/passwd |grep -v "\#" |awk "NR%2==0"|rev| cut -d ':' -f7 | awk 'NR>='$FT_LINE1' && NR<='$FT_LINE2''| tr "\n" "," | sed 's/,/, /g'|sed 's/$/./'|tr -d '\n'
