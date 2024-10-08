# Implement a problem of activity selection problem 
# with K persons. 
# Statement: Given two arrays S[] and E[] of size N denoting starting 
# and closing time of the shops and an integer value K denoting the 
# number of people, the task is to find out the maximum number of 
# shops they can visit in total if they visit each shop optimally based 
# on the following conditions: 
#  A shop can be visited by only one person 
#  A person cannot visit another shop if its timing collide with it 
# Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2 
# Output: 4 
# Input: S[] = {1, 2, 3}, E[] = {3, 4, 5}, K = 2 
# Output: 3
s=[ 1 , 8, 3, 2, 6]
e = [5, 10, 6, 5, 9]
shops = sorted(zip(s,e))     
print(shops)
k = 2 
visited_shop = 0  
person = [0] * k
for start , end in shops:
    for i in range(k):
        if person[i] <= start:
            person[i] = end 
            visited_shop+= 1 
            break
print(visited_shop)