'''

Q). Consider telephone book database of N clients. Make use of a hash table implementation
to quickly look up client's telephone number. Make use of two collision handling
techniques and compare them using number of comparisons required to find a set of
telephone numbers

'''


def linearProbing(hashTableSize):
    #here we are using hashFunction : F(h) = key*key mod sizeOfHashTable (Size of DataBase rounded off at tenth place)
    highestProbing = 1
    print("-----------------------------------------------------------------------------")
    print("Number of collisions for Linear Probing")
    for key in dataBase.keys():
        counter=1
        hashFunction = i**2%hashTableSize
        if hashTableForLinearProbing[hashFunction] == -1:
            hashTableForLinearProbing[hashFunction]=dataBase[key]
        else:
            print(f"The collision is occured for the phone number {key}")
            counter+=1
            k = hashFunction + 1
            while(1):
                if k>hashTableSize-1:
                    k = 0
                if hashTableForLinearProbing[k] == -1:
                    hashTableForLinearProbing[k] = dataBase[key]
                    break
                else:
                    counter+=1
                    k+=1
            if counter>highestProbing:
                highestProbing = counter

    print("The hashTable for Linear Probing is created!!")
    print("-----------------------------------------------------------------------------")
    print(hashTableForLinearProbing)
    print("-----------------------------------------------------------------------------")
    print()
    return highestProbing

def doubleHasingTechnique(sizeOfHashTable):
    #here were are using 2 hash functions f(h1) = key mod sizeOfHashTable,  f(h2) = (70*sizeOfDatabase)/100 - (key mod sizeOfDatabase)*(70*sizeOfDatabase)/100
    print("-----------------------------------------------------------------------------")
    print("Number of collision for Double Hashing Technique")
    highestProbing = 1
    for key in dataBase.keys():
        counter = 0
        hashFunction1 = key%sizeOfHashTable
        if hashTableForDoubleHashingTechnique[hashFunction1] == -1:
            hashTableForDoubleHashingTechnique[hashFunction1] = dataBase[key]
        else:
            counter+=1
            print(f"The collision is occured for the phone number {key}")
            k = (70*sizeOfHashTable)//100
            hashFunction2 = k-(key%k)
            hashFunction = (hashFunction1 + (counter*hashFunction2))%sizeOfHashTable
            while(1):
                if hashTableForDoubleHashingTechnique[hashFunction] == -1:
                    hashTableForDoubleHashingTechnique[hashFunction] = dataBase[key]
                    break
                else:
                    counter+=1
                    hashFunction = (hashFunction1 + (counter*hashFunction2))%sizeOfHashTable

            if counter>highestProbing:
                highestProbing=counter
    print("The hashTable for Double Hashing Technique is created!!")
    print("-----------------------------------------------------------------------------")
    print(hashTableForDoubleHashingTechnique)
    print("-----------------------------------------------------------------------------")
    print()
    return highestProbing

def searchInLinearProbing(key,hashTableSize):
    probing = 1
    hashFunction = key ** 2 % hashTableSize
    if hashTableForLinearProbing[hashFunction] == dataBase[key]:
        print(f"Phone number found name of the person {dataBase[key]} by using Linear Probing ")
        print()
        return probing
    else:
        k = hashFunction + 1
        while (1):
            if probing>hashTableSize+1:
                print("key not found")
                return 0
            if k > hashTableSize-1:
                k = 0
            if hashTableForLinearProbing[k] == dataBase[key]:
                print(f"Phone number found name of the person {dataBase[key]} by using Linear Probing")
                print()
                return probing
            else:
                probing +=1
                k += 1

def searchInDoubleHasingTechnique(key,sizeOfHashTable):
    counter = 0 #counter is the number of collosion we hit
    hashFunction1 = key % sizeOfHashTable
    if hashTableForDoubleHashingTechnique[hashFunction1] == dataBase[key]:
        print(f"Phone number found name of the person {dataBase[key]} by using Double Hashing Technique")
        print()
        return counter+1# number of collision hit + 1 = number of probing
    else:
        counter+=1
        k = (70 * sizeOfHashTable) // 100
        hashFunction2 = k - (key % k)
        hashFunction = (hashFunction1 + (counter * hashFunction2)) % sizeOfHashTable
        while (1):
            if counter>sizeOfHashTable+1:
                print("Key not found!!")
                return 0
            if hashTableForDoubleHashingTechnique[hashFunction] == dataBase[key]:
                print(f"Phone number found name of the person {dataBase[key]} by using Double Hashing Technique")
                print()
                return counter+1
            else:
                counter += 1
                hashFunction = (hashFunction1 + (counter * hashFunction2)) % sizeOfHashTable


dataBase={}
sizeOfDataBase=int(input("Enter the size of database: "))

for i in range(sizeOfDataBase):
    name=input(f"Enter the name of {i+1}th person: ")
    phoneNumber=int(input(f"Enter the phone number of Mr./Ms. {name}: "))
    dataBase[phoneNumber] = name

print("Alright the dataBase is created!!")
print()
print()

hashTableForLinearProbing = []
hashTableSizeForLinerProbing = (10 - (sizeOfDataBase % 10)) + sizeOfDataBase
hashTableForLinearProbing.extend(-1 for i in range(hashTableSizeForLinerProbing))

hashTableForDoubleHashingTechnique = []
hashTableSizeForDoubleHashingTechnique = (10 - (sizeOfDataBase % 10)) + sizeOfDataBase
hashTableForDoubleHashingTechnique.extend(-1 for i in range(hashTableSizeForDoubleHashingTechnique))


#here we are using linear Probing as well as Double hasing technique and will compair each of them

linearProbing(hashTableSizeForLinerProbing)
doubleHasingTechnique(hashTableSizeForDoubleHashingTechnique)

key = int(input("Enter the phone number of person you want to find: "))

countOfProbsInLinerProbing=searchInLinearProbing(key,hashTableSizeForLinerProbing)
countOfProbsInDoubleHashingTechnique=searchInDoubleHasingTechnique(key,hashTableSizeForDoubleHashingTechnique)

print(f"Number of probs in Linear Probing : {countOfProbsInLinerProbing}")
print(f"Number of probs in Double Hashing Technique : {countOfProbsInDoubleHashingTechnique}")