echo "Enter a number:"
read n
sum=0
while((n>0))
do
    mod=$((n%10))
    sum=$((sum+mod))
    n=$((n/10))
done    
echo "Sum="$sum