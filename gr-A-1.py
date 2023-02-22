#linear probing method   hashfunction= i*i mod 10

keys=[]
while(1):
    n=int(input("Enter the size of database(must be less than 10): "))
    if(n>10):
        print("An error occurred please enter the size less than or equal to 10 \n")
    else:
        break

for i in range(n):
    temp=int(input(f"Enter the {i+1}th phone number: "))
    keys.append(temp)

hashtable=[]
hashtable.extend(-1 for i in range(10))

for i in range(n):
    hashfunc=(keys[i]*keys[i])%10
    if hashtable[hashfunc] == -1:
        hashtable[hashfunc] = keys[i]
    else:
        print(f"Collision occurred at {hashfunc}")
        k=hashfunc+1
        if k>9:
            k=0
        if hashtable[k] == -1:
            hashtable[k] = keys[i]
        else:
            k=k+1

print("keys are",end=" ")
print(keys)
print("hashtable = ",end=" " )
print(hashtable)