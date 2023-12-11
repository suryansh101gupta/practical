class String:
    def __init__(self):
        inp = (input("enter sentence : "))
        self.inp = inp
        self.num = self.length(inp)
        self.list = self.word_list()

    def length(self,s):
        count = 0
        for i in s:
            count+=1
        return count
    
    def word_list(self):
        l1 = []
        word = str()
        for i in range(0,self.num):
            if self.inp[i] == " ":
                l1.append(word)
                word = str()
            else:
                word +=self.inp[i]
                if i == self.num-1:
                    l1.append(word)
        return l1
    
    def longest(self):
        l = []
        count = self.length(self.list[0])
        for i in self.list:
            if self.length(i)>count:
                count = self.length(i)
                l = []
                l.append(i)
            elif self.length(i) == count:
                l.append(i)
        return set(l)

    def frequency(self):
        e = input("enter char ")
        count = 0
        for i in self.inp:
            if i==e:
                count+=1
        return count
    
    def palindrome(self):
        i = 0
        j = self.num-1
        while i!=j:
            if(self.inp[i] != self.inp[j]):
                return "no"
            i+=1
            j-=1
        return "yes"
    
    def sub(self):
        e = input("enter sub")
        n = self.length(e)
        for i in range(0, self.num-n+1):
            if self.inp[i:i+n]==e:
                return i
        return -1
    
    def occurence(self):
        l3=[]
        for i in self.list:
            count=0
            for j in self.list:
                if i == j:
                    count +=1
            l3.append(count)
        return dict(zip(self.list,l3))



obj = String()
print(obj.word_list())
print(obj.longest())
print(obj.frequency())
print(obj.palindrome())
print(obj.sub())
print(obj.occurence())