'''


Q). To create ADT that implement the "set" concept.

a. Add (new Element) -Place a value into the set , 
b. Remove (element) Remove the value  
c. Contains (element) Return true if element is in collection, 
d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection, 
e. Intersection of two sets , 
f. Union of two sets, 
g. Difference between two sets, 
h. Subset


'''


class ADT_SET:
    def __init__(self,_list1,_list2):
        self.list_1 = _list1
        self.list_2 = _list2

    def addNewelement(self,_element):
        list1.append(_element)
        print(f"Element {_element} is Added")

    def removeElement(self,_element):
        if _element not in list1:
            print("Element is not Prenset")
        else:
            list1.remove(_element)

    def isPresent(self,_element):
        if _element in list1:
            print(f"Element {_element} is present")
        else:
            print(f"Element {_element} is not present")

    def size(_element):
        print(f"Size of the ADT_SET is {len(list1)}")

    def interSection(self):
        intersection = list(set(list1) & set(list2))
        print(f"The intersection of two list is {intersection}")

    def union(self):
        uni = list(set(list1) | set(list2))
        print(f"The Union of two list is {uni}")

    def difference(self):
        diff = list(set(list1) - set(list2))
        print(f"The Difference of two list is {diff}")

    def subSets(self):
        lists = [[]]
        newList = list1
        newList=set(newList)
        newList = list(newList)
        for i in range(len(newList) + 1):
            for j in range(i):
                lists.append(newList[j: i])
        print(lists)



list1 = [2,3,4,5,1,5,2,3,3,3,3]
list2 = [3,4,2,1,4,54,3,2,1,3]

my_set = ADT_SET(list1,list2)
my_set.addNewelement(6)
my_set.subSets()