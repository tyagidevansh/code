def mergeInBetween(list1, a, b, list2):
        i = 1
        temp = list1.next
        prev = list1

        while i != a:
            temp = temp.next
            prev = prev.next
            i += 1
        
        for i in range(b - a + 1):
            temp = temp.next

        prev.next = list2

        temp2 = list2
        while temp2.next != None:
            temp2 = temp2.next

        temp2.next = temp        

        return list1