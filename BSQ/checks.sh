norminette -R CheckForbiddenSourceHeader | grep -e '^(Error|Warning)'
norminette | grep -e '^(Error|Warning)'
cat ./*/*.c | grep printf
cat ./*/*.c | grep stdio
cat ./*/*.c | grep "for"
cat ./*/*.c | grep "do"
