# FIBONACCI REMAINING



class part_a:
    def linear(self,arr,ele):
        for i in range(len(arr)):
            if arr[i]==ele:
                return i+1
        return 0 # or return -1
    
    def sentinel(self,arr,ele):
        temp = arr[len(arr)-1]
        arr[len(arr)-1] = ele
        i=0
        while arr[i] != ele:
            i+=1
        if i == len(arr) - 1:
            if(temp!=ele):
                return "not found"
        arr[len(arr) - 1] = temp
        return i+1
    
class part_b:
    def bubble(self,arr):
        for i in range(len(arr)-1):
            for j in range(len(arr)-1-i):
                if arr[j]>arr[j+1]:
                   arr[j], arr[j+1] = arr[j+1], arr[j]
        return arr
    
    def binary(self, arr, ele):
        start = 0
        end = len(arr)-1
        while(start<=end):
            mid = (start+end)//2
            if arr[mid]<ele:
                start = mid+1
            elif arr[mid]>ele:
                end = mid-1
            else:
                return (mid+1)
        return -1

n=int(input("enter no of elements"))
arr=[]
for i in range(n):
    ele=int(input("enter elements"))
    arr.append(ele)
key=int(input("enter search element"))



obja = part_a()
objb = part_b()
print(obja.linear(arr,key))
print(obja.sentinel(arr,key))
print(objb.bubble(arr.copy()))
print(objb.binary(arr.copy(),key))
