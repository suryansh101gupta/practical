# SHELL SORT REMAINING



class partb():
    def selection(self,arr):
        for i in range(len(arr)-1):
            temp=i
            for j in range(i+1,len(arr)):
                if arr[j]<arr[temp]:
                    temp=j
                arr[i],arr[temp]=arr[temp],arr[i]
        return arr
    
    def insertion(self,arr):
        for i in range(1,len(arr)):
            temp = arr[i]
            j=i-1
            while(j>=0):
                if temp<arr[j]:
                    arr[j+1]=arr[j]
                else:
                    break
                j-=1
            arr[j+1]=temp
        return arr

n=int(input("enter no of elements"))
arr=[]
for i in range(n):
    ele=int(input("enter elements"))
    arr.append(ele)
key=int(input("enter search element"))



objb = partb()
print(objb.insertion(arr))
print(objb.selection(arr))
    
                





