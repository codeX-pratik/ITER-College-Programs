echo Enter the first number!
read a
echo Enter the second number!
read b
echo Sum : `echo $a + $b | bc`
echo Difference : `echo $a - $b | bc`
echo Product : `echo $a \* $b | bc`
echo Quotient : `echo $a / $b | bc`
echo Remainder : `echo $a % $b | bc`