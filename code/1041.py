

sumlist = []


n = int(input())

number = list(map(int , input().split()))

sumnum = 0


#get max

#first
sumlist.append(min(number))

#second
second_sum = []
for i in range(0 ,5):
    for j in range(i+1,6):
        second_sum.append(number[i]+number[j])
second_sum.remove(number[0] + number[5])
second_sum.remove(number[1] + number[4])
second_sum.remove(number[2] + number[3])
#
sumlist.append(min(second_sum))

#third
third_sum = []

third_sum.append(number[0] + number[1] + number[2])
third_sum.append(number[0] + number[2] + number[4])
third_sum.append(number[0] + number[4] + number[3])
third_sum.append(number[0] + number[3] + number[1])
third_sum.append(number[1] + number[5] + number[2])
third_sum.append(number[1] + number[3] + number[5])
third_sum.append(number[5] + number[4] + number[2]) 
third_sum.append(number[5] + number[4] + number[3])


#
sumlist.append(min(third_sum))


#####




if n == 1:
    a = max(number)
    sumnum += sum(number) - a

else :
    sumnum += sumlist[0] * ((n-2)*(n-2)*5 + (n-2)*4 )
    sumnum += sumlist[1] * (4+ (n-2)*8)
    sumnum += sumlist[2] * 4


print(sumnum)
