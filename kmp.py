# -*- coding: utf-8 -*-
"""
Created on Thu Nov 22 09:11:55 2018

@author: 704423953
"""
def nextJ(list1,listofnext):
    j=-1
    listofnext[0]=-1
    for i in range(1,len(list1)):
        while j!=-1 and list1[i]!=list1[j+1]:
               j=listofnext[j]              
        if list1[i]==list1[j+1]:
            j+=1
        listofnext[i]=j    
    print(listofnext)        
def kmp(listofnext,list1,list2):
    j=-1
    for i in range(len(list2)):
        while j!=-1 and list2[i]!=list1[j+1]:
            j=listofnext[j]
        if  list2[i]==list1[j+1]:
            j+=1
        if j==len(list1)-1:
            print("getit")
            print(i)
            break
list1=list("ABCDABD")
listofnext=[0 for i in range(len(list1))]
nextJ(list1,listofnext)
list2=list("BBCABCDABABCDABCDABDE")
kmp(listofnext,list1,list2)