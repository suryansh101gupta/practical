classroom = []
cricket = []
badminton = []
football = []
cb = []
cf = []
bf = []
icbf = []
n1 = int(input("Enter number and roll no. of students in classroom : "))
for i in range(0, n1):
    element = int(input())
    classroom.append(element)
n2 = int(input("Enter number and roll no. of students playing cricket : "))
for i in range(0, n2):
    element1 = int(input())
    cricket.append(element1)
n3 = int(input("Enter number and roll no. of students playing badminton : "))
for i in range(0, n3):
    element2 = int(input())
    badminton.append(element2)
n4 = int(input("Enter number and roll no. of students playing football : "))
for i in range(0, n4):
    element3 = int(input())
    football.append(element3)

    
def unionb():
    for j in cricket:
        for k in badminton:
            if k == j:
                break
            else:
                cricket.append(k)
    print("this is cricket union badminton", set(cricket))

for w in cricket:
    for q in football:
        if q == w:
            cf.append(q)
        else:
            continue
print("this is cricket intersection football", cf)


for w in cf:
    for q in badminton:
        if q == w:
            icbf.append(q)
        else:
            continue
print("this is football intersection badminton intersection cricket", icbf)


def unioncbf():
    for t in football:
        for r in badminton:
            if t == r:
                break
            else:
                badminton.append(t)
    for o in football:
        for p in cricket:
            if o == p:
                break
            else:
                football.append(p)
    print("this is football union badminton union cricket", set(football))


unionb()

unioncbf()

print(n4)